#include <iostream>  // std
#include <fstream>   // file open
#include <sstream>   // std::istringstream
#include <vector>   // dyanamic array
#include <string>   // string 
#include <algorithm>  //replace 

using namespace std;
 
int address_starter ; 

class ST {
public:
  vector<string> name; 
  vector<string> address; 
  vector<string> value; 
  vector<string> lenght; 

  void addelement (string element , int location)
  {
    // add element and corresponding location
  }


}st;

/*
  class MOT {
  public:
    
  }mot;
  //HARD CODED  */

class LT {
public:
  int numbercount  ; 
  vector<string> number; 
  vector<string> literal; 
  vector<string> location;
  LT()
  {
    numbercount = 0 ; 
  }
  void addelement (string element , int location)
  {
    //number increment 
    numbercount = numbercount +1 ;
    // add element and corresponding location
  }
}lt;

class FRT {
public:
  vector<string> symbol; 
  //vector<string> addofdef; 
  vector<vector <int> > addofuse; 

  void addelement (string element , int location)
  {
    int curr_posi ; 
    curr_posi = elementfinder(element);
    if (curr_posi != -1)// check present or not
      {
	
      }
    else 
      {
	symbol.push_back (element) ; // else add .. and create new vector add in vector
	vector<int> locations (1,location) ; 
	addofuse.push_back (locations); 
      }
    
    
  }

  int elementfinder (string elem)
  {
    int position = -1 ;  //position not got 
    vector<string>::iterator iter;
    if( (iter = find(symbol.begin(), symbol.end(),elem )) != symbol.end())
      {
	position = distance(symbol.begin(), iter);	
      } 

    return position ;  
  }

}frt;


// white space trimmer function 
string trim(string str)  
{
  string::size_type pos = str.find_last_not_of(' ');

  if(pos != string::npos) {
    str.erase(pos + 1);
    pos = str.find_first_not_of(' ');
    if(pos != string::npos) str.erase(0, pos);
  }

  else
    {
      str.erase(str.begin(), str.end());  // ALL ARE WHITE SPACES 
    }

  return str ; 
}


//label finder function 
vector<string> labelfinder(string complete_string)
{
  vector<string> local ;

  string words= complete_string;
  istringstream line(words);
  if (words.find(":")!= string::npos)
    {
      std::string token;

      while(std::getline(line, token, ':')) {
	token = trim(token);    // removing all extra white spaces of both sides
	local.push_back (token) ;
      }
    }
  else{local.push_back (words);}
  return local ;  // all label and remaing string  
}

//replace comma with other
string cleancomma(string linetoclean){
  replace( linetoclean.begin(), linetoclean.end(), ',', ' ');
  return linetoclean ; 
}

int addressinc ()
{
  address_starter = address_starter  + 1 ; 
  return address_starter ; 
}

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
