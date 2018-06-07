#include "my_utilities/my_input.h"

using namespace std;


/********************************************/
///Input_user


void myInput::Test()
{
	using namespace myInput;
	cout << "Test myInput" << endl;

	cout << "Test input conversion to float (not handling of errors)" << endl;

	float f = myInput::get_std_input ( myConvert::m_strtof );
	cout << f << endl;

	cout << "Test input conversion to float" << endl;
	f = myInput::get_std_input_blocked ( myConvert::m_strtof );
	cout << f << endl;

	cout << "Test input conversion to long" << endl;
	long int integer = myInput::get_std_input_blocked ( myConvert::m_strtol );
	cout << integer << endl;

	cout << "Test input conversion to unsigned long" << endl;
	unsigned long int integer_long = myInput::get_std_input_blocked ( myConvert::m_strtoul );
	cout << integer_long << endl;

	cout << "Test input conversion to double" << endl;
	double d = myInput::get_std_input_blocked ( myConvert::m_strtod );
	cout << d << endl;

	cout << "Test input conversion to hex integer" << endl;
	integer = myInput::get_std_input_blocked<long int, 2> ( myConvert::m_strtol );
	cout  << integer << endl;

	cout <<  endl;
	return;
}

//END Input_User
/********************************************/



