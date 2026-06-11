# Brindi – Assistant Windows Vocal

Brindi est un assistant personnel Windows capable de parler, exécuter des commandes système et ouvrir des applications à partir de commandes textuelles. Il fonctionne localement et utilise la voix Windows pour interagir avec l'utilisateur.

**Développé par :** Brandon

## Fonctionnalités

- Synthèse vocale (Text-to-Speech) avec la voix Windows
- Ouverture d'applications (Chrome, Bloc-notes, Calculatrice, etc...)
- Recherche Google automatique si la commande n'est pas reconnue
- Boucle continue : l'assistant reste à l'écoute
- Programmation modulaire
- Aucune bibliothèque externe à installer

## Exemples de commandes

```
bonjour
chrome
ouvre vscode
calculatrice
quelle heure est-il
youtube
au revoir
```

Si Brindi ne reconnaît pas la commande, il effectue automatiquement une recherche sur Internet.

## Structure du projet

```
Brindi/
├─ src/
│   ├─ main.c          # Point d'entrée
│   ├─ assistant.c     # Logique des commandes
│   ├─ voice.c         # Gestion de la voix
│   ├─ utils.c         # Fonctions utilitaires
├─ include/
│   ├─ assistant.h
│   ├─ voice.h
│   ├─ utils.h
├─ scripts/
│   └─ speak_file.ps1  # Script PowerShell pour la voix
├─ README.md
└─ .gitignore
```

## Prérequis

- Windows 10 ou 11
- Un périphérique audio actif (haut-parleurs ou casque)
- PowerShell (installé par défaut sur Windows)
- Code::Blocks, VS Code ou tout compilateur C compatible Windows

## Installation & Compilation

1. Clonez le projet :
```bash
git clone https://github.com/ton-username/brindi.git
```

2. Ouvrez le projet dans Code::Blocks
3. Ajoutez tous les fichiers .c et .h au projet
4. Compilez le projet
5. Placez `speak_file.ps1` dans le même dossier que l'exécutable
6. Lancez `Brindi.exe`

## Comment fonctionne la voix

Brindi utilise une méthode stable et fiable :

1. Le texte à prononcer est écrit dans un fichier temporaire
2. PowerShell lit ce fichier avec System.Speech
3. La phrase complète est prononcée

Cette méthode évite tous les problèmes liés aux guillemets et aux espaces.

## Ajouter une nouvelle commande

Pour ajouter une commande (ex : ouvrir VS Code) :

1. Ouvrez `assistant.c`
2. Ajoutez un bloc :
```c
else if (strstr(input, "vscode")) {
    parler("J'ouvre Visual Studio Code");
    system("code");
}
```

3. Compilez, testez, et c'est prêt

## Sécurité & Confidentialité

- Aucune donnée personnelle collectée
- Aucune connexion serveur
- Tout fonctionne en local
- PowerShell utilisé uniquement pour la voix

## Objectif du projet

Brindi est un projet éducatif visant à :

- Apprendre la programmation modulaire en C
- Comprendre l'interaction entre C et Windows
- Créer un assistant vocal simple et extensible


## Améliorations futures

- Reconnaissance vocale (parler à Brindi)
- Système de commandes dynamique
- Historique des commandes
- Interface graphique
