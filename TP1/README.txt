----------------Question 1----------------
a) x vaut 3.0

b) 	Ligne 6 - une réference à la variable x est créée avec le nom "r";
	Ligne 7 - "r" passe à réferencéer la variable y;
	Ligne 8 - on essaye de réferencéer une constante, mais c'est pas possible. Donc, "r" continue à réferencéer "y".

----------------Question 2----------------
2.2.1
a) Le compilateur indique que il y a une ambiguité entre la fonction qui receve pour valeur et pour référence. C'est en fait la même forme de fonction, puis la référence n'est qu'un alias pour une variable.

b) Avec le espace de noms, on peut specifiquer quel est la fonction choisi.

----------------Question 3----------------
L'erreur obtenu est 
---
error: cannot convert ‘Livre’ to ‘Livre*’ for argument ‘1’ to ‘void echanger(Livre*, Livre*)’
---
Ça occurs parce que la fonction creerLivre() -- ou lireLivre() -- retourne un instance en place d'un pointeur, alors que la fonction echanger() -- ou echangerPages() -- prend comme argument des pointeurs.

Si la fonction creerLivre() retournait l'adresse d'une variable créée dans cette fonction, ça provocait un warning -- le retourne de l'adresse d'une variable locale.

----------------Question 4----------------
-----Fonction "porte logique"-----
---Mais si cette variable est déclarée static, alors cela devient possible (Pourquoi ?)---
Parce que la variable static n'est pas dans la pille, mais dans la mémoire statique du programme; si c'était dans la pille, à la fin de la fonction, cette variable serait perdu. Comme c'est statique, elle dure à la fin du programme.

-----Surcharge et espaces de noms-----
a) Compilez ce programme. Justifiez le message d'erreur du compilateur.
Le message d'erreur est
---
error: invalid initialization of reference of type ‘double&’ from expression of type ‘double*’
---
Cela occurs parce que sur la ligne 39 la seule fonction que le compilateur connaît dans l'espace de nom MaLib utilise une référence comme argument, et pas un pointeur.

b) Pourquoi l'ajout entre les lignes 18 et 19 de la using-declaration résoult-il le problème?
Parce que la using-declaration "importe" la fonction du namespace global dans le namespace MaLib. Donc, le compilateur a la option de choisir entre la fonction local (MaLib::appliqueTVA()), que ne marche pas avec un pointeur, ou la fonction global (::appliqueTVA()), que utilise une référence.
