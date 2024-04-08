#include "display.h"
#include <unistd.h>
#include <stdio.h>
#include "sense.h"

#define WHITE 0xFFFF
#define BLACK 0x0000

#define BLUE 0x001F
#define GREEN 0x07E0
#define RED 0xF800


pi_framebuffer_t *fb = NULL;
sense_fb_bitmap_t *bm = NULL;

int open_display(void) {
// fb and bm are initialized (notice the lack of type), and
// display colons is called in open_display
// to me (Mekhai) this makes sense, because the colons are
// a necessary part of the clock's environment.
	fb=getFrameBuffer();
	bm=fb->bitmap;
	clearFrameBuffer(fb, 0);
}

void display_time(int hours, int minutes, int seconds) {
	display_hours(hours);
	display_minutes(minutes);
	display_seconds(seconds);
}

void display_colons(void) {

// Left Colon
	bm->pixel[5][2]=WHITE;
	bm->pixel[5][3]=WHITE;
	bm->pixel[5][5]=WHITE;
	bm->pixel[5][6]=WHITE;

	bm->pixel[4][2]=WHITE;
	bm->pixel[4][3]=WHITE;
	bm->pixel[4][5]=WHITE;
	bm->pixel[4][6]=WHITE;

// Right Colon
	bm->pixel[2][2]=WHITE;
	bm->pixel[2][3]=WHITE;
	bm->pixel[2][5]=WHITE;
	bm->pixel[2][6]=WHITE;

	bm->pixel[1][2]=WHITE;
	bm->pixel[1][3]=WHITE;
	bm->pixel[1][5]=WHITE;
	bm->pixel[1][6]=WHITE;
}

void display_hours(int hours) {

// Converting the hour to binary

	static char binary_hours[4] ;
	int i = 0 ;

	while (hours > 0) {
		int remainder = hours % 2 ;

		binary_hours[i] = remainder + '0' ;

		hours = hours / 2 ;

		i++ ;
	}

// IT WILL CONVERT IT BACKWARDS
// 24 => 00011 , instead of , 24 => 11000
// but it is taken care of because reverse the checking order for display


// Displaying Hours

	// Check for_00001
	if ( binary_hours[0] == '1' ) {
		bm->pixel[6][7]=BLUE ;
	} else {
		bm->pixel[6][7]=BLACK ;
	}

	// Check for_00010
	if ( binary_hours[1] == '1' ) {
		bm->pixel[6][6]=BLUE ;
	} else {
		bm->pixel[6][6]=BLACK ;
	}

	// Check for_00100
	if ( binary_hours[2] == '1' ) {
		bm->pixel[6][5]=BLUE ;
	} else {
		bm->pixel[6][5]=BLACK ;
	}

	// Check for_01000
	if ( binary_hours[3] == '1' ) {
		bm->pixel[6][4]=BLUE ;
	} else {
		bm->pixel[6][4]=BLACK ;
	}

	// Check for_10000
	if ( binary_hours[4] == '1' ) {
		bm->pixel[6][3]=BLUE ;
	} else {
		bm->pixel[6][3]=BLACK ;
	}
}

void display_minutes(int minutes) {

// Converting the minutes to binary

	static char binary_minutes[5] ;
	int i = 0 ;

	while (minutes > 0) {
		int remainder = minutes % 2 ;

		binary_minutes[i] = remainder + '0' ;

		minutes = minutes / 2 ;

		i++ ;
	}

// IT WILL CONVERT IT BACKWARDS
// 60 => 001111 , instead of , 60 => 111100
// but it is taken care of because reverse the checking order for display


// Displaying Minutes

	// Check for_000001
	if ( binary_minutes[0] == '1' ) {
		bm->pixel[3][7]=GREEN ;
	} else {
		bm->pixel[3][7]=BLACK ;
	}

        // Check for_000010
        if ( binary_minutes[1] == '1' ) {
                bm->pixel[3][6]=GREEN ;
        } else {
                bm->pixel[3][6]=BLACK ;
	}

        // Check for_000100
        if ( binary_minutes[2] == '1' ) {
                bm->pixel[3][5]=GREEN ;
        } else {
                bm->pixel[3][5]=BLACK ;
	}

        // Check for_001000
        if ( binary_minutes[3] == '1' ) {
                bm->pixel[3][4]=GREEN ;
        } else {
                bm->pixel[3][4]=BLACK ;
	}

        // Check for_010000
        if ( binary_minutes[4] == '1' ) {
                bm->pixel[3][3]=GREEN ;
        } else {
                bm->pixel[3][3]=BLACK ;
	}

        // Check for_100000
        if ( binary_minutes[5] == '1' ) {
                bm->pixel[3][2]=GREEN ;
        } else {
                bm->pixel[3][2]=BLACK ;
	}
}

void display_seconds(int seconds) {

// Converting the seconds to binary

        static char binary_seconds[5] ;
        int i = 0 ;

        while (seconds > 0) {
                int remainder = seconds % 2 ;

                binary_seconds[i] = remainder + '0' ;

                seconds = seconds / 2 ;

                i++ ;
        }

// IT WILL CONVERT IT BACKWARDS
// 60 => 001111 , instead of , 60 => 111100
// but it is taken care of because reverse the checking order for display

// Displaying Seconds
	// Check for_000001
	if ( binary_seconds[0] == '1' ) {
		bm->pixel[0][7]=RED ;
	} else {
		bm->pixel[0][7]=BLACK ;
	}

	// Check for_000010
        if ( binary_seconds[1] == '1' ) {
                bm->pixel[0][6]=RED ;
        } else {
                bm->pixel[0][6]=BLACK ;
        }

        // Check for_000100
        if ( binary_seconds[2] == '1' ) {
                bm->pixel[0][5]=RED ;
        } else {
                bm->pixel[0][5]=BLACK ;
	}

        // Check for_001000
        if ( binary_seconds[3] == '1' ) {
                bm->pixel[0][4]=RED ;
        } else {
                bm->pixel[0][4]=BLACK ;
	}

        // Check for_010000
        if ( binary_seconds[4] == '1' ) {
                bm->pixel[0][3]=RED ;
        } else {
                bm->pixel[0][3]=BLACK ;
	}

        // Check for_100000
        if ( binary_seconds[5] == '1' ) {
                bm->pixel[0][2]=RED ;
        } else {
                bm->pixel[0][2]=BLACK ;
	}
}

void close_display(void) {
//Pretty self explanatory. the LED array is cleared
//and one second later the program stops.
	clearFrameBuffer(fb,0);
	sleep(1);
	freeFrameBuffer(fb);
}
