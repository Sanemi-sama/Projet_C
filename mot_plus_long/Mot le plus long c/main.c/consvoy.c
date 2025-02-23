char generer_consonne() {
    char consonnes[] = "BCDFGHJKLMNPQRSTVWXYZ";
    return consonnes[rand() % 21];
}

char generer_voyelle() {
    char voyelles[] = "AEIOUY";
    return voyelles[rand() % 6];
}

// Fonction pour générer une grille de 9 lettres
void generer_grille(char grille[]) {
    char choix;
    for (int i = 0; i < 9; i++) {
        printf("Choisissez C (Consonne) ou V (Voyelle) : ");
        scanf(" %c", &choix);
        if (choix == 'C' || choix == 'c') {
            grille[i] = generer_consonne();
        } else if (choix == 'V' || choix == 'v') {
            grille[i] = generer_voyelle();
        } else {
            printf("Choix invalide !\n");
            i--;
        }
    }
}
// Afficher la grille de lettres
void afficher_grille(char grille[]) {
    for (int i = 0; i < 9; i++) {
        printf("%c ", grille[i]);
    }
    printf("\n");
}

