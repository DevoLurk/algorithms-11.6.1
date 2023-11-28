#include"myFunc.h"


void write_arr(const std::string& filename, const int* arr, const int n)
{
    std::fstream fs;

    fs.open(filename, std::fstream::out);
    if (fs.is_open()) // проверяем, что файл успешно открыт
    {
        fs << n << '\n';  // записываем размер массива
        for (int i = 0; i < n; i++)
            fs << arr[i] << ' '; // записываем значения через пробел
        fs << '\n';

        fs.close(); // закрываем файл
    }
}

void read_arr(const std::string& filename, int*& arr, int& n)
{
    std::fstream fs;

    fs.open(filename, std::fstream::in);
    if (fs.is_open()) // проверяем, что файл успешно открыт
    {
        fs >> n;  // читаем размер массива
        arr = new int[n];
        for (int i = 0; i < n; i++)
            fs >> arr[i]; // читаем из файла разделительные символы - пробел и перенос строки

        fs.close(); // закрываем файл
    }
}

int random(int lef_border, int right_border)
{
    return lef_border + rand() % abs(right_border + abs(lef_border));
}

void fillarr(int* arr, int size, int lef_border, int right_border)
{
    for (auto i{ 0 }; i < size; i++)
        arr[i] = random(lef_border, right_border);
    
}

void print_arr(int* arr, int lenth)
{
    for (auto i{ 0 }; i < lenth; i++)
    {
        if (i % 20 == 0)
            std::cout << std::endl;
        std::cout.width(3);
        std::cout << arr[i] << ",";
    }
    std::cout << "\b." << std::endl;
}