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
        SinglyLL(){
            first=last=temp=temp1=NULL;
        }
        ~SinglyLL(){
            last=temp;
            last=temp->next;
            delete temp;
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
        void operator +(const SinglyLL *l2){
            last->next=l2->first;
            last=l2->last;   
        }
        
        // node* reverseRecur(node* &first);
        // void callRevRecur();
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
}
void SinglyLL::add_in_bet(){
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
    if(first == NULL){
        first=last=temp;
    }else{
        while(temp1->data != key){
            temp1=temp1->next;
        }
        temp->next=temp1->next;
        temp1->next=temp;
    }
}
void SinglyLL::del_head(){
    if(first==NULL){
        cout<<"Errot, Linked list empty"<<endl;
    }else if(first == last){
        delete first;
        last=NULL;
    }else{
        temp=first;
        first=temp->next;
        delete temp;
    }
}
void SinglyLL::del_tail(){
    if(first==NULL){
        cout<<"Error, Linked list empty"<<endl;
    }else if(first == last){
        delete first;
        last=NULL;
    }else{
        temp=first;
        while(temp->next->next != NULL){
            temp=temp->next;
        }
        last=temp;
        delete temp->next;
        temp->next=NULL;
    }
}
void SinglyLL::del_in_bet(){
    if(first==NULL){
        cout<<"Error, Linked list empty"<<endl;
    }else if(first == last){
        delete first;
        last=NULL;
    }else{
        int key;
        cout<<"Enter the element to be deleted: ";
        cin>>key;
        temp1=first;
        temp=first->next;
        while(temp != NULL){
            if(temp->data == key)
                break;
            temp=temp->next;
            temp1=temp1->next;
        }
        temp1->next=temp->next;
        delete temp;
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
void SinglyLL::search(){
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
void SinglyLL::count(){
    temp=first;
    int count=0;
    while(temp != NULL){
        count++;
        temp=temp->next;
    }
    cout<<"Size of linked list: "<<count<<endl;
}
// void SinglyLL:: callRevRecur(){
//     first=reverseRecur(first);
// }
// node* SinglyLL::reverseRecur(node* &first){
//     node *newfirst=reverseRecur(first->next);
//     first->next->next=first;
//     first->next=NULL;
//     return newfirst;
// }
void menu(){
    cout<<"\n\tLinked List Operations "<<endl;
    cout<<"1. Add"<<endl;
    cout<<"2. Delete"<<endl;
    cout<<"3. Display"<<endl;
    cout<<"4. Reverse"<<endl;
    cout<<"5. Search"<<endl;
    cout<<"6. Size of linked list"<<endl;
    cout<<"7. Concatenate"<<endl;
    cout<<"8. Exit"<<endl;
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
    SinglyLL *sl;
    // SinglyLL *sl= new SinglyLL();
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
                sl->count();
                break;
            
            case 7:
            {
                SinglyLL* l2=new SinglyLL();
                cout<<"Enter list to be appended\n";
                while(true){
                    add_menu();
                    cout<<"\t4. Stop"<<endl;
                    cout<<"Enter your choice: ";
                    cin>>ch2;
                    if(ch2==1){
                        l2->add_to_head();
                    }else if(ch2==2){
                        l2->add_to_tail();
                    }else if(ch2==3){
                        l2->add_in_bet();
                    }else{
                        break;
                    }
                }
                *sl+l2;
                cout<<"Contatenation Successful";
                break;
            }
            case 8:
                return 0;
        }
        menu();
        cout<<"Enter your choice: ";
        cin>>ch;
    }
}
