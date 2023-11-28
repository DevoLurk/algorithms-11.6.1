#ifndef MYFUNC
#define MYFUNC

#include<iostream>
#include<cstring>
#include<fstream>
#include<chrono>
#include<cstdlib>
#include<ctime>

void print_arr(int* arr, int lenth);
void write_arr(const std::string& filename, const int* arr, const int n);
void read_arr(const std::string& filename, int*& arr, int& n);
int random(int lef_border, int right_border);
void fillarr(int* arr, int size, int lef_border, int right_border);

#endif // !MYFUNC


