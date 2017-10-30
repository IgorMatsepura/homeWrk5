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
        //An attempt to re-initialize the allocated memory
        if (sizeLetter >= numberLetter){
            memLetter = (char*)realloc(memLetter, numberLetter*sizeof(char*));
            memLetter = (char*)(malloc(sizeLetter +1));
        }

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
            wordsNumber = 0;

            for(;;){

                for ( i; i < strlen(letterInput); i++) {
                    letter = tolower(letterInput[i]);

                    if (!(letter) == isalpha(letter)){
                        wordsNumber++;
                    // if user enter not letter. Cycle search words
                        while (!isalpha(letter)){
                                letter = tolower(letterInput[i]);
                                letterInput[i++];

                            if (letter == isalpha(letter) && isalpha(letter) || !letter == '0' ) {
                                wordsNumber++;
                                printf("The letter in worlds %d \n"  , wordsNumber);
                            }

                            if (isalpha(letter)){
                                tolower(letterInput[i--]);
                                i--;
                                break;
                            }

                            if (sizeLetter == i && isalpha(letter) || letter == '0' ){
                                printf("The letter in worlds %d \n"  , wordsNumber);
                                break;
                            }

                            if (sizeLetter == i && !isalpha(letter)){
                                if (wordsNumber > 0){
                              //  wordsNumber = 0;
                                break;
                                }
                                else {
                                    wordsNumber = 0;
                                    break;
                                }
                            }
                        }
                    }
                }
                if (sizeLetter == i && isalpha(letter)){
                    wordsNumber++;
                }

                if (wordsNumber > 0){
                    printf("The worlds is a string: %d \n"  , wordsNumber);
                } else {
                    printf("Number of characters entered...Retry again...\n");
                }
                break;
            }
        }
    }
    free(memLetter);
}






