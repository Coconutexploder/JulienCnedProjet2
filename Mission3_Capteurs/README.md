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
________________________________________________________________________________________________________________________________________________________________________
Explication du fonctionement des fichiers "mbed_app.json"

target_overrides = section obligatoire dans le fichier.
Elle permet de modifier des paramètres spécifiques pour un ou plusieurs types de cartes cibles.
"*" = "joker" (généralisation une regle sans sans nomer une cible spécifique)
Définit la vitesse de communication série entre la carte et l'ordinateur. =9600 bauds, qui est une vitesse classique et stable pour les terminaux
Permet de convertir les caractères de saut de ligne (\n) en un format compréhensible pour les terminaux, donc chaque ligne s’affiche correctement sur le terminal 
