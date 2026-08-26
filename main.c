#include <stdio.h>

#include "unit_tests.h"
#include "buffer_operations.h"
#include "double_utils.h"
#include "solve_quadratic.h"
#include "interface.h"

int main(void)
{
    printf("======================================\nUltra Solver for quadratic equations by OKD\n======================================\n");

    run_tests();

    while(turn_on())
    {
        struct Quadratic_equation_param parameters = {0};

        greeting(&parameters);

        parameters.number_of_roots = solve(&parameters);

        output(&parameters);
    }

    printf("Thank you");

    return 0;
}


