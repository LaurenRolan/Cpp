/* @file: livres.cpp
   @author: Lauren Sampaio
*/
struct Livre {
	int pages;
	char titre[50];
};

Livre creerLivre();
Livre* creerLivreP();
Livre* plusLong(Livre tableau[], int taille);
Livre* plusCourt(Livre tableau[], int taille);

void remplirListe(Livre tableau[], int taille);
void montrerLivre(Livre livre);
void montrerTableau(Livre tableau[], int taille);
void echanger(Livre *un, Livre *deux);
void blague(Livre tableau[], int taille);
void blagueBis(Livre tableau[], int taille);

int litNombre();
int litNombre(int *nombre);
int litNombre(int nombre);

namespace refer {
	int litNombre(int &nombre);
}
