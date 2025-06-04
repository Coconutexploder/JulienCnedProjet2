Mission 2 – Test : Inversion de l’état de la LED à chaque appui

Ce programme permet de changer l’état d’une LED à chaque **pression** du bouton utilisateur.

________________________________________________________________________________________________________________________________________________________________________
Étapes de fonctionnement

1. La LED est initialisée comme sortie numérique sur PA_5.
2. Le bouton est lu sur PC_13.
3. À chaque passage de l’état relâché à l’état appuyé, la LED s’inverse (allumée → éteinte ou inversement).
4. Une temporisation de 50 ms évite les rebonds de bouton.

________________________________________________________________________________________________________________________________________________________________________
Fichiers inclus

- `main.cpp` : code principal

________________________________________________________________________________________________________________________________________________________________________
Résultat attendu

La LED change d’état à chaque appui du bouton.
