#include <stdio.h> // traitement entrées/sortie
#include <stdlib.h>
#include <string.h> // traitement des chaines de caractère

#include "header.h"

int main()
{
	FILE *f;		//création du pointeur vers le fichier
	char *ligne = malloc(sizeof(char) * 1024);	// création de la chaine de caractère qui stockera la ligne
	char type[10];	// création de la variable contenant le type de PBM
	int dim[2];	//création d'un tableau
	int *lignes = malloc(sizeof(int *)); // création du pointeur qui contiendra le nombre de lignes
	int *colonnes = malloc(sizeof(int *));	// création du pointeur qui contiendra le nombre de colonnes
	int n; // variable compteur (pour parcourir toute la ligne)
	int nc;
	int quelprojet;
	int nbradd = 1;

	taillefen(colonnes, lignes); // on appelle la fonction pour connaître la taille de la fenêtre

	readPBM("test_coeur.pbm", dim, type, ligne);	// on envoie les paramètres nécéssaires au module de lecture

	for(n=0;n<strlen(ligne);n++)
	{
		if(ligne[n] == '1')	// si on lit 1 dans le .pbm
		{
			printf("█");	// on affiche le caractère █
		}
		else if(ligne[n] == '2') //sinon si on lit 2 dans le pbm
		{
			printf("\n"); // faire un retour à la ligne
		}
		else	// sinon si on lit un 0 dans le .pbm
		{
			printf(" ");	// afficher un espace
		}
	}
	printf("\n");	// retour à la ligne à la fin de chaque lignes
	printf("Le fichier PBM est de type %s\n", type);
	printf("Largeur = %d Longueur = %d.\n", dim[0], dim[1]);
	printf("Ce terminal possède %d colonnes et %d lignes.\n", *colonnes, *lignes);

	free(lignes);
	free(colonnes);
	return 0;
}