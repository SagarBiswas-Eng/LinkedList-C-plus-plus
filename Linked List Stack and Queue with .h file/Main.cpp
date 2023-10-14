#include <iostream>
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main() {

    cout << "\t\t..:: LinkedList ::..\t\t\t\n" <<endl;
    LinkedList<int> intList;

    intList.insertAtFirst(40);
    intList.insertAtFirst(30);
    intList.insertAtFirst(20);
    intList.deleteLast();
    intList.displayList();

    LinkedList<string> strList;
    strList.insertAtFirst("One");
    strList.insertAtFirst("Two");
    strList.insertAtFirst("Three");
    strList.displayList();

    cout << "\t\t..:: StackList ::..\t\t\t\n" <<endl;
    Stack <int> myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    cout << "Stack Elements: ";
    myStack.pop();
    myStack.display();
    myStack.top();

    cout << "\t\t..:: QueueList ::..\t\t\t\n" <<endl;
    Queue <string> myQueue;
    myQueue.enQueue("Asif");
    myQueue.enQueue("Sagar Biswas");
    myQueue.enQueue("John Wick");
    myQueue.enQueue("Arif");
    myQueue.deQueue();
    cout << "Queue ";
    myQueue.display();
    myQueue.top();

    return 0;
}
