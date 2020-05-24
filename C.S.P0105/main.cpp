/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cuongnm
 *
 * Created on March 22, 2020, 9:01 PM
 */

#include <cstdlib>
#include <stdio.h>

using namespace std;

/*
 * 
 */
void reverse(char *str) {
    
    if (*str) {
        reverse(str + 1);
        printf("%c", *str);
    }
}
int main(int argc, char** argv) {
    do {
        char a[100];
        printf("Please input any string:  ");
        gets(a);
        printf("\nResult:\n");
        reverse(a);
        printf("\nPress any key to continue, ESC to exit");
        char key = getchar();
        if (key == 27) break;
    } while (1);
    return 0;
}

