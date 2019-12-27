/*
 * getbit -- a program for obtaining a bit from an integer
 *
 * History
 * 1.0          Matt Bishop; original version
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * the main routine -- does it all
 *
 * Entered by:  no parameters; takes input from stdin
 *
 * Exits with:  nothing
 *
 * Exceptions:  bit position must be between 0 and 32"
 *                      -- invalid bit position entered
 * 
 * BUG: The bug is that the program will bitshift correctly, but it will return the integer version of the entire bitshifted number rather than bit number 0. 
 * FIXED: Bit number 0 can either be a 1 or 0, so I needed to find a way to convert all the preceding digits to 0 while keeping bit number 0 constant. 
 *        In order to this, after bitshifting, I used that & bitwise operator to do ((n >> bpos)&1). Because 1 is 8 bits, all the precedoing digits of 1 are zero. Thus everything before the bit number
 *        0 is converted to 0. If bit number 0 is 1, it will print a 1 because true AND true is true. If bit number 0 is 0, it will print a 0 because 0 AND 1 is false.
 */
int main(void)
{
        int n;    /* number to get bits from */
        int bpos; /* bit position we want */
        int i;    /* number of numbers read */
        char buf[1024];

        /*
     * loop reading numbers and printing bit positions
     */
    while(printf("integer bitnumber> "),
        fgets(buf, 1024, stdin) != NULL)
        {
                /* now scan in the numbers */
                i = sscanf(buf, "%d %d", &n, &bpos);
                /* first check the numbers input for errors */
                if (i == 0)
                {
                        /* nothing entered -- reprompt */
                        continue;
                }
                if (i == 1)
                {
                        /* number entered -- go for bit number */
                        printf("bit number>> ");
                        /* on eof, exit */
                        if ((i = scanf("%d", &bpos)) == -1)
                                exit(0);
                        /* if just a return, ask for number again */
                        if (i == 0)
                                continue;
                }
                /* is bit position too big? */
                if (bpos > (sizeof(n) * 8 - 1))
                {
                        printf("bit position must be between 0 and %ld\n",sizeof(n) * 8 - 1);
                        continue;
                }
                /* print the result */
                
                printf("%d\n", ((n >> bpos)&1));
        }
    

        /*
         * put out a newline, so shell prompt is on the next line
         */
        putchar('\n');

        /*
         * fare thee well!
         */
        exit(0);
}
