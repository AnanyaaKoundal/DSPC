#include <iostream>
using namespace std;

template <class T>
class C_Queue{
    T *queue;
    public:
    int size, first, last;
    C_Queue(int s){
        size=s;
        queue=new T(size);
        first=last=-1;
    }
    void enqueue(T el);
    T dequeue();
    bool isEmpty();
    bool isFull();
    T at_first();
    T size_q();
    void display();
};

template <class T>
void C_Queue<T>::enqueue(T el){
    if(isFull()!=true){
        if(last==size-1 || last==-1){
            queue[0]=el;
            last=0;
            if(first==-1)
                first=0;
        }else{
            queue[++last]=el;
        }
    }else{
        cout<<"\nQueue is Full";
    }
}

template <class T>
T C_Queue<T>::dequeue(){
    if(isEmpty() || first>=size){
        return -1;
    }else{
        int data=queue[first];
        if(first==last){
            first=last=-1;
        }else if(first==size-1){
            first=0;
        }else{
            first++;
        }
        return data;
    }
}

template <class T>
bool C_Queue<T>::isEmpty(){
    return first==-1 && last==-1;
}

template <class T>
T C_Queue<T>::at_first(){
    if(isEmpty()){
        return -1;
    }
    return queue[first];
}

template <class T>
bool C_Queue<T>:: isFull(){
    return (first==0 && last==size-1 || first==last+1);
}

template <class T>
T C_Queue<T>:: size_q(){
    if(isEmpty()){
        cout<<"Queue is Empty!!";
    }else{
        int s=0;
        if(last>=first){
            for(int i=first; i<=last; i++){
                s++;
            }
        }else if(first>=last){
            for(int i=first; i<size; i++){
                s++;
            }
            for(int i=0; i<=last; i++){
                s++;
            }
        }
        
    return s;
    }
}

template <class T>
void C_Queue<T>::display(){
    if(isEmpty()){
        cout<<"Queue is Empty!!";
    }else{
        cout<<"Queue: \n";
        if(last>=first){
            cout<<"Front -> ";
            for(int i=first; i<=last; i++){
                cout<<queue[i]<<" ";
            }
            cout<<" <-Rear ";
        }else if(first>=last){
            cout<<"Front -> ";
            for(int i=first; i<size; i++){
                cout<<queue[i]<<" ";
            }
            for(int i=0; i<=last; i++){
                cout<<queue[i]<<" ";
            }
            cout<<" <-Rear ";
        }
    }
    
}

void menu(){
    cout<<"\n\t\tQUEUE OPERATIONS";
    cout<<"\n1. Enqueue";
    cout<<"\n2. Dequeue";
    cout<<"\n3. Element at first";
    cout<<"\n4. Size";
    cout<<"\n5. Display";
    cout<<"\n6. Exit";
}

int main(){
    int size,d,t;
    cout<<"Enter the size of the queue: ";
    cin>>size;
    C_Queue<int> *queue=new C_Queue<int>(size);
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
            t=queue->at_first();
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