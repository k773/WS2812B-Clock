//
// Created by Alexander Galilov on 26.05.2019.
// E-Mail: alexander.galilov@gmail.com
#include "ws2812b/Led.h"
#include "ws2812b/RGB.h"

int NUM_LEDS = 30;
WS2812B::Led leds(0, NUM_LEDS);

void setPixelColor(int pixelNumber, int r, int g, int b);

void setPixelColor(int pixelNumber, int r, int g, int b){
    WS2812B::RGB color = leds.getColor(pixelNumber);
    bool r_ok = false;
    bool g_ok = false;
    bool b_ok = false;
    while (true){
        if (!r_ok){
            if (color._r > r) color._r --;
            else if (color._r < r) color._r++;
            else r_ok = true;
        }
        if (!g_ok){
            if (color._g > g) color._g --;
            else if (color._g < g) color._g++;
            else g_ok = true;
        }
        if (!b_ok){
            if (color._b > b) color._b --;
            else if (color._b < b) color._b++;
            else b_ok = true;
        }
        leds.setColor(color, pixelNumber);
        leds.show();
        if (r_ok && g_ok && b_ok) return;
    }
}

int main() {
    while (true) {
        for (int i = 0; i < NUM_LEDS; i++) {
            setPixelColor(i, 255, 255, 255);
        }
        for (int i = NUM_LEDS - 1; i > 0; i--) {
            setPixelColor(i, 0, 0, 0);
        }
    }
    return 0;
}



