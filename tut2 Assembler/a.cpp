#include <iostream>  // std
#include <fstream>   // file open
#include <sstream>   // std::istringstream
#include <vector>   // dyanamic array
using namespace std;
 
class ST {
  public:
    vector<string> name; 
    vector<string> address; 
    vector<string> value; 
    vector<string> lenght; 
}st;
/*
class MOT {
  public:
    
}mot;
//HARD CODED  */
class LT {
  public:
    vector<string> number; 
    vector<string> literal; 
    vector<string> location; 
}lt;
class FRT {
  public:
    vector<string> symbol; 
    vector<string> addofdef; 
    vector<string> addofuse; 
}frt;


int main()
{
	
  ifstream file("a.asm");   //open file
  string line_by_line;     //line by line read
  string words ;           // word
  while (getline(file, line_by_line))   //get line
    {
    	istringstream iss (line_by_line);  // string stream
       	while(iss >> words) {
       		cout << words ;
       		
       	}
    }
  
  return 0 ; 
}
