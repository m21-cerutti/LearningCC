#ifndef MY_INPUT_H_INCLUDED
#define MY_INPUT_H_INCLUDED

#include "my_utilities/my_convert.h"

#include <iostream>

// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

using namespace std;

/** \namespace  myUtilities
*   Name spacing for standart input
*/
namespace myInput
{
	/********************************************/
	///Input_user

	/** \fn T get_std_input(T (*ptr_conversion)(string))
	*   \brief Template Fonction that take the input of the user and give to the standart template (int,float,etc...)
	*   \param ptr_conversion Pointer of the fonction which return in the result type and take a string to entry.
	*   \return the value of conversion string to template, if fail quit the program.
	*/
	template<typename T>
	T get_std_input ( T ( *ptr_conversion ) ( string ) )
	{
		string in;
		cin >> in;
		return  ptr_conversion ( in );
	}
	///For conversion with a Base
	template<typename T, int B = 10>
	T get_std_input ( T ( *ptr_conversion ) ( string, int ) )
	{
		string in;
		cin >> in;
		return  ptr_conversion ( in, B );
	}


	/** \fn T get_std_input_blocked(T (*ptr_conversion)(string))
	*   \brief Template Fonction that take the input of the user and give to the standart template (int,float,etc...)
	*   But it blocked the program while it's an unvalid input.
	*   \param ptr_conversion Pointer of the fonction which return in the result type and take a string to entry.
	*   \return the value of conversion string to template, if fail quit the program.
	*/
	template<typename T>
	T get_std_input_blocked ( T ( *ptr_conversion ) ( string ) )
	{
		bool valid = false;
		T obj;

		while ( !valid )
		{
			string in;
			cin >> in;

			try
			{
				obj = ptr_conversion ( in );
				valid = true;
			}
			catch ( std::exception const& e )
			{
				cerr << "ERROR : " << e.what() << endl;
				cerr << "Give an other value." << endl;
				valid = false;
			}
		}

		return  obj;
	}
	///For conversion with a Base
	template<typename T, int B = 10>
	T get_std_input_blocked ( T ( *ptr_conversion ) ( string, int ) )
	{
		bool valid = false;
		T obj;

		while ( !valid )
		{
			string in;
			cin >> in;

			try
			{
				obj = ptr_conversion ( in, B );
				valid = true;
			}
			catch ( std::exception const& e )
			{
				cerr << "ERROR : " << e.what() << endl;
				cerr << "Give an other value." << endl;
				valid = false;
			}
		}

		return  obj;
	}

	//END Input_user
	/********************************************/

	///Test functions of myInput.
	void Test();

}

#endif // MY_INPUT_H_INCLUDED
