#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "list.h"
#include <vector>
#include <iostream>

class ArrayList : public List {
private:
    std::vector<int> data;
    void AddToFront();
    void AddToTail();
    void AddAtIndex();
    void RemoveFromFront();
    void RemoveFromTail();
    void RemoveAtIndex();
    void SwapElements();
    void PrintList() const;
public:
    void PerformAction(int action) override;
};

#endif
