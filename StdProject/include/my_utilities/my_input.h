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

    /**  \fn void get_float ()
    *    \brief Fonction that take the input of the user and give a float
    *   \return the float, if fail quit the program.
    */
    float get_float();



    //END Input_user
    /********************************************/

}

#endif // MY_INPUT_H_INCLUDED
