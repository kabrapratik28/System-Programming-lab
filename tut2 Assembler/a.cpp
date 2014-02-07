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
  vector<int> addofdef; 
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
	addofdef.push_back (0) ; 
      }
    
    
  }


  void addelement_with_add (string element , int addloct)
  {
    int curr_posi ; 
    curr_posi = elementfinder(element);     // element finder class using
    if (curr_posi != -1)// check present or not
      {
	addofdef.at(curr_posi) = addloct ;
      }
    else 
      {
	symbol.push_back (element) ; // else add .. and create new vector add in vector
	addofdef.push_back (addloct);
	vector<int> locations ; 
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

vector<string> tokengiver(string com_sen)
{
  vector<string> tokens ; 
  istringstream is_in (com_sen);  // string stream
  string words ; 
  while(is_in >> words) {
    tokens.push_back(trim(words)) ;	
  }

  return tokens ; 
}

void frtadder(vector<string> frtadd)
{
  for(std::vector<string>::iterator itera = frtadd.begin(); itera != frtadd.end(); ++itera) {
    if ((*itera != "a") && (*itera != "b") && (*itera != "c") && (*itera != "d")){
      frt.addelement ( *itera ,address_starter );
    }
  }
}

void startchecker(string onelineofcode)
{
  // 1. move 2.mover 3.movem 4.mult 5.bc 6.stop 7.end 8.start 9.add 10.sub 11.jmp 12.ltorg 13.comp 14. equ
  vector<string> tokensgot ;
  //order imp of mover movem and move
   if (onelineofcode.compare(0, mover.length(), mover) == 0)
    {
      onelineofcode.erase (0,mover.length());
      tokensgot = tokengiver(trim(onelineofcode)) ;
      frtadder(tokensgot) ; 
    }
  else if (onelineofcode.compare(0, movem.length(), movem) == 0)
    {
      onelineofcode.erase (0,movem.length());  
      tokensgot = tokengiver(trim(onelineofcode)) ;
      frtadder(tokensgot) ; 
    }
  else if (onelineofcode.compare(0, move.length(), move) == 0)
    {
      onelineofcode.erase (0,move.length());  
      tokensgot = tokengiver(trim(onelineofcode)) ;
      frtadder(tokensgot) ; 
    }
  else if (onelineofcode.compare(0, mult.length(), mult) == 0)
    {
      onelineofcode.erase (0,mult.length());  
      tokensgot = tokengiver(trim(onelineofcode)) ;
      frtadder(tokensgot) ; 
    }
  else if (onelineofcode.compare(0, bc.length(),bc) == 0)
    {
      onelineofcode.erase (0,bc.length()); 
      string nonsense  ; // for bc i.e.for e.g. less than (le)
      istringstream is_nonse (onelineofcode);  // string stream
      is_nonse >> nonsense ;    // remove than conditional
      string words ;                    
      vector<string> tokens ;
      while(is_nonse >> words) {               // above .str() also take le 
    tokens.push_back(trim(words)) ;	
      }
      frtadder(tokens) ; 
    }
  else if (onelineofcode.compare(0, stop.length(),stop) == 0)
    {
      // do nothing 
    }
  else if (onelineofcode.compare(0, end.length(), end) == 0)
    {
      // do nothing 
    }
  else if (onelineofcode.compare(0, start.length(), start) == 0)
    {
      onelineofcode.erase (0,start.length());
      istringstream addr_str (onelineofcode);  // string stream     ..... //set address
      addr_str >> address_starter ; 
    }
  else if (onelineofcode.compare(0, add.length(), add) == 0)
    {
      onelineofcode.erase (0,add.length());  
      tokensgot = tokengiver(trim(onelineofcode)) ;
      frtadder(tokensgot) ; 
    }
  else if (onelineofcode.compare(0, sub.length(), sub) == 0)
    {
      onelineofcode.erase (0,sub.length());  
      tokensgot = tokengiver(trim(onelineofcode)) ;
      frtadder(tokensgot) ; 
    }
  else if (onelineofcode.compare(0, jmp.length(), jmp) == 0)
    {
      onelineofcode.erase (0,jmp.length());  
      tokensgot = tokengiver(trim(onelineofcode)) ;
      frtadder(tokensgot) ; 
    }
  else if (onelineofcode.compare(0, ltorg.length(), ltorg) == 0)
    {
      // do nothing 
    }
  else if (onelineofcode.compare(0, comp.length(), comp) == 0)
    {
      onelineofcode.erase (0,comp.length());  
      tokensgot = tokengiver(trim(onelineofcode)) ;
      frtadder(tokensgot) ; 
    }
  else if (onelineofcode.compare(0, equ.length(), equ) == 0)
    {
      lt.addelement (onelineofcode , address_starter );
      vector<string> justone(1,onelineofcode);       
      frtadder(justone) ;
    }
  else 
    {
      // ds and dc storage and defination
      istringstream dcdm (onelineofcode);  // string stream     ..... //dcdm
      string oper , dd  ; 
      int val ; 
      dcdm >> oper ; 
      dcdm >> dd ; 
      dcdm >> val ; 
      if (dd == "dc")
	{
	  st.addelement (oper,address_starter,val , 0);
	  frt.addelement_with_add (trim(oper) ,address_starter ) ; 
	}
      else if (dd == "ds"){
	st.addelement (oper , address_starter, 0, val);
	  frt.addelement_with_add (trim(oper) ,address_starter ) ; 
      }
    }
}


int main()
{
	
  ifstream file("a.asm");   //open file
  string line_by_line;     //line by line read
  string clean_string,clean_string1, instru ;
  vector<string> labelstorer ; 
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
	    frt.addelement_with_add (trim(labelstorer.at(elela)) ,address_starter ) ; 
	  }
	}
      else
	{
	  cout << "Problem !!!" ;
	}
      //label processing ends here ================================

      //check instruction and do operations 
     
      startchecker(instru) ; 

      address_starter =   addressinc ();

    }
  int loc_con =  0 ;
  cout << "             LITREAL TABLE             \n" ; 
  while (loc_con<=lt.number.size()-1)
    {
      cout << lt.number[loc_con] << "  " << lt.literal[loc_con]<< " "<< lt.location[loc_con]<<"\n" ; 
      loc_con++ ;   
    }
  
 cout << "\n\n\n"  ; 
  loc_con =  0 ;
  cout << "             FORWARD REVERSE TABLE             \n" ; 
  while (loc_con<=frt.symbol.size()-1)
    {

      string maker("") ; 
  int tato = 0  ; 
  
  while (tato<=frt.addofuse.at(loc_con).size()-1)
    {
     
stringstream ss;
 ss << frt.addofuse.at(loc_con).at(tato) ; 
      maker = maker + ss.str()+" ";
      tato++ ; 
    }

  stringstream tatkkk ; 
   tatkkk << frt.addofdef[loc_con] ; 

   cout << frt.symbol[loc_con] << "  " <<tatkkk.str() << " "<< maker<<"\n" ; 
      loc_con++ ;   
    }
  
  cout << "\n\n\n"  ; 
  loc_con =  0 ;
  cout << "             SYMBOL TABLE             \n" ; 
  while (loc_con<=st.name.size()-1)
    {
      cout << st.name[loc_con] << "  " << st.address[loc_con]<< " "<< st.value[loc_con]<< st.lenght[loc_con]<<"\n" ; 
      loc_con++ ;   
    }
  
  
  return 0 ; 
}
