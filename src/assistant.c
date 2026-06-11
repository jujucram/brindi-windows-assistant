#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "voice.h"
#include "utils.h"

void executerCommande(const char *input)
{
    char cmd[512];
    char tmp[256];

    if (strstr(input, "bonjour")) {
        parler("Bonjour Brandon, je suis Brindi. Prêt à vous aider !");
    }
    else if (strstr(input, "chrome") || strstr(input, "internet")) {
        parler("Ouverture Google Chrome");
        system("start chrome");
    }
    else if (strstr(input, "bloc-notes") || strstr(input, "note")) {
        parler("Ouverture le Bloc-notes");
        system("start notepad");
    }
    else if (strstr(input, "youtube")) {
        parler("Ouverture de YouTube");
        system("start https://www.youtube.com");
    }
    else if (strstr(input, "calculatrice") || strstr(input, "calc")) {
        parler("Ouverture la calculatrice");
        system("start calc");
    }
    else if(strstr(input, "visual studio code") || strstr(input, "vs code")){
        parler("Ouverture de Visual studio code");
        system("start code");
    }
    else if(strstr(input, "GTA") || strstr(input, "gta")){
        parler("Ouverture de GTA");
        system("start GTA SA");
    }
    else if (strstr(input, "heure")) {
        time_t now = time(NULL);
        struct tm *ltm = localtime(&now);
        snprintf(tmp, sizeof(tmp), "Il est actuellement %02d heures %02d", ltm->tm_hour, ltm->tm_min);
        parler(tmp);
        printf("Brindi : %s\n", tmp);
    }
    else if (strstr(input, "au revoir") || strstr(input, "quitter") || strstr(input, "fermeture") || strstr(input, "ferme toi")
        ) {
        parler("revoir ! À bientôt.");
        exit(0);
    }
    else {
        snprintf(cmd, sizeof(cmd), "start https://www.google.com/search?q=%s", input);
        parler("Je ne connais pas cette commande. Je cherche sur Internet.");
        system(cmd);
    }
}
