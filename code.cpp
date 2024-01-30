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

		
