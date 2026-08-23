#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <assert.h>
#include "unit_tests.h"

void run_tests()
{
    char test_choice = 'n';

    printf("Do you want to run unit-tests?\n(y\\n)? ");
    while(scanf("%c", &test_choice) != 1 || (test_choice != 'y' && test_choice != 'n') || check_buffer())
    {
        printf("ERROR: Incorrect formats\n");
        printf("(y\\n)?: ");
        clear_buffer();
    }

    if (test_choice == 'y')
    {
        struct Quadratic_equation_param test_1 = {.coefficients = {1, 2, 1}, .roots = {-1, NAN}, .number_of_roots = 1};
        run_one_test(&test_1);
    }
    //printf("test finished\n");
}

void run_one_test(struct Quadratic_equation_param *test_1_ptr)
{
    assert(&test_1_ptr->coefficients != NULL && "ERROR");
    assert(&test_1_ptr->number_of_roots != NULL && "ERROR");
    assert(&test_1_ptr->roots != NULL && "ERROR");

    int test_number_of_roots = test_1_ptr->number_of_roots;
    double test_root_1 = test_1_ptr->roots[0];
    double test_root_2 = test_1_ptr->roots[1];

    test_1_ptr->roots[0] = 0;
    test_1_ptr->roots[1] = 0;
    test_1_ptr->number_of_roots = 0;

    solve(test_1_ptr);

    if (test_1_ptr->number_of_roots == 0) 
    {
        if (test_1_ptr->number_of_roots == test_number_of_roots)
        {
            printf("Test first type OK\n"); return;
        }
    }
    if (test_1_ptr->number_of_roots == 1)
    {
        if (test_1_ptr->number_of_roots == test_number_of_roots && equality_check((test_1_ptr->roots)[0], test_root_1))
        {
            printf("Test second type OK\n"); return;
        }
    }
    if (test_1_ptr->number_of_roots == 2)
    {
        if (test_1_ptr->number_of_roots == test_number_of_roots && equality_check(test_1_ptr->roots[0], test_root_1)
                                                                    && equality_check(test_1_ptr->roots[1], test_root_2))
        {
            printf("Test third type OK\n"); return;
        }
    }

    printf("%i %lg %lg\n", test_1_ptr->number_of_roots, test_1_ptr->roots[0], test_1_ptr->roots[1]);
    printf("ERROR\n");
}
