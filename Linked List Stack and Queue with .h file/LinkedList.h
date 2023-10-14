///LinkedList.
template<typename DType>
class LinkedList {
public:
    typedef class Node { // typedef for creating *NodePointer.
    public:
        DType data;
        Node* next;

        Node() {}
        Node(DType data) {
            this -> data = data;
            this -> next = NULL;
        }
    }* NodePointer;


// typedef Node* NodePointer;

    NodePointer head = NULL, curr = NULL;


///Get Last and first element for top().
    DType getFirstElement() {
        return head->data;
    }
    DType getLastElement() {
        return curr->data;
    }///


/// Getting head.
    NodePointer getHead() {
        return head;
    }


/// Function to create a new node
    NodePointer createNewNode(DType data) {
        NodePointer newNode = new Node(data);
        return newNode;
    }


/// isEmpty().
    bool isEmpty() {
        return head == NULL;
    }


/// insertAtFirst()
    void insertAtFirst(DType data) {

        NodePointer newNode = new Node(data);

        if(head == NULL) {
            head = newNode;
            curr = newNode;
        } else {
            newNode -> next = head;
            head = newNode;
        }
    }


/// insertAtLast()
    void insertAtLast(DType data) {

        if(head == NULL) {
            insertAtFirst(data);
        } else {
            NodePointer newNode = createNewNode(data);
            curr -> next = newNode;
            curr = newNode;
        }
    }


/// deleteFirst()
    void deleteFirst() {
        if(head == NULL) {
            //cout << "The node is empty." << endl;
            return;
        } else {
            NodePointer temp = head;
            head = head -> next;
            delete temp;
        }
    }


/// deleteLast()
    void deleteLast() {
        if(head == NULL) {
            //cout << "The node is empty." << endl;
            return;
        } else if(head -> next == NULL) { //If the List has only one Node
            delete head;
            head = NULL;
        } else { //If the List has more than one Node
            NodePointer temp = head;
            while(temp -> next -> next != NULL) { //Find the second last Node
                temp = temp -> next; //(temp -> next) = second last one
            }
            delete temp -> next; //Delete the last Node
            temp -> next = NULL; //Set the next of second, last Node to NULL
            curr = temp; //Set the curr to second last Node
        }
    }


/// showDiaplay() Recursion [LiFo].
void showDisplay(NodePointer temp) {
    if (temp == NULL) { // Base Case
        return;
    } else {
        std::cout << temp->data << " ";
        showDisplay(temp->next);
    }

};


/// displayList() Iteration.
    void displayList() {

        if(head == NULL) {
            std :: cout << "..:: The node is empty." << std :: endl;
            return; // "return" for preventing the code to going down, if(head == NULL);
        }
        else {
            NodePointer temp = head;
            std :: cout << "List:\t";
            while(temp != NULL) { //Printing the data of all Nodes
                std :: cout << temp -> data << " ";
                temp = temp -> next;
            }
            std :: cout << "\n";
        }
        std :: cout << std :: endl;
    }
};

