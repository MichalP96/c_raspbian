#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

char *znaki;
FILE *plik;
char c;
int main()
{
    struct termios oldSettings, newSettings;

    tcgetattr( fileno( stdin ), &oldSettings );
    tcsetattr( fileno( stdin ), TCSANOW, &oldSettings);
int rozmiar_pliku = 0;



    while ( 1 )
    {
        fd_set set;
        struct timeval tv;

        tv.tv_sec = 3;
        tv.tv_usec = 0;

        FD_ZERO( &set );
        FD_SET( fileno( stdin ), &set );

        int res = select( fileno( stdin)+1, &set, NULL, NULL, &tv );

       if( res < 0 )
       {
            perror( "select error" );
            break;
        }
        else
        {

   plik = fopen ("znaki_klawiatury.txt", "r");

                        while (feof(plik)==0)
                       {
fflush(stdout);
                       fscanf(plik,"%c",&c);
                       rozmiar_pliku++;
                       printf("%c",c);
                       }
fclose(plik);
plik = fopen ("znaki_klawiatury.txt", "w");
   fprintf(plik,"%s","\n brak aktywnosci");

                 fclose(plik);


//plik = fopen ("znaki_klawiatury.txt", "r");
          //      znaki = malloc((rozmiar_pliku * sizeof(char))+1);
                //fgets(znaki,rozmiar_pliku, plik);
               // printf("%s",*znaki);
               // printf( "odczytano" );
                //fclose(plik);
        }
    }
//free(znaki);
    
    return 0;
}