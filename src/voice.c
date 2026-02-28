#include <stdio.h>
#include <stdlib.h>
#include "voice.h"

void parler(const char *texte)
{
    char cmd[2048];

    // powershell pour faire parler
    snprintf(cmd, sizeof(cmd),
        "cmd /c \"\"C:\\Windows\\System32\\WindowsPowerShell\\v1.0\\powershell.exe\" -ExecutionPolicy Bypass -File speak.ps1 \\\"%s\\\"\"",
        texte);

    system(cmd);
}
