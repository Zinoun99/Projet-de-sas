#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100

int nbr;
int choix;

int taille=0;

typedef struct {
	int annee;
	int mois;
	int jours;
}Date;
	
typedef struct {
	char description[100];
	Date date;
	int priorite;
}Tache;


Tache T[MAX];



void Ajouter(){
	printf("Entrer les informations du tache \n");
	printf("Donner la description:\n");
	scanf("%s", T[taille].description);
	printf("Entrer la date (jour mois annee)\n");
	scanf("%d%d%d", &T[taille].date.jours, &T[taille].date.mois, &T[taille].date.annee);
	printf("Donner la priorite:\n");
	scanf("%d", &T[taille].priorite);
	taille++;
}

void Afficher() {
    if (taille == 0) {
        printf("La liste de taches est vide.\n");
    } else {
        printf("Liste des taches :\n");
        for (int i = 0; i < taille; i++) {
        	printf("Tache %d:\n", i+1);
            printf("Description : %s\n", T[i].description);
            printf("Priorite : %d\n", T[i].priorite);
            printf("Date : %d/%d/%d\n", T[i].date.jours, T[i].date.mois, T[i].date.annee);
            printf("\n");
        }
    }
}

		
void Modifier(){
	int numTache;
	
	printf("Entrer le numero de la tache a modifier: \n");
	scanf("%d", &numTache);
	
		if(numTache >= 1 || numTache <= nbr){
			
			numTache--;
    		printf("Entrer la modification pour la tache %d\n", numTache+1);
    		printf("Nouvelle description : ");
    		scanf("%s", T[numTache].description);
    		printf("Nouvelle date (jours/mois/annee): ");
    		scanf("%d/%d/%d", &T[numTache].date.jours, &T[numTache].date.mois, T[numTache].date.annee);
    		printf("Nouvelle priorite : ");
    		scanf("%d", &T[numTache].priorite);
    		printf("Tache modifiee avec succes!\n");
			}
		else 
		printf("Aucune tache est trouve.\n");
	}
	
void Supprimer() {
    int index;
    printf("Entrer le numéro de la tache a supprimer : ");
    scanf("%d", &index);

    if (index <= 0 || index > taille) {
        printf("Numéro de tache invalide.\n");
    } else {
        index--; 
        for (int i = index; i < taille - 1; i++) {
            T[i] = T[i+1];
        }
        taille--;

        printf("Tache supprimee avec succes.\n");
    }
}

void TrierCroissante() {
    Tache temp;
    for (int i = 0; i < taille - 1; i++) {
        for (int j = i; j < taille; j++) {
            if (T[i].date.annee > T[j].date.annee ||
                (T[i].date.annee == T[j].date.annee && T[i].date.mois > T[j].date.mois) ||
                (T[i].date.annee == T[j].date.annee && T[i].date.mois == T[j].date.mois && T[i].date.jours > T[j].date.jours)) {
                temp = T[i];
                T[i] = T[j];
                T[j] = temp;
            }
        }
    }
    printf("La liste est triee avec succes\n");
}

void TrierDecroissante() {
    Tache temp;
    for (int i = 0; i < taille - 1; i++) {
        for (int j = i; j < taille; j++) {
            if (T[i].date.annee < T[j].date.annee ||
                (T[i].date.annee == T[j].date.annee && T[i].date.mois < T[j].date.mois) ||
                (T[i].date.annee == T[j].date.annee && T[i].date.mois == T[j].date.mois && T[i].date.jours < T[j].date.jours)) {
                temp = T[i];
                T[i] = T[j];
                T[j] = temp;
            }
        }
    }
    printf("La liste est triee avec succes\n");
}



int main (){
	
	do{
		printf("\n\n Le menu principale\n\n");
		printf("1.  Ajouter une Tache\n");
		printf("2.  Afficher la Liste des Taches\n");
		printf("3.  Modifier une Tache\n");
		printf("4.  Supprimer une Tache\n");
		printf("5.  Ordonner les Taches par order croissante\n");
		printf("6.  Ordonner les Taches par order decroissante\n");
		
		do{
			printf("Entrer votre choix:\n");
			scanf("%d", &choix);
			if(choix>8 || choix<1)
			printf("Votre choix doit compris entre 1 et 8\n");
		}while(choix>8 || choix<1);
		
		switch(choix){
			case 1:
				Ajouter();
				break;
				
			case 2:
				Afficher();
				break;
			case 3:
                Modifier();
				break;
			case 4:
				Supprimer();
				break;
			
			case 5:
				TrierCroissante();
				break;
			case 6:
				TrierDecroissante();
				break;
				
			default:
				break;
			}
				
	}while(choix=!0); 
	int x;
		
	return 0;
}
