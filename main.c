#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <assert.h>

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

    assert(isnan(a_coeff) == 0);
    assert(isinf(a_coeff) == 0);
    assert(isnan(b_coeff) == 0);
    assert(isinf(b_coeff) == 0);
    assert(isnan(c_coeff) == 0);
    assert(isinf(c_coeff) == 0);

    int number_of_roots = solve(a_coeff, b_coeff, c_coeff, &x1, &x2);

    output(number_of_roots, x1, x2);

    return 0;
}

void greeting(double *a_ptr, double *b_ptr, double *c_ptr)
{
    assert(a_ptr != NULL);
    assert(b_ptr != NULL);
    assert(c_ptr != NULL);

    double a_TEMPORARY = 0, b_TEMPORARY = 0, c_TEMPORARY = 0;
    printf("[------------------------------Ultra Solver for quadratic equations by OKD------------------------------]\n");
    printf("Enter coefficients: ");
    while (scanf("%lf %lf %lf", &a_TEMPORARY, &b_TEMPORARY, &c_TEMPORARY) != 3 || check_buffer())
    {
        printf("ERROR: Incorrect format\n");
        printf("Enter coefficients again:");
        clear_buffer();
    }

    assert(isnan(a_TEMPORARY) == 0);
    assert(isnan(b_TEMPORARY) == 0);
    assert(isnan(c_TEMPORARY) == 0);

    assert(isinf(a_TEMPORARY) == 0);
    assert(isinf(b_TEMPORARY) == 0);
    assert(isinf(c_TEMPORARY) == 0);

    *a_ptr = a_TEMPORARY;
    *b_ptr = b_TEMPORARY;
    *c_ptr = c_TEMPORARY;
}

void clear_buffer()
{
    while(getchar() != '\n');
}
int check_buffer()
{
    char buffer = getchar();
    return (buffer != '\n') ? TRUE : FALSE;
}

int solve(double a_coeff, double b_coeff, double c_coeff, double *x1_ptr, double *x2_ptr)
{
    assert(x1_ptr != NULL);
    assert(x2_ptr != NULL);

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

            assert(isnan(raw_x) == 0);
            assert(isinf(raw_x) == 0);
            assert(isnan(*x1_ptr) == 0);
            assert(isinf(*x1_ptr) == 0);

            return 1;
        }
    }
    else
    {
        double discr = b_coeff*b_coeff - 4*a_coeff*c_coeff;

        assert(isnan(discr) == 0);
        assert(isinf(discr) == 0);

        if (compare(discr, 0))
        {
            double raw_x1 = (-b_coeff + sqrt(discr))/(2*a_coeff);
            double raw_x2 = (-b_coeff - sqrt(discr))/(2*a_coeff);

            assert(isnan(raw_x1) == 0);
            assert(isinf(raw_x1) == 0);
            assert(isnan(raw_x2) == 0);
            assert(isinf(raw_x2) == 0);

            *x1_ptr = convert_to_zero(raw_x1);
            *x2_ptr = convert_to_zero(raw_x2);

            assert(isnan(*x1_ptr) == 0);
            assert(isinf(*x1_ptr) == 0);
            assert(isnan(*x2_ptr) == 0);
            assert(isinf(*x2_ptr) == 0);

            return 2;
        }
        else if (equality_check(discr, 0))
        {
            double raw_x = -b_coeff/(2*a_coeff);

            assert(isnan(raw_x) == 0);
            assert(isinf(raw_x) == 0);

            *x1_ptr = equality_check(raw_x, 0) ? 0 : raw_x;

            assert(isnan(*x1_ptr) == 0);
            assert(isinf(*x1_ptr) == 0);

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
    assert(isnan(x1) == 0);
    assert(isinf(x1) == 0);
    assert(isnan(x2) == 0);
    assert(isinf(x2) == 0);

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
    assert(isnan(x) == 0);
    assert(isinf(x) == 0);
    assert(isnan(y) == 0);
    assert(isinf(y) == 0);

    return (x - y > EPSILON) ? TRUE : FALSE;
}

int equality_check(double x, double y)
{
    assert(isnan(x) == 0);
    assert(isinf(x) == 0);
    assert(isnan(y) == 0);
    assert(isinf(y) == 0);

    return (fabs(x - y) <= EPSILON) ? TRUE : FALSE;
}

double convert_to_zero(double x)
{
    assert(isnan(x) == 0);
    assert(isinf(x) == 0);

    return equality_check(x, 0) ? 0 : x;
}


