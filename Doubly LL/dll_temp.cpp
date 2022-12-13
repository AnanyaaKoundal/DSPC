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
class DoublyLL{
    node<T> *first, *last;
    node<T> *temp;
    node<T> *temp1;
    public:
        DoublyLL(){
            first=last=temp=temp1=NULL;
        }
        ~DoublyLL(){
            temp=first;
            while(temp!=NULL){
                temp1=temp->next;
                delete temp;
                temp=temp1;
            }
            first=last=NULL;
            cout<<"Desctructor called successfully";
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
        void operator +(const DoublyLL *l2){
            last->next=l2->first;
            temp=last->next;
            temp->prev=last;
            last=l2->last;   
        }
};

template <class T>
void DoublyLL<T>::add_to_head(){
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
}

template <class T>
void DoublyLL<T>::add_to_tail(){
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
        last->next=temp;
        temp->prev=last;
        last=temp;
    }
}

template <class T>
void DoublyLL<T>::add_in_bet(){
    temp=new node<T>;
    cout<<"Enter the data: ";
    T d;
    cin>>d;
    temp->data=d;
    temp->next=NULL;
    cout<<"Enter the position of insertion: ";
    int key;
    cin>>key;
    temp1=first;
    if(first == NULL){
        first=last=temp;
        return;
    }else if(key==1){
        temp->next=first;
        first->prev=temp;
        first=temp;
        return;
    }
    for(int i=1; temp1!=NULL && i<key-1; i++){
        temp1=temp1->next;
    }
    if(temp1==NULL){
        cout<<"Index not valid";
        return;
    }
    if(temp1==last){
        last->next=temp;
        temp->prev=last;
        last=temp;
        return;
    }
    temp->next=temp1->next;
    temp->prev=temp1;
    temp1->next->prev=temp;
    temp1->next=temp;
}

template <class T>
void DoublyLL<T>::del_head(){
    if(first==NULL){
        cout<<"Error, Linked list empty"<<endl;
    }else if(first == last){
        delete first;
        last=NULL;
    }else{
        temp=first;
        first=temp->next;
        first->prev=NULL;
        delete temp;
    }
}

template <class T>
void DoublyLL<T>::del_tail(){
    if(first==NULL){
        cout<<"Error, Linked list empty"<<endl;
    }else if(first == last){
        delete first;
        last=NULL;
    }else{
        temp=last;
        last=temp->prev;
        last->next=NULL;
        delete temp;
    }
}

template <class T>
void DoublyLL<T>::del_in_bet(){
    if(first==NULL){
        cout<<"Error, Linked list empty"<<endl;
    }else if(first == last){
        delete first;
        last=NULL;
    }else{
        int key;
        cout<<"Enter the position of element to be deleted: ";
        cin>>key;
        temp1=first;
        if(key==1){
            temp=first;
            first=temp->next;
            first->prev=NULL;
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
        if(temp1->next==last){
            temp=last;
            last=temp->prev;
            last->next=NULL;
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
void DoublyLL<T>::display(){
    temp=first;
    cout<<"Linked List: ";
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

template <class T>
void DoublyLL<T>::reverse(){
    int c=0;
    temp=first;
    temp1=NULL;
    while(temp!=NULL){
        temp->prev=temp->next;
        temp->next=temp1;
        temp1=temp;
        if(c==0){
            last=temp1;
            c++;
        }
        temp=temp->prev;
    }
    first=temp1;
    display();
}

template <class T>
node<T>* DoublyLL<T>::search(){
    int key;
    cout<<"Enter element to be searched: ";
    cin>>key;
    temp=first;
    while(temp != NULL){
        if(temp->data == key){
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}

template <class T>
int DoublyLL<T>::count(){
    temp=first;
    int count=0;
    while(temp != NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

void menu(){
    cout<<"\n\tDoubly Linked List Operations "<<endl;
    cout<<"1. Add"<<endl;
    cout<<"2. Delete"<<endl;
    cout<<"3. Display"<<endl;
    cout<<"4. Reverse"<<endl;
    cout<<"5. Search"<<endl;
    cout<<"6. Size of linked list"<<endl;
    cout<<"7. Concatenate"<<endl;
    cout<<"8. Destructor"<<endl;
    cout<<"9. Exit"<<endl;
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
    DoublyLL<int> *dl= new DoublyLL<int>();
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
                cout<<"Size of linked list: "<<dl->count()<<endl;
                break;
            case 7:
            {
                DoublyLL<int>* l2=new DoublyLL<int>();
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
                dl->~DoublyLL();
                break;
            case 9:
                return 0;
        }
        menu();
        cout<<"Enter your choice: ";
        cin>>ch;
    }
}
