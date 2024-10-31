#include "print.h"


uint16_t *video_memory=0;
uint16_t screen_x=0;
uint16_t screen_y=0;

static uint16_t format_char(char c, char color);
static void put_char_in_memory(int x, int y, char c, char color);
static void write_char(char c,char color);

/*
    todo
    implement color bg and color font!
*/



static uint16_t format_char(char c, char color){
    //color=color| 0x90;  // make bg color light blue
    return (color<<8) | c;
}

static void put_char_in_memory(int x, int y, char c, char color){
    video_memory[(SCREEN_WIDTH * y) + x] = format_char(c, color);
}

static void write_char(char c,char color){
    if(c=='\n'){
        screen_x=0;
        screen_y+=1;
    }
    else{
        put_char_in_memory(screen_x,screen_y,c,color);
        screen_x+=1;
    }
    
    if(screen_x>=SCREEN_WIDTH){
        screen_y++;
        screen_x=0;
    }
    if (screen_y >= SCREEN_HEIGHT) {
        screen_y = 0;
    }
    return;
}

void termial_init(){
    video_memory = (uint16_t*)(0xB8000);
    screen_x = 0;
    screen_y = 0;
    for (int y = 0; y < SCREEN_HEIGHT; y++){
        for (int x = 0; x < SCREEN_WIDTH; x++){
            put_char_in_memory(x, y, ' ', 0);
        }
    }
}

void print(const char *s){
    int i=0;
    while(s[i]!='\0'){
        write_char(s[i],WHITE);
        i++;
    }
}