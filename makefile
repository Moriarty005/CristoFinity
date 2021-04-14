#This makefile has the different options as compiling the program.

compile: main.o CristoFinity.o media.o Comment.o Punctuation.o Film.o Series.o Videogame.o Song.o Administrator.o Normal.o User.o
	g++ main.o CristoFinity.o media.o Comment.o Punctuation.o Film.o Series.o Videogame.o Song.o User.o Normal.o Administrator.o -o yey

main.o: main.cpp Media.h Comment.h Punctuation.h Film.h Series.h Videogame.h Song.h User.h Normal.h Administrator.h
	g++ -c main.cpp Media.h Comment.h Punctuation.h Film.h Series.h Videogame.h Song.h User.h Normal.h Administrator.h

CristoFinity.o: CristoFinity.cpp CristoFinity.h
	g++ -c CristoFinity.cpp CristoFinity.h

media.o: media.cpp Media.h
	g++ -c media.cpp Media.h

Comment.o: Comment.cpp Comment.h
	g++ -c Comment.cpp Comment.h

Punctuation.o: Punctuation.cpp Punctuation.h
	g++ -c Punctuation.cpp Punctuation.h

Film.o: Film.cpp Film.h
	g++ -c Film.cpp Film.h

Series.o: Series.cpp Series.h
	g++ -c Series.cpp Series.h

Videogame.o: Videogame.cpp Videogame.h
	g++ -c Videogame.cpp Videogame.h

Song.o: Song.cpp Song.h
	g++ -c Song.cpp Song.h

User.o: User.cpp User.h
	g++ -c User.cpp User.h

Normal.o: Normal.cpp Normal.h
	g++ -c Normal.cpp Normal.h

Administrator.o: Administrator.cpp Administrator.h
	g++ -c Administrator.cpp Administrator.h

borrar:	main.o CristoFinity.o media.o Comment.o Punctuation.o Film.o Series.o Videogame.o Song.o Administrator.o Normal.o User.o
	rm -r *.o yey