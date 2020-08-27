#include <stdio.h>
#include <math.h>

#define LUBOE -10
#define HETRESHENIY -1

int main()
{
    printf("RESHENIE KBADRATNOGO YRABNENIYA\n");
    
    printf("BBEDITE CHISLA:");
    
    double a=0,b=0,c=0; /* a,b,c - коэфициенты квад ур*/
    scanf("%lg %lg %lg",&a,&b,&c);
    
    double x1=0,x2=0;   /* x1 и x2 - корни квад ур*/
    int nroot=PoiskKorney(a,b,c,&x1,&x2);
    
    if(nroot==0)              printf("HETRESHENIY\n");
      else
        {
        if(nroot==LUBOE)      printf("X LUBOE\n");
          else
            {
            if(nroot==1)      printf("ODHO RESHENIE: %lg\n",x1);
              else
                {
                if(nroot==2)  printf("DVA RESHENIYA: %lg I %lg\n",x1,x2);
                else          printf("ERROR\n");
                }
            }
        }
    return 0;
}
int PoiskKorney(double a,double b,double c,double* x1,
                double* x2)
{
    if(a==0)
      {
      if(b==0)
        {
        if(c==0)
          {
          return LUBOE;
          }
        else /* a=0,b=0,c!=0*/
          {
          *x1=*x2=HETRESHENIY;
          return 0;
          }
        }
        else /* a=0,b!=0 */
          {
          *x2=*x1=(-c/b);
          return 1;;
          }
      }
    else /* a!=0*/
      {
      double D=b*b-4*a*c; /* вычисление дискриминанта*/
      
      if(D==0)
        {
        *x2=*x1=-b/(2*a);
        return 1;
        }
      else
        {
        if(D>0)
          {
          *x1=(-b+sqrt(D))/(2*a);
          *x2=(-b-sqrt(D))/(2*a);
          return 2;
          }
        if(D<0)
          {
          *x1=*x2=HETRESHENIY;
          return 0;
          }
        }
      }
    return 100;
}
