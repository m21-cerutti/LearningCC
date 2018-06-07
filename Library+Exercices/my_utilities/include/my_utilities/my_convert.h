#ifndef MY_CONVERT_H_INCLUDED
#define MY_CONVERT_H_INCLUDED

#include <iostream>

// uncomment to disable assert()
// #define NDEBUG
#include <cassert>
#include <math.h>

#include <cerrno>
#include <string>

#include "my_utilities/my_error.h"

using namespace std;



/** \namespace  myConvert
*   Name spacing for conversion
*/
namespace myConvert
{

	/** \fn long int m_strtol(string str, int base)
	*   \brief Fonction
	*   \param str String
	*   \param base Int
	*   \return the long int, if fail throw an exception.
	*/
	long int m_strtol ( string str, int base );

	/** \fn unsigned long int m_strtoul(string str, int base)
	*   \brief Fonction
	*   \param str String
	*   \param base Int
	*   \return the unsigned long, if fail throw an exception.
	*   Watch out, a negative number will overflow without error.
	*/
	unsigned long int m_strtoul ( string str, int base );

	/** \fn float m_strtof(string str)
	*   \brief Fonction
	*   \param str String
	*   \param base Int
	*   \return the float, if fail throw an exception.
	*/
	float m_strtof ( string str );

	/** \fn double m_strtod(string str)
	*   \brief Fonction
	*   \param str String
	*   \return the double, if fail throw an exception.
	*/
	double m_strtod ( string str );

	/** \fn bool f_isInteger (float f)
	*   \brief Fonction
	*   \param f Float
	*   \return true if integer, else false.
	*/
	bool f_isInteger ( float f );

	/** \fn float f_decimal (float f)
	*   \brief Fonction
	*   \param f Float
	*   \return the decimal part of the float.
	*/
	float f_decimal ( float f );

	///Test functions of myConvert.
	void Test();
}


#endif // MY_CONVERT_H_INCLUDED
