#include<iostream>
using namespace std;
template <class T>

class node{
    public:
    T data;
    node *next;
};

template <class T>
class SinglyLL{
    node<T> *first, *last;
    node<T> *temp;
    node<T> *temp1;
    public:
        int cn=0;
        SinglyLL(){
            first=last=temp=temp1=NULL;
        }
        ~SinglyLL(){
            temp=first;
            while(temp!=NULL){
                temp1=temp->next;
                delete temp;
                temp=temp1;
            }
            first=last=NULL;
            cout<<"Destructor Called Successfully";
        }
        void add_to_tail();
        void add_to_head();
        void add_in_bet();
        void del_tail();
        void del_head();
        void del_in_bet();
        void display();
        void reverse();
        //void search1();
        node<T> *search();
        int count();
        void operator +(const SinglyLL *l2){
            last->next=l2->first;
            last=l2->last;   
        }
};

template <class T>
void SinglyLL<T>::add_to_head(){
    temp=new node<T>;
    cout<<"Enter the data: ";
    T d;
    cin>>d;
    temp->data=d;
    temp->next=NULL;
    if(first == NULL){
        first=last=temp;
    }else{
        temp->next=first;
        first=temp;
    }
    cn++;
}

template <class T>
void SinglyLL<T>::add_to_tail(){
    temp=new node<T>;
    cout<<"Enter the data: ";
    T d;
    cin>>d;
    temp->data=d;
    temp->next=NULL;
    if(first == NULL){
        first=last=temp;
    }else{
        last->next=temp;
        last=temp;
    }
    cn++;
}

template <class T>
void SinglyLL<T>::add_in_bet(){
    temp=new node<T>;
    node<T> *temp2=new node<T>;
    cout<<"Enter the data: ";
    T d;
    cin>>d;
    temp->data=d;
    temp->next=NULL;
    cout<<"Enter the position of element: ";
    int key;
    cin>>key;
    temp2=first;
    temp1=temp2->next;
    int c=2;
    if(key<0){
        cout<<"Invalid input\n";
        return;
    }
    else if(first == NULL){
        first=last=temp;
        cout<<first->data;
    }else if(key==1){
        temp->next=first;
        first=temp;
    }else if(key==count()+1){
        last->next=temp;
        last=temp;
    }
    else{
        while(c!=key){
            temp2=temp2->next;
            temp1=temp1->next;
            c++;
        }
        temp2->next=temp;
        temp->next=temp1;
    }
    cn++;
}
template <class T>

void SinglyLL<T>::del_head(){
    if(first==NULL){
        cout<<"Error, Linked list empty"<<endl;
    }else if(first == last){
        delete first;
        first=last=NULL;
        cn--;
    }else{
        temp=first;
        first=temp->next;
        delete temp;
        cn--;
    }
}
template <class T>
void SinglyLL<T>::del_tail(){
    if(first==NULL){
        cout<<"Error, Linked list empty"<<endl;
    }else if(first == last){
        delete first;
        first=last=NULL;
        cn--;
    }else{
        temp=first;
        while(temp->next->next != NULL){
            temp=temp->next;
        }
        last=temp;
        delete temp->next;
        temp->next=NULL;
        cn--;
    }
}

template <class T>
void SinglyLL<T>::del_in_bet(){
    if(first==NULL){
        cout<<"Error, Linked list empty"<<endl;
    }else if(first == last){
        delete first;
        last=NULL;
        cn--;
    }else{
        int key;
        cout<<"Enter the position of element to be deleted: ";
        cin>>key;
        temp1=first;
        temp=temp1->next;
        int c=1;
        if(key==1){
            temp=first;
            first=temp->next;
            delete temp;
        }else if(key >= cn){
            temp=first;
            while(temp->next->next != NULL){
                temp=temp->next;
            }
            last=temp;
            delete temp->next;
            temp->next=NULL;
        }else{
            while(c!= key-1){
                temp=temp->next;
                temp1=temp1->next;
                c++;
            }
            temp1->next=temp->next;
            /*if(temp1->next==last){
                last=temp1;
            }*/
            delete temp;
            
        }
        cn--;
    }
}

template <class T>
void SinglyLL<T>::display(){
    temp=first;
    cout<<"Linked List: ";
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

template <class T>
void SinglyLL<T>::reverse(){
    node<T> *behind=NULL;
    node<T> *position=first;
    node<T> *ahead;
    int c=0;
    while(position != NULL){
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
node<T>* SinglyLL<T>::search(){
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
int SinglyLL<T>::count(){
    node<T> *t=first;
    int count=0;
    while(t != NULL){
        count++;
        t=t->next;
    }
    return count;
}

void menu(){
    cout<<"\n--------------------------\n";
    cout<<"\tLinked List Operations "<<endl;
    cout<<"1. Add"<<endl;
    cout<<"2. Delete"<<endl;
    cout<<"3. Display"<<endl;
    cout<<"4. Reverse"<<endl;
    cout<<"5. Search"<<endl;
    cout<<"6. Size of linked list"<<endl;
    cout<<"7. Concatenate"<<endl;
    cout<<"8. Destructor"<<endl;
    cout<<"9. Exit"<<endl;
    cout<<"--------------------------\n";
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
    cout<<"\n1. int\n";
    cout<<"2. float\n";
    cout<<"3. char\n";
    cout<<"Enter the type of your data: ";
    int t;
    cin>>t;
    switch (t)
    {
    case 1:{
        SinglyLL<int> *sl= new SinglyLL<int>();
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
                        sl->add_to_head();
                    }else if(ch2==2){
                        sl->add_to_tail();
                    }else if(ch2==3){
                        sl->add_in_bet();
                    }
                    break;
                case 2:
                    delete_menu();
                    cout<<"Enter your choice: ";
                    cin>>ch2;
                    if(ch2==1){
                        sl->del_head();
                    }else if(ch2==2){
                        sl->del_tail();
                    }else if(ch2==3){
                        sl->del_in_bet();
                    }
                    break;
                case 3:
                    sl->display();
                    break;
                case 4:
                    sl->reverse();
                    break;
                case 5:
                {
                    node<int>* n=sl->search();
                    if(n==NULL){
                        cout<<"Element not found";
                    }else{
                        cout<<"Element found at "<<n;
                    }
                    break;
                }
                case 6:
                    cout<<"Size of linked list: "<<sl->count();
                    break;
                case 7:
                {
                    SinglyLL<int> *l2= new SinglyLL<int>();
                    int s;
                    cout<<"Enter the length of list to be appended: ";
                    cin>>s;
                    for(int i=0; i<s; i++)
                        l2->add_to_tail();
                    *sl+l2;
                    sl->cn+=l2->cn;
                    cout<<"Contatenation Successful";
                    break;
                }
                case 8:
                    sl->~SinglyLL();
                    break;
                case 9:
                    return 0;
                default:
                    cout<<"\nIncorrect input.\n";
            }
            menu();
            cout<<"Enter your choice: ";
            cin>>ch;
        }
        break;
    }
    case 2:
    {
        SinglyLL<double> *sl= new SinglyLL<double>();
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
                        sl->add_to_head();
                    }else if(ch2==2){
                        sl->add_to_tail();
                    }else if(ch2==3){
                        sl->add_in_bet();
                    }
                    break;
                case 2:
                    delete_menu();
                    cout<<"Enter your choice: ";
                    cin>>ch2;
                    if(ch2==1){
                        sl->del_head();
                    }else if(ch2==2){
                        sl->del_tail();
                    }else if(ch2==3){
                        sl->del_in_bet();
                    }
                    break;
                case 3:
                    sl->display();
                    break;
                case 4:
                    sl->reverse();
                    break;
                case 5:
                    {
                    node<double>* n=sl->search();
                    if(n==NULL){
                        cout<<"Element not found";
                    }else{
                        cout<<"Element found at "<<n;
                    }
                    break;
                }
                case 6:
                    cout<<"Size of linked list: "<<sl->count();
                    break;
                case 7:
                {
                    SinglyLL<double> *l2= new SinglyLL<double>();
                    int s;
                    cout<<"Enter the length of list to be appended: ";
                    cin>>s;
                    for(int i=0; i<s; i++)
                        l2->add_to_tail();
                    *sl+l2;
                    sl->cn+=l2->cn;
                    cout<<"Contatenation Successful";
                    break;
                }
                case 8:
                    sl->~SinglyLL();
                    break;
                case 9:
                    return 0;
                default:
                    cout<<"\nIncorrect input.\n";
            }
            menu();
            cout<<"Enter your choice: ";
            cin>>ch;
        }
        break;
    }
    case 3:
    {
        SinglyLL<char> *sl= new SinglyLL<char>();
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
                        sl->add_to_head();
                    }else if(ch2==2){
                        sl->add_to_tail();
                    }else if(ch2==3){
                        sl->add_in_bet();
                    }
                    break;
                case 2:
                    delete_menu();
                    cout<<"Enter your choice: ";
                    cin>>ch2;
                    if(ch2==1){
                        sl->del_head();
                    }else if(ch2==2){
                        sl->del_tail();
                    }else if(ch2==3){
                        sl->del_in_bet();
                    }
                    break;
                case 3:
                    sl->display();
                    break;
                case 4:
                    sl->reverse();
                    break;
                case 5:
                    {
                    node<char>* n=sl->search();
                    if(n==NULL){
                        cout<<"Element not found";
                    }else{
                        cout<<"Element found at "<<n;
                    }
                    break;
                }
                case 6:
                    cout<<"Size of linked list: "<<sl->count();
                    break;
                case 7:
                {
                    SinglyLL<char> *l2= new SinglyLL<char>();
                    int s;
                    cout<<"Enter the length of list to be appended: ";
                    cin>>s;
                    for(int i=0; i<s; i++)
                        l2->add_to_tail();
                    *sl+l2;
                    sl->cn+=l2->cn;
                    cout<<"Contatenation Successful";
                    break;
                }
                case 8:
                    sl->~SinglyLL();
                    break;
                case 9:
                    return 0;
                default:
                    cout<<"\nIncorrect input.\n";
            }
            menu();
            cout<<"Enter your choice: ";
            cin>>ch;
        }
        break;
    }
    default:
        cout<<"Invalid input";
        return 1;
    }
   } 
