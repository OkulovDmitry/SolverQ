/**
 * \file main.c
 * \brief This program solves linear and quadratic equations and runs unit tests.
 * @param argc The number of command-line arguments. / [RU] Количество аргументов командной строки.
 * @param argv An array of command-line argument strings. / [RU] Массив строк аргументов командной строки.
 * @return int Returns 0 on success, or an error code on failure. [RU] Возвращает 0 в случае успеха или код ошибки при сбое.
 */
#include <stdio.h>
#include <string.h>
#include "unit_tests.h"
#include "buffer_operations.h"
#include "double_utils.h"
#include "solve_quadratic.h"
#include "interface.h"

int main(int argc, char *argv[])
{
    if (argc > 1) {is_run_tests(argv[1]);}

    printf("======================================\nUltra Solver for quadratic equations by OKD\n======================================\n");

    while (turn_on())
    {
        struct Quadratic_equation_param parameters = {0};

        greeting(&parameters);

        parameters.number_of_roots = solve(&parameters);

        output(&parameters);
    }

    printf("Thank you");

    return 0;
}


