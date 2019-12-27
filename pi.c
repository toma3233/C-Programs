/*
 * Program that prints value of pi that is rounded to 11 decimals. Then, it adds pi to itseld 10 times 
 * and also prints that value rounded to 11 decimals
 * 
 * this is for homework 2, extra credit for ECS 36A Fall 2019
 * 
 * When I compare the two values, I notice that it seems like the only difference between the two values 
 * for the first seven indices is that the decimal has been moved one place over to the right. The rest of the values differ,
 * and this is due to the fact that floating point numbers have 7 digits of precision in C. 
 *
 * Tom Abraham, ECS 36A
 * October 22, 2019
 */
# include<stdlib.h>

/* main function that runs the entire program */
int main(){
    int i; /* declare counter variable i for the for loop */
    float pi = 3.1415926535897932384626433832795028841971693993751058209; /* declare and initialize value of pi to be rounded to 11 decimals */
    float another_pi = 3.1415926535897932384626433832795028841971693993751058209; /* declare and initialize value of pi to be added to pi */
        /* uses formatting to print value of pi to 11 places */
    printf("%.11f\n", pi);
        /* for loop that uses "another_pi" to add to the increasing pi variable to get the valuable of 10pi. */
    for (i = 0; i < 9; i++){
        pi += another_pi;
    }
        /* uses formatting to print the value of 10pi to 11 places */
    printf("%1.11f\n", pi);
    return(0);
}
