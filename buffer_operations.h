/**
 * \file buffer_operations.h
 * \brief This file handles buffer operations: clear buffer, check if buffer is empty, check for end of file (EOF).
 */

#ifndef BUFFER_OPERATIONS_H_INCLUDED
#define BUFFER_OPERATIONS_H_INCLUDED

#include <stdio.h>

/**
 * \brief Enum for boolean values / [RU] Enum для bool значений.
 */
enum boolean {FALSE, TRUE};

/**
 * \brief Clears the buffer.
 * \details [RU] Очищает буфер
 */
void clear_buffer(void);

/**
 * \brief Clears the file buffer.
 * \details [RU] Очищает файловый буфер.
 * \param [in, out] *unit_tests_file_ptr Pointer to the file to be cleared. / [RU] Указатель на файл, который нужно очистить.
 */
void clear_file_buffer(FILE *unit_tests_file_ptr);

/**
 * \brief Check the file buffer.
 * \details [RU] Проверяет пустой ли
 */
int check_buffer(void);
int is_file_buffer_empty(FILE *unit_tests_file_ptr);
int is_file_end(FILE *unit_tests_file_ptr);

#endif
