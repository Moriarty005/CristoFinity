#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#define DEBUG "\033[1;31m"
#define USER "\033[1;34m"
#define RESTORE "\033[1;0m"
#define amarillo "\033[1;43m"
#define morado "\033[1;45m"
#define cyan "\033[1;46m"
#define verde "\033[1;42m"
#include "CristoFinity.h" 

using namespace std;

int main(){

cout << cyan << "Debug: entramos en el main" << RESTORE << endl;

	/*Media **vector_de_medias;
	vector_de_medias = new Media*[6];

	Media *multimedia;
	multimedia = new Media(1, "Avengers:Endgame", "Action", 183, "15-04-2019", 14, "towapatioestapelienverda", 30000, 10, 30000);

	Song *cansionsica;
	cansionsica = new Song(2, "supersonic rocket ship", "rock", 3, "1972", 4, "tabien", 123123, 5, 123123, "josegras", "dios nuestro señor");

	Videogame *jueguico;
	jueguico = new Videogame(3, "Minecraftt", "Survival", 123, "2009", 3, "wapisimo", 10000000, 8, 10000000, "Bethesda", "Bethesda", 567, "PS4, PC");

	Film *peliculica;
	peliculica = new Film(1, "Avengers:Endgame", "Action", 183, "15-04-2019", 14, "towapatioestapelienverda", 30000, 10, 30000, "Robert Downey Jr.", "nomeacuerrod", "Disney", "Disney");

	Series *seriesika;
	seriesika = new Series(4, "Elementary", "Police", 456, "2014", 18, "Best series ever", 12353, 10, 12353, "luvy Liu", "CBO", "CDO", "CDO", 7, 25, true);

	vector_de_medias[0] = cansionsica;

	vector_de_medias[1] = jueguico;

	vector_de_medias[2] = multimedia;

	vector_de_medias[3] = peliculica;

	vector_de_medias[4] = seriesika;


	for(int index = 0; index < 5; index++){

		cout << verde << "debug: celda por la que vamos: " << index << RESTORE << endl;
		vector_de_medias[index]->print();


	}

	Normal usuario_normal_de_prueba("JuaniKong", "Nietazo", "sucksItHard", "https://yey.com");

	usuario_normal_de_prueba.likeAMedia(peliculica);
	usuario_normal_de_prueba.likeAMedia(seriesika);
	usuario_normal_de_prueba.likeAMedia(multimedia);

	//usuario_normal_de_prueba.printUser();


	cout << cyan << "NOW WE ARE GOING TO DELTE A MEDIA LETS SEE IF ITS WORKS" << RESTORE << endl;

	usuario_normal_de_prueba.dislikeAMedia(1);

	usuario_normal_de_prueba.printUser();*/

	CristoFinity vista;


	vista.AddUserInVector();

	vista.changeUser();

	vista.MainMenu();
}