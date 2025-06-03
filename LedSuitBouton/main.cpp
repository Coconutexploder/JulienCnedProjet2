#include "mbed.h"

DigitalOut led(PA_5);     // LED verte
DigitalIn bouton(PC_13);  // Bouton utilisateur

int main() 
{
    while (true) 
    {
        led = bouton.read(); // La LED copie l’état du bouton (0 ou 1)    //lit la valeur de bouton, change sa valeur, valeur devient 1 ou 0, led s'allume ou s'éteind
    }
}
