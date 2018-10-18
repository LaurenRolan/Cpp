

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



