#include<bits/stdc++.h>
using namespace std;

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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10, 34, 56, 12, 78, 45, 67, 89, 23, 3};
    int n = arr.size();
    mergeSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}
