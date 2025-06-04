#include "mbed.h"                                                                // mbed.h = bibliothèque principale de Mbed OS
#include "WiFiInterface.h"                                                       // WiFiInterface.h = permet d'utiliser la connexion WiFi
#include "TCPSocket.h"                                                           // TCPSocket.h = gère les connexions réseau simples (TCP)
#include "TLSSocket.h"                                                           // TLSSocket.h = gère les connexions réseau sécurisées (TLS/HTTPS)

BufferedSerial pc(USBTX, USBRX, 9600);                                           // Initialise la communication série USB avec le PC à 9600 bauds
// Envoie les messages dans le terminal

const char *ssid = "TON_SSID";                                                   // ssid = nom du réseau WiFi
const char *password = "TON_MOT_DE_PASSE";                                       // password = mot de passe associé au WiFi

// Fonction utilitaire pour centraliser la vérification des erreurs, sinon doit recopier 5 fois le meme code
void check_error(int ret, const char* message) 
{
    if (ret != 0) 
    {
        printf("%s : %d\n", message, ret);
        exit(1);                                                                                               // Arrête complètement le programme
    }
}

int main() 
{
    WiFiInterface *wifi = WiFiInterface::get_default_instance();                 // Récupère l'interface WiFi de la carte / WiFiInterface est une classe spéciale pour gérer les connexions sans fil
  
    if (!wifi)                                                                                                 // Vérifie que la carte a bien une interface WiFi
    {
        printf("Erreur : pas d'interface WiFi.\n");                                                            // Sinon, le programme s'arrête
        return 1;
    }

    printf("Connexion au WiFi...\n");
    int ret = wifi->connect(ssid, password, NSAPI_SECURITY_WPA_WPA2);            // Essaie de se connecter au WiFi
    // dans le cas présent "->" est utilisé pour accéder à un membre d'une structure ou classe via un pointeur.
  
    check_error(ret, "Échec de connexion");

    printf("Connecté avec IP : %s\n", wifi->get_ip_address());                                                // Affiche l’adresse IP locale obtenue via le WiFi

    TLSSocket socket;                                                                                         // Crée une socket sécurisée TLS pour faire une connexion HTTPS
    ret = socket.open(wifi);                                                                                  // Attache à l’interface WiFi
    check_error(ret, "Erreur socket TLS");

    ret = socket.set_root_ca_cert(MbedTLS_DEFAULT_ROOT_CA_CERT);                                              // Ajoute un certificat racine pour valider la connexion HTTPS
    check_error(ret, "Erreur certificat");

    ret = socket.connect("ifconfig.io", 443);                                                                // Se connecte à ifconfig.io sur le port HTTPS (443)
    check_error(ret, "Erreur connexion HTTPS");

   
    const char *http_request = "GET / HTTP/1.1\r\nHost: ifconfig.io\r\nConnection: close\r\n\r\n";           // Envoie d'une requête HTTP GET au serveur
    socket.send(http_request, strlen(http_request));

    
    char buffer[512];                                                                                        // Lecture de la réponse dans un buffer
    nsapi_size_or_error_t size = socket.recv(buffer, sizeof(buffer) - 1);                                    //sizeof(buffer) - 1 =  la taille totale du tableau (ici : 512 octets)/-1 pour garder une place pour ajouter le caractère de fin \0 (chaîne de texte propre)
// nsapi_size_or_error_t = type spécial défini par Mbed OS
//un nombre d’octets reçus (si positif ou nul) ou un code d’erreur (si négatif)
//Permet de savoir si la réception réseau a réussi ou échoué
//RESUME
//Essaie de recevoir jusqu'à 511 caractères depuis la socket TLS,
//les met dans buffer,
//stocke soit le nombre d’octets reçus, soit un code d’erreur dans la variable size.


  
    if (size >= 0)                                                                                           // Size contient le résultat de socket.recv(...);S’il est positif ou nul, ça veut dire La réception a réussi et size = nombre d'octets reçus    {
        buffer[size] = '\0';                                                                                 // Ajoute fin de chaîne
        printf("Réponse :\n%s\n", buffer);                                                                   // Affiche la réponse HTTP dans le terminal
    } 
    else 
    {
        printf("Erreur de réception : %d\n", size);                                                          // Affiche une erreur si rien n’est reçu
    }

    socket.close();                                                                                          // Ferme la connexion TLS
    wifi->disconnect();                                                                                      // Déconnecte le WiFi
    printf("Déconnecté.\n");                                                                                 // Message de fin
}
