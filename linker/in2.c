#include <stdio.h>
#include<in.c> 
main()
{
   int n,a,b,v, c;float k ; 
   char pop , v2,lo ;  char att,mtttt ;  
   double aasd,v3 ;
   extern s,s2,s3 ;
   printf("Enter a number\n");
   scanf("%d", &n);
 
   if ( s == 2 )
      printf("Prime int number.\n"); 
   else
   {
       for ( c = 2 ; c <= n - 1 ; c++ )
       {
           if ( n % c == 0 )
              break;
       }
       if ( c != n )
          printf("Not prime.\n");
       else
          printf("Prime number.\n");
   }
   return 0;
}
