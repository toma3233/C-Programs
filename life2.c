# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char ch = 'a';
/*
 * Helper function that searches the current row for any characters other than 'X' or 'O' or '\n'
 * Parameters:
 *      - char arr[]: current row of the board 
 *      - arr_size: size of the current row 
 */
int searchRow(char arr[], int arr_size){
        /* Initialize counter and loop through entire row to check for invalid characters */
    int t = 0;
    for(t = 0; t < arr_size; t++){
        if(((arr[t] != 'X')) && ((arr[t] != 'O') && (arr[t]!='\n'))){
            ch = arr[t];
            return(1);
        }
    }
    return (0);
}


/*
 * draw the outline of the board
 * Method used from Professor Bishop's Life.c program
 */
void prboard(int rows, int cols, char **pattern)
{
        int i, j;       /* counters in for loops */

        /* top border */
        int len = 0;
        len = strlen(pattern[0]);
        char current_row[len];
        for(i = 0; i < cols+2; i++)
                putchar('-');
        putchar('\n');

        /* now the rows */
        for(i = 0; i < rows; i++)
        {
                putchar('|');
                strcpy(current_row, pattern[i]);
                for(j = 0; j <= cols-1; j++)
                {
                    putchar(current_row[j]);
                }

                putchar('|');
                putchar('\n');
        }

        /* bottom border */
        for(i = 0; i < cols+2; i++)
                putchar('-');
        putchar('\n');
}

/*
 * Main function that runs the entire program
 * Takes in a file containing a board from the command line as a parameter
 */
int main(int argc, char ** argv){
    if (argc != 2){
        fprintf(stderr, "Usage: %s board_pattern\n", argv[0]);
        return(1);
    }
        /* Initializes file pointer fp as well as some other counters used throughout the program. */
    FILE *fp;
    int i, r=0, c;

        /* Allocating memory for the rows and columns of the board array using malloc. Max of 100 chars each needed */
    char **board = malloc(100 * sizeof(char *)); 
    for (i = 0; i < 100; i++){
        board[i] = malloc(100 * sizeof(char));
            /* Checks if malloc fails, if so prints the string saved in allocated space */
        if (board[i] == NULL){
            perror(board[i]);
            return(1);
        }
    }

    fp = fopen(argv[1], "r");
        /* Prints name of file if opening fails*/
    if (fp == NULL){
        perror(argv[1]);
        return(1);
    }
        /* Scanning in all the chars from the board, row by row until eof has been reached */
    while (!feof(fp)){
        fscanf(fp, "%s", board[r]);
        ++r;
    }

    int row_length = strlen(board[0]); /* Initializing the standard row_length (num of columns) as the row_length of the first row */
        /* Loops through every row in the board. Checks if the length of the current row is the same as row_length, else throws an error.
           Also uses helper function searchRow to check if there are any invalid characters in the current line. If there are, it throws an error.*/
    for(c = 0; c < r-1; c++){
        if(strlen(board[c]) != row_length){
            fprintf(stderr, "%s: line %d is wrong length\n", argv[1], c);
            return(1);
        }
        if (searchRow((board[c]), row_length) == 1){
            fprintf(stderr, "%s: bad character ’%c’ in line%d\n", argv[1], ch, c);
            return(1);
        }
    }

        /*If board passes error checking, uses helper function to print out the  board. */
    prboard(r-1, row_length,board);
    
}
