#include<iostream>
using namespace std;

class DoublyLL{
    class node{
        public:
            int data;
            node *next;
            node *prev;
    };
    node *first, *last;
    node *temp;
    node *temp1;
    public:
    int cn=0;
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
        void count();
        void operator +(const DoublyLL *l2){
            last->next=l2->first;
            temp=last->next;
            temp->prev=last;
            last=l2->last;   
        }
};
void DoublyLL::add_to_head(){
    temp=new node;
    cout<<"Enter the data: ";
    int d;
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
void DoublyLL::add_to_tail(){
    temp=new node;
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
// void DoublyLL::add_in_bet(){
//     temp=new node;
//     cout<<"Enter the data: ";
//     int d;
//     cin>>d;
//     temp->data=d;
//     temp->next=NULL;
//     cout<<"Enter the element after which you want insertion to take place: ";
//     int key;
//     cin>>key;
//     temp1=first;
//     if(first == NULL){
//         first=last=temp;
//     }else{
//         while(temp1->data != key){
//             temp1=temp1->next;
//         }
//         temp->next=temp1->next;
//         temp->prev=temp1;
//         temp1->next=temp;
//     }
//     cn++;
// }
void DoublyLL::add_in_bet(){
    temp=new node;
    cout<<"Enter the data: ";
    int d;
    cin>>d;
    temp->data=d;
    temp->next=NULL;
    cout<<"Enter the element after which you want insertion to take place: ";
    int key;
    cin>>key;
    temp1=first;
    int c=2;
    if(key<0){
        cout<<"Invalid input\n";
        return;
    }
    else if(first == NULL){
        first=last=temp;
    }else if(key==1){
        temp->next=first;
        first->prev=temp;
        first=temp;
    }else if(key>cn){
        last->next=temp;
        temp->prev=last;
        last=temp;
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
void DoublyLL::del_head(){
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
void DoublyLL::del_tail(){
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
// void DoublyLL::del_in_bet(){
//     if(first==NULL){
//         cout<<"Error, Linked list empty"<<endl;
//     }else if(first == last){
//         delete first;
//         last=NULL;
//     }else{
//         int key;
//         cout<<"Enter the element to be deleted: ";
//         cin>>key;
//         temp=first;
//         while(temp != NULL){
//             if(temp->data == key)
//                 break;
//             temp=temp->next;
//         }
//         temp->prev->next=temp->next;
//         temp->next->prev=temp->prev;
//         delete temp;
//     }
// }
void DoublyLL::del_in_bet(){
    if(first==NULL){
        cout<<"Error, Linked list empty"<<endl;
    }else if(first == last){
        delete first;
        last=NULL;
    }else{
        int key;
        cout<<"Enter the position of element to be deleted: ";
        cin>>key;
        temp=first->next;
        int c=2;
        if(key==1){
            temp=first;
            first=temp->next;
            first->prev=NULL;
            delete temp;
        }else if(key>=cn){
            temp1=last;
            last=temp1->prev;
            last->next=NULL;
            delete temp1;
        }else{
            while(c!= key){
                temp=temp->next;
                c++;
            }
            cout<<temp->data;
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            delete temp;
        }
        cn--;
    }
}
void DoublyLL::display(){
    temp=first;
    cout<<"Linked List: ";
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void DoublyLL::reverse(){
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
void DoublyLL::search(){
    int key;
    cout<<"Enter element to be searched: ";
    cin>>key;
    temp=first;
    while(temp != NULL){
        if(temp->data == key){
            cout<<"Element found"<<endl;
            return;
        }
        temp=temp->next;
    }
    cout<<"Element not found"<<endl;
}
void DoublyLL::count(){
    temp=first;
    int count=0;
    while(temp != NULL){
        count++;
        temp=temp->next;
    }
    cout<<"Size of linked list: "<<count<<endl;
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
    DoublyLL *dl= new DoublyLL();
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
                dl->count();
                break;
            case 7:
            {
                DoublyLL* l2=new DoublyLL();
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
                dl->cn+= l2->cn;
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
