/**
 * \file my_assert_isfinite.h
 * \brief Asserts for INF and NAN values.
 * \details [RU] Assert на числа типа inf и nan.
 */
#ifndef MY_ASSER_ISFINITE_H
#define MY_ASSERT_ISFIITE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifdef NDEBUG
    #define assert_isfinite(number, notation)(void(0))
#else
    #define assert_isfinite(number, notation) \
        do \
        { \
            if (!(isfinite(number))) \
            { \
                fprintf(stderr, "ASSERTION FAILED, %s is NAN or INF\n", notation); \
                fprintf(stderr, "FILE: %s\nLINE: %d\nFUNCTION: %s\n", __FILE__, __LINE__, __func__); \
                abort(); \
            } \
        } while (0);
#endif

#endif