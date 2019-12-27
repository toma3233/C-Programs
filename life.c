/*
 * program to print out a grid whose dimensions are provided by the user
 * 
 * this is for homework 2, question 4, for ECS 36A Fall 2019
 *
 * Tom Abraham, ECS 36A
 * October 22, 2019
 */
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char finished_array[100]; /* Declare global array ghat will store the row, the x, and the column */

    /* Prints the horizontal dashes of the grid. Paramamters it takes are the rows and columns */
void printHorizontal(int rows, int columns){
    int i; /* Declare int i that acts as counter for the for loop */
        /* Prints a space for formatting purposes */
    printf(" ");
        /* for loop that prints a certain number of horizontal dashes depending on the number of columns*/
    for(i = 1; i <= columns; i++){
        if (i == columns){
            printf("-\n");
        }
        else{
            printf("-");
        }
        
    }
}
    /* Prints the vertical dashes of the grid. Takes in rows and columns as parameters */
void printVertical(int rows, int columns){
    int i; /* Declare int i as a counter for outer for loop */
    int r; /* Declare int r as a counter for inner for loop */

        /* Prints as many vertical dashes as there are rows */
    for(i = 1; i <= rows; i++){
        printf("|");
            /* Prints as many spaces as there are columns in order to place another vertical 
               dash on the opposite side of the rectangle */
        for (r = 0; r < columns; r++){
            printf(" ");
        }
        printf("|\n");

    }
}
    /* This function takes advantage of the previous two helper functions to print the entire grid. Takes in rows and columns as parameters */
void printGrid(int rows, int columns){
        /* Prints the top horizontal line of the grid */
    printHorizontal(rows, columns);
        /* Prints the two vertical lines of the grid */
    printVertical(rows, columns);
        /* Prints the bottom line of the grid */
    printHorizontal(rows, columns); 
}

    /* Helper function to check if a character is a space. Takes a character parameter i. */
int is_space(char i){
        /* If the character is a space, return 1. Otherwise, return 0*/
    if (i == ' '){
        return 1;
    }
    else{
        return 0;
    }
}
    /* Function to get input from the user (including all spaces) and stores it in an array with 3 indices, row dimension,
       the x character, and the columns dimension */
void getInput(){
    int i=0, j=0, q=0;
    char arr[100]; /* Declare array that's used to store initial input */
        /* stores all input into array arr */
    fgets(arr, 100, stdin);
        /* filters out spaces from original array and places contents into finished_array[] */
    for (i = 0; i < sizeof(arr); i++){
       if(is_space(arr[i]) == 1){
            q = 0;
        }
        else{
            finished_array[j] = arr[i];
            j++;
        } 
    }
  

    
}

    /* main function that runs the entire program */
int main(){
    int row = 0; /* Declare and initialize row as 0 */
    int col = 0; /* Declare and initialize col as 0 */
        /* Gets input from user and stores row and col as integers */
    getInput();
    sscanf(finished_array, "%dx%d", &row, &col);
        /* Prompts user to provide proper input while input involves negative numbers or words */
    while((finished_array[0] == '-') || (finished_array[2] == '-') || (finished_array[3] == '-') || sscanf(finished_array, "%dx%d", &row, &col) != 2){
        printf("Please provide integer input that is greater than 1\n");
        getInput();
        sscanf(finished_array, "%dx%d", &row, &col);
    }
        /* Once valid input has been received, it prints the grid */
    printGrid(row, col);
    
    return(0);
}
