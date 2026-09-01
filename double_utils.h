/**
 * \file double_utils.h
 * \brief A custom-precision utility library for double-type numbers.
 * \details [RU] Библиотека утилит настраиваемой точности для работы с числами типа double.
 */
#ifndef DOUBLE_UTILS_H_INCLUDED
#define DOUBLE_UTILS_H_INCLUDED

/**
 * \brief Precision threshold for floating-point comparisons.
 * \details [RU] Порог точности для сравнения вещественных чисел.
 */
#define EPSILON 1e-10

/*============================================================================================*/
/*                                    COMPARISON FUNCTIONS                                    */
/*                                [RU] ФУНКЦИИ СРАВНЕНИЯ ЧИСЕЛ                                */
/*============================================================================================*/

/**
 * \brief Checks if the first double value is strictly greater than the second.
 * \details [RU] Проверяет строго ли первое число больше второго с учетом погрешности.
 * \param[in] x The first double value to compare. / [RU] Первое сравниваемое число.
 * \param[in] y The second double to compare. / [RU] Второе сравниваемое число.
 * \return 1 if x is greater than y by a margin exceeding EPSILON.
 *         / [RU] 1, если x больше y с разностью, превышающей EPSILON.
 * \return 0 if x is less than or equal to y within EPSILON precision.
 *         / [RU] 0, если x меньше или равен y в пределах точности.
 */
int is_greater(double x, double y);

/**
 * \brief Checks if two double values are equal within a specific precision.
 * \details [RU] Проверяет два вещественных числа на равенство в пределах точности.
 * \param[in] x First double value / [RU] Первое вещественное число.
 * \param[in] y Second double value / [RU] Второе вещественное число.
 * \return 1 if the values are equal within EPSILON precision. 
 *         / [RU] 1, если числа равны с точностью до EPSILON.
 * \return 0 otherwise. / [RU] 0 в противном случае.
 */
int equality_check(double x, double y);

/*=================================================================================*/
/*                                OTHERS UTILITIES                                 */
/*                              [RU] ДРУГИЕ УТИЛИТЫ                                */
/*=================================================================================*/

/**
 * \brief Prevents the appearance of negative zero (-0.0).
 * \details [RU] Исключает появление отрицательного нуля (-0.0) в результатах.
 * \param[in] x The target double value to be evaluated. / [RU] Проверяемое число.
 * \return 0 if x is approximately equal to zero, or the original value x otherwise.
 *         / [RU] 0, если x равен нулю, иначе — исходное значение x.
 */
double convert_minus_zero_to_zero(double x);

/**
 * \brief Swaps the values of two double variables in memory.
 * \details [RU] Меняет местами значения двух переменных типа double в памяти.
 * \param[in, out] x Pointer to the first double variable. / [RU] Указатель на первую переменную.
 * \param[in, out] y Pointer to the second double variable. / [RU] Указатель на вторую переменную.
 */
void swap(double *x, double *y);

#endif
