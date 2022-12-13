#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
};
class CSLL{
    node *tail;
    node *temp;
    node *temp1;
    public:
    int cn=0;
        CSLL(){
            tail=temp=temp1=NULL;
        }
        ~CSLL(){
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
        void operator +(const CSLL *l2){
            temp=tail->next;
            tail->next=l2->tail->next;
            l2->tail->next=temp;
            tail=l2->tail;   
        }
};
void CSLL::add_to_head(){
    temp=new node;
    cout<<"Enter the data: ";
    int d;
    cin>>d;
    temp->data=d;
    temp->next=NULL;
    if(tail==NULL){
        tail=temp;
        tail->next=tail;
    }else{
        temp->next=tail->next;
        tail->next=temp;
        cn++;
    }
}
void CSLL::add_to_tail(){
    temp=new node;
    cout<<"Enter the data: ";
    int d;
    cin>>d;
    temp->data=d;
    temp->next=NULL;
    if(tail==NULL){
        tail=temp;
        tail->next=tail;
    }else{
        temp->next=tail->next;
        tail->next=temp;
        tail=temp;
        cn++;
    }
} 
void CSLL::add_in_bet(){
    temp=new node;
    cout<<"Enter the data: ";
    int d;
    cin>>d;
    temp->data=d;
    temp->next=NULL;
    cout<<"Enter the position of insertion: ";
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
        tail->next=tail;
    }else if(key==1){
        temp->next=tail->next;
        tail->next=temp;
    }else if(key>=cn){
        temp->next=tail->next;
        tail->next=temp;
        tail=temp;
    }
    else{
        while(c!=key){
            temp1=temp1->next;
            c++;
        }
        temp->next=temp1->next;
        temp1->next=temp;
    }
    cn++;
    
}
void CSLL::del_head(){
    if(tail==NULL){
        cout<<"Errot, Linked list empty"<<endl;
    }else if(count()==1){
        delete tail;
    }else{
        temp=tail->next;
        tail->next=temp->next;
        delete temp;
        cn--;
    }
}
void CSLL::del_tail(){
    if(tail==NULL){
        cout<<"Error, Linked list empty"<<endl;
    }else if(count()==1){
        delete tail;
    }else{
        temp=tail->next;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=tail->next;
        delete tail;
        tail=temp;
        cn--;
    }
}
// void CSLL::del_in_bet(){
//     if(tail==NULL){
//         cout<<"Error, Linked list empty"<<endl;
//     }else if(count()==1){
//         delete tail;
//     }else{
//         int key;
//         cout<<"Enter the element to be deleted: ";
//         cin>>key;
//         temp1=tail->next;
//         temp=temp1->next;
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
void CSLL::del_in_bet(){
    if(tail==NULL){
        cout<<"Error, Linked list empty"<<endl;
    }else if(tail==tail->next){
        delete tail;
    }else{
        int key;
        cout<<"Enter the position of element to be deleted: ";
        cin>>key;
        temp1=tail->next;
        temp=temp1->next;
        int c=1;
        if(key==1){
            temp=tail->next;
            tail->next=temp->next;
            delete temp;
        }else if(key >= cn){
            temp=tail->next;
            while(temp->next!=tail){
                temp=temp->next;
            }
            temp->next=tail->next;
            delete tail;
            tail=temp;
        }else{
            while(c!= key-1){
                temp=temp->next;
                temp1=temp1->next;
                c++;
            }
            temp1->next=temp->next;
            delete temp;
        }
        cn--;
    }
}
void CSLL::display(){
    if(tail!=NULL){
        temp=tail->next;
        cout<<"Linked List: ";
        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp != tail->next);
    }else{
        cout<<"Linked list is Empty";
    }
}
void CSLL::reverse(){
    temp=tail->next;
    node *behind=tail;
    node *position=tail->next;
    node *ahead;
    do{
        ahead=position->next;
        position->next=behind;
        behind=position;
        position=ahead;
    }while(position != temp);
    tail=position;
    display();
}
void CSLL::search(){
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
    }while(temp != tail->next);
    cout<<"Element not found"<<endl;
}
int CSLL::count(){
    temp=tail->next;
    int count=0;
    do{
        count++;
        temp=temp->next;
    }while(temp != tail->next);
    
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
    CSLL *sl= new CSLL();
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
                sl->search();
                break;
            case 6:
                cout<<"Size of linked list: "<<sl->count();
                break;
            case 9:
                return 0;
        }
        menu();
        cout<<"Enter your choice: ";
        cin>>ch;
    }
}