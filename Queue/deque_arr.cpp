#include <iostream>
using namespace std;

class Deque{
    int *queue;
    public:
    int size, front, last;
    Deque(int s){
        size=s;
        queue=new int(size);
        front=last=-1;
    }
    ~Deque(){
        
    }
    void enqueue_end(int el);
    void enqueue_front(int el);
    int dequeue_front();
    int dequeue_end();
    bool isEmpty();
    bool isFull();
    int at_front();
    int size_q();
    void display();
};
void Deque::enqueue_end(int el){
    if(last!=size-1){
        if(last==-1){
            queue[0]=el;
            last=0;
            if(front==-1)
                front=0;
        }else{
            queue[++last]=el;
        }
    }else{
        cout<<"\nQueue is Full from end";
    }
}
void Deque::enqueue_front(int el){
    if(front!=0){
        if(front==-1){
            queue[0]=el;
            front=0;
            if(last==-1)
                last=0;
        }else{
            queue[--front]=el;
        }
    }else{
        cout<<"\nQueue is Full from front";
    }
}
int Deque::dequeue_front(){
    if(isEmpty()){
        return -1;
    }else{
        int data=queue[front];
        if(front==last){
            front=last=-1;
        }else if(front==size-1){
            front=0;
        }else{
            front++;
        }
        return data;
    }
}
int Deque::dequeue_end(){
    if(isEmpty()){
        return -1;
    }else{
        int data=queue[last];
        if(front==last){
            front=last=-1;
        }else if(front==size-1){
            front=0;
        }else{
            front++;
        }
        return data;
    }
}
bool Deque::isEmpty(){
    return front==-1 && last==-1;
}
int Deque::at_front(){
    if(isEmpty()){
        return -1;
    }
    return queue[front];
}
bool Deque:: isFull(){
    return (front==0 && last==size-1 || front==last+1);
}
int Deque:: size_q(){
    if(isEmpty()){
        cout<<"Queue is Empty!!";
    }else{
        int s=0;
        if(last>=front){
            for(int i=front; i<=last; i++){
                s++;
            }
        }else if(front>=last){
            for(int i=front; i<size; i++){
                s++;
            }
            for(int i=0; i<=last; i++){
                s++;
            }
        }
        
    return s;
    }
}
void Deque::display(){
    if(isEmpty()){
        cout<<"Queue is Empty!!";
    }else{
        cout<<"Queue: \n";
        if(last>=front){
            for(int i=front; i<=last; i++){
                cout<<queue[i]<<"\n";
            }
        }else if(front>=last){
            for(int i=front; i<size; i++){
                cout<<queue[i]<<"\n";
            }
            for(int i=0; i<=last; i++){
                cout<<queue[i]<<"\n";
            }
        }
    }
    
}
void menu(){
    cout<<"\n\t\tqueue OPERATIONS";
    cout<<"\n1. enqueue_end";
    cout<<"\n2. Dequeue_front";
    cout<<"\n3. Element at front";
    cout<<"\n4. Size";
    cout<<"\n5. Display";
    cout<<"\n6. Exit";
}
int main(){
    int size,d,t;
    cout<<"Enter the size of the queue: ";
    cin>>size;
    Deque *queue=new Deque(size);
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
            queue->enqueue_end(ele);
            break;
        case 2:
            d=queue->dequeue_front();
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