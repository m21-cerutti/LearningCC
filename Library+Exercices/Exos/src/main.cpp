#include <iostream>
#include <fstream>

#include "toolbox.h"

// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

using namespace std;




/********************************************//**
* \file main.cpp
* \brief Program
*
* \author Marc CERUTTI
* \version 0.1
* \date 19/05/2018
*
*   Program for
*
***********************************************/

typedef space_exos::Exercise exs;

static string str_exo_1
{
	"Calcul d'aire et perimetre d'un champ.\
\n      Prends les informations de l'utilisateur et calcule \
\n      l'aire et le périmètre.\
\n"
};

static int exo_1 ()
{
	float width;
	float height;
	cout << "Longueur : ";
	width = myInput::get_std_input_blocked ( myConvert::m_strtof );

	cout << "Largeur : ";
	height = myInput::get_std_input_blocked ( myConvert::m_strtof );

	cout << "\n";
	cout << "Aire : " << width* height << "\n";
	cout << "Perimetre : " << 2 * ( width + height ) << "\n";

	cout << "\n";

	return 0;
}

/***********************************************/

static string str_exo_2
{
	"Calcul moyenne de 5 chiffres\
\n      Prends les informations de l'utilisateur et calcule \
\n      la moyenne des 5 chiffres.\
\n"
};

static int exo_2 ()
{
	float somme;

	for ( int i = 0; i < 5; i++ )
	{
		cout << "chiffre " << i + 1 << " : ";
		somme += myInput::get_std_input_blocked ( myConvert::m_strtof );
	}

	cout << "\n";
	cout << "Moyenne : " << somme / 5 << "\n";
	cout << "\n";

	return 0;
}

/***********************************************/

static string str_exo_3
{
	"Écrire un programme qui demande à l'utilisateur de taper le prix HT d'un kilo de tomates, \
\n      le nombre de kilos de tomates achetés, le taux de TVA (Exemple 10%,20%,...).\
\n      Le programme affiche alors le prix TTC des marchandises.\
\n"
};

static int exo_3 ()
{
	double prix_HT;
	double nb_kilos;
	double TVA;
	cout << "le prix HT d'un kilo de tomates hors taxe : ";
	prix_HT = myInput::get_std_input_blocked ( myConvert::m_strtod );
	cout << "\n";

	cout << "Nombre de kilo : ";
	nb_kilos = myInput::get_std_input_blocked ( myConvert::m_strtod );
	cout << "\n";

	cout << "TVA en % : ";
	TVA = myInput::get_std_input_blocked ( myConvert::m_strtod );
	cout << "\n";

	cout << "Cout : " << prix_HT * nb_kilos * ( 1 + TVA / 100 ) << "\n";
	cout << "\n";

	return 0;
}

/***********************************************/

static string str_exo_4
{
	"Ecrire un programme qui écrit dans le fichier example.txt le texte:\
\n      Hello world!\
\n      Voici un programme illustrant l'écriture dans un fichier.\
\n"
};

static int exo_4 ()
{
	//#include <fstream>
	string save_text {"Hello world!\
	\nVoici un programme illustrant l'écriture dans un fichier."};



	return 0;
}


/***********************************************/

static string str_exo_5
{
	"Ecrire un programme qui lit dans le fichier example.txt\
\n      Si suite à exo_4 :\
\n      Hello world!\
\n      Voici un programme illustrant l'écriture dans un fichier.\
\n"
};

static int exo_5 ()
{
	//#include <fstream>
	string save_text {"Init"};

	return 0;
}

/********************************************//**
 * \fn Main function
 * \return EXIT_SUCCESS - Arrêt normal du programme.
 ***********************************************/
int main ( int argc, char* argv[] )
{
	//cout <<argc << argv[0]<<endl;
	//myError::Test();
	//myConvert::Test();
	//myInput::Test();
	myFile::Test();

	//space_exos::Test();

	//exs Exo_1 =  space_exos::Exercise ( str_exo_1, exo_1 );
	//Exo_1.Test();

	//exs Exo_2 = space_exos::Exercise ( str_exo_2, exo_2 );
	//Exo_2.Test();

	//exs Exo_3 = space_exos::Exercise ( str_exo_3, exo_3 );
	//Exo_3.Test();

	///exs Exo_4 = space_exos::Exercise ( str_exo_4, exo_4 );
	///Exo_4.Test();

	cout << "Number of exercises : " << exs::Numbers() << endl;

	system ( "PAUSE" );
	return EXIT_SUCCESS;
}

