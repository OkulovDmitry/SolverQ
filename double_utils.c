#include <math.h>
#include <assert.h>
#include "double_utils.h"
#include "buffer_operations.h"
#include "my_assert_isfinite.h"
#include "my_assert_null.h"

int is_greater(double x, double y) //return TRUE if x>y
{
    assert_isfinite(x, "x");
    assert_isfinite(y, "y");

    return (x - y > EPSILON) ? TRUE : FALSE;
}

int equality_check(double x, double y)
{
    assert_isfinite(x, "x");
    assert_isfinite(y, "y");

    return (fabs(x - y) <= EPSILON) ? TRUE : FALSE;
}

double convert_minus_zero_to_zero(double x) //convert -0 to 0
{
    assert_isfinite(x, "x");

    return equality_check(x, 0) ? 0 : x;
}

void swap(double *x, double *y)
{
    assert_null(x, "x");
    assert_null(y, "y");
    assert_isfinite(*x, "*x");
    assert_isfinite(*y, "*y");

    double dop = *x;
    *x = *y;
    *y = dop;
}
