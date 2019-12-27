#include <stdio.h>
#include <ctype.h>

/* Homework 1 Queston 4 for Matt Bishop's ECS 36A class
 * Fixed Errors: 
 * 	- Fixed syntax error by adding colon in front on case '\a'
 * 	- Fixed runtime error by prioritizing printing the special characters ("\" would only print one "\" when it is supposed to look like "\\"), and printing everything else within the default case
 * 
 * Completed by Tom Abraham on October 4, 2019
 */

int main(void)
{

	int ch; /* Initalizes ch variable that will hold each character in the text */
			/* While loop that gets each character from the text file and prints accordingly,as long as the end of the file hasn't been reached */
	while ((ch = getchar()) != EOF)
	{
		/* Switch statement that iterates through each possible case, deffering to the default if none of the cases apply */
		switch (ch)
		{
			/* Case statements prioritize the special characters */
		case '\t':
			printf("\\t");
			break;
		case '\b':
			printf("\\b");
			break;
		case '\f':
			printf("\\f");
			break;
		case '\0':
			printf("\\0");
			break;
		case '\\':
			printf("\\\\");
			break;
		case '\v':
			printf("\\v");
			break;
		case '\r':
			printf("\\r");
			break;
		case '\a':
			printf("\\a");
			break;
		case '\n':
			printf("\\n\n");
			break;
		default:
				/* if else statement checks if the character is a normal, printable character and, if so, prints it as such. Otherwise, it will print the octal code. */
			if (isprint(ch))
			{
				putchar(ch);
			}
			else
			{
				printf("\\%03o", ch);
			}
			break;
		}
	}
		/* If the program runs successfully, it will return a 0 */
	return (0);
}
