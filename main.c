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
	//scan time from stdin, skip over colons and assign 
	//everything relatively
	scanf("%d:%d:%d", &hours, &minutes, &seconds);
	//while time is 8 characters
	while (1==1) {
		//continue scanning time
		scanf("%d:%d:%d", &hours, &minutes, &seconds);
		//display the time
		display_time(hours, minutes, seconds);
	}
	//wait one second
	sleep(1);
	//exit program
	close_display();
	return 0;
}
