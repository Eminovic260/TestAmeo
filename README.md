# Test Technique C – Liste Chaînée

Ce projet implémente une liste chaînée générique capable de contenir :
- des chaînes de caractères (TYPE_STRING)
- des tableaux de mots (TYPE_WORDARRAY)

Fonctionnalités principales :
- Initialisation de la liste  
- Ajout de chaînes  
- Suppression d’un élément  
- Ajout de WordArray  
- Tri des WordArray par nombre de mots  
- Parcours et affichage  
- Libération complète de la mémoire

------------------------------------------------------------

Structure du projet

list.h     – Définition des structures et des prototypes  
list.c     – Implémentation des fonctions  
main.c     – Programme de démonstration  

Les autres fichiers proviennent de CLion/CMake et ne sont pas nécessaires.

------------------------------------------------------------

Compilation et exécution

Avec CLion, l’exécutable généré est :

cmake-build-debug/untitled

Exécution :

./cmake-build-debug/untitled

------------------------------------------------------------

Exemple de sortie exacte du programme :

Ajout de chaines simples
Chaine simple : Hello
Chaine simple : World
Chaine simple : Oui
Chaine simple : Test
NULL / fin de liste

Apres suppression de 'oui'
Chaine simple : Hello
Chaine simple : World
Chaine simple : Test
NULL / fin de liste

Apres ajout de WordArrays
WordArray, 4 mots : C est un test 
WordArray, 2 mots : Hellow World 
Chaine simple : Hello
Chaine simple : World
Chaine simple : Test
NULL / fin de liste

Apres tri par nombre de mots :
WordArray, 2 mots : Hellow World 
Chaine simple : Hello
Chaine simple : World
Chaine simple : Test
WordArray, 4 mots : C est un test 
NULL / fin de liste

Liberation de la liste
NULL / fin de liste

------------------------------------------------------------

Notes

- Le tri place correctement les WordArray du plus petit au plus grand nombre de mots.  
- Les chaînes simples restent ordonnées selon leur ordre d’insertion.  
- Le code est volontairement simple pour être expliqué facilement en entretien.

