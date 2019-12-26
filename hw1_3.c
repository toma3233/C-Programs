/*
 * program to count using a for loop, a while loop, and a do...while loop
 * this is the framework; the counting is done in functions to be supplied
 * in another file
 * 
 * this is for homework 1, question 3, for ECS 36A Fall 2019
 * 
 * parameters: m - the user's desired starting number
 *             n - the user's desired ending number
 * 
 * prints: a increasing or decreasing list from m to n depending on the values of m and n
 *
 * Matt Bishop, ECS 36A
 * version 1	September 20, 2019
 *	original version
 * version 2	September 28, 2019
 *  modified so students only need to add the loop code
 * 
 * Homework completed by Tom Abraham on October 2, 2019
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

/*
 * the "for" loop routine
 * m is the starting number
 * n is the ending number
 */
void do_for(int m, int n)
{
    if (m < n){
        int val; /* declare variable val that acts as a counter for the loop */
            /* for loop that prints m and increments it by one until it reaches n, printing a increasing list of numbers from m to n */
        for (val = m; val <= n; val += 1){
            printf("%d\n", val);
        }
    }
        /* if m and n are equivalent, it prints the value m */
    if (m == n){
        printf("%d\n", m);
    }
    if (m > n){
        int val; /* declare variable val that acts as a counter for the loop */
            /* for loop that prints m and decrements it by one until it reaches n, printing a decreasing list of numbers from m to n */
        for (val = m; val >= n; val -= 1){
            printf("%d\n", val);
        }
    }
}

/*
 * the "while" loop routine
 * m is the starting number
 * n is the ending number
 */
void do_while(int m, int n)
{
    if (m < n){
        int val = m; /* initialize variable val that acts as a counter for the loop */
            /* while loop that prints m and increments it by one until it reaches n, printing a increasing list of numbers from m to n */
        while (val <= n){
            printf("%d\n", val);
            val += 1;
        }
    }
        /* if m and n are equivalent, it prints the value m */
    if (m == n){
        printf("%d\n", m);
    }
    if (m > n){ 
        int val = m; /* initialize variable val that acts as a counter for the loop */
            /* while loop that prints m and decrements it by one until it reaches n, printing a decreasing list of numbers from m to n */
        while (val >= n){
            printf("%d\n", val);
            val -= 1;
        }
    }
}

/*
 * the "do . . . while" loop routine
 * m is the starting number
 * n is the ending number
 */
void do_do(int m, int n)
{
    if (m < n){
        int val = m;  /* initialize variable val that acts as a counter for the loop */
            /* do while loop that prints m and increments it by one until it reaches n, printing a increasing list of numbers from m to n */
        do {
            printf("%d\n", val);
            val += 1;
        } while (val <= n);
    }
        /* if m and n are equivalent, it prints the value m */
    if (m == n){
        printf("%d\n", m);
    }
    if (m > n){
        int val = m;  /* initialize variable val that acts as a counter for the loop */
            /* do while loop that prints m and decrements it by one until it reaches n, printing a decreasing list of numbers from m to n */
        do {
            printf("%d\n", val);
            val -= 1;
        } while (val >= n);
    }
}


/*
 * getint -- get an integer
 *
 * in parameters:
 * char *str	the string to be converted to an integer
 * int *error	location for integer error code
 *
 * out parameters:
 * int *error	1 if there is an error, 0 otherwise
 *
 * return value:
 * on success, integer resulting from converting str
 * on failure, -1; *error is set to 1 and error message is printed
 */
int getint(char *str, int *error)
{
	long m;			/* holds value of number in str */
	char *mend = str;	/* points to char beyond end of number */

	/*
 	 * initialize error codes
	 */
	error = 0;
	errno = 0;

	/*
	 * convert the string to a number
	 */
	m = strtol(str, &mend, 10);
	/* possible error 1: non-0integer char in string */
	if (*mend != '\0' || str == mend){
		fprintf(stderr, "%s is not an integer\n", str);
		*error = 1;
		return(-1);
	}
	/* it's a number but is too big or small to be an int */
	if (errno == ERANGE &&
		((m > 0 && m > INT_MAX) ||
			(m < 0 && m < INT_MIN))){
		fprintf(stderr, "%s is too big or small\n", str);
		*error = 1;
		return(-1);
	}

	/* okay, it's a valid integer; convert it and return */
	return((int) m);
}

/*
 * the main return
 */
int main(int argc, char *argv[])
{
	int m;		/* starting point */
	int n;		/* ending point */
	int err;	/* place for error code */


	/*
	 * check that you got 2 arguments,
	 * the starting point and the ending point
	 */
	if (argc != 3){
		fprintf(stderr, "Usage: %s m n\n", argv[0]);
		return(1);
	}

	/* get the starting point */
	if ((m = getint(argv[1], &err)) == -1 && err)
		return(1);

	/* get the ending point */
	if ((n = getint(argv[2], &err)) == -1 && err)
		return(1);
	
	/*
	 * do the loops
	 */
	/* announce the for loop and do it */
	printf("for loop:\n");
	do_for(m, n);

	/* announce the while loop and do it */
	printf("while loop:\n");
	do_while(m, n);

	/* announce the do ... while loop and do it */
	printf("do ... while loop:\n");
	do_do(m, n);

	/*
	 * all done -- give good exit code
	 */
	return(0);
}
