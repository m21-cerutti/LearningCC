#include "my_utilities/my_convert.h"

using namespace std;


/********************************************/
///Convert

long int myConvert::m_strtol ( string str, int base = 0 )
{
	long int i;
	size_t endptr {0};

	try
	{
		i = stol ( str.c_str(), & ( endptr ), base );

	}
	catch ( std::exception const& e )
	{
		throw myError::Error ( myError::CONVERSION, __FILE__, __LINE__, "character(\"" + string ( 1, str.at ( endptr ) ) + "\") on \"" + str + "\" is not a integer number." );
	}

	if ( str.size() != endptr )
	{
		throw myError::Error ( myError::CONVERSION, __FILE__, __LINE__,  "character(\"" + string ( 1, str.at ( endptr ) ) + "\") on \"" + str + "\" is not a integer number." );
	}

	if ( errno )
	{
		throw myError::Error ( myError::CONVERSION, __FILE__, __LINE__, "\"" + str + "\" is a too big number." );
	}

	return i;
}

unsigned long int myConvert::m_strtoul ( string str, int base = 0 )
{
	unsigned long int i;
	size_t endptr {0};

	try
	{
		i = stoul ( str.c_str(), & ( endptr ), base );
	}
	catch ( std::exception const& e )
	{
		throw myError::Error ( myError::CONVERSION, __FILE__, __LINE__, "character(\"" + string ( 1, str.at ( endptr ) ) + "\") on \"" + str + "\" is not a unsigned integer number." );
	}

	if ( str.size() != endptr )
	{
		throw myError::Error ( myError::CONVERSION, __FILE__, __LINE__, "character(\"" + string ( 1, str.at ( endptr ) ) + "\") on \"" + str + "\" is not a unsigned integer number." );
	}

	if ( errno )
	{
		throw myError::Error ( myError::CONVERSION, __FILE__, __LINE__, "\"" + str + "\" is a too big number." );
	}

	return i;
}

float myConvert::m_strtof ( string str )
{
	float f;
	size_t endptr {0};

	try
	{
		f = stof ( str.c_str(), & ( endptr ) );
	}
	catch ( std::exception const& e )
	{
		throw myError::Error ( myError::CONVERSION, __FILE__, __LINE__, "character(\"" + string ( 1, str.at ( endptr ) ) + "\") on \"" + str + "\" is not a floating number." );
	}

	if ( str.size() != endptr )
	{
		throw myError::Error ( myError::CONVERSION, __FILE__, __LINE__, "character(\"" + string ( 1, str.at ( endptr ) ) + "\") on \"" + str + "\" is not a floating number." );
	}

	if ( errno )
	{
		throw myError::Error ( myError::CONVERSION, __FILE__, __LINE__, "\"" + str + "\" is a too big number." );
	}

	return f;
}

double myConvert::m_strtod ( string str )
{
	double d;
	size_t endptr {0};

	try
	{
		d = stod ( str.c_str(), & ( endptr ) );
	}
	catch ( std::exception const& e )
	{
		throw myError::Error ( myError::CONVERSION, __FILE__, __LINE__, "character(\"" + string ( 1, str.at ( endptr ) ) + "\") on \"" + str + "\" is not a double number." );
	}

	if ( str.size() != endptr )
	{
		throw myError::Error ( myError::CONVERSION, __FILE__, __LINE__, "character(\"" + string ( 1, str.at ( endptr ) ) + "\") on \"" + str + "\" is not a double number." );
	}

	if ( errno )
	{
		throw myError::Error ( myError::CONVERSION, __FILE__, __LINE__, "\"" + str + "\" is a too big number." );
	}

	return d;
}

/***********************************************/

bool myConvert::f_isInteger ( float f )
{
	return ( f - floor ( f ) == 0 );
}

float myConvert::f_decimal ( float f )
{
	return f - floor ( f );
}

/***********************************************/

void myConvert::Test()
{
	using namespace myConvert;

    cout << "Test myConvert" << endl;
	int base = 10;
	cout << m_strtol ( "123", base ) << endl;
	cout << m_strtoul ( "123", base ) << endl;
	cout << m_strtof ( "123" ) << endl;
	cout << m_strtod ( "123" ) << endl;

	cout << f_isInteger ( 10.3 ) << endl;
	cout << f_decimal ( 10.3 ) << endl;
    cout << endl;
	return;
}
//END Convert
/********************************************/



