#include "mbed.h"

PwmOut led(PA_5); // Pulse Width Modulation

int main() 
{
    led.period(0.001);   // Période = 1 ms → 1000 Hz
    led.write(0.5f);     // 50% de rapport cyclique (luminosité moyenne)

    while (true) {}      //loupe pour que la led clignote seul
}
