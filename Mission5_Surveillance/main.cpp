#include "mbed.h"                                                                               // Bibliothèque principale de Mbed OS
#include "HTS221Sensor.h"                                                                       // Bibliothèque du capteur HTS221 (température et humidité)

// Initialisation de la communication série USB avec le terminal de l’ordinateur
BufferedSerial pc(USBTX, USBRX, 9600);

// Initialisation du bus I2C (lien entre la carte et le capteur)
DevI2C i2c(PB_11, PB_10);                                                                       // PB_11 = SDA / PB_10 = SCL (broches I2C)

// Initialisation du capteur HTS221 (humidité + température) en passant par le bus I2C
HTS221Sensor capteur(&i2c);

// Définition des seuils d’alerte (valeurs de référence à ne pas dépasser)
#define TEMP_MAX 28.0                                                                          // Température maximale autorisée (en °C)
#define HUM_MIN 35.0                                                                           // Humidité minimale autorisée (en %)

int main() {
    capteur.init(NULL);                                                                       // Initialisation du capteur HTS221

    float temp, hum;                                                                          // Déclaration des variables pour stocker les mesures

    while (true)                                                                              // Boucle infinie : répétition continue des mesures
    {
        capteur.get_temperature(&temp);                                                       // Lecture de la température depuis le capteur
        capteur.get_humidity(&hum);                                                           // Lecture de l’humidité depuis le capteur

        // Affichage des mesures dans le terminal de l’ordinateur
        printf("Température : %.2f C | Humidité : %.2f %%\n", temp, hum);

        // Vérification des seuils de sécurité
        if (temp > TEMP_MAX) 
        {
            printf("Alerte : Température trop élevée !\n");                                  // Message d’alerte si température au-dessus du seuil
        }

        if (hum < HUM_MIN) 
        {
            printf("Alerte : Humidité trop basse !\n");                                      // Message d’alerte si humidité en dessous du seuil
        }

        printf("------------------------\n");                                                // Séparateur visuel pour plus de lisibilité
        ThisThread::sleep_for(5000ms);                                                       // Pause de 5 secondes entre chaque mesure
    }
}
