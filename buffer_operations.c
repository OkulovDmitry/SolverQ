#include <stdio.h>
#include <string.h>
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

void clear_file_buffer(FILE *unit_tests_file_ptr)
{
    char s = 'q';
    s = fgetc(unit_tests_file_ptr);
    while(s != '\n') {s = fgetc(unit_tests_file_ptr);};
}

int check_buffer()
{
    char buffer = getchar();
    return (buffer != '\n') ? TRUE : FALSE;
}

int is_file_buffer_empty(FILE *unit_tests_file_ptr)
{
    char file_buffer = fgetc(unit_tests_file_ptr);
    return (file_buffer == '\n') ? TRUE : FALSE;
}

int is_file_end(FILE *unit_tests_file_ptr)
{
    char file_buffer = fgetc(unit_tests_file_ptr);
    return (file_buffer == EOF) ? TRUE : FALSE;
}