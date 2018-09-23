/* @file: livres.cpp
   @author: Lauren Sampaio
*/
#include <iostream>
#include "../include/livres.h"
using namespace std;

void test23();
void test221();
void test243();
void test244();
void test3();

int main()
{
	int topic;
	cout << "Tapez le topic\n";
	cout << "2.2.1 ==> 221\t 2.3 ==> 23\n";
	cout << "2.4.3 ==> 243\t 2.4.4 ==> 244\n";
	cout << "3 ==> 3\n";
	cin >> topic;
	switch(topic)
	{
		case 221: test221(); break;
		case 23: test23(); break;
		case 243: test243(); break;
		case 244: test244(); break;
		case 3: test3(); break;
		default: cout << "Erreur\n";
	}
	
}

void test3()
{
	//echanger(creerLivre(), creerLivre());
}

void test244()
{
	int nLivres;
	cout << "Combien de livres pour le tableau?\t";
	cin >> nLivres; 
	Livre tableau[nLivres];
	remplirListe(tableau, nLivres);
	
	cout << "\nAvant la blague: \n";
	montrerTableau(tableau, nLivres);
	
	blagueBis(tableau, nLivres);
	
	cout << "\nApres la blague: \n";
	
	montrerTableau(tableau, nLivres);
	
}

void test243()
{
	int nLivres;
	cout << "Combien de livres pour le tableau?\t";
	cin >> nLivres; 
	Livre tableau[nLivres];
	remplirListe(tableau, nLivres);
	
	cout << "\nAvant la blague: \n";
	montrerTableau(tableau, nLivres);
	
	blague(tableau, nLivres);
	
	cout << "\nApres la blague: \n";
	
	montrerTableau(tableau, nLivres);
	
}
	
void test23()
{
	Livre livre;
	cout << "Creer un livre. \n";
	livre = creerLivre();
	montrerLivre(livre);
	
	cout << "Remplir un tableau.\n";
	Livre tableau[3];
	remplirListe(tableau, 3);
	montrerTableau(tableau, 3);
}

void test221()
{
	int nombre;
	int &ref = nombre;

	cout << "\nTest de la 1ere.\n Entrer avec un nombre:\t";
	nombre = litNombre();
	cout << nombre << endl;

	cout << "\nTest de la 2eme.\n Entrer avec un nombre:\t";
	litNombre(&nombre);
	cout << nombre << endl;

	cout << "\nTest de la 3eme.\n Entrer avec un nombre:\t";
	litNombre(nombre);
	cout << nombre << endl;

	cout << "\nTest de la 4eme.\n Entrer avec un nombre:\t";
	refer::litNombre(ref);
	cout << nombre << endl;

}