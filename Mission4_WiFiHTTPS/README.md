# Mission 4 – Connexion WiFi et communication sécurisée (HTTPS)

Ce programme permet de connecter la carte **DISCO-L475VG-IOT01A** à un réseau WiFi personnel, puis d'établir une connexion sécurisée en **HTTPS** avec le serveur `ifconfig.io`. 
Il envoie une requête HTTP `GET` et affiche la réponse dans le terminal série, ce qui permet de récupérer l'adresse IP publique de la carte.
_____________________________________________________________________________________________________________________________________________________________________________________
Etapes de fonctionement

1. Initialisation de l'interface WiFi via `WiFiInterface`
2. Connexion au réseau WiFi personnel (SSID + mot de passe à fournir)
3. Création d'une socket sécurisée TLS avec `TLSSocket`
4. Ajout d’un certificat racine pour valider la connexion HTTPS
5. Connexion au serveur `ifconfig.io` sur le port 443
6. Envoi d’une requête `GET / HTTP/1.1`
7. Affichage de la réponse HTTP dans le terminal
_____________________________________________________________________________________________________________________________________________________________________________________
Fichiers inclus

- `main.cpp` → Code principal, bien structuré et commenté
- `mbed_app.json` → Configuration série (9600 bauds, formatage des retours à la ligne)
_____________________________________________________________________________________________________________________________________________________________________________________
Attention

- Les identifiants WiFi (`ssid` et `password`) doivent être **remplacés manuellement** dans le fichier `main.cpp` **pour les tests réels**.
- **Ne pas publier de vrais identifiants WiFi** dans le dépôt GitHub.
- La fonction `check_error()` permet de simplifier la gestion des erreurs réseau et éviter la répétition du même bloc de code après chaque étape
_____________________________________________________________________________________________________________________________________________________________________________________
Exemple de sortie dans le terminal
Connexion au WiFi...
Connecté avec IP : 192.168.1.10
Réponse :
HTTP/1.1 200 OK
Content-Type: text/plain; charset=utf-8

86.234.XX.XXX
