#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


const int allNumberLetter = 26;         // letter in alphabet

int main()
{
int  letterAlphabet[allNumberLetter];   // array number letter
int  numberLetter = 1000;                // Number of characters entered
char letterInput[numberLetter];         // array of characters entered
char letter;
int  i,j,sizeLetter;       // Counters
int wordsNumber = 0;
char* memLetter;

    memLetter = (char*)malloc(numberLetter*sizeof(char*));
    for (;;){

        memset(letterAlphabet, 0, sizeof(letterAlphabet));
        printf("Enter some string: ");
        gets(letterInput);
        sizeLetter = strlen(letterInput);
        if (sizeLetter >= numberLetter){
            memLetter = (char*)realloc(memLetter, numberLetter*sizeof(char*));
            memLetter = (char*)(malloc(sizeLetter +1));
        }

        if (strlen(letterInput) == NULL){
            break;
            fflush(stdin);
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
            for ( j = 0; j < allNumberLetter; j++){
                if (letterAlphabet[j] == i){
                    printf("%c - %d\n", char(j + int('a')), letterAlphabet[j]);
                }
            }
        }
        // Search words
        sizeLetter = strlen(letterInput);
        if (sizeLetter > 3){
            wordsNumber = 0;

            for(;;){
                for ( i; i < strlen(letterInput); i++) {
                    letter = tolower(letterInput[i]);
                    if (!isalpha(letter) || int(letter) < 64){
                         wordsNumber++;
                    }
                }
                if (sizeLetter == i && isalpha(letter)){
                    wordsNumber++;
                    printf("The letter in worlds %d \n"  , wordsNumber);
                break;
                }
            }
        }
    }
    free(memLetter);
}






