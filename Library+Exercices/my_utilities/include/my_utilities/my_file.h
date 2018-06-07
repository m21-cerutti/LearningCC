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

	/**  \class ioFile
	*    \brief Class for valid input/output stream
	*/
	class ioFile
	{
		public:

			ioFile ( string file, bool app, bool ate, bool bin );
			ioFile ( char* file,  bool app, bool ate, bool bin );

			~ioFile();

			fstream& stream();
			bool is_valid_iostream ();

		private:

			string filename;                //Fichier du stream
			fstream p_stream;
	};

    /** \fn bool is_valid_stream(ofstream& stream);
	*       bool is_valid_stream ( ifstream& stream );
	*       bool is_valid_stream ( ioFile& stream );
	*   \brief Function that check if it's a valid stream.
	*   \param stream Stream to check.
	*   \return true if sucess, false else.
	*/
	bool is_valid_iostream (ioFile& stream);


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
		ofstream out;
		ios_base::openmode mode{ofstream::out};

		if ( app )mode = mode | ofstream::app;
		else mode = mode | ofstream::trunc;
		if ( ate )mode = mode | ofstream::ate;
		if ( binary )mode = mode | ofstream::binary;

		out.open ( file, mode );

		if (out.is_open)
		{
			out << obj <<endl;
		}
		else throw myError::Error ( myError::STREAM, __FILE__, __LINE__, "Fail to open file \"" +  file + "\"." );

        out.close();

		if ( ios::good )return;
		else throw myError::Error ( myError::STREAM, __FILE__, __LINE__, "Fail to write in the file \"" + file + "\"." );
	}

	template<typename T>
	void save ( char* file, T obj, bool app = false, bool ate = false, bool binary = false )
	{
		ofstream out;
		ios_base::openmode mode{ofstream::out};

		if ( app )mode = mode | ofstream::app;
		else mode = mode | ofstream::trunc;
		if ( ate )mode = mode | ofstream::ate;
		if ( binary )mode = mode | ofstream::binary;

		out.open ( file, mode );

		if ( out.is_open() )
		{
			out << obj <<endl;
		}
		else throw myError::Error ( myError::STREAM, __FILE__, __LINE__, "Fail to open file \"" + string ( file ) + "\"." );

        out.close();

		if ( ios::good )return;
		else throw myError::Error ( myError::STREAM, __FILE__, __LINE__, "Fail to write in the file \"" + string ( file ) + "\"." );
	}

	template<typename T>
	void save ( ofstream& out, T obj )
	{
		if ( out.is_open )
		{
			out << obj <<endl;
		}
		else throw myError::Error ( myError::STREAM, __FILE__, __LINE__, "The stream given is not open." );

        out.close();

		if ( ios::good )return;
		else throw myError::Error ( myError::STREAM, __FILE__, __LINE__, "Fail to write in the stream given." );
	}

	///Reading functions

	/** \fn string read (string file);
	*       string read (ofstream& file);
	*   \brief Function that return the content of the given file
	*   \param file String or Stream of the file to read.
	*   \return the content of the file, if fail throw an error.
	*/
	string read ( string file );
	string read ( char* file );
	string read ( ifstream& file );

	/***********************************************/

	///Test functions of myFile.

	void Test();
}

#endif // MY_FILE_H_INCLUDED
