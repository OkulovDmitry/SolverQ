// –¿«Œ¡–¿“‹—ﬂ — ¿——≈–“¿Ã»
//
//
//
//
//
//
//
//\
//
//
//
//


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <assert.h>

enum number_of_roots {NO_ROOTS, ONE_ROOT, TWO_ROOTS, INF_ROOTS};
enum boolean {FALSE, TRUE};

#define EPSILON 1e-10
#define MAX_ACCURACY 10

struct Quadratic_equation_param
{
    double coefficients[3];
    double roots[2];
    int number_of_roots;
};

struct Test_param
{
    double test_coefficients[3];
    double test_roots[2];
    int test_number_of_roots;
};

void run_tests();
int run_one_test(struct Test_param *test_parameters_ptr);
int turn_on();
void greeting(struct Quadratic_equation_param *parameters_ptr);
void clear_buffer();
int check_buffer();
int solve(struct Quadratic_equation_param *parameters_ptr);
int solve_linear(struct Quadratic_equation_param *parameters_ptr);
int solve_not_linear(struct Quadratic_equation_param *parameters_ptr);
int output(struct Quadratic_equation_param *parameters_ptr);
int compare(double x, double y);
int equality_check(double x, double y);
double convert_to_zero(double x);

int main()
{
    printf("[------------------------------Ultra Solver for quadratic equations by OKD------------------------------]\n");

    run_tests();

    while(turn_on())
    {
        struct Quadratic_equation_param parameters = {0};

        greeting(&parameters);

        assert(finite((parameters.coefficients)[0]) && "ERROR"); // ÒÔÓÒËÚ¸
        assert(finite((parameters.coefficients[1])) && "ERROR");
        assert(finite((parameters.coefficients[2])) && "ERROR");

        parameters.number_of_roots = solve(&parameters);

        output(&parameters);
    }

    printf("Thank you");

    return 0;
}

void run_tests()
{
    char test_choice = 'n';

    printf("Do you want to run unit-tests?\n(y\\n)? ");
    while(scanf("%c", &test_choice) != 1 || check_buffer())
    {
        printf("ERROR: Incorrect format\n");
        printf("Enter your choice again: ");
        clear_buffer();
    }

    if (test_choice == 'y')
    {
        struct Test_param test_parameters = {{1, 2, 1}, 1, {-1, NAN}};
        run_one_test(&test_parameters);

    }
}

int run_one_test(struct Test_param *test_parameters_ptr)
{
    assert(test_parameters_ptr != NULL && "ERROR");

    struct Quadratic_equation_param prog_test_parameters = {*(test_parameters_ptr->test_coefficients), 0, {0, NAN}};

    if (solve(&prog_test_parameters) == (test_parameters_ptr->test_number_of_roots))
    {
        printf("Test 1 OK\n");
    }
    else
    {
        printf("%i", &prog_test_parameters);
        printf("ERROR\n");
    }

}

int turn_on()
{
    int choice;
    printf("(0) Stop the programn (1) Solve the quadratic equtation\nEnter your choice: ");
    while(scanf("%i", &choice) != 1 || (choice != 0 && choice != 1) || check_buffer())
    {
        printf("ERROR: Incorrect format\n");
        printf("Enter choice again: ");
        clear_buffer();
    }

    assert(finite(choice) != 0 && "ERROR");

    return choice;
}

void greeting(struct Quadratic_equation_param *parameters_ptr)
{
    assert(&parameters_ptr->coefficients != NULL && "ERROR");
    assert(&parameters_ptr->roots != NULL && "ERROR");
    assert(&parameters_ptr->number_of_roots != NULL && "ERROR");

    printf("Enter coefficients: ");
    // ÒÔÓÒËÚ¸
    while (scanf("%lg %lg %lg", &(parameters_ptr->coefficients)[0],
                                &(parameters_ptr->coefficients)[1],
                                &(parameters_ptr->coefficients)[2]) != 3 || check_buffer())
    {
        printf("ERROR: Incorrect format\n");
        printf("Enter coefficients again: ");
        clear_buffer();
    }

    assert(finite((parameters_ptr->coefficients)[0]));
    assert(finite((parameters_ptr->coefficients)[1]));
    assert(finite((parameters_ptr->coefficients)[2]));
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

int solve(struct Quadratic_equation_param *parameters_ptr)
{
    //error
    assert(&parameters_ptr->coefficients != NULL);
    assert(&parameters_ptr->roots != NULL);
    assert(&parameters_ptr->number_of_roots != NULL);

    if (equality_check((parameters_ptr->coefficients)[0], 0))
    {
        return solve_linear(parameters_ptr);
    }
    else
    {
        return solve_not_linear(parameters_ptr);
    }
}

int solve_not_linear(struct Quadratic_equation_param *parameters_ptr)
{
    //ÒÔÓÒËÚ¸
    assert(&parameters_ptr->coefficients != NULL);
    assert(&parameters_ptr->roots != NULL);
    assert(&parameters_ptr->number_of_roots != NULL);

    double discr = (parameters_ptr->coefficients)[1]*(parameters_ptr->coefficients)[1] - 4*(parameters_ptr->coefficients)[0]*(parameters_ptr->coefficients)[2];

        if (compare(discr, 0))
        {
            //ÔÓ‰ÛÏ‡Ú¸
            double raw_x1 = (-(parameters_ptr->coefficients)[1] + sqrt(discr))/(2*(parameters_ptr->coefficients)[0]);
            double raw_x2 = (-(parameters_ptr->coefficients)[1] - sqrt(discr))/(2*(parameters_ptr->coefficients)[0]);

            (parameters_ptr->roots)[0] = convert_to_zero(raw_x1);
            (parameters_ptr->roots)[1] = convert_to_zero(raw_x2);

            return 2;
        }
        else if (equality_check(discr, 0))
        {
            double raw_x = -(parameters_ptr->coefficients)[1]/(2*(parameters_ptr->coefficients)[0]);

            (parameters_ptr->roots)[0] = equality_check(raw_x, 0) ? 0 : raw_x;

            return 1;
        }
        else
        {
            return NO_ROOTS;
        }
}

int solve_linear(struct Quadratic_equation_param *parameters_ptr)
{
    assert(&parameters_ptr->coefficients != NULL);
    assert(&parameters_ptr->roots != NULL);
    assert(&parameters_ptr->number_of_roots != NULL);

    if (equality_check((parameters_ptr->coefficients)[1], 0))
    {
        return (equality_check((parameters_ptr->coefficients)[2], 0)) ? INF_ROOTS : NO_ROOTS;
    }
    else
    {
        double raw_x = -(parameters_ptr->coefficients)[2]/(parameters_ptr->coefficients)[1];
        (parameters_ptr->roots)[0] = convert_to_zero(raw_x);

        return 1;
    }
}

int output(struct Quadratic_equation_param *parameters_ptr)
{
    assert(&parameters_ptr->coefficients != NULL);
    assert(&parameters_ptr->roots != NULL);
    assert(&parameters_ptr->number_of_roots != NULL);

    assert(finite((parameters_ptr->roots)[0]));
    assert(finite((parameters_ptr->roots)[1]));

    switch(parameters_ptr->number_of_roots)
    {
        case NO_ROOTS: printf("No roots\n");
                break;

        case ONE_ROOT: printf("This equation has one root: %.*g\n", MAX_ACCURACY, (parameters_ptr->roots)[0]);
                break;

        case TWO_ROOTS: printf("This equation has two roots: %.*g and %.*g\n", MAX_ACCURACY, (parameters_ptr->roots)[0], MAX_ACCURACY, (parameters_ptr->roots)[1]);
                break;

        case INF_ROOTS: printf("This equation has infinite number of roots.\n");
                break;

        default: printf("ERROR: number_of_roots = %i\n", parameters_ptr->number_of_roots);
    }
}

int compare(double x, double y)
{
    assert(finite(x));
    assert(finite(y));

    return (x - y > EPSILON) ? TRUE : FALSE;
}

int equality_check(double x, double y)
{
    assert(finite(x));
    assert(finite(y));

    return (fabs(x - y) <= EPSILON) ? TRUE : FALSE;
}

double convert_to_zero(double x)
{
    assert(finite(x));
    return equality_check(x, 0) ? 0 : x;
}


