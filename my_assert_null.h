/**
 * \file my_assert_null.h
 * \brief Asserts for null files.
 * \details [RU] Assert на null файлы.
 */
#ifndef MY_ASSER_NULL_H
#define MY_ASSERT_NULL

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifdef NDEBUG
    #define assert_null(condition, notation)(void(0))
#else
    #define assert_null(condition, notation) \
        do \
        { \
            if (condition == NULL) \
            { \
                fprintf(stderr, "ASSERTION FAILED, %s is NAN or INF\n", notation); \
                fprintf(stderr, "FILE: %s\nLINE: %d\nFUNCTION: %s\n", __FILE__, __LINE__, __func__); \
                abort(); \
            } \
        } while (0);
#endif

#endif