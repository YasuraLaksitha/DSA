//
// Created by ASUS on 09/07/2025.
//

//init of vector: current_size->0 maximum_size->1
//push_back: if maximum_size == current_size -> double the array size and after copying new values to  add the element to arr[current_size++];
//           if maximum_size > current_size -> add the element to arr[current_size++];
//pop_back: if current_size > 0 ->  return the arr[--current_size];
//          if current_size == 0 ->  return -1(no element);

#include <iostream>
using namespace std;

class Vector {
    int *arr;
    int current_size;
    int maximum_size;

    void double_the_array(int * &arr) {
        maximum_size = maximum_size * 2;
        const auto new_arr = new int[maximum_size];

        for (int i = 0; i < maximum_size; i++) {
            new_arr[i] = arr[i];
        }

        delete [] arr;
        arr = new_arr;
    }

public:
    Vector() {
        current_size = 0;
        maximum_size = 1;
        arr = new int[maximum_size];
    }

    void push_back(const int element) {
        if (maximum_size == current_size) {
            double_the_array(arr);
        }
        arr[current_size++] = element;
    }

    int pop_back() {
        if (current_size > 0) {
            return arr[--current_size];
        }
        return -1;
    }

    void print_array() const {
        for (int i = 0; i < current_size; i++) {
            cout << arr[i] << " ";
        }
    }

    [[nodiscard]] bool is_empty() const {
        return current_size == 0;
    }

    [[nodiscard]] int front() const {
        return is_empty() ? -1 : arr[0];
    }

    [[nodiscard]] int back() const {
        return is_empty() ? -1 : arr[current_size - 1];
    }

    [[nodiscard]] int capacity() const {
        return maximum_size;
    }

    [[nodiscard]] int size() const {
        return current_size;
    }

    [[nodiscard]] int at(const int index) const {
        return is_empty() ? -1 : index > current_size - 1 ? -1 : arr[index];
    }

    [[nodiscard]] int operator[](const int index) const {
        return is_empty() ? -1 : index > current_size - 1 ? -1 : arr[index];
    }
};

int main() {
    Vector v;

    cout << "Initial State:\n";
    cout << "Capacity: " << v.capacity() << "\n";
    cout << "Size: " << v.size() << "\n";
    cout << "Is Empty: " << (v.is_empty() ? "Yes" : "No") << "\n";
    cout << "------------------------------------\n";

    cout << "Adding Elements:\n";
    v.push_back(10);
    v.push_back(30);
    v.push_back(20);
    v.push_back(62);
    v.push_back(50);

    cout << "After push_back():\n";
    cout << "Front Element: " << v.front() << "\n";
    cout << "Back Element: " << v.back() << "\n";
    cout << "Capacity: " << v.capacity() << "\n";
    cout << "Size: " << v.size() << "\n";
    cout << "Array Contents: ";
    v.print_array();
    cout << "\n------------------------------------\n";

    cout << "Accessing Elements:\n";
    cout << "at(2): " << v.at(2) << "\n";
    cout << "operator : " << v[2] << "\n";
    cout << "at(10) [out of bounds]: " << v.at(10) << "\n";
    cout << "------------------------------------\n";

    cout << "Popping Elements:\n";
    cout << "Pop: " << v.pop_back() << "\n";
    cout << "Pop: " << v.pop_back() << "\n";
    cout << "Pop: " << v.pop_back() << "\n";
    cout << "Pop: " << v.pop_back() << "\n";
    cout << "Pop: " << v.pop_back() << "\n";
    cout << "Pop (should return -1): " << v.pop_back() << "\n";
    cout << "------------------------------------\n";

    cout << "Final State:\n";
    cout << "Capacity: " << v.capacity() << "\n";
    cout << "Size: " << v.size() << "\n";
    cout << "Is Empty: " << (v.is_empty() ? "Yes" : "No") << "\n";
    cout << "Array Contents: ";
    v.print_array();

    return 0;
}
