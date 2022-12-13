#include <iostream>
using namespace std;

template <class T>
class S{
    T *stack;
    public:
        int size, top;
        S(int s=100){
            size=s;
            stack=new int(size);
            top=-1;
        }
        void push(T ele){
            if(top=size-1){
                cout<<"Full";
            }else{
                stack[++top]=ele;
            }
        }
        T pop(){
            if(isEmpty()){
                return -1;
            }
            return stack[top--];
        }
        bool isEmpty(){
            return top==-1;
        }
        T atTop(){
            return stack[top];
        }
};

template <class T>
class Q{
    T *stack;
    public:
        int size, top, front, rear;
        Q(int s=100){
            size=s;
            stack=new int(size);
            front=rear=top=-1;
        }
        void push(T ele){
            if(top=size-1){
                cout<<"Full";
            }else if(rear==-1){
                stack[++rear]=ele;
                front++;
            }else{
                stack[++rear]=ele;
            }
        }
        T pop(){
            if(isEmpty()){
                return -1;
            }else if(front==rear){
                T data=stack[front];
                front=rear=-1;
                return data;
            }
            return stack[front++];
        }
        bool isEmpty(){
            return front==-1 && rear==-1;
        }
};

template <class T>
class node{
    public:
        T data;
        node *next;
        node *prev;
};
template <class T>
class BST{
    node<T> *p, *q, *root, *p1, *temp, *temp1;
    Q<node<T> *> qu;
    S<node<T> *> s;
    public:
        BST(){
            p=q=root=p1=temp=temp1=NULL;
        }
        void insert(){
            q=new node<T>;
            cout<<"Enter the data: ";
            T d;
            cin>>d;
            q->data=d;
            q->next=q->prev=NULL;
            if(root== NULL){
                root=q;
            } else{
                p=root;
                while(p!=NULL){
                    if(p->data>d){
                        p1=p; p=p->prev;
                    }else{
                        p1=p; p=p->next;
                    }
                }
                if(p1->data>d){
                    p->prev=temp;
                }else{
                    p->next=temp;
                }
            }
        }
        bool search(node<T> *node, T key){
            if(node==NULL)
                return false;
            if(node->data==key)
                return true;
            bool p=search(node->prev, key);
            if(p)
                return true;
            bool n=search(node->next, key);
            return n;
        }
        int height(node<T> *current){
            if(current==NULL){
                return 0;
            }else{
                int p=height(current->prev);
                int n=height(current->next);
                if(p>n)
                    return p+1;
                return n+1;
            }
        }
        void merg(node<T> *temp, T key){
            node<T> *prev=NULL;
            while(temp!=NULL){
                if(temp->data==key) break;
                prev=temp;
                if(temp->data<key) temp=temp->next;
                else temp=temp->prev;
            }
            if(temp!=NULL && temp->data==key){
                if(temp==root){
                    merge(root);
                }else if(prev->prev==temp) merge(prev->prev);
                else merge(prev->next);
            }else if(root!=NULL)
                cout<<"Not found";
        }
        void merge(node<T> *&node){
            temp=node;
            if(node==NULL) return;
            if(node->prev==NULL) node=node->prev;
            else if(node->next==NULL) node=node->next;
            else{
                temp=node->prev;
                while(temp->next!=NULL)
                    temp=temp->next;
                temp->next=node->next;
                temp=node;
                node=node->prev;
            }
            delete temp;
        }
        void cop(node<T> *temp, T key){
            node<int> *prev=NULL;
            while(temp!=NULL){
                if(temp->data==key) break;
                prev=temp;
                if(temp->data<key) temp=temp->next;
                else temp=temp->prev;
            }
            if(temp!=NULL && temp->data==key){
                if(temp==root){
                    copy(root);
                }else if(prev->prev==temp) copy(prev->prev);
                else copy(prev->next);
            }else if(root!=NULL)
                cout<<"Not found";
        }
        void copy(node<T> *&Node){
            node<int> *prev, *temp=NULL;
            if(Node->next==NULL) Node=Node->prev;
            else if(Node->prev==NULL) Node=Node->next;
            else{
                temp=Node->prev;
                prev=Node;
                while(temp->next!=NULL){
                    prev=temp; temp=temp->next;
                }
                Node->data=temp->data;
                if(prev==Node){
                    prev->prev=Node->prev;
                }else{
                    prev->next=Node->next;
                }
            }
            delete temp;
            return;
        }
        void replace(node<T> *temp, T key){
            if(search(root, key)){
                delete merg(root, key);
                cout<<"Enter the key to inser: ";
                insert();
            }else{
                cout<<"Key not found!!";
            }
        }
        void BFT(){
            node<T> *current=root;
            if(current==NULL) return;
            qu.push(current);
            while(qu.pop()!=-1){
                current=qu.pop();
                cout<<current->data<<" ";
                if(current->prev) qu.push(current->prev);
                if(current->next) qu.push(current->next);
            }
            cout<<endl;
        }
        void inorder(){
            node<T> *current=root;
            while(current!=NULL ||s.isEmpty==false){
                while(current!=NULL){
                    s.push(current);
                    current=current->prev;
                }
                current=s.pop();
                cout<<current->data <<" ";
                current=current->next;
            }
        }
        void preorder(){
            node<T> *temp=root;
            if(temp==NULL) return;
            s.push(temp);
            while(!s.isEmpty()){
                temp=s.pop();
                cout<<temp->data<<" ";
                if(temp->next) s.push(temp->next);
                if(temp->prev) s.push(temp->prev);
            }
        }
        void postorder(){
            node<T> *temp=root;
            if(temp==NULL) return;
            do{
                while(temp){
                    while(temp->next) s.push(temp->next);
                    s.push(temp);
                    temp=temp->prev;
                }
                temp=s.pop();
                if(temp->next && !s.isEmpty() && temp->next==s.atTop()){
                    s.pop();
                    s.push(temp);
                    temp=temp->next;
                }else{
                    cout<<temp->data<<" ";
                    temp=NULL
                }
            }while(!s.isEmpty());
        }
};