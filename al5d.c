 /*
 * al5d.c - multi-thread program to control ald5 arm robot
 *	
 *
 *	Author				Date			Version
 *	Serge Hould			28 Feb 2019		template
 *		
*			
 *			
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <pthread.h>
#include <stdint.h>
#include <ctype.h>
#include <libgen.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/uio.h>
#include <net/if.h>
#include "../terminal.h"
#include <fcntl.h>   /* File control definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include "../lib.h"
#include "can.h"
#include "kinematic.h"
#include "public.h"





int main(int argc, char **argv)
{
	 /*Ncurse config */
	initscr();			/* Start curses mode 		  */
	keypad(stdscr, TRUE);  // enable keyboard mapping
	nonl();         // tell curses not to do NL->CR/NL on output
	cbreak();       // take input chars one at a time, no wait for \n ; necessary for moving the robot
	noecho();        // do not echo input

	/**** rx-tx CAN stuff ***********/
	open_socket(); // CAN socket


	startTask1();	//Control
	startTask3();  //Rx
	
	
	pthread_join1();
	pthread_join3();

    exit(EXIT_SUCCESS);
}




