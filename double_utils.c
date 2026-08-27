#include <math.h>
#include <assert.h>
#include "double_utils.h"
#include "buffer_operations.h"

int compare(double x, double y) //return TRUE if x>y
{
    assert(isfinite(x) && "ERROR: x in compare is NAN");
    assert(isfinite(y) && "ERROR: y in compare is NAN");

    return (x - y > EPSILON) ? TRUE : FALSE;
}

int equality_check(double x, double y)
{
    assert(isfinite(x) && "ERROR: x in equality_check is NAN");
    assert(isfinite(y) && "ERROR: y in eauality_check is NAN");

    return (fabs(x - y) <= EPSILON) ? TRUE : FALSE;
}

double convert_minus_zero_to_zero(double x) //convert -0 to 0
{
    assert(isfinite(x) && "ERROR: x in convert_minus_zero_to_zero is NAN");

    return equality_check(x, 0) ? 0 : x;
}

void swap(double *x, double *y)
{
    assert(isfinite(*x) && "ERROR: x in swap is NAN");
    assert(isfinite(*y) && "ERROR: y in swap is NAN");

    double dop = *x;
    *x = *y;
    *y = dop;
}
