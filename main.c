#include "display.h"

int main(void) {
// currently (as of 4/7/24, 4:06pm) none of the conditions required for open_display
// or close_display are programmed yet. This is because I was simply testing
// the functions.
	int hours;
	int minutes;
	int seconds;
	//prepare LED array to display time
	open_display();
	display_colons();
	scanf("%d:%d:%d", &hours, &minutes, &seconds);
	//scan time from stdin, skip over colons and assign
	//everything relatively
	//while time is 8 character
	//continue scanning time
	while(1==1) {
		scanf("%d:%d:%d", &hours, &minutes, &seconds);
		display_time(hours, minutes, seconds);
	}
	//display the time
	//wait one second
	//exit program
	close_display();
	return 0;
}
