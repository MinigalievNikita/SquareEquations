///@file
#include <stdio.h>
#include <math.h>

#include <assert.h>

const int ANYX = -10;
const int NOSOLUTIONS = -1;
const int ERROR = -100;
const int LIM = 1E-6;
/**
 Function SolveSquare search how many roots square equation has.
 @param a - 1st coef
 @param b - 2nd coef
 @param c - 3rd coef
 @param x1 - 1st root
 @param x2 - 2nd root
 @return number of roots
**/

int SolveSquare (double a,double b,double c,double* x1,
                double* x2);

/**
Function IsZero compare variables with 0.
@param param  - input number
@return 1 when number is NULL and 0 in others cases
**/

int IsZero (double param);
 
/**
Function ENTER check correctness of input data
**/

int Enter  (double* coef);

/**
This is program which solves any of square equation ax^2+bx+c=0.
**/

int main()
{
    printf ("FIND SOLUTIONS OF SQUARE EQUATION\n");
    
    printf ("ENTER COEFFICIENTS:");
    
    double a = 0, b = 0, c = 0; /* a,b,c - коэфициенты квад ур*/
    
    if (Enter (&a) == ERROR)
        {
        printf ("Wrong type of input data\n");
        return 1;
        }
    if (Enter (&b) == ERROR)
        {
        printf ("Wrong type of input data\n");
        return 1;
        }
    if (Enter (&c) == ERROR)
        {
        printf ("Wrong type of input data\n");
        return 1;
        }
    
    double x1 = 0, x2 = 0;   /* x1 и x2 - корни квад ур*/
    int nroot = SolveSquare (a, b, c ,&x1, &x2);
    
    switch (nroot)
      {
          case 0:     printf ("NO SOLUTIONS\n");
                      break;
          case 1:     printf ("ONE SOLUTION: %lg\n", x1);
                      break;
          case 2:     printf ("TWO SOLUTIONS: %lg AND %lg\n", x1, x2);
                      break;
          case ANYX:  printf ("ANY X\n");
                      break;
          default:    printf ("ERROR\n");
                      return 1;
      }
    return 0;
}

int SolveSquare (double a, double b, double c, double* x1,
                double* x2)

{
    assert (x1);
    assert (x2);
    assert (x1 != x2);
    if (IsZero(a) == 1)
        {
        if (IsZero(b) == 1)
            {
            if (IsZero(c) == 1)
                {
                return ANYX;
                }
            else /* a = 0, b = 0, c != 0*/
                {
                *x1 = *x2 = NOSOLUTIONS;
                return 0;
                }
            }
        else /* a = 0, b != 0 */
            {
            *x2 = *x1 = (-c/b);
            return 1;;
            }
        }
    else /* a != 0*/
        {
        double D = b*b - 4*a*c; /* вычисление дискриминанта*/
      
        if (IsZero(D) == 1)
            {
            *x2 = *x1 = -b / (2*a);
            return 1;
            }
        if (D > 0)
            {
            *x1 = (-b+sqrt(D)) / (2*a);
            *x2 = (-b-sqrt(D)) / (2*a);
            return 2;
            }
        if (D < 0)
            {
            *x1 = *x2 = NOSOLUTIONS;
            return 0;
            }
        }
    return ERROR;
}

int IsZero (double param)
    {
    if (param < 1E-6 && -(1E-6) < param)  return 1;
    return 0;
    }

int Enter (double* coef)
    {
    assert (coef);
        
    double y;
    if (scanf ("%lg", &y) != 0)
        {
        *coef = y;
        return 0;
        }
    return ERROR;
    }
