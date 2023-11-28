#include "mySort.h"

void Sort::swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Sort::partition(int* arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void Sort::quickSort(int* arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void Sort::bubbleSort(int* arr, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

int Sort::getMax(int* arr, int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int Sort::getExp(int value)
{
    int exp = 1;
    while (value > 10)
    {
        value /= 10;
        exp *= 10;
    }
    return exp;
}

void Sort::countSort(int* arr, int n)
{
    if (!n)
        return;

    int max = getMax(arr, n);
    int* output = new int[n];
    int* count = new int[max + 1];

    for (int i = 0; i < max + 1; i++)
        count[i] = 0;

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    delete[] output;
    delete[] count;
}


void Sort::bucketSort(int* arr, int n)
{
    struct bucket buckets[11];
    int exp = getExp(getMax(arr, n));

    for (int i = 0; i < 11; i++)
    {
        buckets[i].count = 0;
        buckets[i].data = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        int bi = arr[i] / exp;
        buckets[bi].data[buckets[bi].count++] = arr[i];
    }

    int l = 0;
    for (int i = 0; i < 11; i++)
    {
        countSort(buckets[i].data, buckets[i].count);
        for (int j = 0; j < buckets[i].count; j++)
            arr[l++] = buckets[i].data[j];
    }

    for (int i = 0; i < 11; i++)
        delete[] buckets[i].data;
}

void Sort::insertionSort(int* arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        for (; j >= 0; j--)
            if (arr[j] > key)
                arr[j + 1] = arr[j];
            else
                break;

        arr[j + 1] = key;
    }
}

void Sort::merge(int* arr, int l, int m, int r)
{
    int nl = m - l + 1;
    int nr = r - m;

    int* left = new int[nl];
    int* right = new int[nr];

    for (int i = 0; i < nl; i++)
        left[i] = arr[l + i];
    for (int j = 0; j < nr; j++)
        right[j] = arr[m + 1 + j];

    int i = 0, j = 0;
    int k = l;

    while (i < nl && j < nr)
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];

    while (i < nl)
        arr[k++] = left[i++];

    while (j < nr)
        arr[k++] = right[j++];

    delete[] left;
    delete[] right;
}

void Sort::mergeSort(int* arr, int l, int r)
{
    if (l >= r)
        return;

    int m = (l + r - 1) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

void Sort::countSort_radix(int* arr, int n, int exp)
{
    int* output = new int[n];
    int count[10] = { 0 }; 

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    delete[] output;
}

void Sort::radixSort(int* arr, int n)
{
    int m = getMax(arr, n);
    int exp = 1;

    while (m > 10)
    {
        m /= 10;
        countSort_radix(arr, n, exp);
        exp *= 10;
    }
    countSort_radix(arr, n, exp);
}

void Sort::selectionSort(int* arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int i_min = i;

        for (int j = i; j < n; j++)
            if (arr[j] < arr[i_min])
                i_min = j;

        swap(&arr[i], &arr[i_min]);
    }
}

void Sort::insertionSort_tim(int* arr, int l, int r)
{
    for (int i = l + 1; i <= r; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= l && arr[j] > key)
            arr[j + 1] = arr[j--];

        arr[j + 1] = key;
    }
}

void Sort::timSort(int* arr, int n)
{
    const int RUN = 64;

    for (int i = 0; i < n; i += RUN)
        if ((n - RUN) > i)
            insertionSort_tim(arr, i, i + RUN - 1);
        else
            insertionSort_tim(arr, i, n - 1);

    for (int size = RUN; size < n; size = 2 * size)
        for (int left = 0; left < n; left += 2 * size)
        {
            int mid = left + size - 1;
            int right = std::min((left + 2 * size - 1), (n - 1));

            if (mid > right)
                mid = left;

            merge(arr, left, mid, right);
        }
}




