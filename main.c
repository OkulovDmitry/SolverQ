
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <assert.h>
#include "unit_tests.h"
#include "buffer_operations.h"
#include "double_utills.h"
#include "solve_quadratic.h"
#include "interface.h"

int main()
{
    printf("[------------------------------Ultra Solver for quadratic equations by OKD------------------------------]\n");

    run_tests();

    while(turn_on())
    {
        //fprintf(stderr, "I WAS HERE\n");
        struct Quadratic_equation_param parameters = {0};

        //fprintf(stderr, "I WAS HERE\n");

        greeting(&parameters);

        //fprintf(stderr, "I WAS HERE\n");

        assert(finite((parameters.coefficients)[0]) && "ERROR");
        assert(finite((parameters.coefficients[1])) && "ERROR");
        assert(finite((parameters.coefficients[2])) && "ERROR");

        parameters.number_of_roots = solve(&parameters);

        output(&parameters);
    }

    printf("Thank you");

    return 0;
}


