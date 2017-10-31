#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


const int ALL_NUMBER_LETTER = 26;           // letter in alphabet
const int WORDS = 3;                        // if letters >3 its word

int main()
{
int  letterAlphabet[ALL_NUMBER_LETTER];     // array number letter
int  numberLetter = 100000;                 // Number of characters entered
char letterInput[numberLetter];             // array of characters entered
char letter;                                // One Letter of array
int  i,j,sizeLetter;                        // Counters
int  wordsNumber = 0;
char* memLetter;                            //init memory for array

    memLetter = (char*)malloc(numberLetter*sizeof(char));
    if ((char*)malloc(numberLetter*sizeof(char))== NULL) {
        printf ("Memory allocation error...");
        return 1;
    }

    for (;;){
        memset(letterAlphabet, 0, sizeof(letterAlphabet));
        printf("Enter some string: ");
        gets(letterInput);
        sizeLetter = strlen(letterInput);

        if (strlen(letterInput) == NULL){
            printf("Please of characters entered...Retry again...\n");
            continue;
        }
        // Search letter and count sum of letter
        for (i = 0; i < strlen(letterInput); i++){
            if (isalpha(letterInput[i]))
            {
                letter = tolower(letterInput[i]);
                letterAlphabet[ letter - 'a' ] ++;
            }
        }

        // Symbol output and condition matching
        for (i = strlen(letterInput); i > 0 ; i-- ){
            for ( j = 0; j < ALL_NUMBER_LETTER; j++){
                if (letterAlphabet[j] == i){
                    printf("%c - %d\n", char(j + int('a')), letterAlphabet[j]);
                }
            }
        }
        // Search words in strings
        sizeLetter = strlen(letterInput);
        if (sizeLetter > WORDS){
            for (i=0, wordsNumber =0; letterInput[i]!='\0';){
                for (;!isalpha(letterInput[i]) && letterInput[i]!='\0'; i++) ;
                    if (isalpha(letterInput[i])){
                        wordsNumber++;
                        for (;isalpha(letterInput[i]); i++);
                    }
            }
            if (wordsNumber==0){
                printf("The worlds is not a string...\n");
            } else {
                printf("The worlds is a string: %d \n"  , wordsNumber);
            }
            continue;
        }
    }
    free(memLetter);
}









