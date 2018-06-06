#include "toolbox.h"

#include <iostream>
#include <fstream>


float toolFunction()
{
    float f = myConvert::m_strtof("5");
    f = myError::MEMORY;
    f = myInput::get_float();

    return f;
}
