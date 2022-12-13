#include <iostream>
using namespace std;

class L_Queue{
    int *queue;
    public:
    int size, front, rear;
    L_Queue(int s){
        size=s;
        queue=new int(size);
        front=rear=-1;
    }
    ~L_Queue(){
        
    }
    void enqueue(int el);
    int dequeue();
    bool isEmpty();
    int at_front();
    int size_q();
    void display();
};
void L_Queue::enqueue(int el){
    if(rear==size-1){
        cout<<"Queue is Full!!";
        return;
    }else if(front==-1){
        queue[++rear]=el;
        front++;
    }
    else{
        queue[++rear]=el;
    }
}
int L_Queue::dequeue(){
    int data;
    if(isEmpty() || front>=size){
        return -1;
    }else{
        data=queue[front++];
        return data;
    }
}
bool L_Queue::isEmpty(){
    return front==-1;
}
int L_Queue::at_front(){
    if(isEmpty()){
        return -1;
    }
    return queue[front];
}
int L_Queue:: size_q(){
    int s=0;
    for(int i=front; i<=rear; i++){
        s++;
    }
    return s;
}
void L_Queue::display(){
    cout<<"Queue: \n";
    for(int i=front; i<=rear; i++){
        cout<<queue[i]<<"\n";
    }
}
void menu(){
    cout<<"\n\t\tqueue OPERATIONS";
    cout<<"\n1. Enqueue";
    cout<<"\n2. Dequeue";
    cout<<"\n3. Element at front";
    cout<<"\n4. Size";
    cout<<"\n5. Display";
    cout<<"\n6. Exit";
}
int main(){
    int size,d,t;
    cout<<"Enter the size of the queue: ";
    cin>>size;
    L_Queue *queue=new L_Queue(size);
    while(true){
        menu();
        int ch;
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"Enter the element: ";
            int ele;
            cin>>ele;
            queue->enqueue(ele);
            break;
        case 2:
            d=queue->dequeue();
            if(d!=-1){
                cout<<"Deleted element: "<<d;
            }else{
                cout<<"Queue Empty!";
            }
            break;
        case 3:
            t=queue->at_front();
            if(t!=-1){
                cout<<"Element at the top is: "<<t;
            }else{
                cout<<"Queue Underflow!!";
            }
            break;
        case 4:
            cout<<"Size of the queue is: "<<queue->size_q();
            break;
        case 5:
            queue->display();
            break;
        case 6:
            return 0;
        }
    }
}