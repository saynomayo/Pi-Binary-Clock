#include "display.h"

int main(void) {
	int hours;
	int minutes;
	int seconds;
	//prepare LED array to display time
	open_display();
	scanf("%d:%d:%d", &hours, &minutes, &seconds);
	//scan time from stdin, skip over colons and assign
	//everything relatively
	//while time is "proper"
	while (hours>-1 && hours<24 && minutes>-1 && minutes<60 && seconds>-1 && seconds<60) {
		scanf("%d:%d:%d", &hours, &minutes, &seconds);
		display_time(hours, minutes, seconds);
	}
	//exit program
	close_display();
	return 0;
}
