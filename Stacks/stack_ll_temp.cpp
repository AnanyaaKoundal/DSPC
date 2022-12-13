#include <iostream>
using namespace std;

template <class T>
class node{
    public:
        T data;
        node *next;
};

template <class T>
class Stack{
    node<T> *first, *last, *temp, *temp1;
    int size, top=-1;
    public:
    Stack(int s){
            first=last=temp=temp1=NULL;
            size=s;
    }
    ~Stack(){
        temp=first;
        while(temp!=NULL){
            temp1=temp->next;
            delete temp;
            temp=temp1;
        }
        first=last=NULL;
    }
    void push(T el);
    T pop();
    bool isEmpty();
    T atTop();
    void display();
};

template <class T>
void Stack<T>::push(T el){
    if(top==size-1){
        cout<<"Stack Overflow!!";
        return;
    }
    else{
        temp=new node<T>;
        temp->data=el;
        temp->next=NULL;
        if(first == NULL){
            first=last=temp;
        }else{
            last->next=temp;
            last=temp;
        }
        top++;
    }
}

template <class T>
T Stack<T>::pop(){
    T data;
    if(isEmpty()){
        return -1;
    }else if(first == last){
        data=first->data;
        delete first;
        last=NULL;
    }else{
        temp=first;
        while(temp->next->next != NULL){
            temp=temp->next;
        }
        last=temp;
        data=temp->next->data;
        delete temp->next;
        temp->next=NULL;
    }
    top--;
    return data;
}

template <class T>
bool Stack<T>::isEmpty(){
    return top==-1;
}

template <class T>
T Stack<T>::atTop(){
    if(isEmpty()){
        return -1;
    }
    return last->data;
}

template <class T>
void Stack<T>::display(){
    if(isEmpty()){
        cout<<"Stack Empty..";
    }else{
        temp=first;
        cout<<"Stack: \n";
        while(temp->next != NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<temp->data<<" <- top";
    }
}

void menu(){
    cout<<"\n\t\tSTACK OPERATIONS";
    cout<<"\n1. Push";
    cout<<"\n2. Pop";
    cout<<"\n3. Element at top";
    cout<<"\n4. Display";
    cout<<"\n5. Exit";
}

int main(){
    int size,d,t;
    cout<<"Enter the size of the stack: ";
    cin>>size;
    Stack<int> *stk=new Stack<int>(size);
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
            stk->push(ele);
            break;
        case 2:
            d=stk->pop();
            if(d!=-1){
                cout<<"Deleted element: "<<d;
            }else{
                cout<<"Stack Underflow!!";
            }
            break;
        case 3:
            t=stk->atTop();
            if(t!=-1){
                cout<<"Element at the top is: "<<stk->atTop();
            }else{
                cout<<"Stack Underflow!!";
            }
            break;
        case 4:
            stk->display();
            break;
        case 5:
            return 0;
        }
    }
}