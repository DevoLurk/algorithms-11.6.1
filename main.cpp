#include"myFunc.h"
#include"mySort.h"
#include <iomanip>

using namespace std;


int main()
{
	Sort algoritm;

    string filename1 = "array_Small_data.txt";
	string filename2 = "array_Long_data.txt";
	string filename3 = "array_LongBig_data.txt";

	int arrSize1 = 100;
	int arrSize2 = 10000;
	int arrSize3 = 100000;

	int* array_Small = new int[arrSize1];
	int* array_Long = new int[arrSize2];
	int* array_LongBig = new int[arrSize3];

	fillarr(array_Small, arrSize1, 1, 1);
	fillarr(array_Long, arrSize2, 1, 1);
	fillarr(array_LongBig, arrSize3, 1, 10000);

	//print_arr(array_Small, arrSize1);

	/*write_arr(filename1, array_Small, arrSize1);
	write_arr(filename2, array_Long, arrSize2);
	write_arr(filename3, array_LongBig, arrSize3);

	read_arr(filename1, array_Small, arrSize1);
	read_arr(filename2, array_Long, arrSize2);
	read_arr(filename3, array_LongBig, arrSize3);*/

	cout << fixed << setprecision(7);


	cout << "\n\tbubbleSort sort" << endl;                             // bubbleSort
	auto start = std::chrono::high_resolution_clock::now();
	algoritm.bubbleSort(array_Small, arrSize1);
	auto finish = std::chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed1 = finish - start;
	cout << "array_Small   time = " << elapsed1.count() << endl;

	start = std::chrono::high_resolution_clock::now();
	algoritm.bubbleSort(array_Long, arrSize2);
	finish = std::chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed2 = finish - start;
	cout << "array_Long    time = " << elapsed2.count() << endl;


	start = std::chrono::high_resolution_clock::now();
	algoritm.bubbleSort(array_LongBig, arrSize3);
	finish = std::chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed3 = finish - start;
	cout << "array_Long    time = " << elapsed3.count() << endl;
	cout << "average time       \033[32m= " << (elapsed3.count() + elapsed2.count() + elapsed1.count())/3 << "\033[0m" << endl;

	cout << "\n\tmergeSort sort" << endl;                            // mergeSort
	start = std::chrono::high_resolution_clock::now();
	algoritm.mergeSort(array_Small, 0, arrSize1 - 1);
	finish = std::chrono::high_resolution_clock::now();
	elapsed1 = finish - start;
	cout << "array_Small   time = " << elapsed1.count() << endl;

	start = std::chrono::high_resolution_clock::now();
	algoritm.mergeSort(array_Long, 0, arrSize2 - 1);
	finish = std::chrono::high_resolution_clock::now();
	elapsed1 = finish - start;
	cout << "array_Small   time = " << elapsed2.count() << endl;

	start = std::chrono::high_resolution_clock::now();
	algoritm.mergeSort(array_LongBig, 0, arrSize3 - 1);
	finish = std::chrono::high_resolution_clock::now();
	elapsed1 = finish - start;
	cout << "array_Small   time = " << elapsed3.count() << endl;
	cout << "average time       \033[32m= " << (elapsed3.count() + elapsed2.count() + elapsed1.count())/3 << "\033[0m" << endl;

	cout << "\n\tcountSort sort" << endl;                            // countSort
	start = std::chrono::high_resolution_clock::now();
	algoritm.countSort(array_Small, arrSize1);
	finish = std::chrono::high_resolution_clock::now();
	elapsed1 = finish - start;
	cout << "array_Small   time = " << elapsed1.count() << endl;

	start = std::chrono::high_resolution_clock::now();
	algoritm.countSort(array_Long, arrSize2);
	finish = std::chrono::high_resolution_clock::now();
	elapsed1 = finish - start;
	cout << "array_Small   time = " << elapsed2.count() << endl;

	start = std::chrono::high_resolution_clock::now();
	algoritm.countSort(array_LongBig, arrSize3);
	finish = std::chrono::high_resolution_clock::now();
	elapsed1 = finish - start;
	cout << "array_Small   time = " << elapsed3.count() << endl;
	cout << "average time       \033[32m= " << (elapsed3.count() + elapsed2.count() + elapsed1.count())/3 << "\033[0m" << endl;

	cout << "\n\tinsertionSort sort" << endl;                            // insertionSort
	start = std::chrono::high_resolution_clock::now();
	algoritm.insertionSort(array_Small, arrSize1);
	finish = std::chrono::high_resolution_clock::now();
	elapsed1 = finish - start;
	cout << "array_Small   time = " << elapsed1.count() << endl;

	start = std::chrono::high_resolution_clock::now();
	algoritm.insertionSort(array_Long, arrSize2);
	finish = std::chrono::high_resolution_clock::now();
	elapsed1 = finish - start;
	cout << "array_Small   time = " << elapsed2.count() << endl;

	start = std::chrono::high_resolution_clock::now();
	algoritm.insertionSort(array_LongBig, arrSize3);
	finish = std::chrono::high_resolution_clock::now();
	elapsed1 = finish - start;
	cout << "array_Small   time = " << elapsed3.count() << endl;
	cout << "average time       \033[32m= " << (elapsed3.count() + elapsed2.count() + elapsed1.count())/3 << "\033[0m" << endl;

	cout << "\n\tselectionSort sort" << endl;                            // selectionSort
	start = std::chrono::high_resolution_clock::now();
	algoritm.selectionSort(array_Small, arrSize1);
	finish = std::chrono::high_resolution_clock::now();
	elapsed1 = finish - start;
	cout << "array_Small   time = " << elapsed1.count() << endl;

	start = std::chrono::high_resolution_clock::now();
	algoritm.selectionSort(array_Long, arrSize2);
	finish = std::chrono::high_resolution_clock::now();
	elapsed1 = finish - start;
	cout << "array_Small   time = " << elapsed2.count() << endl;

	start = std::chrono::high_resolution_clock::now();
	algoritm.selectionSort(array_LongBig, arrSize3);
	finish = std::chrono::high_resolution_clock::now();
	elapsed1 = finish - start;
	cout << "array_Small   time = " << elapsed3.count() << endl;
	cout << "average time       \033[32m= " << (elapsed3.count() + elapsed2.count() + elapsed1.count())/3 << "\033[0m" << endl;


	cout << "\n\ttimSort sort" << endl;                            // timSort
	start = std::chrono::high_resolution_clock::now();
	algoritm.timSort(array_Small, arrSize1);
	finish = std::chrono::high_resolution_clock::now();
	elapsed1 = finish - start;
	cout << "array_Small   time = " << elapsed1.count() << endl;

	start = std::chrono::high_resolution_clock::now();
	algoritm.timSort(array_Long, arrSize2);
	finish = std::chrono::high_resolution_clock::now();
	elapsed1 = finish - start;
	cout << "array_Small   time = " << elapsed2.count() << endl;

	start = std::chrono::high_resolution_clock::now();
	algoritm.timSort(array_LongBig, arrSize3);
	finish = std::chrono::high_resolution_clock::now();
	elapsed1 = finish - start;
	cout << "array_Small   time = " << elapsed3.count() << endl;
	cout << "average time       \033[32m= " << (elapsed3.count() + elapsed2.count() + elapsed1.count())/3 << "\033[0m" << endl;

	cout << "\n\tradixSort sort" << endl;                            // radixSort
	start = std::chrono::high_resolution_clock::now();
	algoritm.radixSort(array_Small, arrSize1);
	finish = std::chrono::high_resolution_clock::now();
	elapsed1 = finish - start;
	cout << "array_Small   time = " << elapsed1.count() << endl;

	start = std::chrono::high_resolution_clock::now();
	algoritm.radixSort(array_Long, arrSize2);
	finish = std::chrono::high_resolution_clock::now();
	elapsed1 = finish - start;
	cout << "array_Small   time = " << elapsed2.count() << endl;

	start = std::chrono::high_resolution_clock::now();
	algoritm.radixSort(array_LongBig, arrSize3);
	finish = std::chrono::high_resolution_clock::now();
	elapsed1 = finish - start;
	cout << "array_Small   time = " << elapsed3.count() << endl;
	cout << "average time       \033[32m= " << (elapsed3.count() + elapsed2.count() + elapsed1.count())/3 << "\033[0m" << endl;


	cout << "\n\tbucketSort sort" << endl;                            // bucketSort
	start = std::chrono::high_resolution_clock::now();
	algoritm.bucketSort(array_Small, arrSize1);
	finish = std::chrono::high_resolution_clock::now();
	elapsed1 = finish - start;
	cout << "array_Small   time = " << elapsed1.count() << endl;

	start = std::chrono::high_resolution_clock::now();
	algoritm.bucketSort(array_Long, arrSize2);
	finish = std::chrono::high_resolution_clock::now();
	elapsed1 = finish - start;
	cout << "array_Small   time = " << elapsed2.count() << endl;

	start = std::chrono::high_resolution_clock::now();
	algoritm.bucketSort(array_LongBig, arrSize3);
	finish = std::chrono::high_resolution_clock::now();
	elapsed1 = finish - start;
	cout << "array_Small   time = " << elapsed3.count() << endl;
	cout << "average time       \033[32m= " << (elapsed3.count() + elapsed2.count() + elapsed1.count())/3 << "\033[0m" << endl;

	//cout << "\n\tquickSort sort" << endl;                            // quickSort
	//start = std::chrono::high_resolution_clock::now();
	//algoritm.quickSort(array_Small, 0, arrSize1 - 1);
	//finish = std::chrono::high_resolution_clock::now();
	//elapsed1 = finish - start;
	//cout << "array_Small   time = " << elapsed1.count() << endl;

	//start = std::chrono::high_resolution_clock::now();
	//algoritm.quickSort(array_Long, 0, arrSize2 - 1);
	//finish = std::chrono::high_resolution_clock::now();
	//elapsed1 = finish - start;
	//cout << "array_Small   time = " << elapsed2.count() << endl;

	//start = std::chrono::high_resolution_clock::now();
	//algoritm.quickSort(array_LongBig, 0, arrSize3 - 1);
	//finish = std::chrono::high_resolution_clock::now();
	//elapsed1 = finish - start;
	//cout << "array_Small   time = " << elapsed3.count() << endl;
	//cout << "average time       \033[32m= " << (elapsed3.count() + elapsed2.count() + elapsed1.count())/3 << "\033[0m" << endl;

	delete[] array_Small;
	delete[] array_Long;
	delete[] array_LongBig;

	return 0;
}