/* Author: Lauren Sampaio
 * File: README.txt
 */
 
 --1-- Les iterateurs version STL
 (b) Iterateur sur ensemble d'entiers. Que remarquez vous?
     L'ordre d'insertion dans l'ensemble n'est pas respectée: chaque entier est positioné
	 d'accord sa valeur.
	 
 --2-- Taille et capacite d'un vecteur
 (Q) Qu'en deduisez  vous de la façon dont un vecteur est implementé?
     La capacite est toujours de 2^n elements. Alors qu'un élément en plus que
	 2^n est ajouté, la capacité du vecteur est augmenté à 2^(n+1).

 --5-- Tableau associatif et itérateur.
 (Q) Qu'en déduisez vous sur le fonctionnement de less<string>?
     Chaque lettre est comparée, et celle qui à la plus baisse valeur ASCII est
	 selectionnée en avance.

 (6.1)D'ailleurs, quelle est l'utilite du modele de fonction make_pair()?
     Il permettre la creation de pairs temporaires sans la necessité d'avoir
	 la specification des types.
     