#include <iostream>
using namespace std;

template <class T>
class node{
    public:
        T data;
        node *prev;
        node *next;
};

template <class T>
class sll{
    public:
        node<T> *first, *tail, *temp, *temp1, *tail;
        sll(){
            tail=first=tail=temp1=temp=NULL;
        }
        ~sll(){
            if(tail==NULL){
                return;
            }
            temp=tail->next;
            while(temp!=tail){
                temp1=temp;
                temp=temp->next;
                delete temp1;
            }
            delete temp;
            tail=NULL;
        }
        void add_to_first();
        void add_to_tail();
        void add_in_btw();
        void delele_first();
        void delete_tail();
        void del_in_btw();
        void reverse();
        node<T> *search(int);
        void display();
        void operator +(const sll *l2){
            temp=tail->next;
            tail->next=l2->tail->next;
            l2->tail->next->prev=tail;
            l2->tail->next=temp;
            temp->prev=l2->tail;
            tail=l2->tail;
        }
        int count();
};

template <class T>
void sll<T>::add_to_first(){
    temp=new node<T>;
    cout<<"Enter the data: ";
    T d;
    cin>>d;
    temp->data=d;
    temp->prev=NULL;
    temp->next=NULL;
    if(first==NULL){
        tail=temp;
        tail->next=NULL;
        tail->prev=NULL;
    }else{
        temp->next=tail->next;
        tail->next->prev=temp;
        tail->next=temp;
        temp->prev=tail;
    }
}
template <class T>
void sll<T>::add_to_tail(){
    temp=new node<T>;
    cout<<"Enter the data: ";
    T d;
    cin>>d;
    temp->data=d;
    temp->next=NULL;
    temp->prev=NULL;
    if(first==NULL){
        tail=temp;
        tail->next=NULL;
        tail->prev=NULL;
    }else{
        temp->next=tail->next;
        tail->next->prev=temp;
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
}
template <class T>
void sll<T>::add_in_btw(){
    temp=new node<T>;
    cout<<"Enter the data: ";
    T d;
    cin>>d;
    temp->data=d;
    temp->next=NULL;
    int key, c=2;
    cout<<"Enter the position of insertion: ";
    cin>>key;
    temp1=first;
    node<T> *temp2=temp1->next;
    if(first==NULL){
        tail=temp;
        tail->next=NULL;
        tail->prev=NULL;
    }else if(key==1){
        temp->next=tail->next;
        tail->next->prev=temp;
        tail->next=temp;
        temp->prev=tail;
    }else{
        for(int i=1; temp1!=NULL && i<key-1 ; i++)
            temp1=temp1->next;
        if(temp1==NULL || temp1->next=NULL){
            cout<<"Invalid index!";
            return;
        }
        if(temp1==tail){
            temp->next=tail->next;
            tail->next->prev=temp;
            tail->next=temp;
            temp->prev=tail;
        }
        temp->next=temp1->next;
        temp1->next->prev=temp;
        temp1->next=temp;
        temp->prev=temp1;
    }
}
template <class T>
void sll<T>::delele_first(){
    if(tail==NULL){
        cout<<"Error";
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
void sll<T>:: delete_tail(){
    if(tail==NULL){
        cout<<"Error";
    }else if(count()==1){
        delete first;
        tail=NULL;
    }else{
        temp=tail;
        temp->next->prev=tail->prev;
        temp->prev->next=tail->next;
        tail=temp->prev;
        delete temp;
    }    
}

template <class T>
void sll<T>::del_in_btw(){
    if(first==NULL){
        cout<<"Error";
    }else if(first==tail){
        delete first;
        first=tail=NULL;
    }else{
        int key, c=2;
        cout<<"Enter the position of insertion: ";
        cin>>key;
        temp1=first;
        if(first==NULL){
            first=tail=temp;
        }else if(key==1){
            temp=first;
            first=temp->next;
            delete temp;
            first->prev=NULL;
        }else{
            for(int i=1; temp1!=NULL && i<key-1 ; i++)
            temp1=temp1->next;
            if(temp1==NULL){
                cout<<"Invalid index!";
                return;
            }
            if(temp1==tail){
                temp=tail;
                tail=temp->prev;
                delete temp;
                tail->next=NULL;
                return;
            }
            temp=temp1->next->next;
            temp->prev=temp1;
            delete temp1->next;
            temp1->next=temp;
        }
    }
}

template <class T>
void sll<T>::reverse(){
    int c=0;
    node<T> *behind= tail;
    node<T> *position= first;
    do{
        position->prev=position->next;
        position->next=behind;
        behind=position;
        if(c==0){
            tail=position;
            c++;
        }
        position=position->prev;
    }while(position!=tail);
    display();
}

template <class T>
node<T>* sll<T>::search(int n){
    temp=tail->next;
    do{
        if(temp->data==n)
            return temp;
        temp=temp->next;
    }while(temp!=tail->next);
    return NULL;
}

template <class T>
void sll<T>:: display(){
    if(tail==NULL){
        cout<<"Empty";
        return;
    }
    temp=tail->next;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=tail->next);
}

template <class T>
int sll<T>::count(){
    node<T> *t=tail->next;
    int count=0;
    do{
        count++;
        t=t->next;
    }while(temp!=tail->next);
    return count;
}

void menu(){
    cout<<"\n\tLinked List Operations";
    cout<<"\n1. Add";
    cout<<"\n2. Delete";
    cout<<"\n3. Display";
    cout<<"\n4. Reverse";
    cout<<"\n5. Size";
    cout<<"\n6. Concatenate";
    cout<<"\n7. Search";
    cout<<"\n8. Destructor";
    cout<<"\n9. Exit";
}

void add_menu(){
    cout<<"\t\n1. Add to first";
    cout<<"\t\n2. Add to tail";
    cout<<"\t\n3. Add in between";
}

void del_menu(){
    cout<<"\t\n1. Delete from first";
    cout<<"\t\n2. Delete from tail";
    cout<<"\t\n3. Delete in between";
}

int main(){
    sll<int> *sl=new sll<int>();
    int ch, ch2;
    do{
        menu();
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch){
            case 1:
                add_menu();
                cout<<"Enter your choice: ";
                cin>>ch2;
                if(ch2==1){
                    sl->add_to_first();
                }else if(ch2==2){
                    sl->add_to_tail();
                }else if(ch2==3){
                    sl->add_in_btw();
                }
                break;
            case 2:
                del_menu();
                cout<<"Enter your choice: ";
                cin>>ch2;
                if(ch2==1){
                    sl->delele_first();
                }else if(ch2==2){
                    sl->delete_tail();
                }else if(ch2==3){
                    sl->del_in_btw();
                }
                break;
            case 3:
                sl->display();
                break;
            case 4:
                sl->reverse();
                break;
            case 5:
                cout<<"Size of linked list: "<<sl->count();
                break;
            case 6:
                {
                    sll<int> *l2=new sll<int>();
                    cout<<"Enter the number of elements of new list: ";
                    cin>>ch2;
                    for(int i=0; i<ch2; i++)
                        l2->add_to_tail();
                    *sl+l2;
                    cout<<"Conacatenation Successful!!";
                    break;
                }
            case 7:{
                cout<<"Enter the element to be searched: ";
                cin>>ch2;
                node<int> *n=sl->search(ch2);
                if(n==NULL){
                    cout<<"Element not found";
                }else{
                    cout<<"Element found at "<<n;
                }
                break;
            }
            case 8:
                sl->~sll();
                break;
            case 9:
                return 0;
            default:
                cout<<"Invalid input";

        }
    }while(true);
}