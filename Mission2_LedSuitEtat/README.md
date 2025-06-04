Mission 2 – Test : La LED suit l’état du bouton

Ce programme lie directement l’état du bouton utilisateur à celui de la LED, de manière continue.

________________________________________________________________________________________________________________________________________________________________________
Étapes de fonctionnement

1. La LED est allumée (1) lorsque le bouton est relâché.
2. Elle s’éteint (0) lorsque le bouton est appuyé.
3. Le lien est direct sans condition intermédiaire : la LED = bouton.read()

________________________________________________________________________________________________________________________________________________________________________
Fichiers inclus

- `main.cpp` : code principal

________________________________________________________________________________________________________________________________________________________________________
Résultat attendu

La LED s’allume ou s’éteint en temps réel selon l’état du bouton.
