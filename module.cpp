#include "module.h"
#include <vector>
#include <math.h>
#include <iostream>
#include <string>
#include <fstream>

bool wordOrNot (char& ch)
{
	switch(ch)
	{
		case ' ':
		case ',':
		case '.':
		case '(':
		case ')':
		case '[':
		case ']':
		case ':':
		return false;
		default :
		return true;
	}
}
void getFromeFile1(std::vector<word>& v1, std::vector<word>& v2, std::string textName)
{
	std::ifstream file {textName};
	std::string mot="";
	bool exist;
	int i = 0;
	char ch;
	if(file.is_open())
	{
		while(file.get(ch))
		{
			//file.get(ch);
			if(wordOrNot (ch))
				mot+=ch;
			else
			{
				if(mot != "")
				{
					i=0;
					exist=false;
					while(i<int(v1.size())&&!exist)
					{
						if(v1[i].mot == mot)
							exist=true;
						else
							i++;
					}
					if(!exist)
					{
						v1.push_back(word{mot,1});
						v2.push_back(word{mot,0});
					}
					else
					{
						v1[i].occ+=1;
					}
					mot="";
				}
			}
		}
	}
	else // exit if error of file type  
	{
		std::cout<<"error of file name !"<<std::endl;
		exit(1);
	}
	file.close();
}

float getSimilarty(std::vector<word>& v1, std::vector<word>& v2)
{
	int dV1=0, deV2=0, dot=0;
	for(int i=0; i<int(v1.size());i++)
	{
		dV1+=pow(v1[i].occ,2);
		deV2+=pow(v2[i].occ,2);
		dot+=v1[i].occ*v2[i].occ;
	}

	return float(dot/(sqrt(dV1)*sqrt(deV2))*100);
}