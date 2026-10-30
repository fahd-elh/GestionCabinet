# GestionCabinet
 
Application console en langage C pour gérer la file d'attente des patients d'un cabinet médical.
 
## Description
 
**GestionCabinet** repose sur la structure de données **file (FIFO : First In, First Out)** : le premier patient arrivé est le premier appelé en consultation.
 
Ce projet remplace la gestion manuelle de la salle d'attente par un programme simple qui enregistre les arrivées, appelle les patients dans l'ordre et affiche l'état de la file à tout moment.
 
## Fonctionnalités principales
 
- Enregistrer un nouveau patient (ticket, nom, prénom, âge, motif de consultation)
- Appeler le patient suivant (retrait de la file)
- Afficher la liste des patients en attente
- Consulter le prochain patient sans le retirer
- Connaître le nombre de patients en attente
- Détecter une file vide ou pleine
## Fonctionnalités avancées (optionnelles)
 
- Recherche d'un patient par nom ou numéro de ticket
- Annulation d'un rendez-vous
- Gestion des urgences (passage en tête de file)
- Estimation du temps d'attente
## Choix techniques
 
| Élément | Choix |
|---|---|
| Langage | C (norme C99 ou plus) |
| Structure de données | File (tableau circulaire ou liste chaînée) |
| Interface | Menu interactif en ligne de commande |
| Organisation | `main.c`, `file.c`, `file.h` |
 
## Structure du projet
 
```
GestionCabinet/
├── main.c          # Menu et boucle principale
├── file.c          # Fonctions de la file
├── file.h          # Structures et prototypes
└── README.md       # Description du projet
```
 
## Compilation et exécution
 
```bash
gcc main.c file.c -o gestion_cabinet
./gestion_cabinet
```
 
## Résumé
 
Ce projet consiste à développer en C une application de gestion de la file d'attente d'un cabinet médical. Il met en pratique la structure de données file (FIFO) pour enregistrer les patients à leur arrivée, les appeler dans l'ordre et suivre l'état de la salle d'attente, avec un menu interactif simple d'utilisation.