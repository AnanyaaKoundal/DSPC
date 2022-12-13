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
        }
        int count();
};

template <class T>
void sll<T>::add_to_first(){

}
template <class T>
void sll<T>::add_to_tail(){
    
}
template <class T>
void sll<T>::add_in_btw(){
    
}
template <class T>
void sll<T>::delele_first(){
    
}

template <class T>
void sll<T>:: delete_tail(){
    
}

template <class T>
void sll<T>::del_in_btw(){
    
}

template <class T>
void sll<T>::reverse(){
    
}

template <class T>
node<T>* sll<T>::search(int n){
    
}

template <class T>
void sll<T>:: display(){
    
}

template <class T>
int sll<T>::count(){
    
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
                    
                    break;
                }
            case 7:{
                
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