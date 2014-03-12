#include <iostream>  // std
#include <fstream>   // file open
#include <sstream>   // std::istringstream
#include <vector>   // dyanamic array
#include <string>   // string 
#include <algorithm>  //replace 

using namespace std;

class MNT{
public : 
  vector<string> name   ;
  vector<int> no_of_parameter   ;
  vector<int> start ; 

  void add_element(string na , int noofpara , int sta)
  {
	  name.push_back(na);
	  no_of_parameter.push_back(noofpara);
	  start.push_back(sta);
  }

}mnt ; 

class for_vs_pos{
public : 
  vector<string> formal   ; 
  vector<string> positional  ;
}fp ; 

class MDT {
public : 
  string mac_name; 
  vector<string> def ;
}; 

class pos_vs_act {
public : 
  vector<int> positional   ; 
  vector<int> actual  ;
}pvsa ; 

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

bool macro_finder(string stra)
{
if(stra.find("macro")!=string::npos)
	{
	  return true ;  
	}

 return false  ;
}

bool macro_end_finder(string stra)
{
if(stra.find("mend")!=string::npos)
	{
	  return true ;  
	}

 return false  ;
}

int main()
{
  ifstream infile("abc");
  string line ,trimmed_line;  
  int counter = 0 ; 
  bool macrotell,macroend,macro_def_running;
  vector <MDT> allmdt ; 
  MDT mdt ;
  vector<string> macro_def_line_save ; //for when call macro found check parameter with this line 
  while(getline(infile, line))
    {
      counter++ ; 
      trimmed_line = trim(line) ;
      macrotell = macro_finder(trimmed_line);
      macroend = macro_end_finder(trimmed_line) ; 
      if (macrotell)
	{
	  macro_def_running = true ;  // set macro is running
	  MDT mdt1 ;  //new mdt obj created
	  mdt = mdt1 ; 
	  stringstream macro_def_line ;
	  string nonsense ,name_of_macro ,para ;
	  int count_para=0 ; 
	  macro_def_line << trimmed_line ;  
	  macro_def_line >> nonsense ; 
	  macro_def_line >> name_of_macro ; 
	  mdt.mac_name = name_of_macro ; //macro name aded to object
	  // if any parameter add to 
	  while(macro_def_line>>para)
	    {
	      count_para++ ; 
	    }


	  //mnt work here 
	  mnt.add_element(name_of_macro,count_para,counter);
	}
      else if (macroend)
	{
	  macro_def_running=false ; // set macro is not running
	  allmdt.push_back(mdt) ; 
	}
      else 
	{
	  if (macro_def_running )
	    {
	      //add to current macro defination
	      mdt.def.push_back(trimmed_line) ; 
	    }
	  else 
	    {
	      // normal code 

	    }
	}
    }
  // do other table works here
  cout << " MDT TABLE" << "\n" ; 
   for (vector<MDT>::iterator i = allmdt.begin(); i != allmdt.end(); i++)
     {
       cout << "Macro name : "<<(*i).mac_name <<"\n"; 
       for (vector<string>::iterator j= (*i).def.begin(); j != (*i).def.end(); j++)
	 {
	     cout << *j <<"\n"; 
	 }
       cout << "=======\n" ; 
     }
   cout << " MNT TABLE "<<"\n" ; 
   int localcount = 0  ; 
       for (vector<string>::iterator j= mnt.name.begin(); j != mnt.name.end(); j++)
	 {
	   cout << *j<<" "<< mnt.no_of_parameter[localcount]<<" "<<mnt.start[localcount] <<"\n";
	   localcount++ ; 
	 }
       cout << "=======\n" ; 
     
  return 0 ; 
}
