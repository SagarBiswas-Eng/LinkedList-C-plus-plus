namespace stackList {
    #include "LinkedList.h"
}

template<typename DType>

class Stack {
private:
    stackList:: LinkedList <DType>myStackList;
public:

///push().
    void push(DType data){
        myStackList.insertAtFirst(data);
    }

/// pop().
    void pop(){
        myStackList.deleteFirst();
    }

/// top().
    DType top(){
        if (!myStackList.isEmpty()) {
            std :: cout << "\n\nTop of the stack is: " << myStackList.getLastElement() << std :: endl;
        }
        else{
            std :: cout << "Stack is empty" << std :: endl;
        }
                std :: cout << "\n";
    }

/// display().
    void display(){
        if(myStackList.isEmpty()){
            std :: cout << "..:: The node is empty." << std :: endl;
        }
        else{
            myStackList.showDisplay(myStackList.getHead());
        }
    }
};
