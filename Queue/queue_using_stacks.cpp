#include <iostream>
using namespace std;

class Queue{
    int *queue;
    public:
    int size, top=-1;
    Queue(int s){
        size=s;
        queue=new int(size);
    }
    ~Queue(){
        
    }
    void push(int el);
    int pop();
    bool isEmpty();
    int size_q();
    int atTop();
    void display();
};
void Queue::push(int el){
    if(top==size-1){
        cout<<"Queue Overflow!!";
        return;
    }
    else{
        queue[++top]=el;
    }
}
int Queue::pop(){
    int data;
    data=queue[top--];
    return data;
}
bool Queue::isEmpty(){
    return top==-1;
}
int Queue::atTop(){
    if(isEmpty()){
        return -1;
    }
    return queue[top];
}
void Queue::display(){
    cout<<"Queue: \n";
    for(int i=0; i<=top; i++){
        cout<<queue[i]<<"\n";
    }
}
int Queue:: size_q(){
    int s=0;
    for(int i=0; i<=top; i++){
        s++;
    }
    return s;
}
void menu(){
    cout<<"\n\t\tQUEUE OPERATIONS";
    cout<<"\n1. Push";
    cout<<"\n2. Pop";
    cout<<"\n3. Element at top";
    cout<<"\n4. Size";
    cout<<"\n5. Display";
    cout<<"\n6. Exit";
}
int main(){
    int size,d,t;
    cout<<"Enter the size of the Queue: ";
    cin>>size;
    Queue *q=new Queue(size);
    Queue *s2=new Queue(size);
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
            q->push(ele);
            break;
        case 2:
            if(q->isEmpty()==true){
                cout<<"Queue is empty";
            }else{
                int size1=q->size_q();
                for(int i=0; i<size1;i++){
                    s2->push(q->pop());
                }
                int data=s2->pop();
                for(int i=0; i<size-1;i++){
                    q->push(s2->pop());
                }
                cout<<"Deleted element= "<<data;
            }
            break;
        case 3:
            t=q->atTop();
            if(t!=-1){
                cout<<"Element at the top is: "<<q->atTop();
            }else{
                cout<<"Queue Underflow!!";
            }
            break;
        case 4:
            cout<<"Size of the queue is: "<<q->size_q();
            break;
        case 5:
            q->display();
            break;
        case 6:
            return 0;
        }
    }
}