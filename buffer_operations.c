#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <assert.h>
#include <stddef.h>
#include "buffer_operations.h"

void clear_buffer()
{
    while(getchar() != '\n');
}
int check_buffer()
{
    char buffer = getchar();
    return (buffer != '\n') ? TRUE : FALSE;
}
