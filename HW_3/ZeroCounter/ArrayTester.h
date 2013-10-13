#include "Array.h"
#include <QObject>
#include <QtTest/QTest>

class ArrayTester : public QObject
{
    Q_OBJECT
public:
    explicit ArrayTester(QObject *parent = 0) : QObject(parent){}
    
private slots:

    void testCreationByLength()
    {
        Array<int>* block = new Array<int>(4, 0);
        QVERIFY(block->length == 4);
        delete block;
    }

    void testCreationByInitialization()
    {
        Array<char>* block = new Array<char>(5, '0');
        for (int i = 0; i < 5; i++)
        {
            QVERIFY(block->array[i] == '0');
        }
        delete block;
    }

    void testSettingWithinTheLength()
    {
        Array<int>* block = new Array<int>(4, 0);
        block->set(2,2);
        QVERIFY(block->array[2] == 2);
        delete block;
    }

    void testSettingOutOfTheLength()
    {
        Array<int>* block = new Array<int>(4, 0);
        block->set(70,2);
        QVERIFY(block->array[2] == 0);
        delete block;
    }

    void testGettingWithinTheLength()
    {
        Array<bool>* block = new Array<bool>(4, false);
        for (int i = 0; i < 4 ; i++)
        {
            block->set(i, ((i % 2) == 0));
        }
        QVERIFY(block->get(0));
        QVERIFY(!block->get(1));
        delete block;
    }

    void testGettingOutOfTheLength()
    {
        Array<int>* block = new Array<int>(4, false);
        for (int i = 0; i < 4 ; i++)
        {
            block->set(i, i);
        }
        QVERIFY(block->get(23) == 0);
        delete block;
    }
    
    void testCountingZeroes1()
    {
        Array<int>* block = new Array<int>(4, 0);
        block->set(0,2);
        QVERIFY(block->countZeroes() == 3);
        delete block;
    }

    void testCountingZeroes2()
    {
        Array<bool>* block = new Array<bool>(100, false);
        for (int i = 0; i < 100 ; i++)
        {
            block->set(i, ((i % 2) == 0));
        }
        QVERIFY(block->countZeroes() == 50);
        delete block;
    }
};

