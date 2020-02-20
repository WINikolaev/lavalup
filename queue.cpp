#include <iostream>
#include <queue>        // подключаем заголовочный файл очереди
using namespace std;
 
int main()
{
    priority_queue<float> myPrQueue;   // создаем пустую приоритетную очередь типа float
 
    // вставка в очередь несколько элементов типа float
    myPrQueue.push(12.45);
    myPrQueue.push(6.93);
    myPrQueue.push(-0.1);
    myPrQueue.push(26.93);
    myPrQueue.push(-3.03);
 
    cout << "Количество элементов в очереди: " << myPrQueue.size() << endl;
    cout << "Порядок элементов в приоритетной очереди: ";
 
    // выгружаем элементы очереди по одному, в порядке их приоритета
    while(!myPrQueue.empty()) {
        cout << myPrQueue.top() << " ";
        myPrQueue.pop();
    }
    return 0;
}