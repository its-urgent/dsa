/*
??PROBLEM STATEMET:-
Read the marks obtained by students of second year in an online
examination of particular subject. Find out maximum and minimum marks
obtained in that subject. Use heap data structure.Analyze the algorithm.
*/

/*
#??Quick Revision Notes:-
??HEAP DATA STRUCTURE :- When dynamic allocation is done then we use this data structure.
TYPE :- 1. Min Heap :- Root < Child.
        2. Max Heap :- Root > Child.

1. Complete Binary Tree is requaired.
*/

#include<iostream>
using namespace std;

void MinHeapify(int arr[], int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] < arr[smallest])
        smallest = l;

    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        MinHeapify(arr, n, smallest);
    }
}

void MaxHeapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        MaxHeapify(arr, n, largest);
    }
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    int arr[n];
    cout << "Enter the marks of " << n << " students: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Min heapify the array
    for (int i = n / 2 - 1; i >= 0; i--) {
        MinHeapify(arr, n, i);
    }

    // Min marks
    cout << "Minimum Score: " << arr[0] << endl;

    // Max heapify the array
    for (int i = n / 2 - 1; i >= 0; i--) {
        MaxHeapify(arr, n, i);
    }

    // Max marks
    cout << "Maximum Score: " << arr[0] << endl;

    return 0;
}
