#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <assert.h>

enum number_of_roots {NO_ROOTS, ONE_ROOT, TWO_ROOTS, INF_ROOTS};
enum boolean {FALSE, TRUE};

#define EPSILON 1e-10
#define MAX_ACCURACY 10

int turn_on();
void greeting(double *a_ptr, double *b_ptr, double *c_ptr);
void clear_buffer();
int solve(double a_coeff, double b_coeff, double c_coeff, double *x1_ptr, double *x2_ptr);
int output(int number_of_roots, double x1, double x2);
int compare(double x, double y);
int equality_check(double x, double y);
double convert_to_zero(double x);

int main()
{
    printf("[------------------------------Ultra Solver for quadratic equations by OKD------------------------------]\n");
    while(turn_on())
    {
        double a_coeff = 0, b_coeff = 0, c_coeff = 0;
        double x1 = 0, x2 = 0;

        greeting(&a_coeff, &b_coeff, &c_coeff);

        assert(finite(a_coeff) != 0);
        assert(finite(b_coeff) != 0);
        assert(finite(c_coeff) != 0);

        int number_of_roots = solve(a_coeff, b_coeff, c_coeff, &x1, &x2);

        output(number_of_roots, x1, x2);
    }

    printf("Thank you");

    return 0;
}

int turn_on()
{
    int choice;
    printf("(0) Stop the programn (1) Solve the quadratic equtation\nEnter your choice: ");
    while(scanf("%i", &choice) != 1 || (choice != 0 && choice != 1) || check_buffer())
    {
        printf("ERROR: Incorrect format\n");
        printf("Enter choice again:");
        clear_buffer();
    }

    assert(finite(choice) != 0);

    return choice;
}

void greeting(double *a_ptr, double *b_ptr, double *c_ptr)
{
    assert(a_ptr != NULL);
    assert(b_ptr != NULL);
    assert(c_ptr != NULL);

    printf("Enter coefficients: ");
    while (scanf("%lf %lf %lf", &*a_ptr, &*b_ptr, &*c_ptr) != 3 || check_buffer())
    {
        printf("ERROR: Incorrect format\n");
        printf("Enter coefficients again: ");
        clear_buffer();
    }

    assert(finite(*a_ptr) != 0);
    assert(finite(*a_ptr) != 0);
    assert(finite(*a_ptr) != 0);
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
    assert(finite(x1) != 0);
    assert(finite(x2) != 0);

    switch(number_of_roots)
    {
        case NO_ROOTS: printf("No roots\n");
                break;

        case ONE_ROOT: printf("This equation has one root: %.*g\n", MAX_ACCURACY, x1);
                break;

        case TWO_ROOTS: printf("This equation has two roots: %.*g and %.*g\n", MAX_ACCURACY, x1, MAX_ACCURACY, x2);
                break;

        case INF_ROOTS: printf("This equation has infinite number of roots.\n");
                break;

        default: printf("ERROR: number_of_roots = %i\n", &number_of_roots);
    }
}

int compare(double x, double y)
{
    assert(finite(x) != 0);
    assert(finite(y) != 0);

    return (x - y > EPSILON) ? TRUE : FALSE;
}

int equality_check(double x, double y)
{
    assert(finite(x) != 0);
    assert(finite(y) != 0);

    return (fabs(x - y) <= EPSILON) ? TRUE : FALSE;
}

double convert_to_zero(double x)
{
    assert(finite(x) != 0);
    return equality_check(x, 0) ? 0 : x;
}


