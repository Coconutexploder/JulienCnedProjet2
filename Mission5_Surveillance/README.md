Mission 5 – Mini-projet : Surveillance de chambre

Ce programme permet de surveiller la température et l’humidité dans une chambre d’enfant à l’aide des capteurs intégrés à la carte DISCO-L475VG-IOT01A.
Il réalise des mesures régulières et affiche dans le terminal les valeurs relevées ainsi que des alertes si des seuils critiques sont atteints.
________________________________________________________________________________________________________________________________________________________________________
Etapes de fonctionement

1. Le capteur HTS221 intégré à la carte est initialisé via le bus I2C.
2. Une mesure de température et d’humidité est réalisée toutes les 5 secondes.
3. Si la température dépasse une valeur maximale prédéfinie ou si l’humidité passe sous une valeur minimale, un message d’alerte est affiché dans le terminal.
4. Toutes les données sont transmises via le port série à un terminal connecté à l’ordinateur.
________________________________________________________________________________________________________________________________________________________________________
Seuils définis

- Température maximale : 28.0 °C
- Humidité minimale : 35.0 %
________________________________________________________________________________________________________________________________________________________________________
Fichiers inclus

- `main.cpp` : code principal commenté
- `mbed_app.json` : configuration du port série (9600 bauds, formatage des lignes)
________________________________________________________________________________________________________________________________________________________________________
Résultat attendu

Le terminal affiche à intervalles réguliers les mesures du capteur et notifie si un seuil est dépassé.
