#include "toolbox.h"

#include <iostream>
#include <fstream>


/********************************************/
//space_exos


/********************************************/
//class Exercise

typedef space_exos::Exercise exs;

int exs::number = 0;

exs::Exercise ( string resume, ptr_code code )
	: consignes ( resume ), exo_code ( code )
{
	number = id = Numbers() + 1;
}


exs::Exercise ( float alias, string resume, ptr_code code )
	: id ( alias ), consignes ( resume ), exo_code ( code )
{
	if ( myConvert::f_isInteger ( alias ) )
	{
		number = Numbers() + 1;
	}
}

exs::~Exercise()
{}

void exs::Test()
{
	cout << "Exercice " << ( int ) ( id ) << "v" << 1 + myConvert::f_decimal ( id ) << " :\n";
	cout << consignes << "\n";

	try
	{
		int result = exo_code();

		if ( result != 0 )
		{
			throw myError::Error ( ( myError::error_type ) ( result ), __FILE__, __LINE__ );
		}

		cout << "result : " << result << "\n" << "\n";
	}
	catch ( std::exception const& e )
	{
		cerr << "ERROR : " << e.what() << endl;
		system ( "PAUSE" );
		exit ( EXIT_FAILURE );
	}
}

//END class Exercise
/********************************************/
//Test

///Fonctions for testing the space
static string str_exo_0
{
	"Creation of exercice\
\n      return 0 sucess case.\
\n  Else see the documentation of my_error personnal library.\
\n"
};

static int exo_0 ()
{
	return 0;
}

//Uncomment to test error case
/*
static string str_exo_0_2{
"Creation of wrong exercice\
\n      return 0 sucess case.\
\n  Else see the documentation of my_error personnal library.\
\n"
};
static int exo_0_2 (){
    return 1;
}
*/

void space_exos::Test ()
{
	cout <<
	     R"(Use of the space :
The number of the exercises increase automatically when you instantiate exercises, however you can put a version
like 1.2 or anyting with a float id. See the documentation for more explanations.

    code of example:

#include <iostream>
#include <fstream>

#include "toolbox.h"

using namespace std;
typedef space_exos::Exercise exs;

string str_exo_0{
"Creation of exercice\
\n      return 0 sucess case.\
\n  Else see the documentation of my_error personnal library.\
\n"
};

int exo_0 (){
    return 0;
}

string str_exo_0_2{
"Creation of wrong exercice\
\n      return 0 sucess case.\
\n  Else see the documentation of my_error personnal library.\
\n"
};

int exo_0_2 (){
    return 1;
}
int main()
{
    exs Exo_1 = space_exos::Exercise(str_exo_0, exo_0);
    Exo_1.Test();

    exs Exo_1_2 = space_exos::Exercise(1.2,str_exo_0, exo_0);
    Exo_1_2.Test();

    exs Exo_2 = space_exos::Exercise(2,str_exo_0, exo_0);
    Exo_2.Test();

    //Uncomment to test error case
    /*
    exs Exo_3 = space_exos::Exercise(str_exo_0_2, exo_0_2);
    Exo_3.Test();
    */

    cout << "Number of exercises : " <<exs::Numbers()<<endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}

)";

    exs Exo_1 = space_exos::Exercise(str_exo_0, exo_0);
    Exo_1.Test();

    exs Exo_1_2 = space_exos::Exercise(1.2,str_exo_0, exo_0);
    Exo_1_2.Test();

    exs Exo_2 = space_exos::Exercise(2,str_exo_0, exo_0);
    Exo_2.Test();

    //Uncomment to test error case
    /*
    exs Exo_3 = space_exos::Exercise(str_exo_0_2, exo_0_2);
    Exo_3.Test();
    */
}
//END Test
/***********************************************/


//END space_exos
/********************************************/

