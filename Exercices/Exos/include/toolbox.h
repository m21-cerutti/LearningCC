#ifndef TOOLBOX_H_INCLUDED
#define TOOLBOX_H_INCLUDED

#include <iostream>
#include <fstream>

// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

#include "my_utilities/my_convert.h"
#include "my_utilities/my_error.h"
#include "my_utilities/my_input.h"
#include "my_utilities/my_file.h"

using namespace std;

/** \namespace  space_exos
*   Name spacing for exercises in c++
*/
namespace space_exos
{
	typedef int ( *ptr_code ) ( void );

	/**  \class Exercise
	*    \brief Class
	*    Use for create exercise and manage their index and testing.
	*/
	class Exercise
	{
		public:
			/** \brief Constructor
			*   \param consignes String, the resume of what are done in the exercise
			*   \param code {int(*ptr_code)(void)}, the fonction of the exercise
			*   \param alias Optional Float, use to override the index, use for versionning.
			*   Be carefull, don't put integers or it can cause logical conflict with no errors.
			*/
			Exercise ( string consignes, ptr_code code );
			Exercise ( float alias, string consignes, ptr_code code );

			/**  \brief Destructor
			*/
			~Exercise();


			/** \fn void Test()
			*    \brief Fonction that formats the output of the exercise's function.
			*    The errors are catch by a standart try, throw, catch exception.
			*/
			void Test();

			/**  \fn int static Numbers()
			*    \brief Fonction
			*    \return the actual number of exercise instantiate.
			*/
			int static Numbers()
			{
				return number;
			}

		private:
			///Automatic number of exercises
			static int number;

			///The number of the exercise
			float id;

			///The resume of exercise
			string consignes;

			///Pointer of the code fonction, int(code*)()
			ptr_code exo_code;

	};

	///Test the initialisation od exercises and the use.
	void Test();

}



#endif // TOOLBOX_H_INCLUDED
