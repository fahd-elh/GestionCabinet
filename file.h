#ifndef File_H
#define File_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Patient{
    short  ticket;
    char nom[50];
    char prenom[50];
    short   age;
    char motif[100] ;
    bool is_urgent;

}Patient;

typedef struct file{
    Patient pastient;
    struct file *next;
    
}file;

file* initialiser_file(Patient pts);
bool file_vide(file *f);
void defiler(file** f);
short nombre_patients(file *f);
void premier_patient(file *f);
void afficher_file(file* f);
void enfiler(file** f,Patient pts);
#endif