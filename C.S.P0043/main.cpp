/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cuongnm
 *
 * Created on March 26, 2020, 9:04 AM
 */

#include <cstdlib>
#include <limits.h>
#include <stdio.h>

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

void removeNumber(int *a, int &size, int index) {
    for (int i = index; i < size - 1; i++) {
        a[i] = a[i + 1];
    }
    a = (int*) realloc(a, sizeof (int)*(size - 1));

}
//function1

void addValue(int *&a, int &size) {
    printf("Enter new value: ");
    int newValue = getInt(1, INT_MAX);
    a = (int*) realloc(a, sizeof (int)*(++ size));
    a[size-1] = newValue;
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
//function 3

void removeFirstNumber(int *a, int &size, int value) {
    if (size == 0) {
        printf("Don't have any values in array!!\n");
    } else {
        int isRemove = 0;
        for (int i = 0; i < size; i++) {
            if (value == a[i]) {
                removeNumber(a, size, i);
                isRemove = 1;
                break;
            }
        }
        if (isRemove == 1) printf("First existence of input value have been removed.\n");
        else printf("The array does not contain input value.\n");
    }
}
//function 4

void removeAll(int *a, int &size, int value) {
    if (size == 0) {
        printf("Don't have any values in array!!\n");
    } else {
        int isRemove = 0;
        for (int i = size - 1; i >= 0; i--) {
            if (value == a[i]) {
                removeNumber(a, size, i);
                isRemove = 1;
            }
        }
        if (isRemove == 1) printf("All existence of input value have been removed.\n");
        else printf("The array does not contain input value.\n");
    }
}
//function 5

void printNumber(int a[], int size) {
    if (size != 0) {
        for (int i = 0; i < size; i++) {
            printf("%3d ", a[i]);
        }
    } else {
        printf("Don't have any values in array!!\n");
    }
}
//function 6+7

void sortingArray(int a[], int size, int type) {
    if (size != 0) {
        int *b = (int*) malloc(size * sizeof (int));
        for (int i = 0; i < size; i++) {
            b[i] = a[i];
        }
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (b[i] > b[j] && type == 0 || b[i] < b[j] && type == 1) {
                    int temp;
                    temp = b[i];
                    b[i] = b[j];
                    b[j] = temp;
                }
            }
        }
        printNumber(b, size);
    } else {
        printf("Don't have any values in array!!\n");
    }
}

int main(int argc, char** argv) {
    
    int function;
    int size = 0;
    int *a = (int *) malloc(size * sizeof ( int));
    
    do {
        printf("\n\n---------------------------------------------------------------------------------------------\n");
        printf("Choose one of the following options:\n");
        printf("\t\t1.Add a value\n");
        printf("\t\t2.Search a value\n");
        printf("\t\t3.Remove first existences value\n");
        printf("\t\t4.Remove all existences values.\n");
        printf("\t\t5.Print out the array \n");
        printf("\t\t6.Sort the array in ascending order\n");
        printf("\t\t7.Sort the array in descending order\n");
        printf("\t\t8.Others-Quit\n");
        printf("---------------------------------------------------------------------------------------------\n");
        printf("Enter function:");
        function = getInt(1, 8);
        switch (function) {
            case 1:
            {
                printf("New value:");
                int newValue = getInt(INT_MIN, INT_MAX);
                addValue(a, size, newValue);
                break;
            }
            case 2:
            {

                searchValue(a, size);
                break;
            }
            case 3:
            {
                printf("Enter number:");
                int number = getInt(INT_MIN, INT_MAX);
                removeFirstNumber(a, size, number);
                break;
            }
            case 4:
            {
                printf("Enter number:");
                int numberValue = getInt(INT_MIN, INT_MAX);
                removeAll(a, size, numberValue);
                break;
            }
            case 5:
            {
                printNumber(a, size);
                break;
            }
            case 6:
            {
                printf("Sorting:");
                sortingArray(a, size, 0);
                break;
            }
            case 7:
            {
                sortingArray(a, size, 1);
                break;
            }
            case 8:
            {
                break;
            }
        }
    } while (function != 8);
    return 0;

}

