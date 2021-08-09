/**SLIMANI Dalia
  *03/08/2021
  */
  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "candidat.h"
#include <stdbool.h>
#include "auto-ecole.h"

int main () {
	int choix,num_doss,nb_doss;
	float somme;
	char exam[10];
	
	//MENU

	while (1){
	printf (" ***************************\n");
	printf ("*************MENU***********\n");
	printf (" ***************************\n");
	printf ("1-Ajouter un candidat \n");
	printf ("2-Passer un examen \n");
	printf ("3-Supprimer un candidat \n");
	printf ("4-Modifier le montant restant dun candidat \n");
	printf ("5-Mettre a jour le statut dun examen \n");
	printf ("6-afficher tous lescandidats \n");
	printf ("7-modifier les frais dun examen \n");
	printf ("8-modifier le montant paye \n");
	printf ("9-quitter le prog \n");
	
	printf ("\n");
	printf ("\n");
	
	printf ("introduisez votre choix \n");
	scanf ("%d",&choix);
	printf ("\n");
	switch( choix){
		case 1 : printf ("ajouter un condidat\n \n");
				 ajout ();
				 printf ("\n");
		break;
		case 2 : printf ("passer un exam \n \n");
				 printf ("donnez le numero de dossier du candidat qui veut passer un exam \n");
				 scanf ("%d",&num_doss);
				 printf("donnez lexamen quil souhaite passer \n");
				 scanf(" %s",exam);
				 pass_exam (num_doss , exam);
				 printf ("\n");
		
		break;
		case 3: printf ("supprimer un candidat \n \n");
		        suppression ();
		        printf ("\n");
		break;
		case 4: printf ("modifier le montant restant dun candidat \n \n");
				printf ("donnez le numero de dossier du candidat dont vous souhaitez modifier le montant restant \n");
				scanf("%d",&num_doss);
				printf ("donnez la somme rajoutee par ce dernier \n");
				scanf("%f",&somme);
				modification_montant(num_doss,somme);
				printf ("\n");

		break;
		case 5: printf ("mettre a jour le statut dun examen \n \n");
				printf ("donnez le numero de dossier du candidat dont vous voulez mettre a jour le statut dun exam \n");
				scanf ("%d",&nb_doss);
				modification_statut(num_doss);
				printf ("\n");
		break;
		case 6 : printf ("la liste des candidats \n");
				 affichage();
				 printf ("\n");
		break;
		case 7 : printf ("modifier les frais dun examen \n");
				 printf ("donnez le numero de dossier du candidat dont vous souhaitez modifier les frais dun exam \n");
				 scanf ("%d",&num_doss);
				 mod_frais (num_doss);
				 printf ("\n");
		break;
		case 8 : printf ("modifier le montant paye \n");
				 printf ("donnez le numero de dossier du candidat a qui vous souhaitez modifier le montant paye  \n");
				 scanf ("%d",&num_doss);
				 mod_mont (num_doss);
				 printf ("\n");
		break;
		case 9 : exit(0);
		break;
		default : printf ("le numero nexiste pas dans le menu \n \n");
		break;
		
		}
	
	}
	return 0;
}

	
	

