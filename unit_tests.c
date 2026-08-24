#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <assert.h>
#include <stddef.h>
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

    assert(finite(test_choice));

    if (test_choice == 'y')
    {
        struct Quadratic_equation_param unit_test_keys[19] = {
            // D > 0
            {.coefficients = {1, -5, 6}, .roots = {2, 3}, .number_of_roots = TWO_ROOTS},
            {.coefficients = {1, -2, -3}, .roots = {-1, 3}, .number_of_roots = TWO_ROOTS},
            {.coefficients = {2, 5, -3}, .roots = {-3, 0.5}, .number_of_roots = TWO_ROOTS},
            {.coefficients = {1, -6, 8}, .roots = {4, 2}, .number_of_roots = TWO_ROOTS},
            {.coefficients = {-1, 3, 4}, .roots = {4, -1}, .number_of_roots = TWO_ROOTS},
            // D = 0, передавать NAN вторым в массиве roots
            {.coefficients = {1, -4, 4}, .roots = {2, NAN}, .number_of_roots = 1},
            {.coefficients = {1.6, 4, 2.5}, .roots = {-1.25, NAN}, .number_of_roots = ONE_ROOT},
            {.coefficients = {0.16, -0.8, 1}, .roots = {2.5, NAN}, .number_of_roots = ONE_ROOT},
            {.coefficients = {0.2, 1.2, 1.8}, .roots = {-3, NAN}, .number_of_roots = ONE_ROOT},
            {.coefficients = {0.8, -4, 5}, .roots = {2.5, NAN}, .number_of_roots = ONE_ROOT},
            // D < 0
            {.coefficients = {1.4, 1.5, 2.1}, .roots = {NAN, NAN}, .number_of_roots = NO_ROOTS},
            {.coefficients = {0.6, -0.8, 1.3}, .roots = {NAN, NAN}, .number_of_roots = NO_ROOTS},
            {.coefficients = {2.2, 3.1, 1.5}, .roots = {NAN, NAN}, .number_of_roots = NO_ROOTS},
            {.coefficients = {0.5, -0.2, 0.8}, .roots = {NAN, NAN}, .number_of_roots = NO_ROOTS},
            {.coefficients = {1.1, 0.5, 0.9}, .roots = {NAN, NAN}, .number_of_roots = NO_ROOTS},
            // linear
            {.coefficients = {0, 1.5, -4.2}, .roots = {2.8, NAN}, .number_of_roots = ONE_ROOT},
            {.coefficients = {0, 2.4, 0.6}, .roots = {-0.25, NAN}, .number_of_roots = ONE_ROOT},
            // inf
            {.coefficients = {0, 0, 0}, .roots = {NAN, NAN}, .number_of_roots = INF_ROOTS},
            // linear no roots
            {.coefficients = {0, 0, 5.2}, .roots = {NAN, NAN}, .number_of_roots = NO_ROOTS}
        };

        for (int i = 0; i < NUMBER_OF_UNIT_TESTS; i++)
        {
            run_one_test(&unit_test_keys[i]);
        }
    }
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

    if (test_1_ptr->number_of_roots == NO_ROOTS) 
    {
        if (test_1_ptr->number_of_roots == test_number_of_roots)
        {
            printf("Test no roots type OK\n"); return;
        }
    }
    if (test_1_ptr->number_of_roots == ONE_ROOT)
    {
        assert(finite(test_root_1));
        assert(finite((test_1_ptr->roots)[0]));

        if (test_1_ptr->number_of_roots == test_number_of_roots && equality_check((test_1_ptr->roots)[0], test_root_1))
        {
            printf("Test one root type OK\n"); return;
        }
    }
    if (test_1_ptr->number_of_roots == TWO_ROOTS)
    {
        assert(finite(test_root_1));
        assert(finite(test_root_2));
        assert(finite((test_1_ptr->roots)[0]));
        assert(finite((test_1_ptr->roots)[1]));

        if (test_root_1 > test_root_2)
        {
            swap(&test_root_1, &test_root_2);
        }
        if (test_1_ptr->number_of_roots == test_number_of_roots && equality_check(test_1_ptr->roots[0], test_root_1)
                                                                    && equality_check(test_1_ptr->roots[1], test_root_2))
        {
            printf("Test two roots type OK\n"); return;
        }
    }
    if (test_1_ptr->number_of_roots == INF_ROOTS)
    {
        if (test_1_ptr->number_of_roots == test_number_of_roots)
        {
            printf("Test inf roots type OK\n"); return;
        }
    }

    printf("=======================================ERROR=======================================\n");
    printf("Expected values:%i - number of roots %lg %lg - roots\n", test_number_of_roots, test_root_1, test_root_2);
    printf("Program values:%i - number of roots %lg %lg - roots\n", test_1_ptr->number_of_roots, test_1_ptr->roots[0], test_1_ptr->roots[1]);
    printf("===================================================================================\n");
}
