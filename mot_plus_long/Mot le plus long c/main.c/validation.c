intverifier_mot(char grille[], char mot[]) {
    int lettres[26] = {0};

    // Compter les lettres de la grille
    for (int i = 0; i < 9; i++) {
        lettres[grille[i] - 'A']++;
    }

    // Vérifier chaque lettre du mot
    for (int i = 0; mot[i] != '\0'; i++) {
        char c = mot[i];
        if (c < 'A' || c > 'Z' || lettres[c - 'A'] == 0) {
            return 0; // Lettre non présente ou épuisée
        }
        lettres[c - 'A']--;
    }
    return 1; // Mot valide
}
