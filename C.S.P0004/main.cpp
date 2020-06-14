/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cuongnm
 *
 * Created on February 18, 2020, 10:05 PM
 */

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
using namespace std;

/*
 * 
 */
void removeChar(char s[], int index) {
    int n = strlen(s);
    for (int i = index; i < n; i++) {
        s[i] = s[i + 1];
    }
    s[n - 1] = '\0';
}

int iMax(int a[], int n) {
    int imax = 0, i;
    for (i = 1; i < n; i++) {
        if (a[i] > a[imax]) {
            imax = i;
        }
    }
    return imax;
}

void outputText(char a[]) {
    for (int i = 0; i < strlen(a) - 1; i++) {
        if (isalpha(a[i])) {
            printf("%c\t", a[i]);
        }
    }
}

void outputNumber(char a[], int b[]) {
    for (int i = 0; i < strlen(a) - 1; i++) {
        if (isalpha(a[i])) {
            printf("%d\t", b[(int) a[i]]);
        }
    }
}

void mostChar(char a[], int b[]) {
    int target = b[iMax(b, 122)];
    for (int i = 0; i < 122; i++) {
        if (b[i] == target) {
            printf("%c\t", i);
        }
    }
    printf("\n");
    for (int i = 0; i < 122; i++) {
        if (b[i] == target) {
            printf("%d\t", b[i]);
        }
    }
}

int main(int argc, char** argv) {
    int n = 0;
    char key;
    do {
        char a[100];
        int b[122] = {0};
        a[0] = 0;
        b[122] = {0};
        printf("Please enter string: ");
        gets(a);
        for (int i = 0; i < strlen(a); i++) {
            if (isalpha(a[i])) {
                b[(int) a[i]]++;
                for (int j = i + 1; j < strlen(a); j++) {
                    if ((int) a[i] == (int) a[j]) {
                        b[(int) a[i]]++;
                        removeChar(a, j);
                    }
                }
            }
        }
        printf("\nTimes of appearance for each character:\n");
        outputText(a);
        printf("\n");
        outputNumber(a, b);
        printf("\n");
        printf("Characters that appears the most:\n");
        mostChar(a, b);
        printf("\nPress enter to continue another reverse, ESC to exit");
        key = getchar();
        if (key == 27) break;
    } while (1);
    return 0;
}