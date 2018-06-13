#include "my_utilities/my_file.h"

using namespace std;



/********************************************/
//BASE File


bool myFile::is_valid_iostream ( myFile::ioFile& stream )
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
{}

fstream& myFile::ioFile::stream()
{
	return p_stream;
}

bool myFile::ioFile::is_valid_iostream ()
{
	return ( p_stream.is_open() );
}

//END BASE File
/********************************************/
//Saving functions


//END Saving functions
/********************************************/
//Reading functions

string myFile::read ( string file, bool del = false, bool binary =false  )
{
	string content;
    ifstream in;
    ios_base::openmode mode{ifstream::in};

    if ( binary )mode = mode | ifstream::binary;

    in.open ( file, mode );

	if ( in.is_open() )
	{
		string line;
		while ( getline ( in, line ) )
		{
			content += line +"\n";
		}
	}
	else throw myError::Error ( myError::STREAM, __FILE__, __LINE__, "Fail to open file \"" +  file + "\"." );

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
	string content;
    ifstream in;
    ios_base::openmode mode{ifstream::in};

    if ( binary )mode = mode | ifstream::binary;

    in.open ( file, mode );

	if ( in.is_open() )
	{
		string line;
		while ( getline ( in, line ) )
		{
			content += line +"\n";
		}
	}
	else throw myError::Error ( myError::STREAM, __FILE__, __LINE__, "Fail to read file \"" +  string(file) + "\"." );

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

//END Reading functions
/********************************************/


void myFile::Test()
{
    using namespace myFile;
	cout << "Test myFile" << endl;
    cout << "Write + Read test, compare with the resume." << endl;

	save ( "test_my_utilities_file.test", "Test 1 : writing into a file." );
    cout << ">>\n" << read("test_my_utilities_file.test") << ">>"  << "\tnum 1 Cleared ! " << endl << endl;

	save ( "test_my_utilities_file.test", 3000, true );
	cout << ">>\n" << read("test_my_utilities_file.test") << ">>"  <<  "\tnum 1.1 Cleared ! " << endl << endl;

	save ( "test_my_utilities_file.test", 0xa, true );
	cout << ">>\n" << read("test_my_utilities_file.test") << ">>"  <<  "\tnum 1.2 Cleared ! " << endl<< endl;

	save ( "test_my_utilities_file.test", "Test 2 : writing into a file with append at end.", true, true, false );
	cout << ">>\n" << read("test_my_utilities_file.test") << ">>"  <<  "\tnum 2 Cleared ! " << endl << endl;

	save ( "test_my_utilities_file.test", "Test 3 : writing into a file with append at end\n\tnot in binary(no change for input like \\r\\n).)", true, true);
	cout << ">>\n" << read("test_my_utilities_file.test") << ">>"  <<  "\tnum 3 Cleared ! " << endl << endl;

	save ( "test_my_utilities_file.test", "Test 4 : writing into a file with append only.)", true );
	cout << ">>\n" << read("test_my_utilities_file.test", true) << ">>" << "\tnum 4 Cleared ! " << endl << "Test_file deleted." << endl << endl;

	save ( "test_my_utilities_file.txt",
	               "Resume tests :\
                \n     Test 1 : writing into a file.\
                \n     Test 1.1 : writing into a file with number 3000.\
                \n     Test 1.2 : writing into a file with hex number 0xa = 10.\
                \n     Test 2 : writing into a file with append at end.\
                \n     Test 3 : writing into a file with append at end\n\tnot in binary(no change for input like \\r\\n).\
                \n     Test 4 : writing into a file with append only.\
                \n     Test 5 : delete test_my_utilities_file.test." );

	return;
}








