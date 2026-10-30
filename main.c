#include <string.h>
#include "file.h"

void vider_buffer(void){
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void saisir_chaine(char *dest, int taille){
    if (fgets(dest, taille, stdin) != NULL) {
        dest[strcspn(dest, "\n")] = '\0';
    }
}

short saisir_entier(const char *message, short min, short max){
    short valeur;
    int ok;
    do {
        printf("%s", message);
        ok = scanf("%hd", &valeur);
        vider_buffer();
        if (ok != 1 || valeur < min || valeur > max) {
            printf("Valeur invalide (entre %hd et %hd).\n", min, max);
            ok = 0;
        }
    } while (!ok);
    return valeur;
}

void afficher_menu(void){
    printf("\n===== GestionCabinet =====\n");
    printf("1 - Ajouter un patient\n");
    printf("2 - Appeler le patient suivant\n");
    printf("3 - Afficher les patients en attente\n");
    printf("4 - Afficher le nombre de patients\n");
    printf("5 - Afficher le prochain patient\n");
    printf("6 - Quitter\n");
}

int main(void){
    file *f = NULL;
    short choix;
    short compteur_ticket = 0;
    Patient pts;
    short urgent;
    short nb;

    do {
        afficher_menu();
        choix = saisir_entier("Quel est votre choix : ", 1, 6);

        switch (choix) {
        case 1:
            pts.ticket = ++compteur_ticket;

            printf("Nom du patient : ");
            saisir_chaine(pts.nom, sizeof(pts.nom));

            printf("Prenom du patient : ");
            saisir_chaine(pts.prenom, sizeof(pts.prenom));

            printf("Motif de consultation : ");
            saisir_chaine(pts.motif, sizeof(pts.motif));

            pts.age = saisir_entier("Age du patient : ", 0, 120);

            urgent = saisir_entier("Urgent ? (1 = oui, 0 = non) : ", 0, 1);
            pts.is_urgent = (urgent == 1);

            enfiler(&f, pts);
            printf("Patient ajoute avec le ticket numero %hd.\n", pts.ticket);
            break;

        case 2:
            if (file_vide(f)) {
                printf("Aucun patient en attente.\n");
            } else {
                printf("Patient appele :\n");
                premier_patient(f);
                defiler(&f);
            }
            break;

        case 3:
            afficher_file(f);
            printf("\n");
            break;

        case 4:
            nb = nombre_patients(f);
            printf("Nombre de patients en attente : %hd\n", nb < 0 ? 0 : nb);
            break;

        case 5:
            premier_patient(f);
            printf("\n");
            break;

        case 6:
            printf("Au revoir.\n");
            break;
        }
    } while (choix != 6);

    while (!file_vide(f)) {
        defiler(&f);
    }

    return 0;
}