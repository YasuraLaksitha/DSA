#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        const int current = a[i];
        int prev = i - 1;

        while (a[prev] > current and prev >= 0) {
            a[prev + 1] = a[prev];
            prev--;
        }
        a[prev + 1] = current;
    }
}

void selection_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_pos = i;

        for (int j = i + 1; j < n; j++) {
            if (a[min_pos] > a[j]) {
                min_pos = j;
            }
        }

        if (min_pos != i) {
            a[i] = a[i] + a[min_pos];
            a[min_pos] = a[i] - a[min_pos];
            a[i] = a[i] - a[min_pos];
        }
    }
}

void counter_sort(int a[], int n) {
    //find the max
    int max = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (max < a[i])
            max = a[i];
    }

    //create 2nd array with the length of max value
    vector freq(max, 0);

    //update the index of the current value in the new array
    for (int i = 0; i < n; i++)
        freq[a[i]]++;

    //replace the original array with the 2nd array indexes
    int idx = 0;
    for (int i = 0; i <= max; i++) {
        while (freq[i]-- > 0)
            a[idx++] = i;
    }
}


int main() {
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 1, 2, 1};
    int n = sizeof(arr) / sizeof(int);

    insertion_sort(arr, n);

    cout << "insertion_sort" << endl;
    for (const auto x: arr) {
        cout << x << ",";
    }
    cout << endl;

    selection_sort(arr, n);

    cout << "selection_sort" << endl;
    for (const auto x: arr) {
        cout << x << ",";
    }
    cout << endl;

    counter_sort(arr, n);

    cout << "counter_sort" << endl;
    for (const auto x: arr) {
        cout << x << ",";
    }
}
