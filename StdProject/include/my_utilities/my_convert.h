#ifndef MY_CONVERT_H_INCLUDED
#define MY_CONVERT_H_INCLUDED

#include <iostream>

// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

#include "my_utilities/my_error.h"

using namespace std;



/** \namespace  myConvert
*   Name spacing for conversion
*/
namespace myConvert
{

    /** \fn float m_strtol(string str,int base)
    *   \brief Fonction
    *   \param str String
    *   \param base Int
    *   \return the float, if fail quit the program.
    */
    float m_strtof(string str);

}


#endif // MY_CONVERT_H_INCLUDED
