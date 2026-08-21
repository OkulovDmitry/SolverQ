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
void greeting(double coefficients_ptr[]);
void clear_buffer();
int solve(double coefficients_ptr[], double roots_ptr[]);
int output(int number_of_roots, double roots_ptr[]);
int compare(double x, double y);
int equality_check(double x, double y);
double convert_to_zero(double x);

int main()
{
    printf("[------------------------------Ultra Solver for quadratic equations by OKD------------------------------]\n");
    while(turn_on())
    {
        double coefficients[3];
        double roots[2];

        greeting(coefficients);

        assert(finite(coefficients[0]) != 0);
        assert(finite(coefficients[1]) != 0);
        assert(finite(coefficients[2]) != 0);

        int number_of_roots = solve(coefficients, roots);

        output(number_of_roots, roots);
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

void greeting(double coefficients_ptr[])
{
    assert(coefficients_ptr != NULL);

    printf("Enter coefficients: ");
    while (scanf("%lg %lg %lg", &coefficients_ptr[0], &coefficients_ptr[1], &coefficients_ptr[2]) != 3 || check_buffer())
    {
        printf("ERROR: Incorrect format\n");
        printf("Enter coefficients again: ");
        clear_buffer();
    }

    assert(finite(coefficients_ptr[0]) != 0);
    assert(finite(coefficients_ptr[1]) != 0);
    assert(finite(coefficients_ptr[2]) != 0);
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

int solve(double coefficients_ptr[], double roots_ptr[])
{
    assert(coefficients_ptr != NULL);

    if (equality_check(coefficients_ptr[0], 0))
    {
        if (equality_check(coefficients_ptr[1], 0))
        {
            return (equality_check(coefficients_ptr[2], 0)) ? INF_ROOTS : NO_ROOTS;
        }
        else
        {
            double raw_x = -coefficients_ptr[2]/coefficients_ptr[1];
            roots_ptr[0] = convert_to_zero(raw_x);

            return 1;
        }
    }
    else
    {
        double discr = coefficients_ptr[1]*coefficients_ptr[1] - 4*coefficients_ptr[0]*coefficients_ptr[2];

        if (compare(discr, 0))
        {
            double raw_x1 = (-coefficients_ptr[1] + sqrt(discr))/(2*coefficients_ptr[0]);
            double raw_x2 = (-coefficients_ptr[1] - sqrt(discr))/(2*coefficients_ptr[0]);

            roots_ptr[0] = convert_to_zero(raw_x1);
            roots_ptr[1] = convert_to_zero(raw_x2);

            return 2;
        }
        else if (equality_check(discr, 0))
        {
            double raw_x = -coefficients_ptr[1]/(2*coefficients_ptr[0]);

            roots_ptr[0] = equality_check(raw_x, 0) ? 0 : raw_x;

            return 1;
        }
        else
        {
            return NO_ROOTS;
        }
    }
}

int output(int number_of_roots, double roots_ptr[])
{
    assert(finite(roots_ptr[0]) != 0);
    assert(finite(roots_ptr[1]) != 0);

    switch(number_of_roots)
    {
        case NO_ROOTS: printf("No roots\n");
                break;

        case ONE_ROOT: printf("This equation has one root: %.*g\n", MAX_ACCURACY, roots_ptr[0]);
                break;

        case TWO_ROOTS: printf("This equation has two roots: %.*g and %.*g\n", MAX_ACCURACY, roots_ptr[0], MAX_ACCURACY, roots_ptr[1]);
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


