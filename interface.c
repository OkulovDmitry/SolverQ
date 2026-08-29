#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <assert.h>
#include <stddef.h>
#include "solve_quadratic.h"
#include "interface.h"
#include "buffer_operations.h"
#include "my_assert_isfinite.h"
#include "my_assert_null.h"

int turn_on(void)
{
    int choice = 0;
    printf("(0) Stop the program (1) Solve the quadratic equation\nEnter your choice: ");
    while(scanf("%i", &choice) != 1 || (choice != 0 && choice != 1) || check_buffer())
    {
        printf("ERROR: Incorrect format\n");
        printf("Enter choice again: ");
        clear_buffer();
    }

    return choice;
}

void greeting(struct Quadratic_equation_param *parameters_ptr)
{
    assert_null(parameters_ptr, "parameters_ptr");

    printf("Please enter the coefficients (a, b, c) separated by spaces. Do not enter a trailing space at the end.\n");

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

}

void output(const struct Quadratic_equation_param *parameters_ptr)
{
    assert_null(parameters_ptr, "parameters_ptr");

    switch(parameters_ptr->number_of_roots)
    {
        case NO_ROOTS: 
            printf("No roots\n");
            break;

        case ONE_ROOT: 
            assert_isfinite((parameters_ptr->roots)[0], "(parameters_ptr->roots)[0]"); 
            printf("This equation has one root: %.*g\n", MAX_ACCURACY, (parameters_ptr->roots)[0]);
            break;

        case TWO_ROOTS: 
            assert_isfinite((parameters_ptr->roots)[0], "(parameters_ptr->roots)[0]");
            assert_isfinite((parameters_ptr->roots)[1], "(parameters_ptr->roots)[1]");
            printf("This equation has two roots: %.*g and %.*g\n", MAX_ACCURACY, 
                                            (parameters_ptr->roots)[0], 
                                            MAX_ACCURACY, 
                                            (parameters_ptr->roots)[1]);
            break;

        case INF_ROOTS: 
            printf("This equation has infinite number of roots.\n");
            break;

        default: printf("ERROR: number_of_roots = %i\n", parameters_ptr->number_of_roots);
    }
}