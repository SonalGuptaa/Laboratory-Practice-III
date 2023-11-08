#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int s, int e) {
    int i = s;
    int m = (s + e) / 2;
    int j = m + 1;
    vector<int> temp;
    while (i <= m && j <= e) {
        if (arr[i] < arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= m) {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= e) {
        temp.push_back(arr[j]);
        j++;
    }
    int k = 0;
    for (int idx = s; idx <= e; idx++) {
        arr[idx] = temp[k];
        k++;
    }
}

void mergesort(vector<int> &arr, int s, int e) {
    if (s >= e) {
        return;
    }
    int mid = (s + e) / 2;
    mergesort(arr, s, mid);
    mergesort(arr, mid + 1, e);
    merge(arr, s, e);
}

int main() {
    vector<int> arr;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    mergesort(arr, 0, n - 1);
    cout << "Sorted array using Merge Sort: ";
    for (int i : arr) {
        cout << i << " ";
    }
    return 0;
}
