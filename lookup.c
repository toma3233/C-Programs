# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>



int total = 0; /* global variable total that contains total num of words checked

/* Helper function that checs for the number of words checked to match each word from the search
   list to the dictionary.
   Parameters:
        - array of words from the search list
        - array of words from the dictionary
        - number of words in dictionary
        - number of words in search list
 */

int numWordsChecked(char **search, char **dict, int dict_length, int search_length){
    int i, j, count = 0,word_found = 0; /* Declaring counters for loops and initializing counter variable for numWordsChecked and avg number of words checked */
        /* Nested for loops that search every word in search list, and for every word in search list, searches the dictionary */
    for (i = 0; i < (search_length-1); i++){
        for(j = 0; j < dict_length-1; j++){
            if (strcmp(search[i], dict[j]) != 0){
                ++count;
                ++total; 
            }
            else{
                ++count;
                ++total;
                word_found = 1;
                break; 
            }
        }
            /* IF the word is not found within the dict, it will print the following*/
        if (word_found != 1){
            printf("\'%s\' is not in the word list\n", search[i]);

        }
            /* If the word is found within the dict, it will print the following */
        if (word_found == 1 && count <= 1000){
            printf("'%s' is word %d in the list\n", search[i], count);
            word_found = 0;
        }
            /* Resets count to 0 so it can get the number of words counted for next word in search list */
        count = 0;
    }

        /* Declared variable average as float, casts total and search length to float in order to get avg value accurate to two decimal spaces */
    double avg;
    avg = (double) (total) / (double)(search_length-1)+0.001;
    printf("Checked %d words while looking for %d words; average is %.2f\n", total, (search_length-1), (avg));
    
}

/* Main function that runs the program. Takes in two files as parameters from the command line. */
int main(int argc, char ** argv){
        /* Checks that there are 3 command line arguments */
    if (argc != 3){
        fprintf(stderr, "Usage: lookup [wordlist] [words]\n");
    }
     /*********************************************************************************************/
        /* This section of code allocates memory to the words[] (dictionary) array and stores all the dictionary words within the array */
    int i = 0, j = 0, k = 0; /* Variables used as counters for loops */
    FILE *fp; /* Declare file pointer that will run through the dictionary file */
    int l = 0, m = 0, n = 0; /* Variables used as counters for loops */
    FILE *fp2; /* Declare file pointer that will run through the search list file */

    char **words = malloc(1000 * sizeof(char *)); /* declares first part of 2d array and allocate memory for pointers points to strings */
    
        /* For loop that allocates memory for each character in each string and declares 2nd part of 2d array */
    for (k = 0; k < 1024; k++){
        words[k] = malloc(1024 * sizeof(char));
            /* Checks if malloc fails, if so prints the string saved in allocated space */
        if (words[k] == NULL){
            perror(words[k]);
        }
    }

        /* opens file passed in as first argument for reading */
    fp = fopen(argv[1], "r");
        /* Prints name of file if opening fails*/
    if (fp == NULL){
        perror(argv[1]);
    }

        /* Until end of file has been reached, it will scan each word and store in 2d array*/
    while (!feof(fp)){
        fscanf(fp, "%s", words[i]);
        i++;

    }
        /* Prints error messsage if there are no words in dictionary*/
    if (i == 0){
        fprintf(stderr, "No words to search!\n");
    }

        /* Closes file pointer*/
    fclose(fp);

    /*********************************************************************************************/
        /* This section of code allocates memory to the search_list[] array and stores all the search_list words within the array */
    char **search_list = malloc(1000 * sizeof(char *)); /* declares first part of 2d array and allocate memory for pointers points to strings */
    
        /* For loop that allocates memory for each character in each string and declares 2nd part of 2d array */
    for (n = 0; n < 1024; n++){
        search_list[n] = malloc(1024 * sizeof(char));
    }

        /* opens file passed in as first argument for reading */
    fp2 = fopen(argv[2], "r");
        /* Prints name of file if opening fails */ 
    if (fp2 == NULL){
        perror(argv[2]);
    }

        /* Until end of file has been reached, it will scan each word and store in 2d array*/
    while (!feof(fp2)){
        fscanf(fp2, "%s", search_list[l]);
        l++;

    }
        /* Prints error message if search list is empty */
    if (l == 0){
        fprintf(stderr, "No words to find!\n");
    }

        /* Closes file pointer*/
    fclose(fp2);

        /* Calls helper function that outputs whether the word is or isn't in the word list. Also prints our the total and average number of words checked.*/
    numWordsChecked(search_list, words, i, l);

    return (0);
}
