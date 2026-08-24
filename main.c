
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <assert.h>
#include <stddef.h>
#include "unit_tests.h"
#include "buffer_operations.h"
#include "double_utills.h"
#include "solve_quadratic.h"
#include "interface.h"

int main()
{
    printf("======================================\nUltra Solver for quadratic equations by OKD\n======================================\n");

    run_tests();

    while(turn_on())
    {
        struct Quadratic_equation_param parameters = {0};

        greeting(&parameters);

        assert(isfinite((parameters.coefficients)[0]) && "ERROR");
        assert(isfinite((parameters.coefficients[1])) && "ERROR");
        assert(isfinite((parameters.coefficients[2])) && "ERROR");

        parameters.number_of_roots = solve(&parameters);

        output(&parameters);
    }

    printf("Thank you");

    return 0;
}


