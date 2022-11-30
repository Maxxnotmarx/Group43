// gp.h

#ifndef GP_H
#define GP_H

#include <fstream>
#include <vector>

using namespace std;

void Classic();
void Easy( string word );
string TargetWord( char voca, int level );
string RandomWord( string file );
void display_L1( string word, vector< string > output, int times, char guess_blank[], vector< char > guessed );
void MainPage();
void Scoring();
void display_Scoring( string word, vector< string > output, int times,char guess_blank[],vector< char > wrong_letter );
void menu();

#endif
