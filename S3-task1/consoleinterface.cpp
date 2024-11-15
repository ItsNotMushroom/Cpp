#include "consoleinterface.h"
#include "arraylist.h"
#include "linkedlist.h"
#include <iostream>

void DisplayMenu() {
    std::cout << "Menu:\n"
              << "1 - Select List Type\n"
              << "2 - Print List\n"
              << "3 - Add to Front\n"
              << "4 - Add to Tail\n"
              << "5 - Add at Index\n"
              << "6 - Remove from Front\n"
              << "7 - Remove from Tail\n"
              << "8 - Remove at Index\n"
              << "9 - Swap Elements\n"
              << "0 - Exit\n"
              << "Enter your choice: ";
}

List* ChooseListType() {
    std::cout << "Choose List Type:\n1 - Array List\n2 - Linked List\nEnter choice: ";
    int type;
    std::cin >> type;
    if (type == 1) return new ArrayList();
    if (type == 2) return new LinkedList();
    std::cout << "Invalid choice.\n";
    return nullptr;
}

void ConsoleInterface::Start() {
    List* list = nullptr;
    int choice;
    do {
        DisplayMenu();
        std::cin >> choice;
        if (choice == 1) {
            delete list;
            list = ChooseListType();
        } else if (list) {
            list->PerformAction(choice);
        } else if (choice != 0) {
            std::cout << "Please select a list type first.\n";
        }
    } while (choice != 0);
    delete list;
}
