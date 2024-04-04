#include "display.h"
#include <unistd.h>
#include <stdio.h>
#include "sense.h"

#define WHITE 0xFFFF
#define BLACK 0x0000

int open_display(void);

void display_time(int hours, int minutes, int seconds);

void display_colons(void);

// Left Colon
bm->pixel[5][1]=WHITE;
bm->pixel[5][2]=WHITE;
bm->pixel[5][4]=WHITE;
bm->pixel[5][5]=WHITE;
bm->pixel[4][1]=WHITE;
bm->pixel[4][2]=WHITE;
bm->pixel[4][4]=WHITE;
bm->pixel[4][5]=WHITE;

// Right Colon
bm->pixel[2][1]=WHITE;
bm->pixel[2][2]=WHITE;
bm->pixel[2][4]=WHITE;
bm->pixel[2][5]=WHITE;
bm->pixel[1][1]=WHITE;
bm->pixel[1][2]=WHITE;
bm->pixel[1][4]=WHITE;
bm->pixel[1][5]=WHITE;

void display_hours(int hours);

void display_minutes(int minutes);

void display_seconds(int seconds);

void close_display(void);
