#include<iostream>
using namespace std;

/// SingleLinkedList Class
template <typename Dtype>
class SingleLinkedList {
public:
    typedef class Node {
    public:
        Dtype data;
        Node* next;

        Node(Dtype value) {
            data = value;
            next = NULL;
        }
    }* NodePointer;

    NodePointer head = NULL;
    NodePointer curr = NULL;

// getLast and getFrist Element
    Dtype getLastElement() {
        return curr -> data;
    }

    Dtype getFristElement() {
        return head -> data;
    }//


// isEmpty...()
    bool isEmpty() {
        return head == NULL;
    }

// createNode...()
    NodePointer createNode(Dtype value) {
        return new Node(value);
    }

// insertAtFirst...()
    void insertAtFirst(Dtype value) {
        NodePointer newNode = createNode(value);
        if(head == NULL) {
            head = newNode;
            curr = newNode;
        } else {
            newNode -> next = head;
            head = newNode;
        }
    }

// insertAtLast...()
    void insertAtLast(Dtype value) {
        if(head == NULL) {
            insertAtFirst(value);
        } else {
            NodePointer newNode = createNode(value);
            curr -> next = newNode;
            curr = newNode;
        }
    }

// insertBeforeElement...()
    void insertBeforeElement(Dtype value, Dtype d) {
        NodePointer newNode = createNode(value);
        NodePointer temp = head;
        NodePointer pre = NULL;

        while(temp != NULL && temp -> data != d) {
            pre = temp;
            temp = temp -> next;
        }
        if(temp != NULL) {
            newNode -> next = temp;
            if(pre != NULL) {
                pre -> next = newNode;
            } else {
                head = newNode;
            }
        } else {
            cout << "..:: Data not founded ..."  << endl;
        }
    }

// insertAtAnyPos...()
    void insertAtAnyPos(Dtype value, int pos) {
        NodePointer newNode = createNode(value);
        NodePointer temp = head;
        NodePointer pre = NULL;

        int count = 1;

        while(temp != NULL && count < pos) {
            pre = temp;
            temp = temp -> next;
            count ++;
        }
        if(count == pos) {
            if(pre == NULL) {
                insertAtFirst(value);
            } else {
                pre -> next = newNode;
                newNode -> next = temp;
            }
        } else {
            cout << "Position is greater than the length of the list" << endl;
        }
    }

// deleteElementByValue...()
    void deleteElementByValue(Dtype value) {
        if(head == NULL) {
            return;
        }
        NodePointer temp = head;
        NodePointer pre = NULL;

        while(temp != NULL && temp -> data != value) {
            pre = temp;
            temp = temp -> next;
        }
        if(temp == NULL) {
            cout << "Searching value not found..." << endl;
        } else if(pre == NULL) {
            head = temp -> next;
            delete temp;
        } else {
            pre -> next = temp -> next;
            delete temp;
        }
    }

// deleteAtPos...()
    void deleteAtPos(int pos) {
        if(head == NULL) {
            return;
        }
        NodePointer temp = head;
        NodePointer pre = NULL;
        int count = 1;

        while(temp != NULL && count < pos) {
            pre = temp;
            temp = temp -> next;
            count++;
        }
        if(count == pos) { // position found.
            if(pre == NULL) { // if the node to be deleted is the head node.

                head = temp->next;
                delete temp;
            } else {
                pre -> next = temp -> next; // connecting ex: 2nd Node to 4th number node. temp and pos = 3rd node.
                delete temp;
            }
        } else {
            cout << "Invalid position" << endl;
        }
    }

// deleteAtFirst...()
    void deleteAtFirst() {
        if(head == NULL) {
            return;
        } else {
            NodePointer temp = head;
            head = head -> next;
        }
    }

// deleteAtLast...()
    void deleteAtLast() {
        if(head == NULL) {
            return;
        } else if(head -> next == NULL) {
            delete head;
            head = NULL;
        } else {
            NodePointer temp = head;
            while(temp -> next -> next != NULL) {
                temp = temp -> next;
            }
            delete temp -> next;
            temp -> next = NULL;
            curr = temp;
        }
    }

// display...()
    void display() {
        if(head == NULL) {
            cout << "..:: The Node is Empty..." << endl;
        } else {
            NodePointer temp = head;
            cout << "Elements of the Single_Linked_List: ";
            while(temp != NULL) {
                cout << temp -> data << " ";
                temp = temp -> next;
            }
        }
    }
};


/// DoubleLinkedList Class
template <typename Dtype>
class DoubleLinkedList {
public:

    typedef class Node {
    public:

        Dtype data;
        Node* next;
        Node* prev;

        Node(Dtype value) {
            data = value;
            next = NULL;
            prev = NULL;
        }
    }* NodePointer;

    NodePointer head = NULL;
    NodePointer curr = NULL;

// getLast and getFrist Element
    Dtype getLastElement() {
        return curr -> data;
    }

    Dtype getFristElement() {
        return head -> data;
    }///


// isEmpty...()
    bool isEmpty() {
        return head == NULL;
    }

// createNode...()
    NodePointer createNode(Dtype value) {
        return new Node(value);
    }

// insertAtFirst...()
    void insertAtFirst(Dtype value) {
        NodePointer newNode = createNode(value);
        if(head == NULL) {
            head = newNode;
            curr = newNode;
        } else {
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
        }
    }

// insertAtLast...()
    void insertAtLast(Dtype value) {
        if(head == NULL) {
            insertAtFirst(value);
        } else {
            NodePointer newNode = createNode(value);
            newNode -> prev = curr;
            curr -> next = newNode;
            curr = newNode;
        }
    }

// insertAtAnyPos...()
    void insertAtAnyPos(Dtype value, int pos) {

        NodePointer newNode = createNode(value);
        if(pos < 0) {
            cout << "..:: Invalid Position..." << endl;
        }
        if(head == NULL) {
            if(pos == 0) {
                head = newNode;
            } else {
                cout << "..:: Invalid Position..." << endl;
            }
        }
        if(pos == 0) {
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
        }

        NodePointer temp = head;
        int count = 0;
        while(temp != NULL && count < pos) {
            temp = temp -> next;
            count ++;
        }
        if(temp == NULL && count == pos) { // if the position is the end of the list
            temp = newNode;
            temp -> prev = curr;
            curr -> next = temp;
            curr = temp;
        } else if(temp == NULL && count != pos) {
            cout << "..:: Invalid Position..." << endl;
        } else {
            newNode -> prev = temp -> prev;
            newNode -> next = temp;
            temp -> prev -> next = newNode;
            temp -> prev = newNode;
        }
    }


// insertBeforeElement...()
    void insertBeforeElement(Dtype value, Dtype element) {
        if(head == NULL) {
            return;
        }
        NodePointer temp = head;
        while(temp != NULL && temp -> data != element) {
            temp = temp -> next;
        }
        if(temp == NULL) {
            cout << "Element not found in list" << endl;
        } else {
            NodePointer newNode = createNode(value);
            newNode -> prev = temp -> prev;
            newNode -> next = temp;
            if(temp -> prev != NULL) { // checking if the previous node of the current node temp is not NULL.
                temp -> prev -> next = newNode;
            } else {
                head = newNode;
            }
            temp -> prev = newNode;
        }
    }

// deleteElement...()
    void deleteElement(Dtype element) {
        if(head == NULL) {
            return;
        }
        NodePointer temp = head;
        while(temp != NULL && temp -> data != element) {
            temp = temp -> next;
        }
        if(temp == NULL) {
            cout << "..:: Element not found..." << endl;
        }
        if(temp == head) {
            head = temp -> next;
        }
        if(temp -> prev != NULL) {
            temp -> prev -> next = temp -> next;
        }
        if(temp -> next != NULL) {
            temp -> next -> prev = temp -> next;
        }
        delete temp;
    }

// deletePos...()
    void deletePos(int pos) {
        if(head == NULL) {
            return;
        }
        NodePointer temp = head;
        int count = 1;
        while(temp != NULL && count < pos) {
            temp = temp -> next;
            count ++;
        }
        if(count == pos && temp!= NULL ) {

            if(temp == head) {
                head = temp -> next;
            }
            if(temp -> prev != NULL) {
                temp -> prev -> next = temp -> next;
            }
            if(temp -> next != NULL) {
                temp -> next -> prev = temp -> prev;
            }
            delete temp;
        } else {
            cout << "Invalid position or position not found" << endl;
        }
    }


// deleteAtFirst...()
    void deleteAtFirst() {
        if(head == NULL) {
            return;
        }

        NodePointer temp = head;
        head = head -> next;

        if(head != NULL) {
            head -> prev = NULL;
        }
        delete temp;
    }


// deleteAtLast...()
    void deleteAtLast() {
        if(head == NULL) {
            return;
        }
        NodePointer temp = curr;
        curr = curr -> prev;
        if(curr == NULL) {
            head = NULL;
        } else {
            curr -> next = NULL;
        }
        delete temp;
    }


// display...()
    void display() {
        if(head == NULL) {
            cout << "..:: The Node is Empty..." << endl;
        } else {
            NodePointer temp = head;
            cout << "Elements of the Double_Linked_List: ";
            while(temp != NULL) {
                cout << temp -> data << " ";
                temp = temp -> next;
            }
        }
        cout << "\n";
    }
};


/// StackSingleList
template <typename Dtype>
class StackSingleList : public SingleLinkedList<Dtype> {
public:

// push...
    void push(Dtype value) {
        this -> insertAtFirst(value);
    }

// pop...
    void pop() {
        this -> deleteAtFirst();
    }

// top...
    void top() {
        if(!SingleLinkedList<Dtype> :: isEmpty()) {
            cout << "Top of the singleList stack is: " << SingleLinkedList<Dtype> :: getFristElement() << endl;
        } else {
            cout << "..:: SingleList Stack list is Empty... " << endl;
        }
        cout << "\n";
    }

// displayStack...
    void displayStack() {
        if(!SingleLinkedList<Dtype> :: isEmpty()) {
            SingleLinkedList<Dtype> :: display();
        } else {
            cout << "..:: SingleList Stack list is Empty..." << endl;
        }
        cout << "\n";
    }
};


/// StackDoubleList
template <typename Dtype>
class StackDoubleList : public DoubleLinkedList<Dtype> {
public:

// push...
    void push(Dtype value) {
        this -> insertAtFirst(value);
    }

// pop...
    void pop() {
        this -> deleteAtFirst();
    }

// top...
    void top() {
        if(!DoubleLinkedList<Dtype> :: isEmpty()) {
            cout << "Top of the doubleList stack is: " << DoubleLinkedList<Dtype> :: getFristElement() << endl;
        } else {
            cout << "..:: DoubleList Stack list is Empty... " << endl;
        }
        cout << "\n";
    }

// displayStack...
    void displayStack() {
        if(!DoubleLinkedList<Dtype> :: isEmpty()) {
            DoubleLinkedList<Dtype> :: display();
        } else {
            cout << "..:: DoubleList Stack list is Empty..." << endl;
        }
        cout << "\n";
    }
};


/// QueueSingleList
template <typename Dtype>
class QueueSingleList : public SingleLinkedList <Dtype> {
public:

// enQueue...
    void enQueue(Dtype value) {
        SingleLinkedList <Dtype> :: insertAtLast(value);
    }

// deQueue...
    void deQueue() {
        SingleLinkedList <Dtype> :: deleteAtFirst();
    }

// top...
    void top() {
        if(!SingleLinkedList <Dtype> :: isEmpty()) {
            cout << "Top of the singleList queue is: " << SingleLinkedList<Dtype> :: getFristElement() << endl;
        } else {
            cout << "..:: SingleList Queue list is Empty..." << endl;
        }
        cout << "\n";
    }

// displayQueue...
    void displayQueue() {
        if(!SingleLinkedList <Dtype> :: isEmpty()) {
            SingleLinkedList <Dtype> :: display();
        } else {
            cout << "..:: SingleList Queue list is Empty..." << endl;
        }
    }
};


/// QueueDoubleList
template <typename Dtype>
class QueueDoubleList : public DoubleLinkedList <Dtype> {
public:

// enQueue...
    void enQueue(Dtype value) {
        DoubleLinkedList <Dtype> :: insertAtLast(value);
    }

// deQueue...
    void deQueue() {
        DoubleLinkedList <Dtype> :: deleteAtFirst();
    }

// top...
    void top() {
        if(!DoubleLinkedList <Dtype> :: isEmpty()) {
            cout << "Top of the doubleList queue is: " << DoubleLinkedList<Dtype> :: getFristElement() << endl;
        } else {
            cout << "..:: DoubleList Queue list is Empty..." << endl;
        }
        cout << "\n";
    }

// displayQueue...
    void displayQueue() {
        if(!DoubleLinkedList <Dtype> :: isEmpty()) {
            DoubleLinkedList <Dtype> :: display();
        } else {
            cout << "..:: DoubleList Queue list is Empty..." << endl;
        }
    }
};


template <typename Dtype>
class BST {
public:
    typedef class Node {
    public:

        Dtype data;
        Node* right;
        Node* left;

        Node(Dtype value) {
            data = value;
            right = NULL;
            left = NULL;
        }
    }* NodePointer;

// createNode...()
    NodePointer createNode(Dtype value) {
        return new Node(value);
    }

// insertNode...()
    NodePointer insertNode(NodePointer root, Dtype value) {

        NodePointer newNode = createNode(value);
        if(root == NULL) {
            root = newNode;
        } else if(value < root -> data) {
            root -> left = insertNode(root -> left, value);
        } else if(value > root -> data) {
            root -> right = insertNode(root -> right, value);
        }
        return root;
    }

// inOrderTraversal...()
    void inOrderTraversal(NodePointer root) {
        if(root != NULL) {
            inOrderTraversal(root -> left);
            cout << root -> data << " ";
            inOrderTraversal(root -> right);
        }
    }

// preOrderTraversel...()
    void preOrderTraversel(NodePointer root) {
        if(root != NULL) {
            cout << root -> data << " ";
            preOrderTraversel(root -> left);
            preOrderTraversel(root -> right);
        }
    }

// PostOrderTraversel...()
    void PostOrderTraversel(NodePointer root) {
        if(root != NULL) {
            PostOrderTraversel(root -> left);
            PostOrderTraversel(root -> right);
            cout << root -> data << " ";
        }
    }
};
