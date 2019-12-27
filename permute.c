/*
 * program to output every possible permutation of a character sequence by taking advantage of a 
 * recursive "permute" function as well as a helper function "swapValues"
 * 
 * this is for homework 2, question 3, for ECS 36A Fall 2019
 * 
 * parameters for permute: *s - pointer to the user's desired character sequence
 *                         starting_index - starting index used for swap functon that increments during every iteration
 *                         ending_index - last index of the character sequence
 * 
 * prints: every possible permutation of the user inputted character sequence
 *
 * Tom Abraham, ECS 36A
 * October 22, 2019
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

/* Helper function that swaps two characters from one's
 * original index to the other one's original index and vice versa
 * *first - pointer to the first character that needs to swap places
 * *second - pointer to the second character that needs to swap places
 */
void swapValues(char *first, char *second)
{
    char temp; /* Declare variable that acts as a placeholder for swap to take place*/
        /* Original value of first placed in temp, first takes the value of second, and second reaches back into temp to get the orginal value of first */
    temp = *first;
    *first = *second;
    *second = temp;
}

/* Recursive function permute that uses the swap function and calls itself until every permutation has been printed.
   Takes three parameters: the character sequence, the variable starting_index, and the constant ending_index */
void permute(char *s, int starting_index, int ending_index)
{
    int i; /* Declare variable i that acts as a counter for the for loop*/
    /*Base case is when permute has iterated through the entire character sequence*/
    if (starting_index == ending_index)
    {
        printf("%s", s);
    }
    else
    {
        for (i = starting_index; i <= ending_index; i++)
        {
                /* Swaps characters, calls the recursive function, prints permutation, and last swap resets so swap
                   can continue until all possible permutations have been printed*/
            swapValues((s+starting_index), (s+i));
            permute(s, (starting_index + 1), ending_index);
            swapValues((s+starting_index), (s+i));
        }
    }
}

/* main function that runs the entire program */
int main(){
    char input[SIZE]; /* Declares input array with a maximum size of a 100 characters */
    int input_length; /* length of the user provided input */
        /* while loop that keeps prompting user to enter new character sequences until NULL character and new line character has been red */
    while (*input != '\n'){
        printf("$>$ ");
        fgets(input, SIZE, stdin);
        input_length = strlen(input);
        permute(input, 0, input_length - 2);
    }
    return (0);
}
