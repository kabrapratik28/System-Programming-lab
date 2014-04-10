#include <iostream>  // std
#include <fstream>   // file open
#include <sstream>   // std::istringstream
#include <vector>   // dyanamic array
#include <string>   // string 
#include <algorithm>  //replace 
#include <map>   //dictionary (map)
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
  vector<int> positional  ;
  int positional_curr_no  ; 

  void add(string ddd )
  {
    formal.push_back(ddd);
    positional.push_back(positional_curr_no) ;
  }
}fp ; 

class MDT {
public : 
  string mac_name; 
  vector<string> def ;
}; 

class pos_vs_act {
public : 
  vector<int> positional   ; 
  vector<string> actual  ;


  void add(int pooo ,string posi )
  {
    positional.push_back(pooo);
    actual.push_back(posi) ;
  }


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
  fp.positional_curr_no = 0 ;  //positional no intialized 
  ifstream infile("abc");
  string line ,trimmed_line;  
  int counter = 0 ; 
  bool macrotell,macroend,macro_def_running;
  vector <MDT> allmdt ; 
  MDT mdt ;
  map<string,string> macro_def_line_save ; //for when call macro found check parameter with this line 
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

	  stringstream wholetaken ; 
	  wholetaken << macro_def_line.str() ;
	  wholetaken >> nonsense ; 
	  wholetaken >> nonsense ; 
	  string onlypara="" , para1 ; 
	  while(wholetaken >>para1)
	    {
	      onlypara = onlypara + para1+ " "  ; 
	    }

	  macro_def_line_save[name_of_macro]=onlypara;    //<===    making whole string 
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

int k=0 ; 	
//===============Nested macro =====
  for (vector<MDT>::iterator i = allmdt.begin(); i != allmdt.end(); i++)
    {
      if((*i).mac_name==trimmed_line )
{ 
	k=1 ;  
      for (vector<string>::iterator j= (*i).def.begin(); j != (*i).def.end(); j++)
	{
	  mdt.def.push_back(*j) ; 	
	}
}
    }
if (k==0)
{
	      //add to current macro defination
	      mdt.def.push_back(trimmed_line) ; 	
}
//============== Nested ends
	    }
	  else 
	    {
	      // normal code
	      int counter_pos_at = 0 ; 
	      for (map<string,string>:: iterator u =  macro_def_line_save.begin() ; u!= macro_def_line_save.end() ; u++  )
		{
		  if (trimmed_line.find(u->first)!=string::npos ) // matches ==> this is call to macro
		    {
		      // counter is showing line from which macro gets call 
		      // counter_pos_at shows which macro gets call  
		      stringstream forpara ;
		      string nonsense_2 ,parameter; 
		      forpara << trimmed_line ; 
		      forpara >> nonsense_2 ; // macro name removed from line // from above we got macro name 
		      stringstream para_only ; 
		      string indivual_para ; 
		      para_only << u->second ; // praline get of that macro //THIS IS GOT FROM STANDARD PARALIST AT DEF TIME
		       while(forpara>>parameter)
			 {
			   // add pos_vs_from and form_vs_actual table here 
		    	    fp.positional_curr_no++ ;  //positional  no  increamented 
			    para_only >> indivual_para ; 
			    fp.add(indivual_para) ;
			    pvsa.add(fp.positional_curr_no,parameter) ; 
			    
			 }
		      
		      break ; 
		    }
		  counter_pos_at++ ; 
		}
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
 
  return 0 ; 
}


/*
Input
macro abc &a &k
load p 
add q
mend
macro xyz
load a 
add b 
mend
mult c
xyz
add b
abc 1 3
end

Output
 MDT TABLE
Macro name : abc
load p
add q
=======
Macro name : xyz
load a
add b
=======
 MNT TABLE 
abc 2 1
xyz 0 5
=======
 FP TABLE 
&a 1
&k 2
=======
 PVSA TABLE 
1 1
2 3
=======
*/
