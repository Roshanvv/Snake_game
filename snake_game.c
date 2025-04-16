#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

int i, j, height = 20, width = 30;
int gameover, score;
int x, y, fruitX, fruitY, flag;
int tailX[100], tailY[100];
int nTail = 0;
int highScore = 0;

void loadHighScore() {
    FILE *file = fopen("highscore.txt", "r");
    if (file == NULL) {
        highScore = 0;
    } else {
        fscanf(file, "%d", &highScore);
        fclose(file);
    }
}

void saveHighScore() {
    if (score > highScore) {
        FILE *file = fopen("highscore.txt", "w");
        fprintf(file, "%d", score);
        fclose(file);
    }
}

void setup() {
    gameover = 0;
    flag = 0;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
    nTail = 0;
    loadHighScore();
}

void draw() {
    system("cls");

    printf("\n\t🎮  S N A K E   G A M E\n");
    printf("\tUse Arrow Keys to move | X to quit\n\n");

    for (i = 0; i < width + 2; i++) printf("🟫");
    printf("\n");

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (j == 0) printf("🟫");

            if (i == y && j == x)
                printf("🐍");
            else if (i == fruitY && j == fruitX)
                printf("🍎");
            else {
                int print = 0;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printf("🟩");
                        print = 1;
                    }
                }
                if (!print) printf("  ");
            }

            if (j == width - 1) printf("🟫");
        }
        printf("\n");
    }

    for (i = 0; i < width + 2; i++) printf("🟫");
    printf("\n");

    printf("\n\t📊 Score: %d\t🏆 High Score: %d\n", score, highScore);
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 27: // Handle arrow keys
                if (_kbhit()) { // Check for second character of the arrow key sequence
                    switch (_getch()) {
                        case 65: flag = 3; break; // Up arrow key
                        case 66: flag = 4; break; // Down arrow key
                        case 67: flag = 2; break; // Right arrow key
                        case 68: flag = 1; break; // Left arrow key
                    }
                }
                break;
            case 'x': gameover = 1; break; // Exit game
        }
    }
}

void logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (flag) {
        case 1: x--; break; // Left
        case 2: x++; break; // Right
        case 3: y--; break; // Up
        case 4: y++; break; // Down
    }

    if (x < 0 || x >= width || y < 0 || y >= height)
        gameover = 1;

    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameover = 1;

    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}

void gameOverScreen() {
    system("cls");
    saveHighScore();

    printf("\n\t💀💀💀   G A M E   O V E R   💀💀💀\n");
    printf("\n\t🎯 Your Score: %d", score);
    printf("\n\t🏆 High Score: %d\n", highScore);
    printf("\n\t🔁 Press any key to exit...");
    _getch();
}

int main() {
    setup();
    while (!gameover) {
        draw();
        input();
        logic();
        Sleep(100); // Adjust game speed (milliseconds)
    }
    gameOverScreen();
    return 0;
}
