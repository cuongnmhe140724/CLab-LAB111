/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cuongnm
 *
 * Created on March 4, 2020, 1:47 PM
 */

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

/*
 * 
 */
//void readFile(char fileName[], int &lines, int &len) {
//    FILE* fp;
//    fp = fopen(fileName, "r");
//    lines = 0;
//    len = 0;
//    int max = 0;
//    char s[100];
//    if (fp == NULL) {
//        printf("The file does not exist!");
//    } else {
//        while (!feof(fp)) {
//            fgets(s, 100, fp);
//            lines++;
//            max = strlen(s);
//            if (max >= len) len = max;
//        }
//    }
//    fclose(fp);
//}
int main(int argc, char** argv) {
    int lines, len;
    srand(time(NULL));
    char fileName[50];
    do {
        fileName[0] = 0;
        printf("Enter file game:");
        fpurge(stdin);
        gets(fileName);
        FILE*fp = fopen(fileName, "r");
        lines = 0;
        len = 0;
        int max = 0;
        char s[100];
        if (fp == NULL) {
            printf("The file does not exist! Enter again.\n");
            continue;
        } else {
            while (!feof(fp)) {
                fgets(s, 100, fp);
                lines++;
                max = strlen(s);
                if (max >= len) len = max;
            }
        }
        fclose(fp);
    } while (1);
        len = len + 2;
        char keyWord[lines][len], word[len];
        int index = 0;
        FILE*fp = fopen(fileName, "r");
        if (fp == NULL) {
            printf("The file does not exist!");
        } else {
            while (!feof(fp)) {
                fgets(keyWord[index], len, fp);
                index++;
            }
        }
    
        fclose(fp);
//    play game
    do {
        int randomIndex = rand() % lines;
        int numLives = 5;
        int oldCorrect = 0;
        int numCorrect = 0;
        //get random string
        int lengthOfWord = strlen(keyWord[randomIndex]) - 2;

        int letterGuessed[lengthOfWord];
        for (int i = 0; i < lengthOfWord; i++) {
            letterGuessed[i] = 0;
        }

        int quit = 0;

        int index = 0;
        int reguessed = 0;

        char letterEntered;
        // while loop game
        while (numCorrect < lengthOfWord) {
            printf("\nHangman Word:");

            for (index = 0; index < lengthOfWord; index++) {
                if (letterGuessed[index] == 1) {
                    printf("%c", keyWord[randomIndex][index]);
                } else {
                    printf("-");
                }
            }
            printf("\n");

            printf("Enter a guess letter: ");

            letterEntered = toupper(getchar());
            fpurge(stdin);
            reguessed = 0;

            oldCorrect = numCorrect;

            for (index = 0; index < lengthOfWord; index++) {
                if (letterGuessed[index] == 1) {
                    if (keyWord[randomIndex][index] == letterEntered) {
                        reguessed = 1;
                        break;
                    }
                    continue;
                }

                if (letterEntered == keyWord[randomIndex][index]) {
                    letterGuessed[index] = 1;
                    numCorrect++;
                }
            }
            if (oldCorrect == numCorrect && reguessed == 0) {
                numLives--;
                printf("Sorry, wrong guess\n");
                if (numLives == 0) {
                    break;
                }
            } else if (reguessed == 1) {
                numLives--;
                printf("Already Guessed!!\n");
                if (numLives == 0) {
                    break;
                }
            } else {
                printf("Correct guess :)\n");
            }
        }
        if (numLives == 0) {
            printf("\nSorry you lose, the word was: %s\n",
                    keyWord[randomIndex]);
        } else {
            printf("\nYOU WIN!!! :)\n");
        }
        printf("\nPress enter to continue, ESC to exit");
        char key = getchar();
        if (key == 27) break;
    } while (1);
    return 0;
}

