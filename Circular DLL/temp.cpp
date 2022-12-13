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
class Circular_DoublyLL{
    node<T>  *tail;
    node<T> *temp;
    node<T> *temp1;
    public:
        Circular_DoublyLL(){
            tail=temp=temp1=NULL;
        }
        ~Circular_DoublyLL(){
            if(tail==NULL)
                return;
            temp, temp1=tail->next;
            while(temp!=tail){
                temp1=temp;
                temp=temp1->next;
                delete temp1;
            }
            delete temp;
            tail=NULL;
            cout<<"Destructor called successfully";
        }
        void add_to_tail();
        void add_to_head();
        void add_in_bet();
        void del_tail();
        void del_head();
        void del_in_bet();
        void display();
        void reverse();
        node<T> *search();
        int count();
        void operator +(const Circular_DoublyLL *l2){
            temp=tail->next;
            tail->next=l2->tail->next;
            l2->tail->next->prev=tail;
            l2->tail->next=temp;
            temp->prev=l2->tail;
            tail=l2->tail;   
        }
};

template <class T>
void Circular_DoublyLL<T>::add_to_head(){
    temp=new node<T>;
    cout<<"Enter the data: ";
    T d;
    cin>>d;
    temp->data=d;
    temp->next=NULL;
    temp->prev=NULL;
    if(tail==NULL){
        tail=temp;
        tail->next=tail;
        tail->prev=tail;
    }else{
        temp->next=tail->next;
        temp->prev=tail;
        tail->next=temp;
        
    }
}

template <class T>
void Circular_DoublyLL<T>::add_to_tail(){
    temp=new node<T>;
    cout<<"Enter the data: ";
    int d;
    cin>>d;
    temp->data=d;
    temp->next=NULL;
    temp->prev=NULL;
    if(tail==NULL){
        tail=temp;
        tail->next=tail->prev=tail;
    }else{
        tail->next->prev=temp;
        temp->next=tail->next;
        temp->prev=tail;
        tail->next=temp;
        tail=temp;
    }
}

template <class T>
void Circular_DoublyLL<T>::add_in_bet(){
    node<T> *t=new node<T>;
    cout<<"Enter the data: ";
    T d;
    cin>>d;
    t->data=d;
    t->next=NULL;
    int pos=0, i=0;
    cout<<"Enter the element after which insertion to take place: ";
    int key;
    cin>>key;
    if(tail == NULL){
        cout<<"Linked List is empty";
        return;
    }
    temp=tail->next;
    do{
        ++i;
        if(temp->data==key)
            pos=i;
        temp=temp->next;
    }while(temp != tail->next);
    if(pos==0){
        cout<<"Element not found.";
        return;
    }
    pos++;
    if(pos==1){
        temp->next=tail->next;
        temp->prev=tail;
        tail->next=temp;
        return;
    }
    int s=count();
    if(pos > s+1 || pos<1){
        cout<<"Position is invalid";
        return;
    }
    if(pos== s+1){
        tail->next->prev=temp;
        temp->next=tail->next;
        temp->prev=tail;
        tail->next=temp;
        tail=temp;
        return;
    }
    temp1=tail->next;
    for(int i=1; temp1->next!=tail && i<pos-1; i++){
        temp1=temp1->next;
    }
    t->next=temp1->next;
    t->prev=temp1;
    temp1->next->prev=t;
    temp1->next=t;
}

template <class T>
void Circular_DoublyLL<T>::del_head(){
    if(tail==NULL){
        cout<<"Error, Linked list empty"<<endl;
    }else if(count()==1){
        delete tail;
        tail=NULL;
    }else{
        temp=tail->next;
        temp->next->prev=tail;
        tail->next=temp->next;
        delete temp;
    }
}

template <class T>
void Circular_DoublyLL<T>::del_tail(){
    if(tail==NULL){
        cout<<"Error, Linked list empty"<<endl;
    }else if(count()==1){
        delete tail;
        tail=NULL;
    }else{
        temp=tail;
        temp->prev->next=tail->next;
        tail=temp->prev;
        delete temp;
    }
}

template <class T>
void Circular_DoublyLL<T>::del_in_bet(){
    if(tail==NULL){
        cout<<"Error, Linked list empty"<<endl;
    }else if(tail->next==tail){
        delete tail;
    }else{
        int key;
        cout<<"Enter the position of element to be deleted: ";
        cin>>key;
        temp1=tail->next;
        if(key==1){
            temp=tail->next;
            tail->next=temp->next;
            tail->next->prev=NULL;
            delete temp;
            return;
        }
        for(int i=1; temp1!=NULL && i<key-1; i++){
            temp1=temp1->next;
        }
        if(temp1==NULL || temp1->next==NULL){
            cout<<"Index not valid";
            return;
        }
        if(temp1->next==tail){
            temp=tail;
            tail=temp->prev;
            tail->next=NULL;
            delete temp;
            return;
        }
        temp=temp1->next->next;
        temp->prev=temp1;
        delete temp1->next;
        temp1->next=temp;
    }
}

template <class T>
void Circular_DoublyLL<T>::display(){
    if(tail!=NULL){
        temp=tail->next;
        cout<<"Linked List: ";
        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp != tail->next);
    }else{
        cout<<"Linked list is empty";
    }
}

template <class T>
void Circular_DoublyLL<T>::reverse(){
    int c=0;
    node<T> *t=tail;
    temp=tail->next;
    temp1=tail;
    do{
        temp->prev=temp->next;
        temp->next=temp1;
        temp1=temp;
        if(c==0){
            tail=temp1;
            c++;
        }
        temp=temp->prev;
    }while(temp!=tail);
    display();
}

template <class T>
node<T>* Circular_DoublyLL<T>::search(){
    int key;
    cout<<"Enter element to be searched: ";
    cin>>key;
    temp=tail->next;
    do{
        if(temp->data == key){
            return temp;
        }
        temp=temp->next;
    }while(temp!=tail->next);
    return NULL;
}

template <class T>
int Circular_DoublyLL<T>::count(){
    temp=tail->next;
    int count=0;
    do{
        count++;
        temp=temp->next;
    }while(temp!=tail->next);
    return count;
}
void menu(){
    cout<<"\n------------------------------------\n";
    cout<<"\n\tCircular Linked List Operations "<<endl;
    cout<<"1. Add"<<endl;
    cout<<"2. Delete"<<endl;
    cout<<"3. Display"<<endl;
    cout<<"4. Reverse"<<endl;
    cout<<"5. Search"<<endl;
    cout<<"6. Size of linked list"<<endl;
    cout<<"7. Concatenate"<<endl;
    cout<<"8. Destructor"<<endl;
    cout<<"9. Exit"<<endl;
    cout<<"------------------------------------\n";
}
void add_menu(){
    cout<<"\t1. Add to head"<<endl;
    cout<<"\t2. Add to tail"<<endl;
    cout<<"\t3. Add in between"<<endl;
}
void delete_menu(){
    cout<<"\t1. Delete to head"<<endl;
    cout<<"\t2. Delete to tail"<<endl;
    cout<<"\t3. Delete in between"<<endl;
}
int main(){
    Circular_DoublyLL<int> *dl= new Circular_DoublyLL<int>();
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
                    dl->add_to_head();
                }else if(ch2==2){
                    dl->add_to_tail();
                }else if(ch2==3){
                    dl->add_in_bet();
                }
                break;
            case 2:
                delete_menu();
                cout<<"Enter your choice: ";
                cin>>ch2;
                if(ch2==1){
                    dl->del_head();
                }else if(ch2==2){
                    dl->del_tail();
                }else if(ch2==3){
                    dl->del_in_bet();
                }
                break;
            case 3:
                dl->display();
                break;
            case 4:
                dl->reverse();
                break;
            case 5:
            {
                node<int>* n=dl->search();
                if(n==NULL){
                    cout<<"Element not found";
                }else{
                    cout<<"Element found at "<<n;
                }
                break;
            }
            case 6:
                cout<<"Size of linked list: "<<dl->count();
                break;
            case 7:
            {
                Circular_DoublyLL<int>* l2=new Circular_DoublyLL<int>();
                int s;
                cout<<"Enter the length of list to be appended: ";
                cin>>s;
                for(int i=0; i<s; i++)
                    l2->add_to_tail();
                *dl+l2;
                cout<<"Contatenation Successful";
                break;
            }
            case 8:
                dl->~Circular_DoublyLL();
                break;
            case 9:
                return 0;
        }
        menu();
        cout<<"Enter your choice: ";
        cin>>ch;
    }
}