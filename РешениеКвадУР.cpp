#include <stdio.h>
#include <math.h>

const int ANYX=-10;
const int NOSOLUTIONS=-1;

int main()
{
    printf("FIND SOLUTIONS OF SQUARE EQUATION\n");
    
    printf("ENTER COEFFICIENTS:");
    
    double a=0,b=0,c=0; /* a,b,c - коэфициенты квад ур*/
    scanf("%lg %lg %lg",&a,&b,&c);
    
    double x1=0,x2=0;   /* x1 и x2 - корни квад ур*/
    int nroot=SolveSquare(a,b,c,&x1,&x2);
    
    switch (nroot)
      {
          case 0:     printf("NO SOLUTIONS\n");
                      break;
          case 1:     printf("ONE SOLUTION: %lg\n",x1);
                      break;
          case 2:     printf("TWO SOLUTIONS: %lg AND %lg\n",x1,x2);
                      break;
          case ANYX:  printf("ANY X\n");
                      break;
          default:    printf("ERROR\n");
                      return 1;
      }
    return 0;
}
int SolveSquare(double a,double b,double c,double* x1,
                double* x2)
{
    if (a==0)
        {
        if (b==0)
            {
            if (c==0)
                {
                return ANYX;
                }
            else /* a=0,b=0,c!=0*/
                {
                *x1=*x2=NOSOLUTIONS;
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
      
        if (D==0)
            {
            *x2=*x1=-b/(2*a);
            return 1;
            }
        if (D>0)
            {
            *x1=(-b+sqrt(D))/(2*a);
            *x2=(-b-sqrt(D))/(2*a);
            return 2;
            }
        if (D<0)
            {
            *x1=*x2=NOSOLUTIONS;
            return 0;
            }
        }
    return 100;
}
