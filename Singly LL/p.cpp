#include <iostream>
using namespace std;

template <class T>
class node{
    public:
        T data;
        node *next;
};

template <class T>
class sll{
    public:
        node<T> *first, *last, *temp, *temp1;
        sll(){
            first=last=temp1=temp=NULL;
        }
        ~sll(){
            temp=first;
            while(temp!=NULL){
                temp1=temp->next;
                delete temp;
                temp=temp1;
            }
            first=last=NULL;
            cout<<"Destructor called!!";
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
            last->next= l2->first;
            last= l2->last;
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
    temp->next=NULL;
    if(first==NULL){
        first=last=temp;
    }else{
        temp->next=first;
        first=temp;
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
    if(first==NULL){
        first=last=temp;
    }else{
        last->next=temp;
        last=temp;
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
    if(key<-1 || key>count()+1){
        cout<<"Invalid index!";
    }
    else if(first==NULL){
        first=last=temp;
    }else if(key==1){
        temp->next=first;
        first=temp;
    }else if(key==count()+1){
        last->next=temp;
        last=temp;
    }else{
        while(c!=key){
            temp1=temp1->next;
            temp2=temp2->next;
            c++;
        }
        temp->next=temp2;
        temp1->next=temp;
    }
}
template <class T>
void sll<T>::delele_first(){
    if(first==NULL){
        cout<<"Error";
    }else if(first==last){
        delete first;
        first=last=NULL;
    }else{
        temp=first;
        first=temp->next;
        delete temp;
    }
}

template <class T>
void sll<T>:: delete_tail(){
    if(first==NULL){
        cout<<"Error";
    }else if(first==last){
        delete first;
        first=last=NULL;
    }else{
        temp=first;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        last=temp;
        delete last->next;
        last->next=NULL;
    }    
}

template <class T>
void sll<T>::del_in_btw(){
    if(first==NULL){
        cout<<"Error";
    }else if(first==last){
        delete first;
        first=last=NULL;
    }else{
        int key, c=2;
        cout<<"Enter the position of insertion: ";
        cin>>key;
        temp1=first;
        node<T> *temp2=temp1->next;
        if(key<-1 || key>count()+1){
            cout<<"Invalid index!";
        }
        else if(first==NULL){
            first=last=temp;
        }else if(key==1){
            temp=first;
            first=temp->next;
            delete temp;
        }else if(key==count()+1){
            temp=first;
            while(temp->next->next!=NULL){
                temp=temp->next;
            }
            last=temp;
            delete last->next;
            last->next=NULL;
        }else{
            while(c!=key){
                temp1=temp1->next;
                temp2=temp2->next;
                c++;
            }
            temp1->next=temp2->next;
            delete temp2;
        }
    }
}

template <class T>
void sll<T>::reverse(){
    node<T> *behind= NULL;
    node<T> *position= first;
    node<T> *ahead;
    int c=0;
    while(position!=NULL){
        ahead=position->next;
        position->next=behind;
        behind=position;
        if(c==0){last=position; c++;}
        position=ahead;
    }
    first=behind;
    display();
}

template <class T>
node<T>* sll<T>::search(int n){
    temp=first;
    while(temp!=NULL){
        if(temp->data==n)
            return temp;
        temp=temp->next;
    }
    return NULL;
}

template <class T>
void sll<T>:: display(){
    temp=first;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

template <class T>
int sll<T>::count(){
    node<T> *t=first;
    int count=0;
    while(t!=NULL){
        count++;
        t=t->next;
    }
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