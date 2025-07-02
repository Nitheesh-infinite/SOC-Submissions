#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

// ----------- Counting Sort (Linear Sort) -----------
void countingSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end()); // max_element retunrs an iterator to the maximum element in the range
    vector<int> count(maxVal + 1, 0);
    for (int num : arr) count[num]++;
    int x = 0;
    for (int i = 0; i <= maxVal; ++i)
        while (count[i]--) arr[x++] = i;
}

// ----------- Insertion Sort (Binary Sort analogy) -----------
void insertionSort(vector<int>& arr) {
    int k = arr.size();
    for (int i = 1; i < k; ++i) {
        int current = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}

// ----------- Merge Sort (Divide & Conquer) -----------
void merge(vector<int>& arr, int l, int m, int r) {
    int size1 = m - l + 1;
    int size2 = r - m;
    int* left = new int[size1];
    int* right = new int[size2];
    for (int i = 0; i < size1; ++i) {left[i] = arr[l + i];}
    for (int j = 0; j < size2; ++j) {right[j] = arr[m + 1 + j];}
    int i = 0, j = 0, k = l;
    while (i < size1 && j < size2) {
        if (left[i] <= right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }
    while (i < size1) {arr[k++] = left[i++];}
    while (j < size2) {arr[k++] = right[j++];}
    delete[] left;
    delete[] right;
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int mid = (r + l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr1 = {38, 27, 43, 3, 9, 82, 10, 34, 56, 12, 78, 45, 67, 89, 23, 3};
    vector<int> arr2 = {38, 27, 43, 3, 9, 82, 10, 34, 56, 12, 78, 45, 67, 89, 23, 3};
    vector<int> arr3 = {38, 27, 43, 3, 9, 82, 10, 34, 56, 12, 78, 45, 67, 89, 23, 3};
  
    auto start = high_resolution_clock::now();
    countingSort(arr1);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Counting Sort time: " << duration.count() << " microseconds\n";
    cout << "Sorted array using Counting Sort: ";
    for (int num : arr1) {
        cout << num << " ";
    }
    cout << "\n";

    auto start2 = high_resolution_clock::now();
    insertionSort(arr2);
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(end2 - start2);
    cout << "Insertion Sort time: " << duration2.count() << " microseconds\n";
    cout << "Sorted array using Insertion Sort: ";
    for (int num : arr2) {
        cout << num << " ";
    }
    cout << "\n";

    auto start3 = high_resolution_clock::now();
    mergeSort(arr3, 0, arr3.size() - 1);
    auto end3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(end3 - start3);
    cout << "Merge Sort time: " << duration3.count() << " microseconds\n";
    cout << "Sorted array using Merge Sort: ";
    for (int num : arr3) {
        cout << num << " ";
    }
    cout << "\n";
    
    return 0;
}
