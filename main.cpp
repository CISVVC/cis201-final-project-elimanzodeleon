/*
* file: main.cpp 
* name: elias mazno-de leon
* email: manzoe@student.vvc.ed
* description: will read in a text file and print each word, how many times it was used and where it was used
*/


#include <ctype.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>

int main() {

  char file[20];
  
  double line=0;
  int i=0;
  int j=0;
  int k=0;
  
  std::string lines[1000];
  std::string word;
  std::string concord[1000];

  int count[1000]={0};
  int x=0;

  std::ifstream f;
  f.open("alice.txt");
  std::string w;
  
  while(f.good())
  {
	 //this while loop changes all txt to lower case and removes all punctuation
     std::getline(f, word);	
     for(int i=0; i < word.length(); i++)
     {
     if(!isalpha(word.at(i)))
      	{
        	if(word.at(i)!= ' ')
          	for(int j=i; j < word.length()-1; j++) {
        		word.at(j) = word.at(j+1);
    		}
      		if(i == word.length()-1)
        		word.at(i)= ' ';
        }
      	if(!islower(word.at(i)))
        {
         	word.at(i)=tolower(word.at(i));
        }
     }
   	 std::istringstream s(word);
     while(s>>w) {
		//this loop reads in each line from alice.txt
      	bool fail = false;
      	int m = -1;
      
      	for(int k = 0; k < x; k++) {
        		if(concord[k] == w) {
      				fail=true;
      				m = k;
      			}
    	}
        if(fail!=true) {
         	concord[x]=w;
      	 	count[x]=1;
      	    std::stringstream number;
      		number << line + 1;
      		lines[x]=number.str();
      		x++;
    	}
    	else {
    		count[m]++;
    		std::stringstream number_;
    		number_<< line+1;
    		lines[m] = lines[m]+","+ number_.str();
      	}
    }
  	line=line+1;
  }
  
  std::cout << std::left << "Word: " << "count:" << "Occurences" << std::endl;
  
  //print counts to console
  for(int b = 0; b < x; b++) {
    std::cout << std::left << concord[b] << " : " << count[b] << " : " << lines[b] << std::endl;
  }

return 0;

}
