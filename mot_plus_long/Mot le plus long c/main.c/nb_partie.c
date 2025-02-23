
int nb_parties, nb_parties;

// Fonction pour afficher le menu principal
void afficher_menu() {
    printf("=== Le Mot Le Plus Long ===\n");
    printf("1. Mode Solo (contre l'ordinateur)\n");
    printf("2. Mode 1v1 (deux joueurs)\n");
    printf("Choisissez un mode : ");
    scanf("%d", &nb_parties);
    
    while (nb_parties != 1 && nb_parties != 2) {
        printf("Choix invalide. Réessayez : ");
        scanf("%d", &nb_parties);
    }
}

// Fonction pour demander le nombre de parties
void demander_nb_parties() {
    printf("Combien de parties voulez-vous jouer ? ");
    scanf("%d", &nb_parties);
    while (nb_parties < 1) {
        printf("Erreur ! Le nombre de parties doit être >= 1 : ");
        scanf("%d", &nb_parties);
    }
}

int main() {
    afficher_menu();
    demander_nb_parties();
    printf("Mode : %d | Nombre de parties : %d\n",nb_parties, nb_parties);
    return 0;
}
