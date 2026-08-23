#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <assert.h>
#include "double_utills.h"

int compare(double x, double y)
{
    assert(finite(x));
    assert(finite(y));

    return (x - y > EPSILON) ? TRUE : FALSE;
}

int equality_check(double x, double y)
{
    assert(finite(x));
    assert(finite(y));

    return (fabs(x - y) <= EPSILON) ? TRUE : FALSE;
}

double convert_to_zero(double x)
{
    assert(finite(x));
    return equality_check(x, 0) ? 0 : x;
}
