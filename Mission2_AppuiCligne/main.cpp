#include "mbed.h"

DigitalOut led(PA_5);
DigitalIn button(PC_13);

int main() 
{
    while (true)                                   //création de boucle while de vérification de valeur
    {
        if (button == 0)                           //création de boulce de changement d'état
        {
            led = !led;
            ThisThread::sleep_for(200ms);          //clignotement
        }
    }
}
