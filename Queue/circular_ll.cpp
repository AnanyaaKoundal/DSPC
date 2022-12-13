#include<iostream>
using namespace std;

template <class T>
class node{
    public:
    T data;
    node *next;
};

template <class T>
class C_Queue_LinkedList{
    node<T> *tail, *temp, *temp1;
    public:
        C_Queue_LinkedList(){
            tail=temp=temp1=NULL;
        }
        ~C_Queue_LinkedList(){
            temp=tail->next;
            do{
                temp1=temp->next;
                delete temp;
                temp=temp1;
            }while(temp!=tail->next);
            tail=NULL;
        }
        void enqueue(T ele);
        T dequeue();
        void display();
        T atFront();
        void search();
        bool isEmpty();
        bool isFull();
        int size_q();
};

template <class T>
void C_Queue_LinkedList<T>::enqueue(T ele){
    temp=new node<T>;
    temp->data=ele;
    temp->next=NULL;
    if(tail==NULL){
        tail=temp;
        tail->next=tail;
    }else{
        temp->next=tail->next;
        tail->next=temp;
        tail=temp;
    }
}

template <class T>
T C_Queue_LinkedList<T>::dequeue(){
    if(tail==NULL){
        cout<<"Error, Queue empty"<<endl;
    }else if(size_q()==1){
        T data=tail->data;
        delete tail;
        return data;
    }else{
        T data=tail->next->data;
        temp=tail->next;
        tail->next=temp->next;
        delete temp;
        return data;
    }
}

template <class T>
void C_Queue_LinkedList<T>::display(){
    if(tail!=NULL){
        temp=tail->next;
        cout<<"Linked List: ";
        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp != tail->next);
    }else{
        cout<<"Linked list is Empty";
    }
}

template <class T>
bool C_Queue_LinkedList<T>::isEmpty(){
    return tail==NULL;
}

template <class T>
T C_Queue_LinkedList<T>::atFront(){
    if(isEmpty())
        return -1;
    return tail->next->data;
}

template <class T>
int C_Queue_LinkedList<T>::size_q(){
    temp=tail->next;
    int size=0;
    do{
        size++;
        temp=temp->next;
    }while(temp != tail->next);
    
    return size;
}
void menu(){
    cout<<"\n\t\tCIRCULAR QUEUE OPERATIONS-Linked List";
    cout<<"\n1. Enqueue";
    cout<<"\n2. Dequeue";
    cout<<"\n3. Element at front";
    cout<<"\n4. Size";
    cout<<"\n5. Display";
    cout<<"\n6. Exit";
}

int main(){
    int size,d,t;
    C_Queue_LinkedList<int> *queue=new C_Queue_LinkedList<int>();
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
            t=queue->atFront();
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
        default:
            cout<<"Incorrect Input!!\n";
        }
    }
}