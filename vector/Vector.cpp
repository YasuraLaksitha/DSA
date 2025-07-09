//
// Created by ASUS on 09/07/2025.
//

//init of vector: current_size->0 maximum_size->1
//push_back: if maximum_size == current_size -> double the array size and after copying new values to  add the element to arr[current_size++];
//           if maximum_size > current_size -> add the element to arr[current_size++];
//pop_back: if current_size > 0 ->  return the arr[--current_size];
//          if current_size == 0 ->  return -1(no element);

#include <iostream>
#include <optional>
using namespace std;

template<typename T>
class Vector {
    T *arr;
    int current_size;
    int maximum_size;

    void double_the_array(T * &arr) {
        maximum_size = maximum_size * 2;
        const auto new_arr = new T[maximum_size];

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
        arr = new T[maximum_size];
    }

    void push_back(const T element) {
        if (maximum_size == current_size) {
            double_the_array(arr);
        }
        arr[current_size++] = element;
    }

    optional<T> pop_back() {
        if (current_size > 0) {
            return arr[--current_size];
        }
        return nullopt;
    }

    void print_array() const {
        for (int i = 0; i < current_size; i++) {
            cout << arr[i] << " ";
        }
    }

    [[nodiscard]] bool is_empty() const {
        return current_size == 0;
    }

    [[nodiscard]] optional<int> front() const {
        if (is_empty())return nullopt;
        return arr[0];
    }

    [[nodiscard]] optional<int> back() const {
        if (is_empty())return nullopt;
        return arr[current_size - 1];
    }

    [[nodiscard]] int capacity() const {
        return maximum_size;
    }

    [[nodiscard]] int size() const {
        return current_size;
    }

    [[nodiscard]] optional<int> at(const int index) const {
        if (is_empty() || index > current_size - 1)return nullopt;
        return arr[index];
    }

    [[nodiscard]] optional<int> operator[](const int index) const {
        if (is_empty() || index > current_size - 1)return nullopt;
        return arr[index];
    }
};

int main() {
    Vector<int> v;

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
    if (const auto front = v.front()) {
        cout << "Front Element: " << *front << "\n";
    } else {
        cout << "Front Element: None\n";
    }

    if (const auto back = v.back()) {
        cout << "Back Element: " << *back << "\n";
    } else {
        cout << "Back Element: None\n";
    }

    cout << "Capacity: " << v.capacity() << "\n";
    cout << "Size: " << v.size() << "\n";
    cout << "Array Contents: ";
    v.print_array();
    cout << "\n------------------------------------\n";

    cout << "Accessing Elements:\n";

    if (const auto val = v.at(2)) {
        cout << "at(2): " << *val << "\n";
    } else {
        cout << "at(2): Invalid index\n";
    }

    if (const auto val = v[2]) {
        cout << "operator[2]: " << *val << "\n";
    } else {
        cout << "operator[2]: Invalid index\n";
    }

    if (const auto val = v.at(10)) {
        cout << "at(10) [out of bounds]: " << *val << "\n";
    } else {
        cout << "at(10) [out of bounds]: Invalid index\n";
    }

    cout << "------------------------------------\n";

    cout << "Popping Elements:\n";
    for (int i = 0; i < 6; i++) {
        if (auto val = v.pop_back()) {
            cout << "Pop: " << *val << "\n";
        } else {
            cout << "Pop: Vector is empty\n";
        }
    }

    cout << "------------------------------------\n";

    cout << "Final State:\n";
    cout << "Capacity: " << v.capacity() << "\n";
    cout << "Size: " << v.size() << "\n";
    cout << "Is Empty: " << (v.is_empty() ? "Yes" : "No") << "\n";
    cout << "Array Contents: ";
    v.print_array();

    return 0;
}
