#include "module.h"
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	vector<word> v1; //vector for file1 words
	vector<word> v2; //vector for file2 woeds
	if(argc > 2)
	{
		getFromeFile1(v1,v2, argv[1]); //get words from file1
		getFromeFile1(v2,v1, argv[2]); //get words from file2
		cout<< "similarty result = "<<getSimilarty(v1,v2)<<endl; //get similarity
	}
	else // exit if add lase the 2 names
	{
		cout<<"error of file number \nmast be 2 files of txt"<<endl;
		exit(1);
	}
	
	return 0;
}