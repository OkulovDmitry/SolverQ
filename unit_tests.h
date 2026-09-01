/**
 * \file unit_tests.h
 * \brief Automated unit-testing framework for the quadratic equation solver.
 * \details [RU] Модуль автоматизированного блочного тестирования (юнит-тестирования) для решателя квадратных уравнений. Обеспечивает чтение тестов из файла, проверку их формата и сопоставление результатов.
 */
#ifndef UNIT_TESTS_H_INCLUDED
#define UNIT_TESTS_H_INCLUDED

#include "solve_quadratic.h"

/*============================================================================================*/
/*                                 TEST RUNNER CONTROL                                       */
/*                           [RU] УПРАВЛЕНИЕ ЗАПУСКОМ ТЕСТОВ                                  */
/*============================================================================================*/

/**
 * \brief Evaluates the user command to determine if unit tests should be executed.
 * \details [RU] Анализирует команду пользователя, чтобы определить, нужно ли запускать тесты.
 * \param[in] str Input command string from the user. / [RU] Входная строка команды пользователя.
 */
void is_run_tests(char str[]);

/**
 * \brief Master function that triggers the entire suite of unit tests.
 * \details [RU] Главная функция, запускающая весь комплекс автоматических юнит-тестов.
 */
void run_tests(void);

/*============================================================================================*/
/*                                FILE PARSING UTILITIES                                      */
/*                           [RU] УТИЛИТЫ ПАРСИНГА ФАЙЛА ТЕСТОВ                               */
/*============================================================================================*/

/**
 * \brief Executes a single unit test case with provided parameters and evaluates the outcome.
 * \details [RU] Выполняет один конкретный юнит-тест с переданными параметрами и оценивает результат.
 * \param[in] NUMBER_OF_TESTS ID of the test. / [RU] ID теста.
 * \param[in] test_parameters Pointer to the structure holding equation coefficients and keys.
 *                            / [RU] Указатель на структуру с коэффициентами уравнения и решениями.
 */
void run_one_test(const int NUMBER_OF_TESTS, struct Quadratic_equation_param *test_parameters);

/**
 * \brief Skips comment blocks in the test database file.
 * \details [RU] Пропускает блоки комментариев начинающихся на '#' в файле юнит тестов в начале строки.
 * \param[in,out] unit_tests_file Pointer to the opened test file stream.
 *                                / [RU] Указатель на поток открытого файла с тестами.
 */
void skip_comments(FILE *unit_tests_file);

/**
 * \brief Skips comment blocks in the test database file in the end of the line.
 * \details [RU] Пропускает блоки комментариев начинающихся на ' #' в файле юнит тестов в конце строки.
 * \param[in,out] unit_tests_file Pointer to the opened test file stream.
 *                                / [RU] Указатель на поток открытого файла с тестами.
 */
void skip_end_of_line_comment(FILE *unit_tests_file);

/**
 * \brief Verifies the correctness of the entered test quantity format.
 * \details [RU] Проверяет правильность формата введённого количества тестов.
 * \param[in] NUMBER_OF_TESTS ID of the test. / [RU] ID теста.
 * \param[in, out] roots_status_str_ptr[] Unit test input for solution count in NO_ROOTS/ONE_ROOT/TWO_ROOTS/INF_ROOTS format. 
 *                                      / [RU] Введенное в unit тестах количество решений в формате NO_ROOTS/ONE_ROOT/TWO_ROOTS/INF_ROOTS.
 * \param[in, out] *test_key_1_ptr Pointer to the first unit test solution. 
 *                               / [RU] Указатель на первое решение unit-теста.
 * \param[in, out] *test_key_1_ptr Pointer to the second unit test solution. 
 *                               / [RU] Указатель на второе решение unit-теста.
 */
void is_format_roots_status_str_correct(int NUMBER_OF_TESTS_ptr,char roots_status_str_ptr[], 
                                                                     double *test_key_1_ptr, 
                                                                     double *test_key_2_ptr);
                                                                     
/**
 * \brief Analyzes roots-status_str to find the numerical value of the unit test solution count.
 * \details [RU] Анализирует roots-status_str и находит численное значение количества решений в unit-тесте.
 * \param[in, out] roots_status_str_ptr[] Unit test input for solution count in NO_ROOTS/ONE_ROOT/TWO_ROOTS/INF_ROOTS format. 
 *                                      / [RU] Введенное в unit тестах количество решений в формате NO_ROOTS/ONE_ROOT/TWO_ROOTS/INF_ROOTS.
 * \param[in, out] number_of_roots_ptr The number of unit test solutions as an int type.
 *                                   / [RU] Количество решений unit-теста типа int.
 */
void test_number_of_roots_initialization(char roots_status_str[], int *number_of_roots_ptr);

/**
 * \brief Stops the program if an invalid unit test format is found and provides its path.
 * \details [RU] Останавливает программу если находит unit-тест неверного формата и указывает путь к ней.
 * \param[in] NUMBER_OF_TESTS ID of the test. / [RU] ID теста.
 * \param[in, out] roots_status_str_ptr[] Unit test input for solution count in NO_ROOTS/ONE_ROOT/TWO_ROOTS/INF_ROOTS format. 
 *                                      / [RU] Введенное в unit тестах количество решений в формате NO_ROOTS/ONE_ROOT/TWO_ROOTS/INF_ROOTS.
 * \param[in, out] *test_key_1_ptr Pointer to the first unit test solution. 
 *                               / [RU] Указатель на первое решение unit-теста.
 * \param[in, out] *test_key_1_ptr Pointer to the second unit test solution.
 *                               / [RU] Указатель на второе решение unit-теста.
 */
void error_test(const int NUMBER_OF_TESTS_ptr,char roots_status_str_ptr[], double *test_key_1_ptr, 
                                                                     double *test_key_2_ptr);

#endif
