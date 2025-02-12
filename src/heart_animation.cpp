#include "heart_animation.h"

// Define lc here (only once)
const int DIN = 12;
const int CS = 11;
const int CLK = 10;
LedControl lc(DIN, CLK, CS, 1);  // Adjust for a single 8x8 matrix

// Full-screen heart animation frames for an 8x8 LED matrix
const byte heartFrames[2][8] = {
    {0b00000000, 0b01100110, 0b11111111, 0b11111111, 0b11111111, 0b01111110, 0b00111100, 0b00011000}, // Small Heart
    {0b01100110, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b01111110, 0b00111100, 0b00011000}, // Medium Heart
};

// Setup function for LED Matrix
void setupHeart() {
    lc.shutdown(0, false);
    lc.setIntensity(0, 8);
    lc.clearDisplay(0);
}

// Function to animate the heart
void animateHeart() {
    static int frame = 0;
    static unsigned long lastUpdate = 0;
    unsigned long currentTime = millis();

    if (currentTime - lastUpdate > 300) { // Adjust speed here
        lastUpdate = currentTime;

        // Display the current heart frame
        for (int i = 0; i < 8; i++) {
            lc.setRow(0, i, heartFrames[frame][i]);
        }

        // Cycle through the frames
        frame = (frame + 1) % 2;
    }
}
