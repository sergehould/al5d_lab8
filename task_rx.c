 /*
	
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
#include <ncurses.h>
#include "../terminal.h"
#include <fcntl.h>   /* File control definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include "../lib.h"
#include "can.h"
#include "kinematic.h"
#include "public.h"

static void *pTask3( void *ptr );
static pthread_t thread3;

void startTask3(void){
/* Thread Area	*/
	int  iret3;
	mvprintw(17,0,"Starting task 3");
	refresh();
    /* Create independent threads each of which will execute function */
     iret3 = pthread_create( &thread3, NULL, pTask3, NULL);
     if(iret3)
     {
         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret3);
         exit(EXIT_FAILURE);
     }

}
void pthread_join3(void){
     /* Wait till threads are complete before main continues. Unless we  */
     /* wait we run the risk of executing an exit which will terminate   */
     /* the process and all threads before the threads have completed.   */
     pthread_join( thread3, NULL);
}



void *pTask3( void *ptr );
/*
	Task3
	Task that receive command from the CAN bus.
*/
void *pTask3( void *ptr1 ){
	int j;
	int tics;
	can_frame_ canframe;	// structure containing can frame data and id
	usleep(100000);	//100mS delay

	while (1) {
		
		canframe = get_can_mess();
		if(canframe.id == 0x22){
				mvprintw(17,0,"RX CAN frame id %x , data0: %x",canframe.id, canframe.data[0]);
				refresh();
		}	
	}
	exit;
}