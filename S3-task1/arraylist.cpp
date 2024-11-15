#include "arraylist.h"

void ArrayList::AddToFront() {
    int value;
    std::cout << "Enter value: ";
    std::cin >> value;
    data.insert(data.begin(), value);
}

void ArrayList::AddToTail() {
    int value;
    std::cout << "Enter value: ";
    std::cin >> value;
    data.push_back(value);
}

void ArrayList::AddAtIndex() {
    int value, index;
    std::cout << "Enter index and value: ";
    std::cin >> index >> value;
    if (index >= 0 && index <= data.size()) 
        data.insert(data.begin() + index, value);
    else 
        std::cout << "Invalid index.\n";
}

void ArrayList::RemoveFromFront() {
    if (!data.empty()) data.erase(data.begin());
}

void ArrayList::RemoveFromTail() {
    if (!data.empty()) data.pop_back();
}

void ArrayList::RemoveAtIndex() {
    int index;
    std::cout << "Enter index: ";
    std::cin >> index;
    if (index >= 0 && index < data.size()) 
        data.erase(data.begin() + index);
    else 
        std::cout << "Invalid index.\n";
}

void ArrayList::SwapElements() {
    int i, j;
    std::cout << "Enter two indices: ";
    std::cin >> i >> j;
    if (i >= 0 && i < data.size() && j >= 0 && j < data.size()) 
        std::swap(data[i], data[j]);
    else 
        std::cout << "Invalid indices.\n";
}

void ArrayList::PrintList() const {
    for (int value : data) 
        std::cout << value << " ";
    std::cout << std::endl;
}

void ArrayList::PerformAction(int action) {
    switch (action) {
        case 2: PrintList(); break;
        case 3: AddToFront(); break;
        case 4: AddToTail(); break;
        case 5: AddAtIndex(); break;
        case 6: RemoveFromFront(); break;
        case 7: RemoveFromTail(); break;
        case 8: RemoveAtIndex(); break;
        case 9: SwapElements(); break;
        default: std::cout << "Invalid action.\n"; break;
    }
}
