#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  // Pour _getch()
#include <windows.h> // Pour gotoxy()
#include <time.h> // Pour srand()

// Fonction pour déplacer le curseur dans la console
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Fonction pour afficher un cadre
void dessinerCadre(int x, int y, int largeur, int hauteur) {
    gotoxy(x, y);
    printf("%c", 218);
    for (int i = 0; i < largeur - 2; i++) printf("%c", 196);
    printf("%c", 191);

    for (int i = 1; i < hauteur - 1; i++) {
        gotoxy(x, y + i);
        printf("%c", 179);
        gotoxy(x + largeur - 1, y + i);
        printf("%c", 179);
    }

    gotoxy(x, y + hauteur - 1);
    printf("%c", 192);
    for (int i = 0; i < largeur - 2; i++) printf("%c", 196);
    printf("%c", 217);
}

char generer_consonne() {
    char consonnes[] = "BCDFGHJKLMNPQRSTVWXYZ";
    return consonnes[rand() % 21];
}

char generer_voyelle() {
    char voyelles[] = "AEIOUY";
    return voyelles[rand() % 6];
}

// Fonction pour générer une grille de 9 lettres de manière aléatoire
void generer_grille_manuelle(char grille[]) {
    int index = 0;
    char touche;
    gotoxy(82, 0);
    printf("\nAppuyez sur 'C' pour une consonne ou 'V' pour une voyelle\n");

    while (index < 9) {
        touche = _getch(); // Capture la touche pressée

        if (touche == 'C' || touche == 'c') {
            grille[index] = generer_consonne();
            gotoxy(25 + (index * 7), 5); // Positionner la lettre
            printf("%c", grille[index]);
            index++;
        }
        else if (touche == 'V' || touche == 'v') {
            grille[index] = generer_voyelle();
            gotoxy(25 + (index * 7), 5); // Positionner la lettre
            printf("%c", grille[index]);
            index++;
        }
    }
}


void afficher_grille(char grille[]) {

    for (int i = 0; i < 9; i++) {
        gotoxy(25 + (i * 7), 5); // Positionner chaque lettre horizontalement
        printf("%c", grille[i]); // Afficher la lettre
    }
}


// Fonction pour afficher le menu et obtenir le choix de l'utilisateur
int menu() {
    int choix = 0;
    system("cls"); // Efface l'écran
    dessinerCadre(10, 5, 50, 16); // Cadre du menu
    gotoxy(20, 7);
    printf("=== MENU ===");
    gotoxy(15, 9);
    printf("1. Mode solo");
    gotoxy(15, 10);
    printf("2. Mode 1v1");
    gotoxy(15, 11);
    printf("3. Continuer");
    gotoxy(15, 12);
    printf("4. Quitter");
    gotoxy(15, 14);
    printf("Votre choix : ");
    scanf("%d", &choix);
    return choix;
}

// Programme principal
int main() {
    int score1 = 0;
    int score2 = 0;
      printf("\033[1mTexte en gras\033[0m\n");

    srand(time(NULL)); // Initialisation du générateur de nombres aléatoires
    int choix;
    char joueur[20], joueur1[20], joueur2[20];
    char grille[9];

    do {
        choix = menu();
        system("cls"); // Efface l'écran
        gotoxy(50, 5);
        switch (choix) {
            case 1:
                printf("Vous avez choisi le mode Solo!\n");
                //saisie du nom du joueur
                gotoxy(50, 6);
                printf("Entrez le nom du Joueur: ");
                scanf("%19s", joueur);
                //effacement de l'écran
                system("cls");
                //Cadre principal
                dessinerCadre(5, 2, 90, 22);
                //Affichage du score
                gotoxy(13, 4);
                dessinerCadre(8, 3, 12, 5);

                gotoxy(14, 5);
                printf("%d", score1);
                //Affichage du nom sous le score
                gotoxy(10, 8);
                printf("%s", joueur);
                //Affichage de la grille de lettre
                    dessinerCadre(21, 3, 68, 5);
                    gotoxy(46, 8);
                    printf("Grille de lettres");
                    generer_grille_manuelle(grille);
                    afficher_grille(grille);
                  // Zone de propositions
                    dessinerCadre(27, 11, 55, 3);
                    gotoxy(46, 14);
                    printf("Zone de proposition");
                // Zone d'affichage des propositions
                    dessinerCadre(27, 15, 55, 3);
                    gotoxy(40, 18);
                    printf("Zone d'affichage de la proposition");
                // Zone d'affichage de la proposition de l'ordinateur
                    dessinerCadre(27, 19, 55, 3);
                    gotoxy(40, 22);
                    printf("Affichage proposition de l'ordinateur\n");
                //Empêcher la fermeture immédiate
                gotoxy(43, 29);
                printf("Appuyez sur une touche pour quitter...");
                getchar();
                break;
            case 2:
                printf("Vous avez choisi le mode 1v1!\n");
                //saisie du nom du joueur1
                gotoxy(50, 6);
                printf("Entrez le nom du Joueur 1: ");
                scanf("%19s", joueur1);
                //saisie du nom joueur2
                gotoxy(50, 7);
                printf("Entrez le nom du Joueur 2: ");
                scanf("%19s", joueur2);
                //effacement de l'écran
                system("cls");
                //dessin du cadre principal
                dessinerCadre(5, 2, 100, 27);

                 // Affichage des scores
                    gotoxy(13, 4);
                    dessinerCadre(8, 3, 12, 5);
                    gotoxy(14, 5);
                    printf("%d",score1);

                    gotoxy(86, 4);
                    dessinerCadre(90, 3, 12, 5);
                    gotoxy(96, 5);
                    printf("%d",score2);

                //Affichage des noms sous les scores
                gotoxy(10, 8);
                printf("%s", joueur1);
                gotoxy(92, 8);
                printf("%s", joueur2);
                dessinerCadre(21, 3, 68, 5);
                gotoxy(46, 8);
                printf("Grille de lettres");
                generer_grille_manuelle(grille);
                afficher_grille(grille);

                // Zone de propositions
                    dessinerCadre(27, 11, 58, 3);
                    gotoxy(46, 14);
                    printf("Zone de propositions");

                    // Zone d'affichage des propositions
                    dessinerCadre(27, 15, 58, 3);
                    dessinerCadre(27, 18, 58, 3);
                    gotoxy(43, 21);
                    printf("Zone d'affichage des propositions");

                    // Zone d'affichage de la proposition de l'ordinateur
                    dessinerCadre(27, 23, 58, 3);
                    gotoxy(43, 26);
                    printf("Affichage proposition de l'ordinateur\n");

                    //Empêchement de la fermeture
                gotoxy(43, 29);
                printf("Appuyez sur une touche pour quitter...");
                getchar();
                break;
            case 3:
                printf("Continuer!\n");
                getch();
                break;
            case 4:
                printf("Vous avez choisi de quitter. Au revoir!");
                break;
            default:
                printf("Choix invalide!");
                getch();
                break;
        }
        getch();
    } while (choix == 1 || choix == 2 || choix == 3);
    return 0;
}
