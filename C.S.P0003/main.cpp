/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cuongnm
 *
 * Created on February 16, 2020, 7:26 PM
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

void sortingArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void addValue(int arr[], int &size, int newValue) {
    int index = 0;
    int l = 0;
    int r = size - 1;
    int mid;
    while (1) {
        mid = (l + r) / 2;
        if(arr[mid] == newValue){
            index = mid;
            break;
        }
        if (arr[mid] < newValue)
            l = mid + 1;
        else
            r = mid - 1;
        if(l > r){
            index = l - 1;
            break;
        }
    }
    for (int i = size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = newValue;
    size++;
}

void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
}

int main(int argc, char** argv) {
    int size, arr[100];
    printf("Please enter size of array: ");
    size = getInt(0,INT_MAX);
    for (int i = 0; i < size; i++) {
        printf("Enter element[%d]: ", i);
        arr[i] = getInt(0,INT_MAX);
    }
    sortingArray(arr, size);
    printf("The array after sorting:\n ");
    display(arr, size);
    printf("\nPlease enter new value: ");
    int newValue = getInt(0, INT_MAX);
    addValue(arr, size, newValue);
    printf("\nNew array:\n");
    display(arr, size);
    return 0;
}

