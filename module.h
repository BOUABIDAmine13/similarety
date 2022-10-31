#include <string>
#include <vector>
#include <fstream>
#ifndef __MODULE__
#define __MODULE__
//type of word and hir frequency
typedef struct word
{
	std::string mot = "";
	int occ = 0;
} word;
// see if is latter or not to get the words 
bool wordOrNot (char& ch);
// calcul base of file the words  withe frequency and add to v1 withe just words in v2 
void getFromeFile1(std::vector<word>& v1, std::vector<word>& v2, std::string textName);
// calcul the similarty base of cos algorithme
float getSimilarty(std::vector<word>& v1, std::vector<word>& v2);
#endif