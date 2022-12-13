#include<iostream>
using namespace std;

class Circular_DoublyLL{
    class node{
        public:
            int data;
            node *next;
            node *prev;
    };
    node  *tail;
    node *temp;
    node *temp1;
    public:
        int cn=0;
        Circular_DoublyLL(){
            tail=temp=temp1=NULL;
        }
        ~Circular_DoublyLL(){
            temp=tail->next;
            do{
                temp1=temp->next;
                delete temp;
                temp=temp1;
            }while(temp!=tail->next);
            tail=NULL;
        }
        void add_to_tail();
        void add_to_head();
        void add_in_bet();
        void del_tail();
        void del_head();
        void del_in_bet();
        void display();
        void reverse();
        void search();
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
void Circular_DoublyLL::add_to_head(){
    temp=new node;
    cout<<"Enter the data: ";
    int d;
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
    cn++;
}
void Circular_DoublyLL::add_to_tail(){
    temp=new node;
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
    cn++;
}
// void Circular_DoublyLL::add_in_bet(){
//     temp=new node;
//     cout<<"Enter the data: ";
//     int d;
//     cin>>d;
//     temp->data=d;
//     temp->next=NULL;
//     cout<<"Enter the element after which you want insertion to take place: ";
//     int key;
//     cin>>key;
//     temp1=tail->next;
//     if(tail==NULL){
//         tail=temp;
//         tail->next=tail;
//         tail->prev=tail;
//     }else{
//         while(temp1->data != key){
//             temp1=temp1->next;
//         }
//         temp->next=temp1->next;
//         temp->prev=temp1;
//         temp1->next=temp;
//     }
// }
void Circular_DoublyLL::add_in_bet(){
    temp=new node;
    cout<<"Enter the data: ";
    int d;
    cin>>d;
    temp->data=d;
    temp->next=NULL;
    cout<<"Enter the element after which you want insertion to take place: ";
    int key;
    cin>>key;
    temp1=tail->next;
    int c=2;
    if(key<0){
        cout<<"Invalid input\n";
        return;
    }
    else if(tail == NULL){
        tail=temp;
        tail->next=tail->prev=tail;
    }else if(key==1){
        temp->next=tail->next;
        temp->prev=tail;
        tail->next=temp;
    }else if(key>cn){
        tail->next->prev=temp;
        temp->next=tail->next;
        temp->prev=tail;
        tail->next=temp;
        tail=temp;
    }
    else{
        while(c!=key){
            temp1=temp1->next;
            c++;
        }
        
        temp->next=temp1->next;
        temp->prev=temp1;
        temp1->next=temp;
    }
    cn++;
}
void Circular_DoublyLL::del_head(){
    if(tail==NULL){
        cout<<"Error, Linked list empty"<<endl;
    }else if(count()==1){
        delete tail;
        tail=NULL;
        cn--;
    }else{
        temp=tail->next;
        temp->next->prev=tail;
        tail->next=temp->next;
        delete temp;
        cn--;
    }
}
void Circular_DoublyLL::del_tail(){
    if(tail==NULL){
        cout<<"Error, Linked list empty"<<endl;
    }else if(count()==1){
        delete tail;
        tail=NULL;
        cn--;
    }else{
        temp=tail;
        temp->prev->next=tail->next;
        tail=temp->prev;
        delete temp;
        cn--;
    }
}

void Circular_DoublyLL::del_in_bet(){
    if(tail==NULL){
         cout<<"Error, Linked list empty"<<endl;
    }else if(count()==1){
         delete tail;
    }else{
        int key;
        cout<<"Enter the position of element to be deleted: ";
        cin>>key;
        temp=tail->next;
        int c=1;
        if(key==1){
            temp=tail->next;
            temp->next->prev=tail;
            tail->next=temp->next;
            delete temp;
        }else if(key>=cn){
            temp=tail;
            temp->prev->next=tail->next;
            tail=temp->prev;
            delete temp;
        }else{
            while(c!= key){
                temp=temp->next;
                c++;
            }
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            delete temp;
        }
        cn--;
    }
}
void Circular_DoublyLL::display(){
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
void Circular_DoublyLL::reverse(){
    int c=0;
    node *t=tail;
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
void Circular_DoublyLL::search(){
    int key;
    cout<<"Enter element to be searched: ";
    cin>>key;
    temp=tail->next;
    do{
        if(temp->data == key){
            cout<<"Element found"<<endl;
            return;
        }
        temp=temp->next;
    }while(temp!=tail->next);
    cout<<"Element not found"<<endl;
}
int Circular_DoublyLL::count(){
    temp=tail->next;
    int count=0;
    do{
        count++;
        temp=temp->next;
    }while(temp!=tail->next);
    return count;
}
void menu(){
    cout<<"\n\tLinked List Operations "<<endl;
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
    Circular_DoublyLL *dl= new Circular_DoublyLL();
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
                dl->search();
                break;
            case 6:
                cout<<"Size of linked list: "<<dl->count();
                break;
            case 7:
            {
                Circular_DoublyLL* l2=new Circular_DoublyLL();
                cout<<"Enter list to be appended\n";
                while(true){
                    cout<<"\t1. Add to head"<<endl;
                    cout<<"\t2. Add to tail"<<endl;
                    cout<<"\t3. Stop"<<endl;
                    cout<<"Enter your choice: ";
                    cin>>ch2;
                    if(ch2==1){
                        l2->add_to_head();
                    }else if(ch2==2){
                        l2->add_to_tail();
                    }else{
                        break;
                    }
                }
                *dl+l2;
                dl->cn+=l2->cn;
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