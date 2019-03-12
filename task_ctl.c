 /*
 *		TO DO: encapsulate for initSerial()	
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
#include <ncurses.h>
#include "../terminal.h"
#include <fcntl.h>   /* File control definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include "../lib.h"
#include "can.h"
#include "kinematic.h"
#include "public.h"
//Global
static 	int file=0;  // serial


void *pTask1( void *ptr );
void startTask1(void);
pthread_t thread1;

static pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
;

void startTask1(void){
/* Thread Area	*/

     const char *message = "Thread Task";

     int  iret1;
	mvprintw(17,0,"Starting task 1");
	refresh();
    /* Create independent threads each of which will execute function */

     iret1 = pthread_create( &thread1, NULL, pTask1, NULL);
     if(iret1)
     {
         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret1);
         exit(EXIT_FAILURE);
     }


     /* Wait till threads are complete before main continues. Unless we  */
     /* wait we run the risk of executing an exit which will terminate   */
     /* the process and all threads before the threads have completed.   */
}

void pthread_join1(void){
     pthread_join( thread1, NULL);
}

/*
	Task1
	
*/




void *pTask1( void *ptr )
{

	/* serial init*/
	//initSerial();
	
	while(1){
		
	}// while 1
}

void initSerial(void){

    if ((file = open("/dev/ttyO4", O_RDWR))<0)
    {
        printf("UART: Failed to open the file.\n");
        return;
    }
    struct termios options; // the termios structure is vital
    tcgetattr(file, &options); // sets the parameters associated with file

    // Set up the communications options:
    // 9600 baud, 8-bit, enable receiver, no modem control lines
    options.c_cflag = B9600 | CS8 | CREAD	| CLOCAL;
    options.c_iflag = IGNPAR | ICRNL; // ignore partity errors, CR -> newline
    tcflush(file, TCIFLUSH); // discard file information not transmitted
    tcsetattr(file, TCSANOW, &options); // changes occur immmediately
}


