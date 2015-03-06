/* demo_userns.c

   Copyright 2013, Michael Kerrisk
   Licensed under GNU General Public License v2 or later

   Demonstrate the use of the clone() CLONE_NEWUSER flag.

   Link with "-lcap" and make sure that the "libcap-devel" (or
   similar) package is installed on the system.
*/
#define _GNU_SOURCE
#include <sys/capability.h>
#include <sys/wait.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define errExit(msg)    do { perror(msg); exit(EXIT_FAILURE); \
                        } while (0)

long PPID,PID;

void print_my_caps() {
    cap_t caps;

        printf("eUID = %ld;  eGID = %ld; PPID=%ld; PID=%ld  ",
                (long) geteuid(), (long) getegid(),PPID,(long)getpid());

        caps = cap_get_proc();
        printf("capabilities: %s\n", cap_to_text(caps, NULL));


}


static int                      /* Startup function for cloned child */
childFunc(void *arg)
{
 for(;;) {
  	print_my_caps();
  	sleep(5);
	}
 return 0;
}

#define STACK_SIZE (1024 * 1024)

static char child_stack[STACK_SIZE];    /* Space for child's stack */

int
main(int argc, char *argv[])
{
    /* Create child; child commences execution in childFunc() */

		PPID = getpid();
		PID = clone(childFunc, child_stack + STACK_SIZE,    /* Assume stack
                                                           grows downward */
                CLONE_NEWUSER | SIGCHLD, argv[1]);
    if (PID == -1)
        errExit("clone");
    
		print_my_caps();

    /* Parent falls through to here.  Wait for child. */

    if (waitpid(PID, NULL, 0) == -1)
        errExit("waitpid");

    exit(EXIT_SUCCESS);
}
