#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

int main(int argc, char *argv[])

{

	printf("Hello world (pid:%d)\n", (int)getpid());

	int rc = fork();

	if (rc < 0)
	{

		// fork failed

		fprintf(stderr, "fork Failed\n");

		exit(1);
	}
	else if (rc == 0)
	{

		// child (new Process)

		printf("hello, I am child (pid:%d)\n", (int)getpid());
	}
	else
	{

		// parrent goes down this path (main)

		printf("hello, I am parent of %d (pid:%d)\n", rc, (int)getpid());
	}

	return 0;
}

/* Output of the program*/
