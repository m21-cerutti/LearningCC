#include "my_utilities/my_file.h"

using namespace std;



/********************************************/
//BASE File


myFile::inFile::inFile ( string file )
	: filename ( file )
{

    ios_base::openmode mode{fstream::in};

    open ( file, mode );

    if (!is_open())
        throw myError::Error ( myError::STREAM, __FILE__, __LINE__, "Fail to open file \"" + file + "\"." );
}

myFile::inFile::inFile ( char* file )
	: filename ( string ( file ) )
{

    ios_base::openmode mode{fstream::in};

    open ( file, mode );

    if (!is_open())
        throw myError::Error ( myError::STREAM, __FILE__, __LINE__, "Fail to open file \"" + string ( file ) + "\"." );
}

myFile::inFile::~inFile()
{
    close();
}


/***********************************************/


myFile::outFile::outFile ( string file, bool app = false, bool ate = false, bool binary = false )
	: filename ( file )
{
    ios_base::openmode mode{fstream::out|fstream::in};

    if ( app )mode = mode | fstream::app;
    else mode = mode | fstream::trunc;
    if ( ate )mode = mode | fstream::ate;
    if ( binary )mode = mode | fstream::binary;

    open ( file, mode );

    if (!is_open())
        throw myError::Error ( myError::STREAM, __FILE__, __LINE__, "Fail to open file \"" + file + "\"." );
}

myFile::outFile::outFile ( char* file, bool app = false, bool ate = false, bool binary = false )
	: filename ( string ( file ) )
{

    ios_base::openmode mode{fstream::out|fstream::in};

    if ( app )mode = mode | fstream::app;
    else mode = mode | fstream::trunc;
    if ( ate )mode = mode | fstream::ate;
    if ( binary )mode = mode | fstream::binary;

    open ( file, mode );

    if (!is_open())
        throw myError::Error ( myError::STREAM, __FILE__, __LINE__, "Fail to open file \"" + string ( file ) + "\"." );
}

myFile::outFile::~outFile()
{
    close();
}

//END BASE File
/********************************************/
//Saving functions


//END Saving functions
/********************************************/
//Reading functions

string myFile::read ( string file, bool del = false, bool binary =false  )
{
	inFile in(file);
	string content;
    string line;
    while ( getline ( in, line ) )
    {
        content += line +"\n";
    }
    in.close();

	if ( ios::good )
	{
		if ( del && remove ( file.c_str() ) != 0 )
		{ throw myError::Error ( myError::STREAM, __FILE__, __LINE__, "Fail to delete the file \"" + file  + "\"." ); }
		else
		{return content;}
	}
	else
	{throw myError::Error ( myError::STREAM, __FILE__, __LINE__, "Fail to read in the file \"" + file + "\"." );}

}

string myFile::read ( char* file, bool del, bool binary  )
{
	inFile in(file);
	string content;
    string line;
    while ( getline ( in, line ) )
    {
        content += line +"\n";
    }

    in.close();

	if ( ios::good )
	{
		if ( del && remove ( file ) != 0 )
		{ throw myError::Error ( myError::STREAM, __FILE__, __LINE__, "Fail to delete the file \"" + string(file)  + "\"." ); }
		else
		{return content;}
	}
	else
	{throw myError::Error ( myError::STREAM, __FILE__, __LINE__, "Fail to read in the file \"" + string(file) + "\"." );}
}

string myFile::read ( ifstream& in )
{
	string content;

	if ( in.is_open() )
	{
		string line;
		while ( getline ( in, line ) )
		{
			content += line +"\n";
		}
	}
	else throw myError::Error ( myError::STREAM, __FILE__, __LINE__, "The stream given to read is not open." );

	if ( ios::good ) return content;
	else throw myError::Error ( myError::STREAM, __FILE__, __LINE__, "Fail to read in the stream given." );

}

string myFile::read ( inFile& in )
{
	string content;

	if ( in.is_open() )
	{
		string line;
		while ( getline ( in, line ) )
		{
			content += line +"\n";
		}
	}
	else throw myError::Error ( myError::STREAM, __FILE__, __LINE__, "The stream given to read is not open." );

	if ( ios::good ) return content;
	else throw myError::Error ( myError::STREAM, __FILE__, __LINE__, "Fail to read in the stream given." );

}


/***********************************************/


void myFile::replace_char ( string file, char from, char to )
{
    using namespace myFile;
    inFile in (file);
    string content;
    string line;
    while ( getline ( in, line, from )&& !in.eof() )
    {
			content += line + to;
    }
    in.close();
    if ( !ios::good ) throw myError::Error ( myError::STREAM, __FILE__, __LINE__, "Fail to read and replace in the stream given." );

    save (file, content);
}

void myFile::replace_char ( char* file, char from, char to )
{
    using namespace myFile;
    inFile in (file);
    string content;
    string line;
    while ( getline ( in, line, from ) && !in.eof() )
    {
			content += line + to;
    }
    in.close();
    if ( !ios::good ) throw myError::Error ( myError::STREAM, __FILE__, __LINE__, "Fail to read and replace in the stream given." );

    save (file, content);
}


//END Reading functions
/********************************************/


void myFile::Test()
{
    using namespace myFile;

    //Part 1

	cout << "Test myFile" << endl;
    cout << "Part I : Write + Read test, compare with the resume." << endl;

	save ( "test_my_utilities_file.test", "Test 1 : writing into a file." );
    cout << ">>\n" << read("test_my_utilities_file.test") << ">>"  << "\tnum 1 Cleared ! " << endl << endl;

	save ( "test_my_utilities_file.test", 3000, true );
	cout << ">>\n" << read("test_my_utilities_file.test") << ">>"  <<  "\tnum 1.1 Cleared ! " << endl << endl;

	save ( "test_my_utilities_file.test", 0xa, true );
	cout << ">>\n" << read("test_my_utilities_file.test") << ">>"  <<  "\tnum 1.2 Cleared ! " << endl<< endl;

	save ( "test_my_utilities_file.test", "Test 2 : writing into a file with append at end.", true, true, false );
	cout << ">>\n" << read("test_my_utilities_file.test") << ">>"  <<  "\tnum 2 Cleared ! " << endl << endl;

	save ( "test_my_utilities_file.test", "Test 3 : writing into a file with append at end\n\tnot in binary(no change for input like \\r\\n).", true, true);
	cout << ">>\n" << read("test_my_utilities_file.test") << ">>"  <<  "\tnum 3 Cleared ! " << endl << endl;

	save ( "test_my_utilities_file.test", "Test 4 : writing into a file with append only.", true );
	cout << ">>\n" << read("test_my_utilities_file.test", true) << ">>" << "\tnum 4 Cleared ! " << endl << "Test_file deleted." << endl << endl;

	save ( "test_my_utilities_file.txt",
	               "Resume tests :\
                \nPart I :\
                \n\
                \n     Test 1 : writing into a file.\
                \n     Test 1.1 : writing into a file with number 3000.\
                \n     Test 1.2 : writing into a file with hex number 0xa = 10.\
                \n     Test 2 : writing into a file with append at end.\
                \n     Test 3 : writing into a file with append at end\n\tnot in binary(no change for input like \\r\\n).\
                \n     Test 4 : writing into a file with append only.\
                \n     Test 5 : delete test_my_utilities_file.test.\
                \n\
                \nPart I :\
                \n\
                \n     Test 1 : replace \":\" by \"\\n\".\
                " );
    //Part II

    cout << "Part II : replace and ioFile." << endl;

    save ( "test_my_utilities_file.test","1:2:3:4:5: 5.1: 5.3   lol");
    replace_char( "test_my_utilities_file.test", ':', '_');
    cout << ">>\n" << read("test_my_utilities_file.test") << ">>"  <<  "\tnum 1 Cleared ! " << endl << endl;

	return;
}








