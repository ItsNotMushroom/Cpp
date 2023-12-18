#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            count++;
        }
    }

    std::cout << count << std::endl;

    delete[] arr;
    return 0;
}
