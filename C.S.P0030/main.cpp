/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cuongnm
 *
 * Created on March 2, 2020, 1:42 PM
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
    int sumOdd = 0;
    int sumEven = 0;
    printf("Enter number of element: ");
    size = getInt(1,INT_MAX);
    int arr[size];
    for(int i = 0; i < size; i++){
        printf("Element[%d]: ",i);
        arr[i] = getInt(0,INT_MAX);
    }
    for(int i = 0; i < size; i++){
        if(arr[i] % 2 == 0){
            sumEven += arr[i];
        }
        else{
            sumOdd += arr[i];
        }
    }
    printf("Sum of even: %d",sumEven);
    printf("\nSum of odd: %d",sumOdd);
    return 0;
}

