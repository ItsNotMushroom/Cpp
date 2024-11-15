#ifndef LIST_H
#define LIST_H

class List {
public:
    virtual ~List() {}
    virtual void PerformAction(int action) = 0;
};

#endif
