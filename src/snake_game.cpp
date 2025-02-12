#include "snake_game.h"

// LED Matrix setup
const int DIN = 12;
const int CS = 11;
const int CLK = 10;
LedControl lc = LedControl(DIN, CLK, CS, 1);

// Joystick pins
const int varXPin = A3;
const int varYPin = A4;

// LED Matrix buffer
byte pic[8] = {0, 0, 0, 0, 0, 0, 0, 0};

// Snake and apple objects
Snake snake = {{1, 5}, {{0, 5}, {1, 5}}, 2, {1, 0}};
Apple apple = {(int)random(0, 8), (int)random(0, 8)};

// Game timing variables
float oldTime = 0;
float timer = 0;
float updateRate = 3;

void setupGame() {
    lc.shutdown(0, false);
    lc.setIntensity(0, 8);
    lc.clearDisplay(0);

    pinMode(varXPin, INPUT);
    pinMode(varYPin, INPUT);
}

void updateGame() {
    int xVal = analogRead(varXPin);
    int yVal = analogRead(varYPin);

    if (xVal < 100 && snake.dir[1] == 0) {
        snake.dir[0] = 0;
        snake.dir[1] = -1;
    } else if (xVal > 920 && snake.dir[1] == 0) {
        snake.dir[0] = 0;
        snake.dir[1] = 1;
    } else if (yVal < 100 && snake.dir[0] == 0) {
        snake.dir[0] = 1;
        snake.dir[1] = 0;
    } else if (yVal > 920 && snake.dir[0] == 0) {
        snake.dir[0] = -1;
        snake.dir[1] = 0;
    }

    float deltaTime = calculateDeltaTime();
    timer += deltaTime;

    if (timer > 1000 / updateRate) {
        timer = 0;
        resetGame();
        int newHead[2] = {snake.head[0] + snake.dir[0], snake.head[1] + snake.dir[1]};

        // Handle Borders
        if (newHead[0] == 8) newHead[0] = 0;
        else if (newHead[0] == -1) newHead[0] = 7;
        else if (newHead[1] == 8) newHead[1] = 0;
        else if (newHead[1] == -1) newHead[1] = 7;

        // Check if snake hits itself
        for (int j = 0; j < snake.len; j++) {
            if (snake.body[j][0] == newHead[0] && snake.body[j][1] == newHead[1]) {
                delay(1000);
                snake = {{1, 5}, {{0, 5}, {1, 5}}, 2, {1, 0}};
                apple = {(int)random(0, 8), (int)random(0, 8)};
                return;
            }
        }

        // Check if the snake eats the apple
        if (newHead[0] == apple.rPos && newHead[1] == apple.cPos) {
            snake.len++;
            apple.rPos = (int)random(0, 8);
            apple.cPos = (int)random(0, 8);
        } else {
            removeFirst();
        }

        snake.body[snake.len - 1][0] = newHead[0];
        snake.body[snake.len - 1][1] = newHead[1];

        snake.head[0] = newHead[0];
        snake.head[1] = newHead[1];

        // Update the LED Matrix buffer
        for (int j = 0; j < snake.len; j++) {
            pic[snake.body[j][0]] |= 128 >> snake.body[j][1];
        }
        pic[apple.rPos] |= 128 >> apple.cPos;
    }
}

void renderGame() {
    for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, pic[i]);
    }
}

float calculateDeltaTime() {
    float currentTime = millis();
    float dt = currentTime - oldTime;
    oldTime = currentTime;
    return dt;
}

void resetGame() {
    for (int j = 0; j < 8; j++) {
        pic[j] = 0;
    }
}

void removeFirst() {
    for (int j = 1; j < snake.len; j++) {
        snake.body[j - 1][0] = snake.body[j][0];
        snake.body[j - 1][1] = snake.body[j][1];
    }
}
