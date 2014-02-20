

#include <stdio.h>
 
main()
{
   int n, a,b,c,s;float  k ; 
   char pop ,s2,s3, lo ;  char att,mtttt ;  
   double aasd ;
   extern v,v2,v3 ;
   printf("Enter a number\n");
   scanf("%d", &n);
 
   if ( a == 2 )
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
