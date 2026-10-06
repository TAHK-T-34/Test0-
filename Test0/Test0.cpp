#include <iostream>
#include <iomanip> // Для форматирования вывода
#include <limits>  // Для очистки потока cin
#include <cmath>

// Функция для безопасной проверки равенства вещественного числа нулю
bool isZero(double value, double epsilon = 1e-9)
{
    return std::fabs(value) <= epsilon;
}

int main()
{
    setlocale(LC_ALL, "ru"); // Локаль для кириллицы

    // Ввод переменных
    double a, b, c, x;
    std::cout << "Введите значение a: ";
    if (!(std::cin >> a)); // Проверяем успешность чтения

    std::cout << "Введите значение b: ";
    if (!(std::cin >> b));

    std::cout << "Введите значение c: ";
    if (!(std::cin >> c));

    std::cout << "Введите значение x: ";
    if (!(std::cin >> x));

    // Вычисление числителя
    /*
     * Формула:
     * y = (a * |x^3| + (5/2)*b*sqrt(x^2+1))/(c + sin(x)*cos(x))
     */
    double numerator = a * std::pow(std::fabs(x), 3) + (5.0 / 2) * b * std::sqrt(x * x + 1);

    // Вычисление знаменателя
    double denominator = c + std::sin(x) * std::cos(x);

    // Проверка на деление на ноль
    if (isZero(denominator))
    {
        std::cerr << "Ошибка! Знаменатель равен нулю." << std::endl;
        return 1;
    }

    // Результат
    double result = numerator / denominator;

    // Красивый вывод результата
    std::cout.precision(6); // Количество знаков после запятой
    std::cout << std::fixed;
    std::cout << "Результат: y = " << result << '\n';

    return 0;

input_error:
    // Обработчик ошибки ввода
    std::cerr << "\n❌ Ошибка: вы ввели не число.\n";
    std::cerr << "Программа завершает работу.\n";

    // Сброс состояния потока и очистка буфера
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return -1;
}