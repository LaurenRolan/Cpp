/* Author: Lauren Sampaio
 * File: README.txt
 */
 
*****1 Classe Matrix*****
-- Q -- Quelle règle de base en programmation orientée objet est dans une certaine mesure transgressée ici?
-- R --La règle transgressée ici est l'encapsulation: si quelqu'un utilise la fonction m[0], pour une instance m de la classe Matrix, il peut acceder au contenu de _data, que doit être privé.

*****2 Construction et affectation par déplacement*****

Avant l'insertion de la flag
do=Matrix(0, 0)
// Relatif à la attribuition de "a * b" vers "c"

Après l'insertion de la flag
dddMatrix(0, 0) //Deplacement du résultat "a * b" vers une variable temporaire
dddMatrix(0, 0) //Deplacement du résultat "a * b" vers "d"
dddMatrix(0, 0) //Deplacement du résultat "a * b" vers une variable temporaire
do=Matrix(0, 0) //Atribuition de la variable temporaire dernière sur "c"
dddMatrix(0, 0) //Deplacement du résultat "c * c" vers une variable temporaire
dddMatrix(0, 0) //Deplacement de la variable temporaire sur les paramétres de "foo"

Comparaison
Quand on analyse les traces génerales des deux programmes, on peut déduire que la flag donne priorité à création d'instances pour deplacement que pour création d'une matrice vide.

*****3 Inversion d'une matrice*****
/* Counter = 1 + Nrows² */
Inverse of A(2, 2)  
Counter = 5          

/* Counter = 1 + Nrows + Nrows² */
Inverse of A(3, 3) 
Counter = 13

/* Counter = 1 + Nrows² + Nrows^3 */
Inverse of A(4, 4) 
Counter = 81

/* Counter = 1 + */
Inverse of A(5, 5)
Counter = 511

Inverse of A(6, 6)
Counter = 3613

Inverse of A(7, 7)
Counter = 28953

Inverse of A(8, 8)
Counter = 260641

Inverse of A(9, 9)
Counter = 2606491





