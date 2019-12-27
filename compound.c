/*
 * Fully Functioning Compound program
 * -Takes in user inputted molecule and outputs total atomic weight
 *
 * 
 * Homework completed by Tom Abraham
 * Answer to Homework 5, question 3
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* struct storing a list of element structures containing element symbol and atomic weight. The struct stores all the element structures in the atomic_weights text file*/
struct element_array list;
/* Number of elements stored in "list". Used in loops going through the list */
int list_length = 0;
/* Current Total Atomic Weight */
float running_total = 0;
/* Number of elements for each element*/
int multiply_by = 0;

/* Creating the structure "element" that will store the atomic weight and symbol of every element in the list.*/
struct element{
    float atomic_weight;
    char  symbol[3];
};

/* Creating the structure "element_array" that stores the element structure for every element on the list. */
struct element_array{
    struct element arr[118];
};



/* Reads in user inputed file and creates an array of element structures based on the info given in the file*/
void processInput(char *name){
    /* File pointer that will be used to read atomic_weights file */
    FILE *fp;
    int temp;
    int counter;
    counter = 0;

    /* Error checking in case opening the file fails */
    if ((fp = fopen(name, "r")) == NULL){
        perror(name);
        exit(EXIT_FAILURE);
    }
    fp = fopen(name, "r");

    /* Reads in desired elements from each line in the text file and stores each elemnent in its corresponding member of the list struct */
    while ((temp = fscanf(fp, "%f\t%s\t%*s",&list.arr[list_length].atomic_weight, &list.arr[list_length].symbol)) != EOF){  
        /* Error checking for a line that is undesirable */      
        if (temp == 0){
           fprintf(stderr, "%s: malformed line %d\n", name, counter); 
           exit(EXIT_FAILURE);
        }
        counter++;
        list_length++;
       
    }
    /* Error checking in case file is empty */
    if (counter == 0){
        fprintf(stderr, "%s: no atomic weights there!\n", name);
        exit(EXIT_FAILURE);
    }
    

    fclose(fp);

}

/* Helper function that takes in symbol and symbol length in as parameters. Return the atomic weight of corresponding element*/
float searchList(char *sym, int num){
    int i;
    float weight;
    int found;

    i = 0;
    weight = 0;
    found = 0;

    /* Loop that runs through the list of elements. If found, variable found = 1, weight = atomic weight of element*/
    for(i = 0; i < list_length; i++){
        if(strcmp(list.arr[i].symbol, sym) == 0){
            weight = list.arr[i].atomic_weight;
            found = 1;
            break;
        }

  
    }

    /* In case given element doesn't exist, prints out "no such element" */
    if (found == 0){
        if (num == 1){
            fprintf(stderr, "%s: no such element\n", sym);
                
        }
        else{
            fprintf(stderr, "%s: no such element\n", sym);
        }

        return 0.00;


    }

    return weight;
}

/* Function that takes in the user inputted molecule & length of the molecule as parameters. Returns total weight of the molecule */
float molecule(char *mol, int len){
    int i; /* Counter used to iterate through for loop and parses the molecule */
    char *arr[len]; /* character array where molecule is stored*/
    int hasTwoLetters; /* Designates whether a symbol has one or two letters */
    float subtotal; /* atomic weight of a single element multiplied by the number of elements*/
    int twoDigits;  /* Designates whether the number of elements for a certain letter has two digits */
    int threeDigits; /* Designates  whether the number of elements for a certain letter has three digits */
    int noExist; /* Designated whether a certain element exists or not */
    float return_val;

    i = 0;
    hasTwoLetters = 0;
    subtotal = 0.00;
    twoDigits = 0;
    threeDigits = 0;
    noExist = 0;

    /* Copies molecule into character array "arr" */
    for (i = 0; i < len; i++){
        arr[i] = mol[i];
    }

    /* For loop that iterates through the entire molecule */
    for (i = 0; i < len; i++){
        if (isalpha((long)arr[i])){
            if(isupper((long)arr[i])){
                /* If the current index is an uppercase letter and the next index is a lowercase letter, symbol has two letters */
                if(i < (len-1) && islower((long)arr[i+1])){
                    hasTwoLetters = 1;
                    
                }
                else{
                    hasTwoLetters = 0;
                    /* Otherwise, If the current index is an uppercase letter and the next index is an uppercase letter or not a digit, there is only 1 of the one letter element */
                    if (isupper((long)arr[i+1]) || (!(isdigit((long)arr[i+1])))){
                        multiply_by = 1;
                        subtotal = ((searchList((arr + (i)), 1)) * (float) multiply_by);
                        /* If the element can't be found, noExist = 1 */
                        if(subtotal == 0.00){
                            noExist = 1;
                        }
                        running_total += subtotal;
                        
                    }
                    
                    
                }
            }
            else{
                /* If the current index is a lowercase letter and the next index is an uppercase letter or not a digit, there is only 1 of the two letter element */
                if (isupper((long)arr[i+1]) || (!(isdigit((long)arr[i+1])))){
                    float elem_weight;
                    multiply_by = 1;
                    elem_weight = searchList(strcat((arr + (i-1)), (arr + (i))), 2);
                    /* If the element can't be found, noExist = 1 */
                    if(elem_weight == 0.00){
                        noExist = 1;
                    }
                    running_total += elem_weight;
                }
            }

        }       
        else{
            /* If the current index is a digit and the next index is also a digit... */
            if (isdigit((long)arr[i+1])){
                /* if the digit after that is also a digit, convert all three digits into a single integer */
                if (isdigit((long)arr[i+2])){
                    long f;
                    long s;
                    long t;
                    f = (long)(arr[i] - '0');
                    f = f * 100;
                    
                    s = (long)(arr[i+1] - '0');
                    s = s * 10;
        
                    t = (long)(arr[i+2] - '0');
                    multiply_by = (int)(f + s + t);
                    threeDigits = 1;
                }
                /* otherwise, just convert the two digits into a number */
                else{
                    long first;
                    long second;
                    first = (long)(arr[i] - '0');
                    first = first * 10;
                    
                    second = (long)(arr[i+1] - '0');
                    multiply_by = (int)(first + second);
                    twoDigits = 1;
                }
                
            }
            /* Otherise, just convert the single digit into a integer */
            else{
                long ft;
                ft = (long)(arr[i] - '0');
                multiply_by = (int)(ft);
            }
            /* If the symbol has only one letter, pass it into the searchList and multiple the atomic weight with the previously assigned "multiply_by" variable */
            if(hasTwoLetters == 0){
                subtotal = (searchList((arr + (i-1)), 1) * (float) multiply_by);
                /* If the element doesn't exist, noExist = 1 */
                if(subtotal == 0.00){
                    noExist = 1;
                }
                running_total += subtotal;

            }
            else{
                /* If the symbol has two letters, pass it into the searchList and multiple the atomic weight with the previously assigned "multiply_by" variable */
                float elem_weight;
                elem_weight = searchList(strcat((arr + (i-2)), (arr + (i-1))), 2);
                subtotal = elem_weight * (float) multiply_by;
                /* If the element doesn't exist, noExist = 1 */
                if(subtotal == 0.00){
                    noExist = 1;
                }
                running_total += subtotal;
            }
            
        }
        /* if multiply_by had three digits, skip the next 2 indices to get to the next letter */
        if(threeDigits == 1){
            i = i + 2;
            threeDigits = 0;
        }
        /* if multiply_by had 2 digits, skip the next index to get to the next letter */
        if(twoDigits == 1){
            i++;
            twoDigits = 0;
        }
        /* If one of the elements within the molecule did not exist, return 0 so the main function knows to print out a message and prompt the user for another chemical composition*/
        if(noExist == 1){
            return 0.00;
            noExist = 0;
        }
        
        /* reset multiply_by to 0 */
        multiply_by = 0;
    }
    
    
    return_val =  running_total;
    running_total = 0;
    return return_val;
}

/* main function that runs the entire program and takes the name of a file as one of the parameters */
int main(int argc, char *argv[]){
    int len;
    float total;
    char *mol;
    char *temp;
    len = 0;
    /* Error checking to ensure there are only 2 params */
    if (argc != 2){
        fprintf(stderr, "Usage: %s weightsfile\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Malloced space to array mol that will store user input */
    
    mol = (char *)malloc(100);
    
    /* Call helper function to read file and store information into list struct */
    processInput(argv[1]);
    
    /* While loop that will continue to prompt the user to enter an chemical composiiton until a NULL character is entered */
    printf("Chemical composition? ");
    while((fgets(mol, 1000, stdin)) != NULL){
        len = (strlen(mol) -1);
        if (len && mol[len-1] == '\n'){
            mol[--len] = 0;
        }
        
        temp = (char *)malloc(len);
        temp[len] = '\0';
        strncpy(temp, mol, len);
            /* If nothing is entered by the user, user is prompted again */
        if (len == 0){
           fprintf(stderr, "%s: not a valid compound\n", temp);
           running_total = 0; 
        }
        else{
            /* If total returns 0, that means there is an invalid element within the chemical composition */
            total = molecule(mol, len);
            if (total == 0.00){
                fprintf(stderr, "%s: not a valid compound\n", temp);
            }
            else{
                /* If good input has been provided by the user, it prints out the atomic weight of the molecule */
                printf("The atomic weight of %s is %.2f\n", temp, total);
            }
            
        }
        printf("Chemical composition? ");
        /* reset running_total after each chemical composiiton has been calculated */
        running_total = 0;
            
        
    }
    printf("\n");


    return(0);
}
