#include <stdio.h>
#include <assert.h>
#include "double_utils.h"
#include "buffer_operations.h"

void clear_buffer(void)
{
    int buffer = 0;
    while((buffer = getchar()) != '\n' && buffer != EOF);
}

void clear_file_buffer(FILE *unit_tests_file_ptr)
{
    assert(unit_tests_file_ptr != NULL && "ERROR: File pointer is NULL");

    int buffer = 0;
    while((buffer = fgetc(unit_tests_file_ptr)) != '\n' && buffer != EOF);
}

int check_buffer(void)
{
    int buffer = getchar();
    if (buffer == '\n' || buffer == EOF) {return FALSE;}

    return TRUE;
}

int is_file_buffer_empty(FILE *unit_tests_file_ptr)
{
    assert(unit_tests_file_ptr != NULL && "ERROR: File pointer is NULL");
    char file_buffer = fgetc(unit_tests_file_ptr);
    ungetc(file_buffer, unit_tests_file_ptr);

    return (file_buffer == '\n') ? TRUE : FALSE;
}

int is_file_end(FILE *unit_tests_file_ptr)
{
    assert(unit_tests_file_ptr != NULL && "ERROR: File pointer is NULL");
    char file_buffer = fgetc(unit_tests_file_ptr);

    return (file_buffer == EOF) ? TRUE : FALSE;
}