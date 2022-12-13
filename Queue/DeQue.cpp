#include<iostream>
using namespace std;

template <class T>
class node{
        public:
            T data;
            node *next;
            node *prev;
};

template <class T>
class Deque{
    node<T> *first, *last, *temp, *temp1;
    public:
    int cn=0;
        Deque(){
            first=last=temp=temp1=NULL;
        }
        ~Deque(){
            temp=first;
            while(temp!=NULL){
                temp1=temp->next;
                delete temp;
                temp=temp1;
            }
            first=last=NULL;
        }
        void enqueue_end();
        void enqueue_head();
        void deque_end();
        void deque_head();
        bool isEmpty();
        T at_front();
        T at_end();
        T size();
        void display();
};

template <class T>
void Deque<T>::enqueue_head(){
    temp=new node<T>;
    cout<<"Enter the data: ";
    T d;
    cin>>d;
    temp->data=d;
    temp->next=NULL;
    temp->prev=NULL;
    if(first == NULL){
        first=last=temp;
    }else{
        temp->next=first;
        first->prev=temp;
        first=temp;
    }
    cn++;
}

template <class T>
void Deque<T>::enqueue_end(){
    temp=new node<T>;
    cout<<"Enter the data: ";
    int d;
    cin>>d;
    temp->data=d;
    temp->next=NULL;
    temp->prev=NULL;
    if(first == NULL){
        first=last=temp;
    }else{
        last->next=temp;
        temp->prev=last;
        last=temp;
    }
    cn++;
}

template <class T>
void Deque<T>::deque_head(){
    if(first==NULL){
        cout<<"Error, Linked list empty"<<endl;
    }else if(first == last){
        delete first;
        last=NULL;
        cn--;
    }else{
        temp=first;
        first=temp->next;
        first->prev=NULL;
        delete temp;
        cn--;
    }
}

template <class T>
void Deque<T>::deque_end(){
    if(first==NULL){
        cout<<"Error, Linked list empty"<<endl;
    }else if(first == last){
        delete first;
        last=NULL;
        cn--;
    }else{
        temp=last;
        last=temp->prev;
        last->next=NULL;
        delete temp;
        cn--;
    }
}

template <class T>
bool Deque<T>::isEmpty(){
    return first==NULL;
}

template <class T>
T Deque<T>::at_front(){
    if(isEmpty()){
        return -1;
    }
    return first->data;
}

template <class T>
T Deque<T>::at_end(){
    if(isEmpty()){
        return -1;
    }
    return last->data;
}

template <class T>
void Deque<T>::display(){
   temp=first;
    cout<<"Deque: ";
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    } 
}

template <class T>
T Deque<T>::size(){
    temp=first;
    int count=0;
    while(temp != NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

void menu(){
    cout<<"\n\tDeque Operations ";
    cout<<"\n1. Add";
    cout<<"\n2. Delete";
    cout<<"\n3. Element at front";
    cout<<"\n4. Element at end";
    cout<<"\n5. Size";
    cout<<"\n6. Display";
    cout<<"\n7. Exit\n";
}

void add_menu(){
    cout<<"\t1. Add to front"<<endl;
    cout<<"\t2. Add to back"<<endl;
}

void delete_menu(){
    cout<<"\t1. Delete to front"<<endl;
    cout<<"\t2. Delete to back"<<endl;
}

int main(){
    Deque<int> *dl= new Deque<int>();
    int ch=0, ch2;
    menu();
    cout<<"Enter your choice: ";
    cin>>ch;
    while(true){
        switch(ch){
        case 1:
                add_menu();
                cout<<"Enter your choice: ";
                cin>>ch2;
                if(ch2==1){
                    dl->enqueue_head();
                }else if(ch2==2){
                    dl->enqueue_end();
                }
                break;
            case 2:
                delete_menu();
                cout<<"Enter your choice: ";
                cin>>ch2;
                if(ch2==1){
                    dl->deque_head();
                }else if(ch2==2){
                    dl->deque_end();
                }
                break;
            case 3:
                cout<<"Element at front: "<<dl->at_front();
                break;
            case 4:
                cout<<"Element at end: "<<dl->at_end();
                break;
            case 5:
                cout<<"Size: "<<dl->size();
                break;
            case 6:
                dl->display();
                break;
            
            case 7:
                return 0;
        }
        menu();
        cout<<"Enter your choice: ";
        cin>>ch;
    }
}
