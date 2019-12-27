/*
 * program to count using a for loop, a while loop, and a do...while loop
 * with an increment
 * this is the framework; the counting is done in functions to be supplied
 * in another file
 * 
 * this is for homework 1, extra credit question 1, for ECS 36A Fall 2019
 *
 * Matt Bishop, ECS 36A
 * version 1	September 20, 2019
 *	original version
 * version 2	September 28, 2019
 *  modified so students only need to add the loop code
 * 
 * parameters: m - the user's desired starting number
 *             n - the user's desired ending number
 * 			   d - the user's desired increment or decrement
 * 
 * prints: a increasing or decreasing list from m to n depending on the values of m and n
 * 
 * exception: If the increment/decrement happens to be negative, it will print an error message
 * 
 * Homework Completed by Tom Abraham on October 2, 2019
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

/*
 * the "for" loop routine
 * m is the starting number
 * n is the ending number
 * d is the increment
 */
void do_for(int m, int n, int d)
{
    if (m < n){
        int val; /* declare variable val that acts as a counter for the loop */
			/* for loop that prints m and increments it by d until it reaches n, printing a increasing list of numbers from m to n */
        for (val = m; val <= n; val += d){
				/* Error checking to ensure that the increment value d is not negative */
			if (d < 0){
				printf("Error: invalid increment %d\n", d);
				break;
			}
				/* Uses if else statement to place a comma and a space after all numbers except the last one, where a new line is placed*/
			if ((val == n) || (val + d > n)){
				printf("%d\n", val);
			}
			else{
				printf("%d, ", val);
			}
            
        }
		
    }
    	/* if the starting value m and the ending value n are equivalent it prints the value m */
    if (m == n){
        printf("%d\n", m);
    }
    if (m > n){
        int val; /* declare variable val that acts as a counter for the loop */
			/* for loop that prints starting value m and decrements it by d until it reaches ending value n, printing a decreasing list of numbers from m to n */
        for (val = m; val >= n; val -= d){
			if (d < 0){
					/* Error checking to ensure that the decrement value d is not negative */
				printf("Error: invalid decrement %d\n", d);
				break;
			}
				/* Uses if else statement to place a comma and a space after all numbers except the last one, where a new line is placed */	
            if ((val == n) || (val - d < n)){
				printf("%d\n", val);
			}
			else{
				printf("%d, ", val);
			}
        }
    }
}

/*
 * the "while" loop routine
 * m is the starting number
 * n is the ending number
 */
void do_while(int m, int n, int d)
{
    if (m < n){	
        int val = m; /* intialize variable val that acts as a counter for the loop */
			/* while loop that prints m and increments it by d until it reaches n, printing a increasing list of numbers from m to n */
        while (val <= n){
			if (d < 0){
					/* Error checking to ensure that the increment value d is not negative */
				printf("Error: invalid increment %d\n", d);
				break;
			}
				/* Uses if else statement to place a comma and a space after all numbers except the last one, where a new line is placed */
            if ((val == n) || (val + d > n)){
				printf("%d\n", val);
			}
			else{
				printf("%d, ", val);
			}
            val += d;
        }
		
    }
    	/* if the starting value m and the ending value n are equivalent it prints the value m */
    if (m == n){
        printf("%d\n", m);
    }
    if (m > n){
        int val = m; /* intialize variable val that acts as a counter for the loop */
			/* while loop that prints m and decrements it by d until it reaches n, printing a decreasing list of numbers from m to n */
        while(val >= n){
				/* Error checking to ensure that the decrement value d is not negative */
			if (d < 0){
				printf("Error: invalid decrement %d\n", d);
				break;
			}
				/* Uses if else statement to place a comma and a space after all numbers except the last one, where a new line is placed */
            if ((val == n) || (val - d < n)){
				printf("%d\n", val);
			}
			else{
				printf("%d, ", val);
			}
            val -= d;
        }
    }
}

/*
 * the "do . . . while" loop routine
 * m is the starting number
 * n is the ending number
 */
void do_do(int m, int n, int d)
{
    if (m < n){
        int val = m; /* initialize variable val that acts as a counter for the loop */
			/* do while loop that prints m and increments it by d until it reaches n, printing a increasing list of numbers from m to n */
        do {
				/* Error checking to ensure that the increment value d is not negative */
			if (d < 0){
				printf("Error: invalid increment %d\n", d);
				break;
			}
				/* Uses if else statement to place a comma and a space after all numbers except the last one, where a new line is placed */
            if ((val == n) || (val + d > n)){
				printf("%d\n", val);
			}
			else{
				printf("%d, ", val);
			}
            val += d;
        } while (val <= n);

    }
    	/* if starting value m and ending value n are equivalent it prints the value m */
    if (m == n){
        printf("%d\n", m);
    }
    if (m > n){
        int val = m; /* initialize variable val that acts as a counter for the loop */
			/* do while loop that prints m and decrements it by d until it reaches n, printing a decreasing list of numbers from m to n */
        do {
				/* Error checking to ensure that the decrement value d is not negative */
			if (d < 0){
				printf("Error: invalid decrement %d\n", d);
				break;
			}
			/* Uses if else statement to place a comma and a space after all numbers except the last one, where a new line is placed */
            if ((val == n) || (val - d < n)){
				printf("%d\n", val);
			}
			else{
				printf("%d, ", val);
			}
            val -= d;
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
	int d;		/* increment */
	int err;	/* place for error code */

	/*
	 * check that you got 3 arguments,
	 * the starting point, the ending point,
	 * and the increment
	 */
	if (argc != 4){
		fprintf(stderr, "Usage: %s m n\n", argv[0]);
		return(1);
	}

	/* get the starting point */
	if ((m = getint(argv[1], &err)) == -1 && err)
		return(1);

	/* get the ending point */
	if ((n = getint(argv[2], &err)) == -1 && err)
		return(1);

	/* get the increment */
	if ((d = getint(argv[3], &err)) == -1 && err)
		return(1);

	/*
	 * do the loops
	 */
	/* announce the for loop and do it */
	printf("for loop:\n");
	do_for(m, n, d);

	/* announce the while loop and do it */
	printf("while loop:\n");
	do_while(m, n, d);

	/* announce the do ... while loop and do it */
	printf("do ... while loop:\n");
	do_do(m, n, d);


	/*
	 * all done -- give good exit code
	 */
	return(0);
}
