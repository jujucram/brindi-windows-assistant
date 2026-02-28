#include <stdio.h>
#include <string.h>
#include "voice.h"
#include "utils.h"
#include "assistant.h"

int main()
{
    char input[128];

    parler("Bonjour, je suis Brindi. Prêt à vous aider !");

    while (1)
    {
        printf("\nBrindi > ");
        if (fgets(input, sizeof(input), stdin))
        {
            input[strcspn(input, "\n")] = 0;
            if (strlen(input) > 0)
            {
                toLowerCase(input);
                executerCommande(input);
            }
        }
    }

    return 0;
}
