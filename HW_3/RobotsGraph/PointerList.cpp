#include "PointerList.h"
#include <stdio.h>

PointerList::PointerList()
{
    head = NULL;
}

bool PointerList::listIsEmpty() const
{
    return (head == NULL) ;
}

void PointerList::print() const
{
    ListElement* tmp = head ;
    if (!listIsEmpty())
    {

        while (tmp != NULL)
        {
            printf("%d ", tmp->value);
            tmp = tmp->next;
        }
    }
    else
    {
        printf("You have an empty list.");
    }
    printf("\n");
}

bool PointerList::contains(int value) const
{
    if (!(listIsEmpty()))
    {
        ListElement* tmp = head;
        ListElement* previous = tmp;
        while ((tmp->value != value))
        {
            previous = tmp;
            tmp = tmp->next;
            if (tmp == NULL)
                break;
        }
        return (tmp != NULL);
    }
    else
        return false;
}

void PointerList::remove(int value)
{
    if (!(listIsEmpty()))
    {
       ListElement* tmp = head;
       ListElement* previous = tmp;
       while ((tmp->value != value))
       {
           previous = tmp;
           tmp = tmp->next;
           if (tmp == NULL)
               break;
       }
       if (tmp == NULL)
       {
           printf("no such a value\n");
       }
       else
       {
           if (tmp == head)
           {
               head = tmp->next;
               delete tmp;
           }
           else
           {
               previous->next = tmp->next;
               delete tmp;
           }
       }
    }
    else
    {
        printf("You have an empty list.");
    }
}

void PointerList::add(int value)
{
    if (!listIsEmpty())
    {
        ListElement* tmp = head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = new ListElement;
        tmp->next->value = value;
        tmp->next->next = NULL;

    }
    else
    {
     head = new ListElement;
     head->next = NULL;
     head->value = value;
    }
}
PointerList::~PointerList()
{
    if (!listIsEmpty())
    {
        ListElement* tmp = head;
        while(tmp->next != NULL)
        {
            ListElement* tmp2 = tmp ;
            tmp = tmp->next ;
            delete tmp2;
        }
        delete tmp ;
    }
  }
