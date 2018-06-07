#include "my_utilities/my_error.h"

using namespace std;



/***********************************************/


string myError::error_to_string ( error_type error )
{
	switch ( error )
	{
		case MEMORY:
			return "MEMORY";

		case CONVERSION:
			return "CONVERSION";

		case USER:
			return "USER";

        case STREAM:
			return "STREAM";

	}

	return "UNKNOW";
}

/********************************************/
//Error class functions

myError::Error::Error ( error_type error, const char *file, int line, string options ) throw()
	: m_num ( ( int ) ( error ) ), m_file ( file ), m_line ( line )
{
	m_messages = error_to_string ( error ) + " error type.\n" + options + "\n(" + string ( file ) + "," + to_string ( line ) + ")";
}

myError::Error::~Error() throw()
{}

const char* myError::Error::what() const throw()
{
	return m_messages.c_str();
}

int myError::Error::getCodeError() const throw()
{
	return m_num;
}

int myError::Error::get_line() const throw()
{
	return m_line;
}

string myError::Error::get_file() const throw()
{
	return m_file;
}


//END Error class functions
/********************************************/
void myError::Test()
{
	using namespace myError;
	cout << "Test myError" << endl;
	Error e = Error ( USER, __FILE__, __LINE__, "options." );
	cout << "Test Error.what()" << endl;
	cout << e.what() << endl;
	cout << "Test Error.get_line()" << endl;
	cout << e.get_line() << endl;
	cout << "Test Error.get_file()" << endl;
	cout << e.get_file() << endl;
	cout << "Test Error.getNumberError()" << endl;
	cout << e.getCodeError() << endl;
	cout <<  endl;
	return;
}

//END
/***********************************************/

