#include <stdio.h>
#include "Array.h"
#include "ArrayTester.h"

int main()
{
    ArrayTester* tester = new ArrayTester();
    QTest::qExec(tester);
}
