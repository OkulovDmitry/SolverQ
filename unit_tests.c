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

    assert(finite(test_choice));

    if (test_choice == 'y')
    {
        // D>0
        struct Quadratic_equation_param test_1 = {.coefficients = {1, -5, 6}, .roots = {2, 3}, .number_of_roots = TWO_ROOTS};
        struct Quadratic_equation_param test_2 = {.coefficients = {1, -2, -3}, .roots = {-1, 3}, .number_of_roots = TWO_ROOTS};
        struct Quadratic_equation_param test_3 = {.coefficients = {2, 5, -3}, .roots = {-3, 0.5}, .number_of_roots = TWO_ROOTS};
        struct Quadratic_equation_param test_4 = {.coefficients = {1, -6, 8}, .roots = {4, 2}, .number_of_roots = TWO_ROOTS};
        struct Quadratic_equation_param test_5 = {.coefficients = {-1, 3, 4}, .roots = {4, -1}, .number_of_roots = TWO_ROOTS};
        // D = 0, передавать NAN вторым в массиве roots
        struct Quadratic_equation_param test_6 = {.coefficients = {1, -4, 4}, .roots = {2, NAN}, .number_of_roots = 1};
        struct Quadratic_equation_param test_7 = {.coefficients = {1.6, 4, 2.5}, .roots = {-1.25, NAN}, .number_of_roots = ONE_ROOT};
        struct Quadratic_equation_param test_8 = {.coefficients = {0.16, -0.8, 1}, .roots = {2.5, NAN}, .number_of_roots = ONE_ROOT};
        struct Quadratic_equation_param test_9 = {.coefficients = {0.2, 1.2, 1.8}, .roots = {-3, NAN}, .number_of_roots = ONE_ROOT};
        struct Quadratic_equation_param test_10 = {.coefficients = {0.8, -4, 5}, .roots = {2.5, NAN}, .number_of_roots = ONE_ROOT};
        // D < 0
        struct Quadratic_equation_param test_11 = {.coefficients = {1.4, 1.5, 2.1}, .roots = {NAN, NAN}, .number_of_roots = NO_ROOTS};
        struct Quadratic_equation_param test_12 = {.coefficients = {0.6, -0.8, 1.3}, .roots = {NAN, NAN}, .number_of_roots = NO_ROOTS};
        struct Quadratic_equation_param test_13 = {.coefficients = {2.2, 3.1, 1.5}, .roots = {NAN, NAN}, .number_of_roots = NO_ROOTS};
        struct Quadratic_equation_param test_14 = {.coefficients = {0.5, -0.2, 0.8}, .roots = {NAN, NAN}, .number_of_roots = NO_ROOTS};
        struct Quadratic_equation_param test_15 = {.coefficients = {1.1, 0.5, 0.9}, .roots = {NAN, NAN}, .number_of_roots = NO_ROOTS};
        // linear one root
        struct Quadratic_equation_param test_16 = {.coefficients = {0, 1.5, -4.2}, .roots = {2.8, NAN}, .number_of_roots = ONE_ROOT};
        struct Quadratic_equation_param test_17 = {.coefficients = {0, 2.4, 0.6}, .roots = {-0.25, NAN}, .number_of_roots = ONE_ROOT};
        // inf
        struct Quadratic_equation_param test_19 = {.coefficients = {0, 0, 0}, .roots = {NAN, NAN}, .number_of_roots = INF_ROOTS};
        // linear no roots
        struct Quadratic_equation_param test_18 = {.coefficients = {0, 0, 5.2}, .roots = {NAN, NAN}, .number_of_roots = NO_ROOTS};


        run_one_test(&test_1);
        run_one_test(&test_2);
        run_one_test(&test_3);
        run_one_test(&test_4);
        run_one_test(&test_5);
        run_one_test(&test_6);
        run_one_test(&test_7);
        run_one_test(&test_8);
        run_one_test(&test_9);
        run_one_test(&test_10);
        run_one_test(&test_11);
        run_one_test(&test_12);
        run_one_test(&test_13);
        run_one_test(&test_14);
        run_one_test(&test_15);
        run_one_test(&test_16);
        run_one_test(&test_17);
        run_one_test(&test_18);
        run_one_test(&test_19);
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
    printf("Program values:%i - number of roots %lg %lg - roots", test_1_ptr->number_of_roots, test_1_ptr->roots[0], test_1_ptr->roots[1]);
    printf("===================================================================================\n");
}
