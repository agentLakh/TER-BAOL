#include <iostream>
#include <stdio.h>
#include <cstring>
#include <fstream>

using namespace std;

typedef struct{
    char numeroPieceIdentite[15]; // Numéro de la pièce d'identité
    char prenom[30];             // Prénom
    char nom[30];                // Nom
    char dateNaissance[10];      // Date de naissance (format JJ/MM/AAAA)
    char dateDepart[10];         // Date de départ (format JJ/MM/AAAA)
    char heureDepart[10];        // Heure de départ (format HH:MM)
    char gareDepart[20];         // Gare de départ
    char gareDestination[20];    // Gare de destination
    char classe[15];             // Classe (ex: "Économique", "Première")
} Reservation;

void enregistrerReservation(Reservation &r) {
    // Demander les informations de réservation

    cout << "Donner le nom : ";
    cin >> r.nom;

    cout << "Donner le prénom : ";
    cin >> r.prenom;

    cout << "Donner le numéro de la pièce d'identité : ";
    cin >> r.numeroPieceIdentite;

    cout << "Donner la date de naissance (JJ/MM/AAAA) : ";
    cin >> r.dateNaissance;

    cout << "Donner la date de départ (JJ/MM/AAAA) : ";
    cin >> r.dateDepart;

    cout << "Donner l'heure de départ (HH:MM) : ";
    cin >> r.heureDepart;

    cout << "Donner la gare de départ : ";
    cin >> r.gareDepart;

    cout << "Donner la gare de destination : ";
    cin >> r.gareDestination;

    cout << "Donner la classe (Ex: Économique, Première) : ";
    cin >> r.classe;
}

bool rechercherReservation(Reservation *t, int taille, Reservation r) {
    for (int i = 0; i < taille; i++) {
        if (strcmp(t[i].numeroPieceIdentite, r.numeroPieceIdentite) == 0) {
            cout << "Réservation trouvée :\n";
            cout << "Nom : " << t[i].nom << endl;
            cout << "Prénom : " << t[i].prenom << endl;
            cout << "Numéro de pièce d'identité : " << t[i].numeroPieceIdentite << endl;
            cout << "Date de naissance : " << t[i].dateNaissance << endl;
            cout << "Date de départ : " << t[i].dateDepart << endl;
            cout << "Heure de départ : " << t[i].heureDepart << endl;
            cout << "Gare de départ : " << t[i].gareDepart << endl;
            cout << "Gare de destination : " << t[i].gareDestination << endl;
            cout << "Classe : " << t[i].classe << endl;
            return true;
        }
    }
    cout << "Réservation non trouvée.\n";
    return false;
}

void listerReservation(Reservation *t, int taille) {
    if (taille == 0) {
        cout << "Aucune réservation disponible.\n";
        return;
    }
    for (int i = 0; i < taille; i++) {
        cout << "\nRéservation " << i + 1 << " :\n";
        cout << "Nom : " << t[i].nom << endl;
        cout << "Prénom : " << t[i].prenom << endl;
        cout << "Numéro de pièce d'identité : " << t[i].numeroPieceIdentite << endl;
        cout << "Date de naissance : " << t[i].dateNaissance << endl;
        cout << "Date de départ : " << t[i].dateDepart << endl;
        cout << "Heure de départ : " << t[i].heureDepart << endl;
        cout << "Gare de départ : " << t[i].gareDepart << endl;
        cout << "Gare de destination : " << t[i].gareDestination << endl;
        cout << "Classe : " << t[i].classe << endl;
    }
}

void TableauVersFichier(Reservation r) {
    ofstream reser("reservation.txt", ios::app);
    if (reser) {
        reser << "Prenom : " << r.prenom << endl;
        reser << "Nom : " << r.nom << endl;
        reser << "Numéro Pièce d'Identité : " << r.numeroPieceIdentite << endl;
        reser << "Date de Naissance : " << r.dateNaissance << endl;
        reser << "Date de depart : " << r.dateDepart << endl;
        reser << "Heure de Départ : " << r.heureDepart << endl;
        reser << "Gare de Départ : " << r.gareDepart << endl;
        reser << "Gare de destination : " << r.gareDestination << endl;
        reser << "Classe : " << r.classe << endl;
        reser << "----------------------------------" << endl;
    } else {
        cout << "Erreur lors de la création du fichier de réservation.\n";
    }
}

void FichierVersTableau() {
    ifstream reser("reservation.txt");
    if (!reser) {
        cout << "Erreur : Impossible d'ouvrir le fichier des réservations.\n";
        return;
    }
    string ligne;
    while (getline(reser, ligne)) {
        cout << ligne << endl;
    }
}

int main() {
    int choix;
    Reservation r1;
    Reservation reservations[100];
    int compteurReservations = 0;

    do {
        system("");
        cout << "\n";
        cout << "\t\t\t\t\tRéservation TER du Baol \n\n\n";
        cout << "\t\t===========================<<<<<<<<<<<----->>>>>>>>>>>============================\n\n";
        cout << "\t\t||                                                                               || \n";
        cout << "\t\t||  [1] : ==========<<<<<<<  Enregistrer une reservation     >>>>>>========      || \n";
        cout << "\t\t||  [2] : ==========<<<<<<<  Rechercher une reservation      >>>>>>========      || \n";
        cout << "\t\t||  [3] : ==========<<<<<<<  Lister toutes les reservations  >>>>>>========      || \n";
        cout << "\t\t||  [4] : ==========<<<<<<<  Quitter                         >>>>>>========      || \n";
        cout << "\t\t||                                                                               || \n";
        cout << "\t\t============================<<<<<<<<<<----->>>>>>>>>>>===========================\n\n";
        cout << "Veuillez faire votre choix : ";
        cin >> choix;

        switch (choix) {
            case 1:
                cout << "Enregistrer une reservation. \n";
                enregistrerReservation(r1);
                reservations[compteurReservations++] = r1;
                TableauVersFichier(r1);
                break;
            case 2:
                cout << "Rechercher une réservation. \n";
                cout << "Entrez le numéro de pièce d'identité à rechercher : ";
                cin >> r1.numeroPieceIdentite;
                rechercherReservation(reservations, compteurReservations, r1);
                break;
            case 3:
                cout << "Lister toutes les réservations. \n";
                listerReservation(reservations, compteurReservations);
                break;
            case 4:
                cout << "Quitter le programme.\n";
                break;
            default:
                cout << "Choix invalide. Essayez encore.\n";
        }

    } while (choix != 4);

    return 0;
}
