/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cuongnm
 *
 * Created on April 12, 2020, 9:16 PM
 */

#include <cstdlib>
#include <stdio.h>

using namespace std;

/*
 * 
 */
int CheckInput(char*Msg, int min, int max) {
    int Number, check;
    char ch;
    do {
        printf("%s", Msg);
        fpurge(stdin);
        check = scanf("%d%c", &Number, &ch);
        if (check == 2 && ch == '\n') {
            if (Number >= min && Number <= max) break;
            else printf("Out of range,please enter (%d-%d)\n", min, max);
        } else printf("Invalid input,please enter integer number\n");

    } while (1);
    return Number;
}

void findMax(int n, int a[]) {
    int max = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    printf("The max is:%d\n", max);
}

void findEven(int n, int a[]) {
    printf("Array even values:\n");
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            printf("%3d", a[i]);
        }
    }
}

int main(int argc, char** argv) {
    int n, i;
    n = CheckInput("Enter size of an array:", 1, 100);
    int a[n];
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Array maximum value\n");
    findMax(n, a);
    findEven(n, a);

    return 0;
}

