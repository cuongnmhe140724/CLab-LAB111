/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cuongnm
 *
 * Created on February 19, 2020, 1:17 PM
 */

#include <cstdlib>
#include <stdio.h>
#include <string.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char s[100];
    char newS[100];
    char demiter = ' ';
    char strDemiter[2];
    char key;
    strDemiter[0] = demiter;
    strDemiter[1] = 0;
    do {
        printf("Please enter string:");
        gets(s);
        fpurge(stdin);
        printf("\nThe old string:  %s",s);
        for (int i = strlen(s); i >= 0; i--) {
            if (s[i] == demiter) {
                strcat(newS, &s[i + 1]);
                strcat(newS, strDemiter);
                s[i] = 0; //sau khi cat string s noi vao newS thi cho dau ngat vao vi tri vua cat cua s
            }
        }
        strcat(newS, s);
        printf("\nThe reversed string:  %s\n", newS);
        printf("Press enter to continue another reverse, ESC to exit");
        key = getchar();
        if (key == 27) break;
        newS[0] = 0; // neu nguoi dung chon continue thi cai nay dung de xoa chuoi newS
    } while (1);
    return 0;
}

