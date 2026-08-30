#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <assert.h>
#include <stddef.h>
#include "unit_tests.h"
#include "buffer_operations.h"
#include "my_assert_isfinite.h"
#include "my_assert_null.h"

void is_run_tests(char str[])
{
    if (strcmp(str, "--run-tests") == 0)
    {
        run_tests();
        exit(0);
    }
}

void run_tests(void)
{
    struct Quadratic_equation_param unit_test_key; 
    char roots_status_str[10] = {0};
    
    FILE *unit_tests_file = fopen("unit_test_keys.txt", "r");
    assert(unit_tests_file != NULL && "ERROR: file unit_test_keys.txt is NULL");

    int NUMBER_OF_TESTS = 0;

    skip_comments(unit_tests_file);
    
    while(fscanf(unit_tests_file, "%lg %lg %lg %lg %lg %9s", &unit_test_key.coefficients[0],
                                                             &unit_test_key.coefficients[1],
                                                             &unit_test_key.coefficients[2],
                                                             &unit_test_key.roots[0],
                                                             &unit_test_key.roots[1],
                                                             roots_status_str) == 6)
    {
        NUMBER_OF_TESTS++;
        is_format_roots_status_str_correct(NUMBER_OF_TESTS, roots_status_str, &unit_test_key.roots[0], 
                                                                              &unit_test_key.roots[1]);

        skip_end_of_line_comment(unit_tests_file);
        if (is_file_buffer_empty(unit_tests_file) == FALSE)
        {
            error_test(NUMBER_OF_TESTS, roots_status_str, &unit_test_key.roots[0], &unit_test_key.roots[1]);
        }

        assert_null(roots_status_str, "roots_status_str");

        test_number_of_roots_initialization(roots_status_str, &unit_test_key.number_of_roots);
        run_one_test(NUMBER_OF_TESTS, &unit_test_key);
        clear_file_buffer(unit_tests_file);

        if (is_file_end(unit_tests_file)){ break;}
        else{ fseek(unit_tests_file, -1, SEEK_CUR);}

        skip_comments(unit_tests_file);
    }

    if (!(is_file_end(unit_tests_file)))
    { 
        error_test(NUMBER_OF_TESTS, roots_status_str, &unit_test_key.roots[0], &unit_test_key.roots[0]);
    }

    fclose(unit_tests_file);
}

void skip_end_of_line_comment(FILE *unit_tests_file)
{
    assert_null(unit_tests_file, "unit_tests_file");

    int symbol = fgetc(unit_tests_file);
    if (symbol == ' ')
    {
        symbol = fgetc(unit_tests_file);
        if (symbol == '#')
        {
            while (symbol != '\n') { symbol = fgetc(unit_tests_file);}
        }
    }

    ungetc(symbol, unit_tests_file);
}

void skip_comments(FILE *unit_tests_file)
{
    assert_null(unit_tests_file, "unit_tests_file");

    int symbol = fgetc(unit_tests_file);
    while (symbol == '#')
    {
        while (symbol != '\n') { symbol = fgetc(unit_tests_file);}
        symbol = fgetc(unit_tests_file);
    } 
    
    ungetc(symbol, unit_tests_file);
}

void is_format_roots_status_str_correct(int NUMBER_OF_TESTS_ptr,char roots_status_str_ptr[], 
                                                                     double *test_key_1_ptr, 
                                                                     double *test_key_2_ptr)
{
    if (strcmp(roots_status_str_ptr,"NO_ROOTS") != 0 &&
        strcmp(roots_status_str_ptr,"ONE_ROOT") != 0 &&
        strcmp(roots_status_str_ptr,"TWO_ROOTS") != 0 &&
        strcmp(roots_status_str_ptr,"INF_ROOTS") != 0) 
    {
        error_test(NUMBER_OF_TESTS_ptr, roots_status_str_ptr, test_key_1_ptr, test_key_2_ptr);
        exit(0); 
    }
}

void test_number_of_roots_initialization(char roots_status_str[], int *number_of_roots_ptr)
{
    if (strcmp(roots_status_str,"NO_ROOTS") == 0) {*number_of_roots_ptr = NO_ROOTS;}
    else if (strcmp(roots_status_str, "ONE_ROOT") == 0) {*number_of_roots_ptr = ONE_ROOT;}
    else if (strcmp(roots_status_str, "TWO_ROOTS") == 0) {*number_of_roots_ptr = TWO_ROOTS;}
    else if (strcmp(roots_status_str, "INF_ROOTS") == 0) {*number_of_roots_ptr = INF_ROOTS;}
}

void run_one_test(const int NUMBER_OF_TESTS, struct Quadratic_equation_param *test_1_ptr)
{
    assert_null(test_1_ptr, "test_1_ptr");

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
            printf("%i test no roots type OK\n", NUMBER_OF_TESTS); return;
        }
    }
    if (test_1_ptr->number_of_roots == ONE_ROOT)
    {
        assert_isfinite(test_root_1, "test_root_1");
        assert_isfinite((test_1_ptr->roots)[0], "(test_1_ptr->roots)[0]");

        if (test_1_ptr->number_of_roots == test_number_of_roots && equality_check((test_1_ptr->roots)[0], test_root_1))
        {
            printf("%i test one root type OK\n", NUMBER_OF_TESTS); return;
        }
    }
    if (test_1_ptr->number_of_roots == TWO_ROOTS)
    {
        assert_isfinite(test_root_1, "test_root_1");
        assert_isfinite(test_root_2, "test_root_2");
        assert_isfinite((test_1_ptr->roots)[0], "(test_1_ptr->roots)[0] in run_one_test is NAN");
        assert_isfinite((test_1_ptr->roots)[1], "(test_1_ptr->roots)[1] in run_one_test is NAN");

        if (test_root_1 > test_root_2){ swap(&test_root_1, &test_root_2);}
        if (test_1_ptr->number_of_roots == test_number_of_roots && equality_check(test_1_ptr->roots[0], test_root_1)
                                                                && equality_check(test_1_ptr->roots[1], test_root_2))
        {
            printf("%i test two roots type OK\n", NUMBER_OF_TESTS); return;
        }
    }
    if (test_1_ptr->number_of_roots == INF_ROOTS)
    {
        if (test_1_ptr->number_of_roots == test_number_of_roots)
        {
            printf("%i test inf roots type OK\n", NUMBER_OF_TESTS); return;
        }
    }

    printf("=======================================ERROR %i TEST=======================================\n", NUMBER_OF_TESTS);
    printf("Expected values:%i - number of roots %lg %lg - roots\n", test_number_of_roots, test_root_1, test_root_2);
    printf("Program values:%i - number of roots %lg %lg - roots\n", test_1_ptr->number_of_roots, test_1_ptr->roots[0], test_1_ptr->roots[1]);
    printf("===================================================================================\n");
}

void error_test(const int NUMBER_OF_TESTS, char roots_status_str_ptr[], double *test_key_1_ptr, 
                                                                      double *test_key_2_ptr)
{
    printf("=======================================YOUR TEST IS INCORRECT OR INCORRECTLY FORMAT=======================================\n");
    printf("Your %i test: %s - number of roots %lg %lg - roots\n", NUMBER_OF_TESTS ,roots_status_str_ptr,
                                                                                       *test_key_1_ptr, 
                                                                                       *test_key_2_ptr);
    printf("==========================================================================================================================\n");
    printf("Confess your code sins:");
    char remorse[1000];
    scanf("%s", remorse);
    exit(0);
}
