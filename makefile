# compilazione: programma a file multiplo
crittografia: main.o
	gcc -ansi -Wall -O main.o -o combinazioni
main.o: main.c combina.h
	gcc -ansi -Wall -O -c main.c
# la parte seguente funziona solo sulla bash di Linux
pulisci:
	rm -f *.o
pulisci_tutto:
	rm -f file combinazioni.exe *.o
