#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define NMAX 15
#define round(x) ((int) x + 0.5)
#define arrondi(x,n) (double)((round(n*x) / n))

typedef char chaine[NMAX];
typedef double Reel;

int main(int argc, char** argv)
{
    Reel tableau_notes[NMAX];
    chaine tableau_noms[NMAX] = {"Christian", "Clement", "Gauthier", "Julien", "Lois", "Mathias", "Maximilien", "Messen", "Romain", "Samuel", "Xavier", "Yohan","Fabio","Jean","Luc"};
    int choix_eleve,i,choix_menu,choix_arrondi,ecart[NMAX],ecartmin,nom_proche;
    double note_eleve = 0.00;
    double somme_notes = 0.00;
    double moyenne_notes = 0.00;
    double ecart_type = 0.00;
    double somme_diff_carrees = 0.00;
    char nom_eleve[NMAX];


    srand(time(NULL));

    //Initialisation tableau de notes
    for(i=0;i<NMAX;i++)
    {
        tableau_notes[i] = (rand()/(double)RAND_MAX) * (20-0) + 0;//Aléatoire compris entre 0 et 20
    }

    //Menu
    printf("Nom prog : Gestions d'etudiants\n\n");

    printf("Menu :\n\n");
    printf("1-Afficher les noms et les notes\n");
    printf("2-Modifier la note d'un eleve\n");
    printf("3-Modifier le nom d'un eleve\n");
    printf("4-Afficher la moyenne et l'ecart-type de la classe\n");
    printf("5-Afficher les notes arrondies\n");
    printf("6-Algo Wagner-Fischer\n");
    printf("0-Quitter l'application\n");

    scanf("%d",&choix_menu);

    //Traitement menu
    while(choix_menu >= 1 && choix_menu <= 6)
    {
        switch(choix_menu)
        {
            case 1 :
                //Affichage noms + notes

                for(i=0;i<NMAX;i++)
                {
                    printf("%d - Nom : %s Note : %lf \n",i,tableau_noms[i],tableau_notes[i]);
                }

                do
                {
                    printf("Menu :\n\n");
                    printf("1-Afficher les noms et les notes\n");
                    printf("2-Modifier la note d'un eleve\n");
                    printf("3-Modifier le nom d'un eleve\n");
                    printf("4-Afficher la moyenne et l'ecart-type de la classe\n");
                    printf("5-Afficher les notes arrondies\n");
                    printf("6-Algo Wagner-Fischer\n");
                    printf("0-Quitter l'application\n");

                    scanf("%d",&choix_menu);
                }while(choix_menu < 0 || choix_menu > 6);
                break;

            case 2 :
                //Modification note
                do
                {
                    for(i=0;i<NMAX;i++)
                    {
                        printf("%d - Nom : %s \n",i,tableau_noms[i]);
                    }
                    printf("Veuillez entrer le numero de l'eleve choisi\n");
                    scanf("%d",&choix_eleve);
                }while(choix_eleve < 0 || choix_eleve > 14);


                do
                {
                    printf("Veuillez entrer la note de l'eleve %d :\n",choix_eleve);
                    scanf("%lf",&note_eleve);
                }while(note_eleve < 0 || note_eleve > 20);
                tableau_notes[choix_eleve] = note_eleve;


                do
                {
                    printf("Menu :\n\n");
                    printf("1-Afficher les noms et les notes\n");
                    printf("2-Modifier la note d'un eleve\n");
                    printf("3-Modifier le nom d'un eleve\n");
                    printf("4-Afficher la moyenne et l'ecart-type de la classe\n");
                    printf("5-Afficher les notes arrondies\n");
                    printf("6-Algo Wagner-Fischer\n");
                    printf("0-Quitter l'application\n");

                    scanf("%d",&choix_menu);
                }while(choix_menu < 0 || choix_menu > 6);

                break;

            case 3 :
                //Modification nom
                do
                {
                    for(i=0;i<NMAX;i++)
                    {
                        printf("%d - Nom : %s \n",i,tableau_noms[i]);
                    }
                    printf("Veuillez entrer le numero de l'eleve choisi\n");
                    scanf("%d",&choix_eleve);
                }while(choix_eleve < 0 || choix_eleve > 14);

                printf("Veuillez entrer le nouveau nom de l'eleve %d\n",choix_eleve);
                scanf("%s",tableau_noms[choix_eleve]);

                do
                {
                    printf("Menu :\n\n");
                    printf("1-Afficher les noms et les notes\n");
                    printf("2-Modifier la note d'un eleve\n");
                    printf("3-Modifier le nom d'un eleve\n");
                    printf("4-Afficher la moyenne et l'ecart-type de la classe\n");
                    printf("5-Afficher les notes arrondies\n");
                    printf("6-Algo Wagner-Fischer\n");
                    printf("0-Quitter l'application\n");

                    scanf("%d",&choix_menu);
                }while(choix_menu < 0 || choix_menu > 6);

                break;

            case 4 :
                //Affichage moyenne + ecart-type

                //Moyenne
                for(i=0;i<NMAX;i++)
                {
                    somme_notes += tableau_notes[i];
                }
                moyenne_notes = somme_notes/NMAX;
                printf("Moyenne de la classe : %lf\n",moyenne_notes);

                //Ecart-type
                for(i=0;i<NMAX;i++)
                {
                    somme_diff_carrees  += ((tableau_notes[i] - moyenne_notes) * (tableau_notes[i] - moyenne_notes)); //Somme_diff : note - moyenne
                }
                ecart_type = sqrt((somme_diff_carrees/NMAX)); //Racine carré de la somme de diff_carre / NMAX
                printf("Ecart-type de la classe : %lf\n",ecart_type);

                //Menu
                do
                {
                    printf("Menu :\n\n");
                    printf("1-Afficher les noms et les notes\n");
                    printf("2-Modifier la note d'un eleve\n");
                    printf("3-Modifier le nom d'un eleve\n");
                    printf("4-Afficher la moyenne et l'ecart-type de la classe\n");
                    printf("5-Afficher les notes arrondies\n");
                    printf("6-Algo Wagner-Fischer\n");
                    printf("0-Quitter l'application\n");

                    scanf("%d",&choix_menu);
                }while(choix_menu < 0 || choix_menu > 6);

                break;

            case 5 :

                //Arrondis des notes
                do
                {
                    printf("Quel arrondi souhaitez-vous ?\n");
                    printf("1 - au point\n");
                    printf("2 - au demi-point\n");
                    printf("3 - au quart de point\n");
                    scanf("%d",&choix_arrondi);
                }while(choix_arrondi < 1 || choix_arrondi > 3);

                do
                {
                    for(i=0;i<NMAX;i++)
                    {
                        printf("%d - Nom : %s \n",i,tableau_noms[i]);
                    }
                    printf("Veuillez entrer le numero de l'eleve choisi\n");
                    scanf("%d",&choix_eleve);
                }while(choix_eleve < 0 || choix_eleve > 14);

                switch(choix_arrondi)
                {
                    case 1 :
                        //Arrondi à l'entier de tableau_notes[choix_eleve]
                        printf( "%d \n",(int)arrondi(tableau_notes[choix_eleve],1));
                        break;
                    case 2 :
                        //Arrondi au demi point de tableau_notes[choix_eleve]
                        printf( "%5.2lf \n",(double)arrondi((int)tableau_notes[choix_eleve],2));
                        break;
                    case 3 :
                        //Arrondi au quart de point de tableau_notes[choix_eleve]
                        printf( "%5.2lf \n",(double)arrondi((int)tableau_notes[choix_eleve],4));
                        break;
                }

                do
                {
                    printf("Menu :\n\n");
                    printf("1-Afficher les noms et les notes\n");
                    printf("2-Modifier la note d'un eleve\n");
                    printf("3-Modifier le nom d'un eleve\n");
                    printf("4-Afficher la moyenne et l'ecart-type de la classe\n");
                    printf("5-Afficher les notes arrondies\n");
                    printf("6-Algo Wagner-Fischer\n");
                    printf("0-Quitter l'application\n");

                    scanf("%d",&choix_menu);
                }while(choix_menu < 0 || choix_menu > 6);

                break;
            case 6 :

                for(i=0;i<NMAX;i++)
                {
                    printf("%d - Nom : %s \n",i,tableau_noms[i]);
                }

                printf("Veuillez taper un nom \n");
                scanf("%s",nom_eleve);

                for(i=0; i<NMAX; i++)
                {
                    int a, b ,x;
                    int n = strlen(nom_eleve);
                    int m = strlen(tableau_noms[i]);
                    int m1, m2, m3, min;
                    int tableau[n+1][m+1];

                    tableau[0][0] = 0;

                    for(a=1;a<=n;a++)
                    {
                        tableau[a][0] =  tableau[a-1][0] + 1;
                    }
                    for(b=1; b<=m ;b++)
                    {
                        tableau[0][b] =  tableau[0][b-1] + 1;
                    }

                    for(a=1;a<=n;a++)
                    {
                        for(b=1;b<=m;b++)
                        {
                            if(nom_eleve[b-1] == tableau_noms[i][a-1])
                            {
                                x = 0;
                            }
                            else
                            {
                                x = 1;
                            }

                            m1 = tableau[a-1][b-1] + x;
                            m2 = tableau[a-1][b] + 1;
                            m3 = tableau[a][b-1] + 1;

                            min = m1;
                            if(m2 < m1)
                            {
                                min = m2;
                            }

                            if(m3 < min)
                            {
                                min = m3;
                            }

                            tableau[a][b] = min;
                        }
                    }
                    ecart[i] = tableau[n][m];
                }

                //Recherche du plus proche
                ecartmin = ecart[0];
                nom_proche = 0;
                for(i=1;i<NMAX;i++)
                {
                    if(ecart[i] < ecartmin)
                    {
                        ecartmin = ecart[i];
                        nom_proche = i;
                    }
                }

                //Affichage
                printf("Le nom le plus proche de %s est : %s \n",nom_eleve,tableau_noms[nom_proche]);

                 do
                {
                    printf("Menu :\n\n");
                    printf("1-Afficher les noms et les notes\n");
                    printf("2-Modifier la note d'un eleve\n");
                    printf("3-Modifier le nom d'un eleve\n");
                    printf("4-Afficher la moyenne et l'ecart-type de la classe\n");
                    printf("5-Afficher les notes arrondies\n");
                    printf("6-Algo Wagner-Fischer\n");
                    printf("0-Quitter l'application\n");

                    scanf("%d",&choix_menu);
                }while(choix_menu < 0 || choix_menu > 6);

                break;
        }
    }
    return 0;
}
