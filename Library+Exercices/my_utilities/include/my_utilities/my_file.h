#ifndef MY_FILE_H_INCLUDED
#define MY_FILE_H_INCLUDED

#include <math.h>

#include <cerrno>
#include <string>
#include <fstream>

#include "my_utilities/my_error.h"

using namespace std;

/** \namespace  myUtilities
*   Name spacing for standart saving file
*/
namespace myFile
{

	/**  \class inFile
	*    \brief Class for valid input stream
	*/
	class inFile : public ifstream
	{
		public:

			inFile ( string file );
			inFile ( char* file );

			~inFile();

		private:

			string filename;                //Fichier du stream
	};

	/**  \class outFile
	*    \brief Class for valid output stream
	*/
	class outFile : public ofstream
	{
		public:

			outFile ( string file, bool app, bool ate, bool binary );
			outFile ( char* file,  bool app, bool ate, bool binary );

			~outFile();

		private:

			string filename;                //Fichier du stream
	};


	/***********************************************/
	///Saving functions

	/** \fn T get_std_input(T (*ptr_conversion)(string))
	*   \brief Template Fonction that save an object in a given file.
	*   \param file String or Char* or Stream of the file to save.
	*   \param object The object to save in the file.
	*   \return if fail, throw an error.
	*/
	template<typename T>
	void save ( string file, T obj, bool app = false, bool ate = false, bool binary = false )
	{
		outFile out ( file, app, ate, binary );
        out << obj << endl;
        out.close();

		if ( ios::good )return;
		else throw myError::Error ( myError::STREAM, __FILE__, __LINE__, "Fail to write in the file \"" + file + "\"." );
	}

	template<typename T>
	void save ( char* file, T obj, bool app = false, bool ate = false, bool binary = false )
	{
		outFile out ( file, app, ate, binary );
        out << obj << endl;
        out.close();

		if ( ios::good )return;
		else throw myError::Error ( myError::STREAM, __FILE__, __LINE__, "Fail to write in the file \"" + string ( file ) + "\"." );
	}

	template<typename T>
	void save ( ofstream& out, T obj )
	{
		if ( out.is_open() )
		{
			out << obj << endl;
		}
		else throw myError::Error ( myError::STREAM, __FILE__, __LINE__, "The stream given to write is not open." );

		if ( ios::good )return;
		else throw myError::Error ( myError::STREAM, __FILE__, __LINE__, "Fail to write in the stream given." );
	}

	template<typename T>
	void save ( outFile& out, T obj )
	{
		if ( out.is_open() )
		{
			out << obj << endl;
		}
		else throw myError::Error ( myError::STREAM, __FILE__, __LINE__, "The stream given to write is not open." );

		if ( ios::good )return;
		else throw myError::Error ( myError::STREAM, __FILE__, __LINE__, "Fail to write in the stream given." );
	}

	///Reading functions

	/** \fn string read ( string file, bool del, bool binary );
    *       string read ( char* file, bool del, bool binary );
    *       string read ( ifstream& file );;
	*   \brief Function that return the content of the given file
	*   \param file String, Char* or Stream of the file to read.
	*   \return the content of the file, if fail throw an error.
	*/
	string read ( string file, bool del, bool binary );
	string read ( char* file, bool del, bool binary );
	string read ( ifstream& file );
	string read ( inFile& file );

    /** \fn void replace_char (string file, char from, char to);
    *       void replace_char (char* file, char from, char to);
    *       void replace_char ( ifstream& file );
	*   \brief Function that replace the character "from" to "to" of the given file
	*   \param file String or Stream of the file to read.
	*   \param from Char character to replace.
	*   \param to Char the final character.
	*   \return if fail throw an error.
	*/
    void replace_char (string file, char from, char to);
    void replace_char (char* file, char from, char to);

	/***********************************************/

	///Test functions of myFile.

	void Test();
}

#endif // MY_FILE_H_INCLUDED
