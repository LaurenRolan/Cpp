/* @file: livres.cpp
   @author: Lauren Sampaio
*/

#include <iostream>
#include "../include/livres.h"

int litNombre()
{
	int nombre;
	std::cin >> nombre;
	if(nombre >= 2 && nombre <= 2000)
		return nombre;
	std::cout << "Nombre de pages irreguliere.\n";
	return -1;
}

int litNombre(int *nombre)
{
	int temp;
	std::cin >> temp;
	if(temp >= 2 && temp <= 2000)
	{
		*nombre = temp;
		return temp;
	}
	std::cout << "Nombre de pages irreguliere.\n";
	return temp;
	
}

int litNombre(int nombre)
{
	int temp;
	std::cin >> temp;
	if(temp >= 2 && temp <= 2000)
	{
		nombre = temp;
		return nombre;
	}
	std::cout << "Nombre de pages irreguliere.\n";
	return temp;
}

int refer::litNombre(int & nombre)
{
	int temp;
	std::cin >> temp;
	if(temp >= 2 && temp <= 2000)
	{
		nombre = temp;
		return nombre;
	}
	std::cout << "Nombre de pages irreguliere.\n";
	return temp;
}	

Livre creerLivre()
{
	Livre livre;
	std::cout << "Nombre de pages: \t";
	livre.pages = litNombre();

	std::cout << "Titre: \t";
	std::cin >> livre.titre;

	return livre;
}

void remplirListe(Livre tableau[], int taille)
{
	for(int i = 0; i < taille; i++)
	{
		std::cout << "\nLivre numero " << i + 1 << std::endl;
 		tableau[i] = creerLivre();
	}
}

void montrerLivre(Livre livre)
{
	std::cout << livre.titre << " a " << livre.pages << " pages" << std::endl;
}

void montrerTableau(Livre tableau[], int taille)
{
	for(int i = 0; i < taille; i++)
	{
		std::cout << "\nLivre numero " << i + 1 << std::endl;
 		std::cout << "\t" << tableau[i].titre << " a " << tableau[i].pages << " pages" << std::endl;
	}
}

void echanger(Livre *un, Livre *deux)
{
	int temp = un->pages;
	un->pages = deux->pages;
	deux->pages = temp;
}


Livre* plusLong(Livre tableau[], int taille)
{
	Livre *temp = &tableau[0];
	for(int i = 1; i < taille; i++)
	{
		if(tableau[i].pages > temp->pages)
			temp = &tableau[i];
	}
	return temp;
}

Livre* plusCourt(Livre tableau[], int taille)
{
	Livre *temp = &tableau[0];
	for(int i = 1; i < taille; i++)
	{
		if(tableau[i].pages < temp->pages)
			temp = &tableau[i];
	}
	return temp;
}

void blague(Livre tableau[], int taille)
{
	echanger(plusCourt(tableau, taille), plusLong(tableau, taille));
}
void blagueBis(Livre tableau[], int taille)
{
	Livre *leLong;
	Livre *leCourt;
	leLong = plusLong(tableau, taille);
	leCourt = plusCourt(tableau, taille);
	echanger(leLong, leCourt);
}