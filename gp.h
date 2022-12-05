// gp.h

#ifndef GP_H
#define GP_H

#include <vector>
#include <fstream>

using namespace std;

void Classic();
void Easy( string word );
string TargetWord( char voca, int level );
string RandomWord( string file );
void display_L1( string word, vector< string > output, int times, char guess_blank[], vector< char > guessed );
void MainPage();
void Scoring();
void display_Scoring( vector< string > output, int times );
void menu();

#endif
