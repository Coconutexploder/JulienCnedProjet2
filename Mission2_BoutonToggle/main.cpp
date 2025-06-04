#include "mbed.h"

DigitalOut led(PA_5);
DigitalIn button(PC_13);

int previous = 1;                                            //voit l'état du bouton  

int main() 
{
    while (true) 
    {
        if (button == 0 && previous == 1)                    //boucle de vérification d'état
        {
            led = !led;                                      //si changement d'état, led devient l'inverse de soit meme
        }
        previous = button;                                   //met a jour la valeur de l'état précédent du bouton
        ThisThread::sleep_for(50ms); // anti-rebond          //petite pause pour éviter que le bouton rebondisse trop vite 
    }
}
