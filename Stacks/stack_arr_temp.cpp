#include <iostream>
using namespace std;

template <class T>
class Stack{
    T *stack;
    public:
    int size, top=-1;
    Stack(int s){
        size=s;
        stack=new T(size);
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
        stack[++top]=el;
    }
}

template <class T>
T Stack<T>::pop(){
    int data;
    if(isEmpty()){
        return -1;
    }
    data=stack[top--];
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
    return stack[top];
}

template <class T>
void Stack<T>::display(){
    cout<<"Stack: \n";
    for(int i=0; i<top; i++){
        cout<<stack[i]<<" ";
    }
    cout<<stack[top]<<" <- top";
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