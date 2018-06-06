#include "my_utilities/my_file.h"

using namespace std;



/********************************************/
//BASE File


bool myFile::is_valid_iostream (myFile::ioFile& stream )
{
    return stream.is_valid_iostream();
}

myFile::ioFile::ioFile ( string file, bool app, bool ate, bool bin )
{
//std::ios_base::in | std::ios_base::out
}

myFile::ioFile::ioFile ( char* file,  bool app, bool ate, bool bin )
{

}

myFile::ioFile::~ioFile()
{

}

fstream& myFile::ioFile::stream()
{
    return p_stream;
}

bool myFile::ioFile::is_valid_iostream ()
{
    return (p_stream.is_open());
}

//END BASE File
/********************************************/
//Saving functions


//END Saving functions
/********************************************/
//Reading functions

string myFile::read ( string file )
{

}

string myFile::read ( char* file )
{

}

string myFile::read ( ifstream& file )
{

}

//END Reading functions
/********************************************/


void myFile::Test()
{
    myFile::save("test_lib_my_utilities/test_my_utilities_file.test","Test 1 : writing into a file.");
    myFile::save("test_my_utilities_file.test","Test 2 : writing into a file with append at end.",true,true,false);
    myFile::save("test_my_utilities_file.test",R"(Test 3 : writing into a file with append at end not in binary(no change for input like \r\n).)",true,true,false);
    myFile::save("test_my_utilities_file.test","Test 4 : writing into a file with append only.)",true,false, true);
    myFile::save("test_my_utilities_file.txt",
                "Resume tests :\
                \n     Test 1 : writing into a file.\
                \n     Test 2 : writing into a file with append at end.\
                \n     Test 3 : writing into a file with append at end not in binary(no change for input like \\r\\n).\
                \n     Test 4 : writing into a file with append only.");
	return;
}








