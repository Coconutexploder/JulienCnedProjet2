#include "mbed.h"                                  //donne accès aux fonctions de base (série, délais, etc.)
#include "HTS221Sensor.h"                          //pilote du capteur température + humidité
#include "LPS22HBSensor.h"                         // pilote du capteur pression

//Initialisation de la communication I2C entre la carte et les capteurs
static DevI2C i2c(PB_11, PB_10);                   //PB_11 = SDA ; PB_10 = SCL; broches utilisées par les capteurs

                                  //   ^ 
                                  //  ||  
                                  //  Ces capteurs communiquent via le I2C 

static HTS221Sensor hum_temp(&i2c);                //hum_temp utilise le capteur HTS221 pour température + humidité
static LPS22HBSensor pressure(&i2c);               //pressure utilise LPS22HB pour la pression


BufferedSerial pc(USBTX, USBRX, 9600);             //Sert à envoyer du texte au terminal série
                                                   //USBTX/USBRX = broches USB de la carte pour la communication avec mon PC
                                                   //9600 = vitesse de communication 

int main() 
{
    hum_temp.init(NULL);                           //Active et prépare les capteurs à fonctionner
    pressure.init(NULL);

    float temp, hum, press;                        //Variables pour stocker les valeurs lues depuis les capteurs toutes les 2 secs

    while (true) 
    {
        hum_temp.get_temperature(&temp);           //Chaque capteur met à jour les variables temp, hum, press
        hum_temp.get_humidity(&hum);
        pressure.get_pressure(&press);

        char buffer[128];
        int len = sprintf(buffer,"Temp: %.2f C\nHum: %.2f %%\nPress: %.2f hPa\n\n",temp, hum, press);        //Crée une chaîne de caractères contenant les valeurs formatées
        pc.write(buffer, len);                    //Envoie au terminal série pour que je puisse la lire sur mon PC

        ThisThread::sleep_for(2000ms);            //Attend 2s avant la prochaine lecture (évite de saturer le terminal)
    }
}
