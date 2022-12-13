#include <iostream>
using namespace std;

class Stack{
    int *stack;
    public:
    int size, top=-1;
    Stack(int s){
        size=s;
        stack=new int(size);
    }
    ~Stack(){
        
    }
    void push(int el);
    int pop();
    bool isEmpty();
    int atTop();
    void display();
};
void Stack::push(int el){
    if(top==size-1){
        cout<<"Stack Overflow!!";
        return;
    }
    else{
        stack[++top]=el;
    }
}
int Stack::pop(){
    int data;
    if(isEmpty()){
        return -1;
    }
    data=stack[top--];
    return data;
}
bool Stack::isEmpty(){
    return top==-1;
}
int Stack::atTop(){
    if(isEmpty()){
        return -1;
    }
    return stack[top];
}
void Stack::display(){
    cout<<"Stack: \n";
    for(int i=0; i<=top; i++){
        cout<<stack[i]<<"\n";
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
    Stack *stk=new Stack(size);
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