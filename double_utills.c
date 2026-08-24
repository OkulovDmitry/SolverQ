#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <assert.h>
#include "double_utills.h"

int compare(double x, double y) //return TRUE if x>y
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

double convert_to_zero(double x) //convert -0 to 0
{
    assert(finite(x));
    return equality_check(x, 0) ? 0 : x;
}

void swap(double *x, double *y)
{
    double dop = *x;
    *x = *y;
    *y = dop;
}
