#include <iostream>
using namespace std;

class Stack{
    class node{
    public:
        int data;
        node *next;
    };
    node *first, *last, *temp, *temp1;
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
        temp=new node;
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
int Stack::pop(){
    int data;
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
bool Stack::isEmpty(){
    return top==-1;
}
int Stack::atTop(){
    if(isEmpty()){
        return -1;
    }
    return last->data;
}
void Stack::display(){
    if(isEmpty()){
        cout<<"Stack Empty..";
    }else{
        temp=first;
        cout<<"Stack: \n";
        while(temp != NULL){
            cout<<temp->data<<"\n";
            temp=temp->next;
        }
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