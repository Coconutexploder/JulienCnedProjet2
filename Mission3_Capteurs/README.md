Mission 3 – Découverte des capteurs de la carte

Ce programme utilise les capteurs intégrés à la carte DISCO-L475VG-IOT01A pour mesurer la température, l’humidité et la pression. Les données relevées sont affichées régulièrement dans le terminal série connecté à l’ordinateur.

________________________________________________________________________________________________________________________________________________________________________
Étapes de fonctionnement

1. Le capteur HTS221 est utilisé pour mesurer la température et l’humidité.
2. Le capteur LPS22HB est utilisé pour mesurer la pression atmosphérique.
3. Les deux capteurs sont initialisés via le bus I2C interne de la carte.
4. Toutes les données sont affichées toutes les 2 secondes dans le terminal série à 9600 bauds.

________________________________________________________________________________________________________________________________________________________________________
Fichiers inclus

- `main.cpp` : programme principal qui initialise les capteurs et lit les mesures
- `mbed_app.json` : configuration du port série (9600 bauds et formatage des retours à la ligne)

________________________________________________________________________________________________________________________________________________________________________
Résultat attendu

Le terminal affiche la température (°C), l’humidité relative (%) et la pression (hPa) à intervalles réguliers.
