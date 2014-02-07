#include <iostream>  // std
#include <fstream>   // file open
#include <sstream>   // std::istringstream
#include <vector>   // dyanamic array
#include <string>   // string 
#include <algorithm>  //replace 

using namespace std;
 
int address_starter ;
// 1. move 2.mover 3.movem 4.mult 5.bc 6.stop 7.end 8.start 9.add 10.sub 11.jmp 12.ltorg 13.comp 14.equ
   
string move="move", mover="mover" , movem="movem" , mult= "mult" , bc="bc" ,   stop="stop" , end="end" ,start="start" , add="add",sub="sub", jmp="jmp" , ltorg="ltorg" , comp="comp" , equ="=" ;
class ST {
public:
  vector<string> name; 
  vector<int> address; 
  vector<int> value; 
  vector<int> lenght; 

  void addelement (string element , int location, int valofele, int lenofele)
  {
    // add element and corresponding location
    name.push_back(element) ;
    address.push_back(location);
    value.push_back(valofele) ;
    lenght.push_back(lenofele) ;
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
  vector<int> number; 
  vector<string> literal; 
  vector<int> location;
  LT()
  {
    numbercount = 0 ; 
  }
  void addelement (string element , int loc)
  {
    //number increment 
    numbercount = numbercount +1 ;
    // add element and corresponding location
    number.push_back(numbercount) ;
    literal.push_back(element);
    location.push_back(loc) ; 
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
    curr_posi = elementfinder(element);     // element finder class using
    if (curr_posi != -1)// check present or not
      {
	addofuse.at(curr_posi).push_back(location);
      }
    else 
      {
	symbol.push_back (element) ; // else add .. and create new vector add in vector
	vector<int> locations (1,location) ; 
	addofuse.push_back (locations); 
      }
    
    
  }

  int elementfinder (string elem)    // above class using element finder
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

int startchecker(string onelineofcode)
{
  // 1. move 2.mover 3.movem 4.mult 5.bc 6.stop 7.end 8.start 9.add 10.sub 11.jmp 12.ltorg 13.comp 14. equ
  
  if (onelineofcode.compare(0, move.length(), move) == 0)
    {
      return 1 ; 
    }
  else if (onelineofcode.compare(0, mover.length(), mover) == 0)
    {
      return 2 ;
    }
  else if (onelineofcode.compare(0, movem.length(), movem) == 0)
    {
      return 3 ;
    }
  else if (onelineofcode.compare(0, mult.length(), mult) == 0)
    {
      return 4 ;
    }
  else if (onelineofcode.compare(0, bc.length(),bc) == 0)
    {
      return 5 ;
    }
  else if (onelineofcode.compare(0, stop.length(),stop) == 0)
    {
      return 6 ;
    }
  else if (onelineofcode.compare(0, end.length(), end) == 0)
    {
      return 7 ;
    }
  else if (onelineofcode.compare(0, start.length(), start) == 0)
    {
      return 8 ;
    }
  else if (onelineofcode.compare(0, add.length(), add) == 0)
    {
      return 9 ;
    }
  else if (onelineofcode.compare(0, sub.length(), sub) == 0)
    {
      return 10 ;
    }
  else if (onelineofcode.compare(0, jmp.length(), jmp) == 0)
    {
      return 11 ;
    }
  else if (onelineofcode.compare(0, ltorg.length(), ltorg) == 0)
    {
      return 12 ;
    }
  else if (onelineofcode.compare(0, comp.length(), comp) == 0)
    {
      return 13 ;
    }
  else if (onelineofcode.compare(0, equ.length(), equ) == 0)
    {
      return 14 ;
    }
  else 
    {
      return 15 ; 
    }
}


int main()
{
	
  ifstream file("a.asm");   //open file
  string line_by_line;     //line by line read
  string words ;           // word
  string clean_string,clean_string1, instru ;
  vector<string> labelstorer ;
  istringstream is_in; 
  address_starter = 1000 ;   // by default
  while (getline(file, line_by_line))   //get line
    {
      clean_string =  trim(line_by_line); 
      clean_string1 = cleancomma(clean_string);
      labelstorer = labelfinder(clean_string1);
      // label processing =========================================
      if (labelstorer.size() == 1) 
	{
	  instru = trim(labelstorer[0]) ; 
	}
      else if (labelstorer.size() >  1)
	{
	  instru = trim(labelstorer.at(labelstorer.size()-1)) ; 
	  for(std::vector<string>::size_type elela = 0; elela != labelstorer.size()-1; elela++) {
	    lt.addelement ( trim(labelstorer.at(elela)),address_starter );
	  }
	}
      else
	{
	  cout << "Problem !!!" ;
	}
      //label processing ends here ================================

      //check instruction and do operations 
      

      is_in (instru);  // string stream
      
      while(iss >> words) {
      cout << words ;	
      }




    }
  int loc_con =  0 ;
    while (loc_con<=lt.number.size()-1)
    {
      cout << lt.number[loc_con] << "  " << lt.literal[loc_con]<< " "<< lt.location[loc_con]<<"\n" ; 
      loc_con++ ;   
    }
  
  
  return 0 ; 
}
