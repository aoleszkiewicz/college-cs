#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "sortingAlgorithms.h"

using namespace std;

int main() {
    int optimistic_list[20000];
    int random_list[20000];
    int pesimistic_list[20000];

    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i <= 20000; i++) {
        optimistic_list[i] = i;
        random_list[i] = rand() % 50 + 1;
    }

    int k = 0;
    for (int j = 20000; j >= 0; j--) {
        pesimistic_list[k++] = j;
    }

    int optimistic_list_length = sizeof(optimistic_list)/sizeof(optimistic_list[0]);
    int random_list_length = sizeof(random_list)/sizeof(random_list[0]);
    int pesimistic_list_length = sizeof(pesimistic_list)/sizeof(pesimistic_list[0]);

    // Bubble Sort Optimistic List
    auto start = chrono::high_resolution_clock::now();
    bubble_sort(optimistic_list, optimistic_list_length);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    auto bubbleSortOptimisticListDuration = duration.count();

    // Bubble Sort Random List
    start = chrono::high_resolution_clock::now();
    bubble_sort(random_list, random_list_length);
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    auto bubbleSortRandomListDuration = duration.count();

    // Bubble Sort Pesimistic List
    start = chrono::high_resolution_clock::now();
    bubble_sort(pesimistic_list, pesimistic_list_length);
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    auto bubbleSortPesimisticListDuration = duration.count();


    // Insertion Sort Optimistic List
    start = chrono::high_resolution_clock::now();
    insertion_sort(optimistic_list, optimistic_list_length);
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    auto insertionSortOptimisticListDuration = duration.count();

    // Insertion Sort Random List
    start = chrono::high_resolution_clock::now();
    insertion_sort(random_list, random_list_length);
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    auto insertionSortRandomListDuration = duration.count();

    // Insertion Sort Pesimistic List
    start = chrono::high_resolution_clock::now();
    insertion_sort(pesimistic_list, pesimistic_list_length);
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    auto insertionSortPesimisticListDuration = duration.count();


    // Quick Sort Optimistic List
    start = chrono::high_resolution_clock::now();
    quick_sort(optimistic_list, 0, optimistic_list_length - 1);
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    auto quickSortOptimisticListDuration = duration.count();

    // Quick Sort Random List
    start = chrono::high_resolution_clock::now();
    quick_sort(random_list, 0, random_list_length - 1);
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    auto quickSortRandomListDuration = duration.count();

    // Quick Sort Pesimistic List
    start = chrono::high_resolution_clock::now();
    quick_sort(pesimistic_list, 0, pesimistic_list_length - 1);
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    auto quickSortPesimisticDuration = duration.count();

    // Merge Sort Optimistic List
    start = chrono::high_resolution_clock::now();
    merge_sort(optimistic_list, 0, optimistic_list_length - 1);
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    auto mergeSortOptimisticListDuration = duration.count();

    // Merge Sort Random List
    start = chrono::high_resolution_clock::now();
    merge_sort(random_list, 0, random_list_length - 1);
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    auto mergeSortRandomListDuration = duration.count();

    // Merge Sort Pesimistic List
    start = chrono::high_resolution_clock::now();
    merge_sort(pesimistic_list, 0, pesimistic_list_length - 1);
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    auto mergeSortPesimisticListDuration = duration.count();

//    cout << "Execution time of Bubble Sort algorithm: " << bubbleSortDuration << " milliseconds" << endl;
//    cout << "Execution time of Insertion Sort algorithm: " << insertionSortDuration << " milliseconds" << endl;
//    cout << "Execution time of Quick Sort algorithm: " << quickSortDuration << " milliseconds" << endl;
//    cout << "Execution time of Merge Sort algorithm: " << mergeSortDuration << " milliseconds" << endl;

    ofstream file;
    file.open("./sorting_algorithms_time_complexity.txt");
    string line = "Czas wykonania algorytmu ";
    file << line << "bubbleSort na optymistycznej liście wynosi: " << bubbleSortOptimisticListDuration << "ms" << "\n";
    file << line << "insertionSort na optymistycznej liście wynosi: " << insertionSortOptimisticListDuration << "ms" << "\n";
    file << line << "quickSort na optymistycznej liście wynosi: " << quickSortOptimisticListDuration << "ms" << "\n";
    file << line << "mergeSort na optymistycznej liście wynosi: " << mergeSortOptimisticListDuration << "ms" << "\n\n";

    file << line << "bubbleSort na randomowej liście wynosi: " << bubbleSortRandomListDuration << "ms" << "\n";
    file << line << "insertionSort na randomowej liście wynosi: " << insertionSortRandomListDuration << "ms" << "\n";
    file << line << "quickSort na randomowej liście wynosi: " << quickSortRandomListDuration << "ms" << "\n";
    file << line << "mergeSort na randomowej liście wynosi: " << mergeSortRandomListDuration << "ms" << "\n\n";

    file << line << "bubbleSort na pesymistycznej liście wynosi: " << bubbleSortPesimisticListDuration << "ms" << "\n";
    file << line << "insertionSort na pesymistycznej liście wynosi: " << insertionSortPesimisticListDuration << "ms" << "\n";
    file << line << "quickSort na pesymistycznej liście wynosi: " << quickSortPesimisticDuration << "ms" << "\n";
    file << line << "mergeSort na pesymistycznej liście wynosi: " << mergeSortPesimisticListDuration << "ms" << "\n\n";
    file.close();

    return 0;
}
