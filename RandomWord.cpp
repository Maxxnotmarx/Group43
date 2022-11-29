// RandomWord Function

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "gp.h"

using namespace std;

// Input a dictionary .txt file, and return a word randomly selected from the dictionary file
string RandomWord( string file ) {
	int n, index, size = 0;
	string word, word_in_random;
	vector < string > word_list;
	ifstream dictionary;
	dictionary.open( file.c_str() );
	srand( time(0) );
	
	// Read words as inputs from dictionary files 
	while( dictionary >> word ) {
		size++;
		word_list.push_back( word ); // Append words in the file to the vector
	}
		
	//use rand() to randomly choose an index
	index = rand()%size; 

	word_in_random = word_list[index];

	dictionary.close();

	return word_in_random;
}
