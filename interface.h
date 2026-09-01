/**
 * \file interface.h
 * \brief A library of functions for handling user interaction
 */
#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

/**
 * \brief Precision for double calculations / [RU] Точность для расчетов с числами типа double
 */
#define MAX_ACCURACY 10

/**
 * \brief Gets user confirmation to execute the program
 * \details [RU] Запрашивает подтверждение пользователя для выполнения программы.
 * \return Choice, = 1 if user want to turn on the program
 */
int turn_on(void);

/**
 * \brief Receives the coefficients of a quadratic equation from the user.
 * \details [RU] Принимает от пользователя коэффициенты квадратного уравнения.
 * \param [in, out] (parameters_ptr->coefficients)[0] First solution. / [RU] Первое решение.
 * \param [in, out] (parameters_ptr->coefficients)[1] Second solution. / [RU] Второе решение.
 * \param [in, out] (parameters_ptr->coefficients)[2] Third solution. / [RU] Третье решение.
 */
void greeting(struct Quadratic_equation_param *parameters_ptr);

/**
 * \brief Prints the number of equation solutions and the solutions themselves.
 * \details [RU] Выводит количество решений уравнения и их самих.
 * \param [in] *parameters_ptr Pointer to the structure containing the equation solutions. 
 *                           / [RU] Указатель на структуру содержащую решения уравнения.
 */
void output(const struct Quadratic_equation_param *parameters_ptr);

#endif