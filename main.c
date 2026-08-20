#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#define NO_ROOTS 0
#define ONE_ROOT 1
#define TWO_ROOTS 2
#define INF_ROOTS 3
#define TRUE 1
#define FALSE 0
#define EPSILON 1e-10

void greeting(double *a_ptr, double *b_ptr, double *c_ptr);
void clear_buffer();
int solve(double a_coeff, double b_coeff, double c_coeff, double *x1_ptr, double *x2_ptr);
int output(int number_of_roots, double x1, double x2);
int compare(double x, double y);
int equality_check(double x, double y);
double convert_to_zero(double x);

int main()
{

    double a_coeff = 0, b_coeff = 0, c_coeff = 0;
    double x1 = 0, x2 = 0;

    greeting(&a_coeff, &b_coeff, &c_coeff);

    int number_of_roots = solve(a_coeff, b_coeff, c_coeff, &x1, &x2);

    output(number_of_roots, x1, x2);

    return 0;
}

void greeting(double *a_ptr, double *b_ptr, double *c_ptr)
{
    double a_TEMPORARY, b_TEMPORARY, c_TEMPORARY;
    printf("[------------------------------Ultra Solver for quadratic equations by OKD------------------------------]\n");
    printf("Enter coefficients: ");
    while (scanf("%lf %lf %lf", &a_TEMPORARY, &b_TEMPORARY, &c_TEMPORARY) != 3)
    {
        printf("ERROR: Incorrect format\n");
        printf("Enter coefficients again:");
        clear_buffer();
    }
    *a_ptr = a_TEMPORARY;
    *b_ptr = b_TEMPORARY;
    *c_ptr = c_TEMPORARY;
}

void clear_buffer()
{
    while(getchar() != '\n');
}

int solve(double a_coeff, double b_coeff, double c_coeff, double *x1_ptr, double *x2_ptr)
{
    if (equality_check(a_coeff, 0))
    {
        if (equality_check(b_coeff, 0))
        {
            return (equality_check(c_coeff, 0)) ? INF_ROOTS : NO_ROOTS;
        }
        else
        {
            double raw_x = -c_coeff/b_coeff;
            *x1_ptr = convert_to_zero(raw_x);
            return 1;
        }
    }
    else
    {
        double discr = b_coeff*b_coeff - 4*a_coeff*c_coeff;
        if (compare(discr, 0))
        {
            double raw_x1 = (-b_coeff + sqrt(discr))/(2*a_coeff);
            double raw_x2 = (-b_coeff - sqrt(discr))/(2*a_coeff);
            *x1_ptr = convert_to_zero(raw_x1);
            *x2_ptr = convert_to_zero(raw_x2);
            return 2;
        }
        else if (equality_check(discr, 0))
        {
            double raw_x = -b_coeff/(2*a_coeff);
            *x1_ptr = equality_check(raw_x, 0) ? 0 : raw_x;

            return 1;
        }
        else
        {
            return NO_ROOTS;
        }
    }
}

int output(int number_of_roots, double x1, double x2)
{
    int MAX_ACCURACY = 10;
    switch(number_of_roots)
    {
        case NO_ROOTS: printf("No roots");
                break;

        case ONE_ROOT: printf("This equation has one root: %.*g", MAX_ACCURACY, x1);
                break;

        case TWO_ROOTS: printf("This equation has two roots: %.*g and %.*g", MAX_ACCURACY, x1, MAX_ACCURACY, x2);
                break;

        case INF_ROOTS: printf("This equation has infinite number of roots.");
                break;

        default: printf("ERROR: number_of_roots = %i", &number_of_roots);
    }
}

int compare(double x, double y)
{
    return (x - y > EPSILON) ? TRUE : FALSE;
}

int equality_check(double x, double y)
{
    return (fabs(x - y) <= EPSILON) ? TRUE : FALSE;
}

double convert_to_zero(double x)
{
    return equality_check(x, 0) ? (double)0.0 : x;
}


