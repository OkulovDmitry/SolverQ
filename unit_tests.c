#include <stdio.h>
#include <string.h>
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
        FILE *unit_tests_file = fopen("unit_test_keys.txt", "r");
        assert(unit_tests_file != NULL);

        struct Quadratic_equation_param unit_test_key; char roots_status_str[10];

        while(fscanf(unit_tests_file, "%lg %lg %lg %lg %lg %s", &unit_test_key.coefficients[0],
                                                &unit_test_key.coefficients[1],
                                                &unit_test_key.coefficients[2],
                                                &unit_test_key.roots[0],
                                                &unit_test_key.roots[1],
                                                roots_status_str) == 6)
        {

            if (strcmp(roots_status_str,"NO_ROOTS") == 1 &&
                strcmp(roots_status_str,"ONE_ROOT") == 1 &&
                strcmp(roots_status_str,"TWO_ROOTS") == 1 &&
                strcmp(roots_status_str,"INF_ROOTS") == 1) 
            {
                remorse();
            }

            if (is_file_buffer_empty(unit_tests_file) == FALSE)
            {
                remorse();
            }

            assert(roots_status_str != NULL);

            if (strcmp(roots_status_str,"NO_ROOTS") == 0) {unit_test_key.number_of_roots = NO_ROOTS;}
            else if (strcmp(roots_status_str, "ONE_ROOT") == 0) {unit_test_key.number_of_roots = ONE_ROOT;}
            else if (strcmp(roots_status_str, "TWO_ROOTS") == 0) {unit_test_key.number_of_roots = TWO_ROOTS;}
            else if (strcmp(roots_status_str, "INF_ROOTS") == 0) {unit_test_key.number_of_roots = INF_ROOTS;}

            run_one_test(&unit_test_key);

            fseek(unit_tests_file, -1, SEEK_CUR);
            clear_file_buffer(unit_tests_file);

            if (is_file_end(unit_tests_file))
            {
                break;
            }
            else
            {
                fseek(unit_tests_file, -1, SEEK_CUR);
            }
        }

        if (!(is_file_end(unit_tests_file)))
        {
            remorse();
        }

        fclose(unit_tests_file);
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

void remorse()
{
    printf("Yout test are wrong!!! REPENT: ");
    char REMORSE[1000];
    scanf("%s", REMORSE);
    exit(1);
}
