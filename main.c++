#include <iostream>
#include <stdio.h>
#include <cstring>

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


void enregistrerReservation(Reservation *t, Reservation r, int n) {
    // Demander les informations de réservation
    cout << "Donner le numéro de la pièce d'identité : ";
    cin >> r.numeroPieceIdentite;

    cout << "Donner le nom : ";
    cin >> r.nom;

    cout << "Donner le prénom : ";
    cin >> r.prenom;

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

    // Ajouter la réservation au tableau
    t[n] = r;
}
bool rechercherReservation(Reservation * t, Reservation r){


}

void listerReservation(Reservation *t){

}

void TableauVersFichier(Reservation *t, int nombreReservations) {
    // Ouvrir le fichier en mode ajout (appending)
    FILE *fichier = fopen("reservation.txt", "a");

    if (fichier == NULL) {
        cout << "Impossible d'ouvrir le fichier !" << endl;
        return;
    }

    // Sauvegarder toutes les réservations dans le fichier
    for (int i = 0; i < nombreReservations; i++) {
        fprintf(fichier, "Réservation %d:\n", i + 1);
        fprintf(fichier, "Numéro Pièce d'Identité: %s\n", t[i].numeroPieceIdentite);
        fprintf(fichier, "Nom: %s\n", t[i].nom);
        fprintf(fichier, "Prénom: %s\n", t[i].prenom);
        fprintf(fichier, "Date de Naissance: %s\n", t[i].dateNaissance);
        fprintf(fichier, "Date de Départ: %s\n", t[i].dateDepart);
        fprintf(fichier, "Heure de Départ: %s\n", t[i].heureDepart);
        fprintf(fichier, "Gare de Départ: %s\n", t[i].gareDepart);
        fprintf(fichier, "Gare de Destination: %s\n", t[i].gareDestination);
        fprintf(fichier, "Classe: %s\n", t[i].classe);
        fprintf(fichier, "---------------------------\n");
    }

    // Fermer le fichier après l'écriture
    fclose(fichier);
}


void FichierVersTableau(){

}

int main (){
int choix;
do{
 system("cls");
 cout<<"\n";
 cout<<"\t\t\t\t\t\tRéservation TER du Baol \n\n\n";
 cout<<"\t\t===========================<<<<<<<<<<<----->>>>>>>>>>>============================\n\n";
 cout<<"\t\t||                                                                               || \n";
 cout<<"\t\t||  [1] : ==========<<<<<<<  Enregistrer une reservation     >>>>>>========      || \n";
 cout<<"\t\t||  [2] : ==========<<<<<<<  Rechercher une reservation      >>>>>>========      || \n";
 cout<<"\t\t||  [3] : ==========<<<<<<<  Lister toutes les reservations  >>>>>>========      || \n";
 cout<<"\t\t||  [4] : ==========<<<<<<<  Quitter                         >>>>>>========      || \n";
 cout<<"\t\t||                                                                               || \n";
 cout<<"\t\t============================<<<<<<<<<<----->>>>>>>>>>>===========================\n\n";
 cout<<"Veuillez faire votre choix : ";
cin >> choix;

    switch (choix){
            case 1 : 
                cout << "\t\t\tEnregistrer une reservation\n\n";
                int nombreReservations;
                cout << "Combien de réservations voulez-vous effectuer ? ";
                cin >> nombreReservations;
                    Reservation* t = new Reservation[nombreReservations];
                    for (int i = 0; i < nombreReservations; i++) {
                        cout << "\n--- Réservation " << i + 1 << " ---" << endl;
                        enregistrerReservation(t, t[i], i);
                        }
                        TableauVersFichier(t, nombreReservations);
                    break;
            case 2:
                cout << "Rechercher une réservation - Fonction non implémentée\n";
                break;

            case 3:
                cout << "Lister toutes les réservations - Fonction non implémentée\n";
                break;

            case 4:
                cout << "Quitter le programme.\n";
                break;

            default:
                cout << "Choix invalide. Essayez encore.\n";
        }

    } while (choix != 4);

    
        






 //int nombreReservations;

    // Demander le nombre de réservations à effectuer
  /*  cout << "Combien de réservations voulez-vous effectuer ? ";
    cin >> nombreReservations;

    // Créer un tableau dynamique pour stocker les réservations
    Reservation* t = new Reservation[nombreReservations];

    // Saisir et enregistrer les réservations
    for (int i = 0; i < nombreReservations; i++) {
        cout << "\n--- Réservation " << i + 1 << " ---" << endl;
        Reservation r;
        enregistrerReservation(t, r,i);
    }
    */
    return 0;
}