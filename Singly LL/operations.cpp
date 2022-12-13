#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
};
class SinglyLL{
    node *first, *last;
    node *temp;
    node *temp1;
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
        }
        void add_to_tail();
        void add_to_head();
        void add_in_bet();
        void del_tail();
        void del_head();
        void del_in_bet();
        void display();
        void reverse();
        void search1();
        node* search2();
        int count();
        void operator +(const SinglyLL *l2){
            last->next=l2->first;
            last=l2->last;   
        }
};
void SinglyLL::add_to_head(){
    temp=new node;
    cout<<"Enter the data: ";
    int d;
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
void SinglyLL::add_to_tail(){
    temp=new node;
    cout<<"Enter the data: ";
    int d;
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
// void SinglyLL::add_in_bet(){
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
//         temp1->next=temp;
//     }
// }
void SinglyLL::add_in_bet(){
    temp=new node;
    node *temp2=new node;
    cout<<"Enter the data: ";
    int d;
    cin>>d;
    temp->data=d;
    temp->next=NULL;
    cout<<"Enter the postion of element: ";
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
    }else if(key==cn+1){
        last->next=temp;
        last=temp;
    }
    else{
        while(c!=key){
            temp2=temp2->next;
            temp1=temp1->next;
            c++;
        }
        cout<<temp2->data<<" "<<temp->data<<" "<<temp1->data;
        temp2->next=temp;
        temp->next=temp1;
    }
    cn++;
}

void SinglyLL::del_head(){
    if(first==NULL){
        cout<<"Errot, Linked list empty"<<endl;
    }else if(first == last){
        delete first;
        last=NULL;
        cn--;
    }else{
        temp=first;
        first=temp->next;
        delete temp;
        cn--;
    }
}
void SinglyLL::del_tail(){
    if(first==NULL){
        cout<<"Error, Linked list empty"<<endl;
    }else if(first == last){
        delete first;
        last=NULL;
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
// void SinglyLL::del_in_bet(){
//     if(first==NULL){
//         cout<<"Error, Linked list empty"<<endl;
//     }else if(first == last){
//         delete first;
//         last=NULL;
//     }else{
//         int key;
//         cout<<"Enter the element to be deleted: ";
//         cin>>key;
//         temp1=first;
//         temp=first->next;
//         while(temp != NULL){
//             if(temp->data == key)
//                 break;
//             temp=temp->next;
//             temp1=temp1->next;
//         }
//         temp1->next=temp->next;
//         delete temp;
//     }
// }
void SinglyLL::del_in_bet(){
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
            if(temp1->next==last){
                last=temp1;
            }
            delete temp;
            
        }
        cn--;
    }
}
void SinglyLL::display(){
    temp=first;
    cout<<"Linked List: ";
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void SinglyLL::reverse(){
    node *behind=NULL;
    node *position=first;
    node *ahead;
    while(position != NULL){
        ahead=position->next;
        position->next=behind;
        behind=position;
        position=ahead;
    }
    first=behind;
    display();
}
void SinglyLL::search1(){
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
node* SinglyLL::search2(){
    int key;
    cout<<"Enter element to be searched: ";
    cin>>key;
    temp=first;
    while(temp != NULL){
        if(temp->data == key){
            cout<<"Element found"<<endl;
            return temp;
        }
        temp=temp->next;
    }
    cout<<"Element not found"<<endl;
}
int SinglyLL::count(){
    temp=first;
    int count=0;
    while(temp != NULL){
        count++;
        temp=temp->next;
    }
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
    SinglyLL *sl= new SinglyLL();
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
                cout<<sl->search2();
                break;
            case 6:
                cout<<"Size of linked list: "<<sl->count();
                break;
            case 7:
            {
                SinglyLL* l2=new SinglyLL();
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
        }
        menu();
        cout<<"Enter your choice: ";
        cin>>ch;
    }
}