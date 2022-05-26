#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <string.h>
#include <sys/wait.h>
int main(int argc, char *argv[])
{
	printf("hello world (pid:%d)\n", (int)getpid());
	int rc = fork();
	if (rc < 0)
	{ // fork failed; exit
		fprintf(stderr, "fork failed\n");
		exit(1);
	}
	else if (rc == 0)
	{ // child (new process)
		printf("hello,I am child(pid:%d)\n", (int)getpid());
		char *myargs[4];
		myargs[0] = strdup("cat");	// program: "wc" (word count)
		myargs[1] = strdup("p1.c"); // argument:file to count
		myargs[2] = NULL;			// marks end of array
		execvp(myargs[0], myargs);	// runs word count
		printf("this shouldn't print out\n");
	}
	else
	{ // parent goes down this path (main)
		int rc_wait = wait(NULL);
		printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait, (int)getpid());
	}
	return 0;
}
