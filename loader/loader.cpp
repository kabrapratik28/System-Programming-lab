#include <iostream>  // std
#include <fstream>   // file open
#include <sstream>   // std::istringstream
#include <vector>   // dyanamic array
#include <string>   // string 
#include <algorithm>  //replace 

using namespace std;


int main()
{
  FILE * pFile;
  char  filename[80]  ; 
  long size_of_file;
  long loadersize = 10 ; 
  
  int a = 1 ; 
  while(a>0)
    {
      cout << "Enter file to load\n" ;  
      cin >> filename ; 
      pFile = fopen (filename,"rb");
      if (pFile==NULL) perror ("Error opening file");
      else
	{
	  fseek (pFile, 0, SEEK_END);   // non-portable
	  size_of_file=ftell (pFile);
	  fclose (pFile);
	  printf ("Size of file: %ld bytes.\n",size_of_file);
	  if (size_of_file<=loadersize)
	    {
	      cout << "Sucessfully loaded !!!\n";
	      loadersize = loadersize - size_of_file;
	    }
	  else {
	    cout << "Fail to load !!!\n" ; 
	  } 
	}
       cout << "Size of loader remained: " << loadersize <<"\n"  ;
      cout << "Enter to continue \n";
      cin >> a ; 
    }
  return 0 ; 
}
