//
// Created by ASUS on 30/04/2025.
//

#include "sub_arrays.h"

#include <iostream>
using namespace std;

int largest_sub_array_sum1(int arr[], int n) {
    int largest_sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sub_array_sum = 0;

            for (int k = i; k <= j; k++) {
                sub_array_sum += arr[k];
            }
            largest_sum = max(sub_array_sum, largest_sum);
        }
    }
    return largest_sum;
}

int largest_sub_array_sum2(int arr[], int n) {
    int prefix_sum[100];
    int largest_sum = 0;

    prefix_sum[0] = arr[0];

    for (int i = 1; i < n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
    }

    for (int i = 0; i < n; ++i) {
        int sub_array_sum;
        for (int j = i; j < n; j++) {
            sub_array_sum = i > 0 ? prefix_sum[j] - prefix_sum[i - 1] : prefix_sum[j];
            largest_sum = max(largest_sum, sub_array_sum);
        }
    }
    return largest_sum;
}

//kadane's algorithm
int largest_sub_array_sum3(int arr[], int n) {
    int cs = 0;
    int largest_sum = 0;

    for (int i = 0; i < n; i++) {
        cs += arr[i];
        if (cs <= 0) {
            cs = 0;
        }
        largest_sum = max(largest_sum, cs);
    }
    return largest_sum;
}


int main() {
    int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(arr) / sizeof(int);

    cout << "largest sub array sum: " << largest_sub_array_sum1(arr, n);
    cout << std::endl;
    cout << "largest sub array sum: " << largest_sub_array_sum2(arr, n);
    cout << endl;
    cout << "largest sub array sum (kadane's algorithm): " << largest_sub_array_sum3(arr, n);

    return 0;
}
