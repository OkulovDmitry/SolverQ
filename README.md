# AISolveEquations

A robust C utility and application designed to interactively solve linear and quadratic equations with high floating-point precision constraints. It includes built-in protective assertions and an automated test suite.

> **[RU]** Надёжное консольное приложение и библиотека утилит на C, предназначенные для интерактивного решения линейных и квадратных уравнений с высокой точностью. Проект включает кастомные защитные ассерты и встроенную систему автоматического тестирования.

---

## Features / [RU] Возможности
* **Equation Solver**: Solves linear and quadratic equations with proper handling of special cases (zero coefficients, no roots, infinite roots).
* **Custom Double Precision**: Floating-point operations use a precise `EPSILON` threshold ($10^{-10}$) to ensure accuracy.
* **Robust Input Validation**: Clears buffers and handles incorrect formatting gracefully.
* **Safety Assertions**: Protects functions against `NAN`, `INF`, and `NULL` pointer violations.
* **Automated Unit Tests**: Features a separate testing mode driven by file keys.

> **[RU]**
> * **Решение уравнений**: Решает линейные и квадратные уравнения с корректной обработкой крайних случаев (нулевые коэффициенты, отсутствие корней, бесконечное множество корней).
> * **Настраиваемая точность**: Операции с вещественными числами используют порог точности `EPSILON` ($10^{-10}$).
> * **Надежная валидация**: Очищает буфер ввода и устойчив к некорректным форматам данных.
> * **Защитные утверждения**: Кастомные ассерты страхуют функции от попадания `NAN`, `INF` и `NULL`-указателей.
> * **Автоматические тесты**: Наличие автономного режима тестирования на основе файла с ключами.

---

## Installation & Running / [RU] Сборка и запуск

### Prerequisites / [RU] Требования
Make sure you have `gcc` compiler installed on your system.
> **[RU]** Убедитесь, что в вашей системе установлен компилятор `gcc`.

### Building the Project / [RU] Компиляция
To compile the whole project using `gcc`, run the following command in your terminal:
```bash
gcc -o solver main.c buffer_operations.c double_utils.c interface.c solve_quadratic.c unit_tests.c -lm
```
> **[RU]** Чтобы скомпилировать весь проект с помощью `gcc`, выполните команду выше.

### Running Interactive Mode / [RU] Запуск интерактивного режима
Run the compiled binary without any arguments to start the interactive solver:
```bash
./solver
```
> **[RU]** Запустите скомпилированный файл без аргументов для перехода в диалоговый режим решения уравнений.

### Running Unit Tests / [RU] Запуск Unit-тестов
The program contains an integrated test engine. To execute unit tests, pass the `--run-tests` flag as a command-line argument:
```bash
./solver --run-tests
```
*Note: Make sure `unit_test_keys.txt` is present in the working directory.*

> **[RU]** В программу встроен модуль тестирования. Чтобы запустить unit-тесты, передайте аргумент `--run-tests` при запуске.
> *Примечание: Убедитесь, что файл `unit_test_keys.txt` находится в рабочей директории.*

---

## Project Structure / [RU] Структура проекта
* `main.c` — Main entry point handling logic flow and flags.
* `double_utils.h / .c` — Floating-point comparison with precision thresholds.
* `solve_quadratic.h / .c` — Core algorithm logic for calculating roots.
* `interface.h / .c` — User interaction, greeting, and formatted output.
* `buffer_operations.h / .c` — Standard stream input validation and safe cleaning.
* `my_assert_isfinite.h` — Custom macros validating numbers are not NaN or Infinite.
* `unit_tests.h / .c` — Automated testing routines driven by data keys.
* `Doxyfile` — Configuration file to generate comprehensive HTML/LaTeX documentation.

> **[RU]**
> * `main.c` — Главная точка входа, обрабатывающая аргументы командной строки.
> * `double_utils.h / .c` — Сравнение чисел с плавающей точкой с учетом погрешности.
> * `solve_quadratic.h / .c` — Основной математический алгоритм вычисления корней.
> * `interface.h / .c` — Взаимодействие с пользователем, приглашение к вводу и вывод результатов.
> * `buffer_operations.h / .c` — Валидация потока ввода и безопасная очистка буфера.
> * `my_assert_isfinite.h` — Кастомные макросы проверки чисел на NaN и Inf.
> * `unit_tests.h / .c` — Модуль автоматического тестирования по файлу ответов.
> * `Doxyfile` — Конфигурация Doxygen для автоматической генерации документации (HTML/LaTeX).

---

## Documentation / [RU] Документация
This project uses **Doxygen** format documentation. You can generate it by running:
```bash
doxygen Doxyfile
```
> **[RU]** Код проекта подробно документирован по стандарту **Doxygen**. Вы можете сгенерировать веб-справку командой выше.
