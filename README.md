# Multi-platform-Development
Abordare generala: 
-----------------
Am folosit o lista simplu inlantuita. Pentru operatia de insert am impartit cazurile de inserare a unui nou
element in lista in 3: cazul in care elementul are cea mai mare prioritate si este primul din lista, cazul in
care elementul are cea mai mica prioritate, parcurgem lista si il inseram ultimul in lista si cazul in care nu
este primul sau ultimul. In acest caz parcurgem lista pana gasim o prioritate mai mica decat a elementului
curent, in acel loc retinem in p elementul precedent al listei si in c elementul urmator si intai avem 
nod->urm = c, ceea ce inseamna ca legam nodul curent de c, apoi p->urm = nod ceea ce leaga nodul precedent p 
de nodul curent. Top returneaza primul element, iar pop il elimina si in pop fac free pe spatiul pe care il ocupa. In main daca avem argumente in linia de comanda luam in considerare doar fisierele existente din care
citim linie cu linie si verificam daca linia respectiva reprezinta o comanda valida. Pentru insert se verifica 
daca linia contine 2 spatii si daca primul cuvant este insert urmat de spatiu (nu am verificat validitatea
numelui desi de obicei este necesar, intrucat in enunt se specifica faptul ca numele sunt valide). Am despartit
linia in cuvinte si am apelat functia insert. Similar am facut si pentru in cazul in care nu sunt argumente
in linia de comanda si se citeste de la tastatura.

Dupa parerea mea tema este utila pentru ca ordonarea in functie de prioritati se gaseste in realitate in tot
felul de situatii. Spre exemplu atunci cand comanzi un tort, probabil cofetaria ordoneaza prioritatile in 
functie de termenele de finalizare ale comenzilor. 

Cred ca implementarea este medie, se putea mai bine.

Am intampinat dificultati la functia de insert intrucat greseam cand puneam legaturile dintre noduri. Am gresit
de asemenea makefile-ul pentru windows intrucat incurcam ordinea parametrilor la build.

Pentru build folosim gcc pe Linux si cl pe Windows. Se linkeaza biblioteca compare.lib pe Windows, rulam cu flag-ul pentru warning-uril /W3 si cu /D_CRT_SECURE_NO_DEPRECATE pentru a nu fi nevoie sa folosim s_strcpy() in loc de
strcpy(), spre exemplu. Ambele makefile-uri au reguli de build si clean.

Executabilul se poate rula cu argumente(fisiere din care se citeste daca exista) sau fara(se citeste de la tastatura).

Am folosit laboratorul 1 de SO, niste laboratoare de structuri de date care erau pe cs.curs in 2017 (acum 
nu ma mai pot loga acolo) si alte cateva resurse pentru rezolvarea unor nelamuriri minore.
