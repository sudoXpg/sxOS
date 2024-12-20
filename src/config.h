#ifndef CONFIG_H
#define CONFIG_H

#define SCREEN_HEIGHT 240
#define SCREEN_WIDTH  160

// #define SCREEN_HEIGHT 120
// #define SCREEN_WIDTH  80

#define sxOS_TOTAL_INTERRUPTS 256       // total number of interrupts in the kernel
#define KERNEL_CODE_SELECTOR 0x08       // from the boot.asm
#define KERNEL_DATA_SELECTOR 0x10       // from the boot.asm



#define sxOS_logo "" \
"  /\\_/\\   \n" \
" ( o.o )  \n" \
"  > ^ <    \n"\
"\n            SxOS v1.0"


// colors 
#define BLACK 	        0
#define BLUE 	        1
#define GREEN 	        2
#define CYAN 	        3
#define RED 	        4
#define PURPLE 	        5
#define BROWN 	        6
#define GRAY 	        7
#define DARK_GRAY 	    8
#define LIGHT_BLUE 	    9
#define LIGHT_GREEN     10
#define LIGHT_CYAN 	    11
#define LIGHT_RED 	    12
#define LIGHT_PURPLE    13
#define YELLOW 	        14
#define WHITE 	        15

#endif