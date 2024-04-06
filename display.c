#include "display.h"
#include <unistd.h>
#include <stdio.h>
#include "sense.h"

#define WHITE 0xFFFF
#define BLACK 0x0000

#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x07E0

int open_display(void);

void display_time(int hours, int minutes, int seconds);

void display_colons(void);

// Left Colon
	bm->pixel[5][1]=WHITE;
	bm->pixel[5][2]=WHITE;
	bm->pixel[5][4]=WHITE;
	bm->pixel[5][5]=WHITE;

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

void display_hours(int hours) {

// Converting the hour to binary 

	int binary_hours = 0 ;
	int i = 1 ;
	
	while (hours > 0) {
		int remainder = hours % 2 ;

		binary_hours += remainder * i ;
		
		hours = hours / 2 ;

		i = i * 10 ;
	}

}

// Displaying Hours
	// Check for_00001
	if ( binary_hours[4] == 1 ) { 
		bm->pixel[6][7]=BLUE ;
	} else {
		bm->pixel[6][7]=BLACK ;
	}

	// Check for_00010
	if (binary_hours[3] == 1 ) {
		bm->pixel[6][6]=BLUE ;
	} else {
		bm->pixel[6][6]=BLACK ;

	// Check for_00100
	if (binary_hours[2] == 1) {
		bm->pixel[6][5]=BLUE ;
	} else {
		bm->pixel[6][5]=BLACK ;

	//Check for_01000
	if (binary_hours[1] == 1) {
		bm->pixel[6][4]=BLUE ;
	} else {
		bm->pixel[6][4]=BLACK ;

	//Check for_10000
	if (binary_hours[0] == 1) {
		bm->pixel[6][3]=BLUE ;
	} else {
		bm->pixel[6][3]=BLACK ;


void display_minutes(int minutes);

void display_seconds(int seconds);

void close_display(void);
