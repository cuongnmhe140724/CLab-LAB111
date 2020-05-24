/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cuongnm
 *
 * Created on February 17, 2020, 9:14 AM
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
//function1

void addValue(int *&a, int &size) {
    printf("Enter new value: ");
    int newValue = getInt(1, INT_MAX);
    a = (int*) realloc(a, sizeof (int)*(++size));
    a[size - 1] = newValue;
}
//function2

void searchValue(int a[], int size) {
    int count = -1;
    printf("Enter value: ");
    int value = getInt(1, INT_MAX);
    for (int i = 0; i < size; i++) {
        if (value == a[i]) {
            printf("\nThe value %d have index:\n", value);
            count = i;
            break;
        }
    }
    if (count != -1) {
        for (int i = count; i < size; i++) {
            if (value == a[i]) {
                printf("\t%d", i);
            }
        }
    } else {
        printf("\tNothing\nThe array does not contain your search value\n");
    }
}
//function3

void printArray(int a[], int size) {
    if (size != 0) {
        for (int i = 0; i < size; i++) {
            printf("%3d ", a[i]);
        }
        printf("\n");
    } else {
        printf("Don't have any values in array!!\n");
    }
}
//function4

void range(int a[], int size) {
    int min, max;
    printf("\nEnter Min:");
    min = getInt(INT_MIN, INT_MAX);
    printf("\nEnter Max:");
    max = getInt(INT_MIN, INT_MAX);
    printf("\nValue in a range of inputted %d and %d value :", min, max);
    if (min <= max) {
        for (int i = 0; i < size; i++) {
            if (a[i] >= min && a[i] <= max) {
                printf("%d", a[i]);
            }
        }
    } else {
        for (int i = 0; i < size; i++) {
            if (a[i] <= min && a[i] >= max) {
                printf("%d", a[i]);
            }
        }
    }
}
//function5

void sorting(int a[], int size) {
    if (size != 0) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (a[i] > a[j]) {
                    int temp;
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    } else {
        printf("Don't have any values in array!!\n");
    }
}

int main(int argc, char** argv) {
    int choose;
    int size = 0;
    int *a = (int *) malloc(size * sizeof ( int));
    while (1) {
        printf("Choose one of the following options:\n");
        printf("\t\t1.Add a value\n");
        printf("\t\t2.Search a value\n");
        printf("\t\t3.Print out the array\n");
        printf("\t\t4.Print out values in a ranger of inputted min and max values, inclusively\n");
        printf("\t\t5.Sort the array in ascending order\n");
        printf("\t\t6.Others-Quit\n");
        printf("---------------------------------------------------------------------------------------------\n");
        printf("Enter function:");
        choose = getInt(1, 6);
        switch (choose) {
            case 1:
            {
                addValue(a, size);
                break;
            }
            case 2:
            {
                searchValue(a, size);
                break;
            }
            case 3:
            {
                printArray(a, size);
                break;
            }
            case 4:
            {
                range(a, size);
                break;
            }
            case 5:
            {
                sorting(a, size);
                printf("Array after soft:\n")
                printArray(a, size);
                break;
            }
            default:
            {
                exit(0);
            }
        }
    }
    return 0;
}

