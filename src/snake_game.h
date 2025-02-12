#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <Arduino.h>
#include <LedControl.h>

// Struct definitions
typedef struct Snake {
    int head[2];     // (row, column) of the snake head
    int body[40][2]; // Array containing (row, column) coordinates
    int len;         // Length of the snake
    int dir[2];      // Direction of movement
} Snake;

typedef struct Apple {
    int rPos; // Row index of the apple
    int cPos; // Column index of the apple
} Apple;

// Function declarations
void setupGame();
void updateGame();
void renderGame();
float calculateDeltaTime();
void resetGame();
void removeFirst();

#endif // SNAKE_GAME_H
