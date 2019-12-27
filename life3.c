/*
 * Fully Functioning Game of Life Program
 *
 * 
 * Homework completed by Tom Abraham
 * Answer to Homework 4, question 4
 */
#include <stdio.h>
#include <string.h>

/*
 * macros
 */
#define MAXCOLS 1000
#define MAXROWS 1000

/* board dimensions */
int cols = MAXCOLS;
int rows = MAXROWS;

/* the board -- big enough to hold any reasonable size */
char board[MAXROWS][MAXCOLS];

/* Defining the temporary board where we store the previous generation to manipulate it */
char temp[MAXROWS][MAXCOLS];

/*
 * draw the outline of the board
 */
void prboard(void)
{
        int i, j; /* counters in for loops */

        /* top border */
        for (i = 0; i < cols + 2; i++)
                putchar('-');
        putchar('\n');

        /* now the rows */
        for (i = 0; i < rows; i++)
        {
                putchar('|');
                for (j = 0; j < cols; j++)
                        putchar(board[i][j]);
                putchar('|');
                putchar('\n');
        }

        /* bottom border */
        for (i = 0; i < cols + 2; i++)
                putchar('-');
        putchar('\n');
}

/**
 * Method to count the number of neighbors of the given cell
 * in the life matrix
 * param row - row number
 * param col - column number
 * return - number of neighbors of the given cell
 */
int numberOfNeighbors(int row, int col)
{
        int neighbors = 0; /* Declaring the counter used to return the number of neighbors containing a populated cell surrounding a certain cell */

                /* Uses multiple if statements to check the status of every neighbor of the given cell */
        if (temp[row - 1][col - 1] == 'O')
        {
                ++neighbors;
        }
        if (temp[row][col - 1] == 'O')
        {
                ++neighbors;
        }
        if (temp[row + 1][col - 1] == 'O')
        {
                ++neighbors;
        }
        if (temp[row - 1][col] == 'O')
        {
                ++neighbors;
        }
        if (temp[row + 1][col] == 'O')
        {
                ++neighbors;
        }
        if (temp[row - 1][col + 1] == 'O')
        {
                ++neighbors;
        }
        if (temp[row][col + 1] == 'O')
        {
                ++neighbors;
        }
        if (temp[row + 1][col + 1] == 'O')
        {
                ++neighbors;
        }

        return neighbors;
}

        /* Method that runs the entire dynamic bacteria functionality */
void life(void)
{
        int count = 1;
        int new_rows = rows + 2;
        int new_cols = cols + 2;
        temp[new_rows][new_cols];
        int i, j, a, b;
                /* Intitialize temporary board to a board of spaces with 2 extra rows and cols in order to add a buffer */
        for (i = 0; i < new_rows; i++)
        {
                for (j = 0; j < new_cols; j++)
                {
                        temp[i][j] = ' ';
                }
        }
        
       

        while (count <= 50){
                        /* Copies the previous board array into the temporary array */
                for (i = 1; i < (new_rows - 1); i++)
                {
                        for (j = 1; j < (new_cols - 1); j++)
                        {
                                temp[i][j] = board[i - 1][j - 1];
                        }
                }
                        /* Manipulates the temporary array according to the guidelines of the Game of life. Once outside loop exits, next generation is completed and stored in the board array */
                for (i = 1; i < (new_rows - 1); i++)
                {
                        for (j = 1; j < (new_cols - 1); j++)
                        {       
                                        /* If a populated cell adjoins less than 2 other populated cells, or more than 3 populated cells, it becomes unpopulated */
                                if (temp[i][j] == 'O' && (numberOfNeighbors(i, j) < 2 || numberOfNeighbors(i, j) > 3)){
                                        board[i - 1][j - 1] = 'X';
                                }
                                        /* If a populated cell adjoins 2 or 3 populated cells, it remains populated */       
                                else if (temp[i][j] == 'O' && (numberOfNeighbors(i, j) == 2 || numberOfNeighbors(i, j) == 3)){
                                        board[i - 1][j - 1] = 'O';
                                }
                                        /* If an unpopulated cell adjoins exactly 3 populated cells, it becomes populated */
                                else if (temp[i][j] == 'X' && (numberOfNeighbors(i, j) == 3)){
                                        board[i - 1][j - 1] = 'O';
                                }
                                else{
                                                /* If none of the above conditions are met, current value at temp is copied into the board */
                                        board[i - 1][j - 1] = temp[i][j];
                                }
                        
                        }       
                }
                        /* Every 5 generations, the board is printed */
                if (count % 5 == 0){
                        printf("Generation %d:\n", count);
                        prboard();
                }
                count++;

       }


}

/*
 * main routine
 */
int main(int argc, char *argv[])
{
        int n; /* number of numbers read */
        FILE *inpf;

        /*
         * Error checking to ensure than no more than 6 arguments are inputted
         */
        if (argc != 2)
        {
                fprintf(stderr, "Usage: %s board_pattern\n", argv[0]);
                return (1);
        }

        /*
         * open the file
         */
        if ((inpf = fopen(argv[1], "r")) == NULL)
        {
                perror(argv[1]);
                return (1);
        }

        /*
         * read in the board
         */
        for (rows = 0; fgets(board[rows], MAXCOLS, inpf) != NULL; rows++)
        {
                n = strlen(board[rows]);
                if (board[rows][n - 1] == '\n')
                {
                        board[rows][n - 1] = '\0';
                        n -= 1;
                }
                if (rows == 0)
                {
                        /* set the number of columns */
                        cols = n;
                }
                else
                {
                        /* check that the row length is right */
                        if (n != cols)
                        {
                                fprintf(stderr, "%s: line %d is wrong length\n", argv[1], rows + 1);
                                return (1);
                        }
                }
                /* now check everything is 'X' or 'O' */
                for (n = 0; n < cols; n++)
                        if (board[rows][n] != 'X' && board[rows][n] != 'O')
                        {
                                fprintf(stderr, "%s: bad character '%c' in line %d\n",
                                        argv[1], board[rows][n], rows + 1);
                                return (1);
                        }
        }

        /*
         * print the first generation of the board
         */
        printf("%s", "Generation 0:\n");
        prboard();

        /* Utilizes helper method to run the rest of the Game of Life */
        life();

        /* done! */
        return (0);
}
