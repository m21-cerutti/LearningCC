#ifndef MY_ERROR_H_INCLUDED
#define MY_ERROR_H_INCLUDED

#include <iostream>
#include <exception>
#include <string>

using namespace std;


/** \namespace  myError
*   Name spacing for errors
*/
namespace myError
{

	/***********************************************/
	/** \enum error_type_enum
	*   \brief Constantes
	*.
	* Use for determine the type of error.
	*/

	enum error_type
	{
		USER = 1,
		CONVERSION,
		MEMORY,
		STREAM
	};

	string error_to_string ( error_type error );


	/***********************************************/
	/**  \class Error
	*    \brief Class for the errors
	*/
	class Error: public exception
	{
		public:

			Error ( error_type error, const char *file, int line, string options = "" ) throw();

			virtual ~Error() throw();

			virtual const char* what() const throw();

			int get_line() const throw();

			string get_file() const throw();

			int getCodeError() const throw();

		private:

			int m_num;                  //Numéro de l'erreur
			string m_messages;          //Message de l'erreur
			string m_file;              //Fichier de l'erreur
			int m_line;                 //Line de l'erreur

	};
	/***********************************************/

	///Test functions of myError.
	void Test();
}



#endif // MY_ERROR_H_INCLUDED
