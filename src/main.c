/*
 * main.c
 * Задание 1, вариант 13
 * Дан массив натуральных чисел размерности n.
 * Определить количество чисел-палиндромов в нем.
 * Функция должна проверять, является ли число палиндромом или нет.
 *
 * Автор: Ласицкий Никита, группа 12б
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * has_unique_digits - проверяет, содержит ли десятичная запись числа
 *                     только уникальные (неповторяющиеся) цифры
 * Параметры:
 *   num - натуральное число для проверки
 * Возвращает:
 *   1, если все цифры уникальны
 *   0, если есть повторяющиеся цифры
 */
int
has_unique_digits(unsigned long num)
{
        int digits[10] = {0};

        while (num > 0) {
                int d = num % 10;
                if (digits[d]) {
                        return 0;
                }
                digits[d] = 1;
                num /= 10;
        }

        return 1;
}

int
main(int argc, char *argv[])
{
        int     n;      /* размерность массива */
        int     count;  /* счётчик чисел с уникальными цифрами */
        int     i;

        if (argc < 2) {
                printf("Usage: %s n num1 num2 ... numN\n", argv[0]);
                return 1;
        }

        n = atoi(argv[1]);

        if (n <= 0 || argc < n + 2) {
                printf("Error: invalid number of arguments\n");
                return 1;
        }

        unsigned long *arr = malloc(n * sizeof(unsigned long));
        if (!arr) {
                printf("Error: memory allocation failed\n");
                return 1;
        }

        printf("Input array: ");
        for (i = 0; i < n; i++) {
                arr[i] = strtoul(argv[i + 2], NULL, 10);
                printf("%lu ", arr[i]);
        }
        printf("\n");

        count = 0;
        for (i = 0; i < n; i++) {
                if (has_unique_digits(arr[i])) {
                        printf("%lu - unique digits\n", arr[i]);
                        count++;
                } else {
                        printf("%lu - has repeating digits\n", arr[i]);
                }
        }

        printf("Count of numbers with all unique digits: %d\n", count);

        free(arr);

        return 0;
}
