/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cuongnm
 *
 * Created on February 21, 2020, 1:39 PM
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
//ham dung de luu game vao file
void saveGame(float value, char fileName[]) {
    FILE *fp;
    fp = fopen(fileName,"w"); // mở file với chế độ ghi w = write
    fprintf(fp, "%f", value); //ghi gtri value vào file
    fclose(fp);
}
// de doc file lay gia tri diem đã đc lưu
float loadGame(char fileName[]) {
    float value = 0.0;
    FILE *fp;
    fp = fopen(fileName, "r");//đọc file
    if (fp == NULL) {         //nếu file ko tồn tại thì tạo file mới 
        printf("\nFile '%s' does not exist!Creating file with 10$\n", fileName);
        saveGame(10.0, fileName);
        value = 10.0;
    } else { //nếu file tồn tại thì đọc ạ
        fscanf(fp,"%f", &value);
        if (value == 0) { //nếu số tiền còn lại 0$ thì reset về 10
            printf("\nFile '%s' is exist!The value in file is: %.2f $ Reset money!\n",fileName,value);
            value = 10.0;
        } else {
            printf("\nFile '%s' is exist!The value in file is: %.2f $\n", fileName, value);
        }
    }
    fclose(fp);
    return value;
}
// hàm chơi game nhé bạn iu
float playGame() {
    float value = 0;
    int numbers[3];
    srand(time(NULL));  //khởi tạo bộ sinh số ngẫu nhiên
    numbers[0] = rand() % 10; // random ba số
    numbers[1] = rand() % 10;
    numbers[2] = rand() % 10;
    for (int i = 0; i < 3; i++) {
        printf("%d ", numbers[i]);
    }
    if (numbers[0] == numbers[1] && numbers[1] == numbers[2]) {
        printf("\nYou won biggest prize $10.00\n");
        value = 10;
    }
    if (numbers[0] == numbers[1] || numbers[1] == numbers[2]) {
        printf("\nYou won $0.5\n");
        value = 0.5;
    } else {
        printf("\nYou didn't win this time\n");
    }
    return value;
}

int main() {
    float money = loadGame("SaveGame.txt");
    do {
        printf("You have: %.2f\n",money);
        printf("1.Play the slot machine\n2.Save game\n3.Cash out.\n4.Quit");
        printf("\nEnter your choices:\n");
        int choices = getInt(1,4);
        switch (choices) {
            case 1:
            {
                if (money <= 0) {
                    printf("\nYou don't have enough money to play!'");
                    saveGame(money,"SaveGame.txt");
                    exit(0);
                }
                money = money - 0.25 + playGame();
                break;
            }
            case 2:
            {
                printf("You have saved game!\n");
                saveGame(money,"SaveGame.txt");
                break;
            }
            case 3:
            {
                printf("\n ---THANKS FOR PLAYED---\nYou end the game with $%0.2f\n", money);
                remove("SaveGame.txt");
                return 0;
            }
            case 4:
            {
                saveGame(money,"SaveGame.txt");
                return 0;
            }
            default:
                printf("Invalid input! Accept 1 - 4 only.");
        }
    } while (1);
    return 0;
}
