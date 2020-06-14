/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cuongnm
 *
 * Created on March 2, 2020, 9:00 AM
 */

#include <cstdlib>
#include <stdio.h>
#include <limits.h>
using namespace std;

/*
 * 
 */
int getInt(int min, int max) {
    int number;
    int check;
    char ch;
    do {
        fpurge(stdin);
        check = scanf("%d%c", &number, &ch);
        if (check == 2 && ch == '\n') {
            if (number >= min, number <= max) break;
            else {
                printf("Out of range, please enter %d-%d\n", min, max);
            }
        } else {
            printf("Invalid input, please enter an integer number\n");
        }
    } while (1);
    return number;
}
int main(int argc, char** argv) {
    int size;
    printf("Please enter size of array: ");
    size = getInt(1,INT_MAX);
    int arr[size];
    for (int i = 0; i < size; i++) {
        printf("Element[%d]: ", i);
        arr[i] = getInt(0,INT_MAX);
    }
    printf("The original array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {           // 1 2 3 3 3 4 
            if (arr[i] == arr[j]) {
                for (int k = j; k < size - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                size --;
                j --;
            }
        }
    }
    printf("\nThe array after removing duplicate elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    return 0;
}

