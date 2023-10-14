#include<iostream>

using namespace std;
namespace my_namespace {
    #include "mySTL.h"
}

int main() {

/// mySingleList...
    cout << "..:: #.Single Linked List..." << endl << "\n";

    my_namespace :: SingleLinkedList <int> mySingleList;
    mySingleList.insertAtFirst(10);
    mySingleList.insertAtFirst(20);
    mySingleList.insertAtFirst(30);
    mySingleList.insertAtFirst(40);
    mySingleList.insertAtFirst(60);
    mySingleList.deleteAtPos(4);
    mySingleList.insertAtFirst(50);
    mySingleList.insertAtLast(70);
    mySingleList.insertBeforeElement(100, 40);
    mySingleList.insertAtAnyPos(80, 3);
    mySingleList.deleteElementByValue(30);
    mySingleList.deleteAtFirst();
    mySingleList.deleteAtLast();
    mySingleList.deleteAtPos(5);
    mySingleList.display();

    cout << "\n\t ----- X -----" << endl;
    cout << "\n";

/// myDoubleList...
    cout << "..:: #.Double Linked List..." << endl << "\n";

    my_namespace :: DoubleLinkedList <int> myDoubleList;
    myDoubleList.insertAtFirst(10);
    myDoubleList.insertAtFirst(20);
    myDoubleList.insertAtFirst(30);
    myDoubleList.insertAtFirst(40);
    myDoubleList.deleteAtFirst();
    myDoubleList.display();

    cout << "\t ----- X -----" << endl;
    cout << "\n";

/// mySingleStackList...
    cout << "..:: #.Single Stack Linked List..." << endl << "\n";

    my_namespace :: StackSingleList <int> mySingleStackList;
    mySingleStackList.push(10);
    mySingleStackList.push(20);
    mySingleStackList.push(30);
    mySingleStackList.push(40);
    mySingleStackList.top();
    mySingleStackList.pop();
    mySingleStackList.displayStack();

    cout << "\t ----- X -----" << endl;
    cout << "\n";

/// myDoubleQueueList...
    cout << "..:: #.Double Queue Linked List..." << endl << "\n";

    my_namespace :: QueueDoubleList <int> myDoubleQueueList;
    myDoubleQueueList.enQueue(10);
    myDoubleQueueList.enQueue(20);
    myDoubleQueueList.enQueue(30);
    myDoubleQueueList.enQueue(40);
    myDoubleQueueList.top();
    myDoubleQueueList.deQueue();
    myDoubleQueueList.displayQueue();

    cout << "\t ----- X -----" << endl;
    cout << "\n";

/// Binary Search Tree...
    my_namespace :: BST <int> myBST;
    my_namespace :: BST <int> :: NodePointer root = NULL;

    root = myBST.insertNode(root, 10);
    myBST.insertNode(root, 7);
    myBST.insertNode(root, 3);
    myBST.insertNode(root, 5);
    myBST.insertNode(root, 15);

    cout << "In Order Traversal\t: ";
    myBST.inOrderTraversal(root);

                    cout << "\n";

    cout << "In Pre-Order Traversal\t: ";
    myBST.preOrderTraversel(root);

                    cout << "\n";

    cout << "In Post-Order Traversal\t: ";
    myBST.PostOrderTraversel(root);

                    cout << "\n";

    cout << "\t ----- X -----" << endl;


    return 0;
}
/// end.................
