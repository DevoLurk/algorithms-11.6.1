#ifndef MYSORT
#define MYSORT

#include<iostream>
#include<algorithm>
#include<chrono>

class Sort
{
private:
    struct bucket
    {
        int count;
        int* data;
    };

    void swap(int* a, int* b);
    int partition(int* arr, int low, int high);
    int getMax(int* arr, int n);
    int getExp(int value);
    void merge(int* arr, int l, int m, int r);
    void countSort_radix(int* arr, int n, int exp);
    void insertionSort_tim(int* arr, int l, int r);
    void countSort_bucket(int* arr, int n);

public:
    void mergeSort(int* arr, int l, int r);
    void quickSort(int* arr, int low, int high);
    void bubbleSort(int* arr, int n);
    void bucketSort(int* arr, int n);
    void countSort(int* arr, int n);
    void insertionSort(int* arr, int n);
    void radixSort(int* arr, int n);
    void selectionSort(int* arr, int n);
    void timSort(int* arr, int n);
};

#endif // MYSORT