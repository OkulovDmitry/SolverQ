#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <assert.h>
#include <stddef.h>
#include "solve_quadratic.h"

int solve(struct Quadratic_equation_param *parameters_ptr)
{
    //error
    assert(&parameters_ptr->coefficients != NULL);
    assert(&parameters_ptr->roots != NULL);
    assert(&parameters_ptr->number_of_roots != NULL);

    if (equality_check((parameters_ptr->coefficients)[0], 0))
    {
        return solve_linear(parameters_ptr);
    }
    else
    {
        return solve_not_linear(parameters_ptr);
    }
}

int solve_not_linear(struct Quadratic_equation_param *parameters_ptr)
{
    assert(&parameters_ptr->coefficients != NULL);
    assert(&parameters_ptr->roots != NULL);
    assert(&parameters_ptr->number_of_roots != NULL);

    double discr = (parameters_ptr->coefficients)[1]*(parameters_ptr->coefficients)[1] - 4*(parameters_ptr->coefficients)[0]*(parameters_ptr->coefficients)[2];

        if (compare(discr, 0))
        {
            double raw_x1 = (-(parameters_ptr->coefficients)[1] - sqrt(discr))/(2*(parameters_ptr->coefficients)[0]);
            double raw_x2 = (-(parameters_ptr->coefficients)[1] + sqrt(discr))/(2*(parameters_ptr->coefficients)[0]);

            (parameters_ptr->roots)[0] = convert_to_zero(raw_x1);
            (parameters_ptr->roots)[1] = convert_to_zero(raw_x2);

            if(compare((parameters_ptr->roots)[0], (parameters_ptr->roots)[1]))
            {
                swap(&(parameters_ptr->roots)[0], &(parameters_ptr->roots)[1]);
            }
            //now (parameters_ptr->roots)[0] < (parameters_ptr->roots)[1]

             parameters_ptr->number_of_roots = TWO_ROOTS;

            return TWO_ROOTS;
        }
        else if (equality_check(discr, 0))
        {
            double raw_x = -(parameters_ptr->coefficients)[1]/(2*(parameters_ptr->coefficients)[0]);

            (parameters_ptr->roots)[0] = equality_check(raw_x, 0) ? 0 : raw_x;
            (parameters_ptr->roots)[1] = equality_check(raw_x, 0) ? 0 : raw_x;
             parameters_ptr->number_of_roots = ONE_ROOT;

            return ONE_ROOT;
        }
        else
        {
            parameters_ptr->number_of_roots = NO_ROOTS;

            return NO_ROOTS;
        }
}

int solve_linear(struct Quadratic_equation_param *parameters_ptr)
{
    assert(&parameters_ptr->coefficients != NULL);
    assert(&parameters_ptr->roots != NULL);
    assert(&parameters_ptr->number_of_roots != NULL);

    if (equality_check((parameters_ptr->coefficients)[1], 0))
    {
        parameters_ptr->number_of_roots = (equality_check((parameters_ptr->coefficients)[2], 0)) ? INF_ROOTS : NO_ROOTS;

        return (equality_check((parameters_ptr->coefficients)[2], 0)) ? INF_ROOTS : NO_ROOTS;
    }
    else
    {
        double raw_x = -(parameters_ptr->coefficients)[2]/(parameters_ptr->coefficients)[1];

        (parameters_ptr->roots)[0] = convert_to_zero(raw_x);
         parameters_ptr->number_of_roots = ONE_ROOT;

        return ONE_ROOT;
    }
}
