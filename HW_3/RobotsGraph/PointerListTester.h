#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "PointerList.h"

class PointerListTester : public QObject
{
    Q_OBJECT
public:
    explicit PointerListTester(QObject *parent = 0) : QObject(parent) {}
    
private slots:

    void testAdding()
    {
        PointerList* list = new PointerList();
        list->add(1);
        list->add(2);
        list->add(3);
        QVERIFY(list->contains(1));
        QVERIFY(list->contains(2));
        QVERIFY(list->contains(3));
        delete list;
    }

    void testDeleting()
    {
        PointerList* list = new PointerList();
        list->add(1);
        list->add(2);
        list->add(3);
        list->remove(2);
        list->remove(1);
        list->remove(3);
        QVERIFY(!list->contains(1));
        QVERIFY(!list->contains(2));
        QVERIFY(!list->contains(3));
        delete list;
    }
    
};
