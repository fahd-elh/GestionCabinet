#include"file.h"

file* initialiser_file(Patient pts){
    file* f=malloc(sizeof(file));
    if (f!=NULL){
        f->pastient=pts;
        f->next=NULL;
        return f;
    }
    return f;
}
bool file_vide(file *f){
     return f==NULL;
}

void enfiler(file** f,Patient pts){
    if(file_vide(*f)){
        *f=initialiser_file(pts);
        return;
    }
    file* elmt=malloc(sizeof(file));
    if (elmt!=NULL){
      elmt->next=NULL;
      elmt->pastient=pts;
      file* temp=*f;

    while (temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next=elmt;
    }
    
}
void defiler(file** f){
     if(file_vide(*f)){
        printf("tous les patients sont deja passer");
        return;
     }
     else if((*f)->next==NULL){
        free(*f);
        *f=NULL;
        return;
     }
     file *temp=*f;
     *f=(*f)->next;
     free(temp);

     
}

void afficher_file(file* f){
    if(file_vide(f)){
      printf("pas de patient!");
      return;
    }
    printf("ticket \t nom \t prénom  \t  age \t motif \t is_urgent \n");
    file *temp =f;
    while (temp->next!=NULL)
    {
         printf("%d \t %s \t %s  \t  %hd \t %s \t %d \n",temp->pastient.ticket,temp->pastient.nom,temp->pastient.prenom,temp->pastient.age,temp->pastient.motif,temp->pastient.is_urgent);
         temp=temp->next;
    }
    printf("%d \t %s \t %s  \t  %hd \t %s \t %d \n",temp->pastient.ticket,temp->pastient.nom,temp->pastient.prenom,temp->pastient.age,temp->pastient.motif,temp->pastient.is_urgent);
    

}
short nombre_patients(file *f){
  if(!file_vide(f)){
      short count=0;
    file *temp =f;;
    while (temp->next!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count+1;
  }
  return -1;
    
}
void premier_patient(file *f){
    if(!file_vide(f)){
       printf("ticket \t nom \t prénom  \t  age \t motif \t is_urgent \n");
       printf("%d \t %s \t %s  \t  %hd \t %s \t %d \n",f->pastient.ticket,f->pastient.nom,f->pastient.prenom,f->pastient.age,f->pastient.motif,f->pastient.is_urgent);
       return;
    }
    printf("pas de patient!");

}

