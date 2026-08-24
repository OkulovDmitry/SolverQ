#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <assert.h>
#include <stddef.h>
#include "interface.h"

int turn_on()
{
    int choice = 0;
    printf("(0) Stop the programm (1) Solve the quadratic equtation\nEnter your choice: ");
    while(scanf("%i", &choice) != 1 || (choice != 0 && choice != 1) || check_buffer())
    {
        printf("ERROR: Incorrect format\n");
        printf("Enter choice again: ");
        clear_buffer();
    }

    assert(finite(choice) != 0 && "ERROR");

    //printf("I WAS HERE\n");

    return choice;
}

void greeting(struct Quadratic_equation_param *parameters_ptr)
{
    assert(&parameters_ptr->coefficients != NULL && "ERROR");
    assert(&parameters_ptr->roots != NULL && "ERROR");
    assert(&parameters_ptr->number_of_roots != NULL && "ERROR");

    printf("Please enter the coefficients (a, b, c) separated by spaces. Do not a trailing space at the end.\n");

    printf("Enter coefficients: ");
    while (scanf("%lg %lg %lg", &(parameters_ptr->coefficients)[0],
                                &(parameters_ptr->coefficients)[1],
                                &(parameters_ptr->coefficients)[2]) != 3 || !(isfinite(parameters_ptr->coefficients[0]))
                                                                         || !(isfinite(parameters_ptr->coefficients[1]))
                                                                         || !(isfinite(parameters_ptr->coefficients[2]))
                                                                         || check_buffer())
    {
        printf("ERROR: Incorrect format\n");
        printf("Enter coefficients again: ");
        clear_buffer();
    }

    assert(finite((parameters_ptr->coefficients)[0]));
    assert(finite((parameters_ptr->coefficients)[1]));
    assert(finite((parameters_ptr->coefficients)[2]));
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

    return 1;
}