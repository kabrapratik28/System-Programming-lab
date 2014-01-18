

#include <stdio.h>
 
main()
{
   int n,a,b, c;float b, k ; 
   char pop , lo ;  char att,mtttt ;  
   double aasd ;
   printf("Enter a number\n");
   scanf("%d", &n);
 
   if ( n == 2 )
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
