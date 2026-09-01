/**
 * \file solve_quadratic.h
 * \brief Module containing functions to solve linear and quadratic equations.
 * \details [RU] Модуль содержащий функции решения линейных и квадратных уравнений.
 */
#ifndef SOLVE_QUADRATIC_H_INCLUDED
#define SOLVE_QUADRATIC_H_INCLUDED

#include "double_utils.h"

/**
 * \brief Enum for the number of equation solutions / [RU] Enum для количества решений уравнения
 */
enum number_of_roots {NO_ROOTS, ONE_ROOT, TWO_ROOTS, INF_ROOTS};

/**
 * \brief This sructure holds the coefficients, roots, and number of solutions for the equation.
 *      / [RU] Эта структура данных содержит коэффициенты, решения и количество решений уравнения.
 * \param [in, out] coefficients[3] Coefficients of the quadratic equation / [RU] Коэффициенты квадратного уравнения
 * \param [in, out] roots[2] Solutions of the quadratic equation / [RU] Решения квадратного уравнения
 * \param [in, out] number_of_roots Number ot roots of the quadratic equation / [RU] Количество решений квадратного уравнения
 */
struct Quadratic_equation_param
{
    double coefficients[3];
    double roots[2];
    int number_of_roots;
};

/**
 * \brief Identifies if the equation is quadratic or linear and invokes the appropriate function.
 *      / [RU] Определяет является уравнение квадратным или линейным и вызывает соответсвующую функцию.
 * \param [in, out] *parameters_ptr A pointer to the Quadratic_equation_param structure that holds the equation parameters.
 *                                / [RU] Указатель на структуру Quadratic_equation_param parameters содержащую параметры уравнения
 * \return Количество решений уравнения
 */
int solve(struct Quadratic_equation_param *parameters_ptr);

/**
 * \brief Resolves the linear equation.
 *        / [RU] Решает линейное уравнение
 * \param [in, out] *parameters_ptr A pointer to the Quadratic_equation_param structure that holds the equation parameters.
 *                                / [RU] Указатель на структуру Quadratic_equation_param parameters содержащую параметры уравнения
 * \return Количество решений уравнения
 */
int solve_linear(struct Quadratic_equation_param *parameters_ptr);

/**
 * \brief Finds the discriminant and resolves the quadratic equation.
 *        / [RU] Находит дискриминант и решает квадратное уравнение
 * \param [in, out] *parameters_ptr A pointer to the Quadratic_equation_param structure that holds the equation parameters.
 *                                / [RU] Указатель на структуру Quadratic_equation_param parameters содержащую параметры уравнения
 * \return Количество решений уравнения
 */
int solve_not_linear(struct Quadratic_equation_param *parameters_ptr);

#endif
