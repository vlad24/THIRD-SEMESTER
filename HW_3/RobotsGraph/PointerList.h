#pragma once

class PointerList
{
    friend class ListTester;
public:
    PointerList();
    void add(int value);
    void remove(int value);
    void print() const;
    bool contains(int value) const;
    ~PointerList();
private:
    struct ListElement
    {
        int value;
        ListElement* next;
    };
    ListElement* head;
    bool listIsEmpty() const;
};
