#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>
#include <termios.h>
#include <time.h>
char * tablica_znakow(int);
struct termios orig_term_attr;
struct termios new_term_attr;
static const char *const evval[3] = {
    "RELEASED",
    "wcisnieto ",
    "REPEATED"
};

int main(void)
{
tcgetattr(fileno(stdin), &orig_term_attr);
    memcpy(&new_term_attr, &orig_term_attr, sizeof(struct termios));
    new_term_attr.c_lflag &= ~(ECHO|ICANON);
    new_term_attr.c_cc[VTIME] = 0;
    new_term_attr.c_cc[VMIN] = 0;
    tcsetattr(fileno(stdin), TCSANOW, &new_term_attr);


 FILE *fp;
char * znak;
//fp=fopen("znaki_klawiatury.txt", "w");
    const char *dev = "/dev/input/by-path/platform-3f980000.usb-usb-0:1.4:1.0-event-kbd";
    struct input_event ev;
    ssize_t n;
    int fd;

    fd = open(dev, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Cannot open %s: %s.\n", dev, strerror(errno));
        return EXIT_FAILURE;
    }

while (1) {
        n = read(fd, &ev, sizeof ev);
        if (n == (ssize_t)-1) {
            if (errno == EINTR)
                continue;
            else
                break;
        } else
        if (n != sizeof ev) {
            errno = EIO;
            break;
        }


      if (ev.type == EV_KEY && ev.value > 0 && ev.value < 2)
{
fp=fopen("znaki_klawiatury.txt", "a+");
 printf("%s  (%s)\n", evval[ev.value],znak);

znak = tablica_znakow((int)ev.code);
fprintf (fp, "%s", znak);
fclose (fp);
if(ev.code == KEY_ESC)
{
tcsetattr(fileno(stdin), TCSANOW, &orig_term_attr);
//fclose (fp); 
return 0;
}
}
    }
    fflush(stdout);
    fprintf(stderr, "%s.\n", strerror(errno));
    return EXIT_FAILURE;
}

char * tablica_znakow(int event_code)
{
char** znakchar = (char**) malloc(123*sizeof(char*));
char* znak;
znakchar[0] ="  KEY_RESERVE";
znakchar[1] ="  KEY_ESC";		
znakchar[2] ="  KEY_1"	;	
znakchar[3] ="  KEY_2"	;	
znakchar[4] ="  KEY_3"	;	
znakchar[5] ="  KEY_4"	;	
znakchar[6] ="  KEY_5"	;
znakchar[7] ="  KEY_6"	;		
znakchar[8] ="  KEY_7"	;		
znakchar[9] ="  KEY_8"	;	
znakchar[10] ="  KEY_9"	;		
znakchar[11] ="  KEY_0"	;		
znakchar[12] ="  KEY_MINUS";		
znakchar[13] ="  KEY_EQUAL"	;
znakchar[14] ="  KEY_BACKSPACE";		
znakchar[15] ="  KEY_TAB"		;
znakchar[16] ="  KEY_Q"		;
znakchar[17] ="  KEY_W"		;
znakchar[18] ="  KEY_E"		;
znakchar[19] ="  KEY_R"		;
znakchar[20] ="  KEY_T"		;
znakchar[21] ="  KEY_Y"		;
znakchar[22] ="  KEY_U"		;
znakchar[23] ="  KEY_I"		;
znakchar[24] ="  KEY_O"		;
znakchar[25] ="  KEY_P"		;
znakchar[26] ="  KEY_LEFTBRACE";		
znakchar[27] ="  KEY_RIGHTBRACE";	
znakchar[28] ="  KEY_ENTER"	;
znakchar[29] ="  KEY_LEFTCTRL";		
znakchar[30] ="  KEY_A"	;
znakchar[31] ="  KEY_S"	;
znakchar[32] ="  KEY_D"	;
znakchar[33] ="  KEY_F";
znakchar[34] ="  KEY_G";
znakchar[35] ="  KEY_H";
znakchar[36] ="  KEY_J";
znakchar[37] ="  KEY_K";
znakchar[38] ="  KEY_L";
znakchar[39] ="  KEY_SEMICOLON";
znakchar[40] ="  KEY_APOSTROPHE";		
znakchar[41] ="  KEY_GRAVE";
znakchar[42] ="  KEY_LEFTSHIFT";		
znakchar[43] ="  KEY_BACKSLASH";
znakchar[44] ="  KEY_Z";
znakchar[45] ="  KEY_X";
znakchar[46] ="  KEY_C";
znakchar[47] ="  KEY_V";
znakchar[48] ="  KEY_B";
znakchar[49] ="  KEY_N";
znakchar[50] ="  KEY_M";
znakchar[51] ="  KEY_COMMA"	;
znakchar[52] ="  KEY_DOT"	;
znakchar[53] ="  KEY_SLASH"	;
znakchar[54] ="  KEY_RIGHTSHIFT";		
znakchar[55] ="  KEY_KPASTERISK";		
znakchar[56] ="  KEY_LEFTALT";
znakchar[57] ="  KEY_SPACE"	;
znakchar[58] ="  KEY_CAPSLOCK";		
znakchar[59] ="  KEY_F1"	;
znakchar[60] ="  KEY_F2"	;
znakchar[61] ="  KEY_F3"	;
znakchar[62] ="  KEY_F4"	;
znakchar[63] ="  KEY_F5"	;
znakchar[64] ="  KEY_F6"	;
znakchar[65] ="  KEY_F7"	;
znakchar[66] ="  KEY_F8"	;
znakchar[67] ="  KEY_F9"	;
znakchar[68] ="  KEY_F10"	;
znakchar[69] ="  KEY_NUMLOCK";	
znakchar[70] ="  KEY_SCROLLLOCK";		
znakchar[71] ="  KEY_KP7";
znakchar[72] ="  KEY_KP8"	;
znakchar[73] ="  KEY_KP9"	;
znakchar[74] ="  KEY_KPMINUS";	
znakchar[75] ="  KEY_KP4"	;
znakchar[76] ="  KEY_KP5"	;
znakchar[77] ="  KEY_KP6"	;
znakchar[78] ="  KEY_KPPLUS";	
znakchar[79] ="  KEY_KP1"	;
znakchar[80] ="  KEY_KP2"	;
znakchar[81] ="  KEY_KP3"	;
znakchar[82] ="  KEY_KP0"	;
znakchar[83] ="  KEY_KPDOT"	;
znakchar[85] ="  KEY_ZENKAKUHANKAKU";	
znakchar[86] ="  KEY_102ND"	;
znakchar[87] ="  KEY_F11"	;
znakchar[88] ="  KEY_F12"	;
znakchar[89] ="  KEY_RO"	;
znakchar[90] ="  KEY_KATAKANA"	;	
znakchar[91] ="  KEY_HIRAGANA"	;
znakchar[92] ="  KEY_HENKAN"	;
znakchar[93] ="  KEY_KATAKANAHIRAGANA";	
znakchar[94] ="  KEY_MUHENKAN"	;
znakchar[95] ="  KEY_KPJPCOMMA"	;
znakchar[96] ="  KEY_KPENTER"	;
znakchar[97] ="  KEY_RIGHTCTRL	";
znakchar[98] ="  KEY_KPSLASH	";
znakchar[99] ="  KEY_SYSRQ"	;
znakchar[100] ="  KEY_RIGHTALT";		
znakchar[101] ="  KEY_LINEFEED"	;	
znakchar[102] ="  KEY_HOME"	;
znakchar[103] ="  KEY_UP"	;
znakchar[104] ="  KEY_PAGEUP";	
znakchar[105] ="  KEY_LEFT"	;
znakchar[106] ="  KEY_RIGHT";	
znakchar[107] ="  KEY_END" 	;	
znakchar[108] ="  KEY_DOWN"	;
znakchar[109] ="  KEY_PAGEDOWN";		
znakchar[110] ="  KEY_INSERT"	;
znakchar[111] ="  KEY_DELETE"	;
znakchar[112] ="  KEY_MACRO"	;
znakchar[113] ="  KEY_MUTE";
znakchar[114] ="  KEY_VOLUMEDOWN";		
znakchar[115] ="  KEY_VOLUMEUP"	;
znakchar[116] ="  KEY_POWER"	;
znakchar[117] ="  KEY_KPEQUAL"	;
znakchar[118] ="  KEY_KPPLUSMINUS";		
znakchar[119] ="  KEY_PAUSE";
znakchar[120] ="  KEY_SCALE";
znakchar[121] ="  KEY_KPCOMMA";	
znakchar[122] ="  KEY_HANGEUL"	;
znak = znakchar[event_code];
free(znakchar);
return znak;
}
