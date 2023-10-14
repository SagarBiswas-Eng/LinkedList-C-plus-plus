namespace QueueList{
    #include "LinkedList.h"
}

template<typename DType>

class Queue{
private:
    QueueList :: LinkedList <DType> myQueueList;

public:
/// enQueue().
    void enQueue(DType data){
        myQueueList.insertAtFirst(data);
    }

/// deQueue().
    void deQueue(){
        myQueueList.deleteFirst();
    }

/// top().
    DType top(){
        if(!myQueueList.isEmpty()){
            std :: cout << "Top of the queue is: " << myQueueList.getFirstElement() << std :: endl;
        }
        else{
            std :: cout << "Queue is empty." << std :: endl;
        }
        std :: cout << "\n";
    }

///display().
    void display(){
        myQueueList.displayList();
    }
};
