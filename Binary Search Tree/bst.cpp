#include <iostream>
using namespace std;
#define MAX_SIZE 100

template <class T>
class Stack
{
    int top, size;
    T stack[MAX_SIZE];

public:
    Stack(int size = 30)
    {
        this->top = -1;
        this->size = size;
    }
    bool push(T ele)
    {
        if (this->tos >= (this->size - 1))
        {
            cerr << "ERROR: Stack Overflow\n";
            return false;
        }
        this->arr[++(this->tos)] = ele;
        return true;
    }

    T pop()
    {
        if (this->isEmpty())
        {
            cout << "ERROR: Stack Underflow\n";
            return (T)(NULL);
        }
        return this->arr[(this->tos)--];
    }

    T atFirst()
    {
        if (this->isEmpty())
        {
            cout << "Stack Empty";
            return (T)(NULL);
        }
        return this->arr[this->tos];
    }

    bool isEmpty()
    {
        return this->tos == -1;
    }

    void clear()
    {
        while (!this->isEmpty())
            this->pop();
    }
};

template <class T>
class Queue
{
protected:
    T arr[MAX_SIZE];
    int front, rear, size;

public:
    Queue(int size = 100)
    {
        this->front = -1;
        this->rear = -1;
        this->size = size;
    }

    bool enqueue(T ele)
    {
        if (this->rear >= (this->size - 1))
        {
            cerr << "ERROR: Queue Filled\n";
            return false;
        }
        else if (this->isEmpty())
        {
            this->rear++;
            this->front++;
            this->arr[this->front] = ele;
        }
        else
            this->arr[++(this->rear)] = ele;
        return true;
    }

    T dequeue()
    {
        if (this->front >= this->size)
        {
            cout << "ERROR: Queue Overflow\n";
            return (T)(NULL);
        }
        else if (this->isEmpty())
        {
            cout << "ERROR: Queue Empty\n";
            return (T)(NULL);
        }
        else if (this->front == this->rear)
        {
            T temp = this->arr[this->front];
            this->clear();
            return temp;
        }
        return this->arr[(this->front)++];
    }

    T frontEl()
    {
        if (this->isEmpty())
        {
            cout << "Queue Empty";
            return (T)(NULL);
        }
        return this->arr[this->front];
    }

    bool isEmpty()
    {
        return this->front == -1;
    }

    void clear()
    {
        this->front = this->rear = -1;
    }

    void display()
    {
        if (this->isEmpty())
        {
            cout << "Queue Empty";
            return;
        }
        int i;
        for (i = this->front; i < this->rear; i++)
            cout << this->arr[i] << " <- ";
        cout << this->arr[i] << endl;
        return;
    }
};

template <class T>
class node
{
public:
    T data;
    node *next;
    node *prev;
};

template <class T>
class BST
{

    Stack<node<int> *> stack;
    Queue<node<int> *> queue;

public:
    node<T> *root, *p, *q, *p1, *r;
    BST()
    {
        root = p = q = p1 = r = NULL;
    }
    void insert();
    void preorder_recursive(node<T> *);
    void postorder_recursive(node<T> *);
    void inorder_recursive(node<T> *);
    void preorder_iterative(node<T> *);
    void postorder_iterative(node<T> *);
    void inorder_iterative(node<T> *);
    void preorder_iterative();
    void postorder_iterative();
    void inorder_iterative();
    void breadth_first_traversal();
    void delete_merging(node<int> *temp, int key);
    void merge(node<int> *&node);
    void delete_copy(node<int> *temp, int key);
    void copy(node<int> *&node);
    void replace(int key, int newKey);
    int height(node<int> *current);
};

template <class T>
void BST<T>::insert()
{
    q = new node<T>;
    cout << "Enter the element: ";
    T d;
    cin >> d;
    q->prev = q->next = NULL;
    q->data = d;
    if (root == NULL)
    {
        root = q;
    }
    else
    {
        p = root;
        while (p != NULL)
        {
            if (d < p->data)
            {
                p1 = p;
                p = p->prev;
            }
            else
            {
                p1 = p;
                p = p->next;
            }
        }
        if (p1->data > d)
        {
            p1->prev = q;
        }
        else
        {
            p1->next = q;
        }
    }
}

template <class T>
void BST<T>::preorder_recursive(node<T> *temp)
{
    if (temp != NULL)
    {
        cout << temp->data << " ";
        preorder_recursive(temp->prev);
        preorder_recursive(temp->next);
    }
}

template <class T>
void BST<T>::postorder_recursive(node<T> *temp)
{
    if (temp != NULL)
    {
        postorder_recursive(temp->prev);
        postorder_recursive(temp->next);
        cout << temp->data << " ";
    }
}

template <class T>
void BST<T>::inorder_recursive(node<T> *temp)
{
    if (temp != NULL)
    {
        inorder_recursive(temp->prev);
        cout << temp->data << " ";
        inorder_recursive(temp->next);
    }
}

template <class T>
void BST<T>::inorder_iterative()
{
    node<int> *current = root;

    while (current != nullptr ||
           stack.isEmpty() == false)
    {
        while (current != nullptr)
        {
            stack.push(current);
            current = current->prev;
        }
        current = stack.pop();
        cout << current->data << " ";
        current = current->next;
    }
}
template <class T>
void BST<T>::preorder_iterative()
{
    node<int> *node, *temp = root;
    if (temp == nullptr)
        return;
    stack.push(temp);
    while (!stack.isEmpty())
    {
        node = stack.pop();
        cout << node->data << " ";
        if (node->next)
            stack.push(node->next);
        if (node->prev)
            stack.push(node->prev);
    }
}

template <class T>
void BST<T>::postorder_iterative()
{
    node<int> *temp = root;
    if (temp == nullptr)
        return;
    do
    {
        while (temp)
        {
            if (temp->next)
                stack.push(temp->next);
            stack.push(temp);
            temp = temp->prev;
        }
        temp = stack.pop();
        if (temp->next && !stack.isEmpty() &&
            stack.top() == temp->next)
        {
            stack.pop();
            stack.push(temp);
            temp = temp->next;
        }
        else
        {
            cout << temp->data << " ";
            temp = nullptr;
        }
    } while (!stack.isEmpty());
}
template <class T>
void BST<T>::breadth_first_traversal()
{
    node<int> *current = root;

    if (current == nullptr)
        return;

    queue.enqueue(current);
    while (!queue.isEmpty())
    {
        current = queue.dequeue();
        cout << current->data << " ";
        if (current->prev)
            queue.enqueue(current->prev);
        if (current->next)
            queue.enqueue(current->next);
    }

    cout << endl;
}

template <class T>
void BST<T>::delete_merging(node<int> *temp, int key)
{
    node<int> *prev = nullptr;

    while (temp != nullptr)
    {
        if (temp->data == key)
            break;
        prev = temp;
        if (temp->data < key)
            temp = temp->next;
        else
            temp = temp->prev;
    }

    if (temp != nullptr && temp->data == key)
    {
        if (temp == root)
            merge(root);
        else if (prev->prev == temp)
            merge(prev->prev);
        else
            merge(prev->next);
    }
    else if (root != nullptr)
        cout << "\nnode Not Found...";

    return;
}
template <class T>
void BST<T>::merge(node<int> *&node)
{
    node<int> *temp = node;

    if (node == nullptr)
        return;

    // no next child - single child
    if (node->next == nullptr)
        node = node->prev;

    // no prev child - single chold
    else if (node->prev == nullptr)
        node = node->next;

    // node has both children
    else
    {
        // find in-order predecessor
        temp = node->prev;
        while (temp->next != nullptr)
            temp = temp->next;
        // merge subtree to predecessor
        temp->next = node->next;
        temp = node;
        node = node->prev;
    }

    // delete the node
    delete temp;

    return;
}

template <class T>
void BST<T>::delete_copy(node<int> *temp, int key)
{
    node<int> *prev = nullptr;

    while (temp != nullptr && temp->data != key)
    {
        prev = temp;
        if (temp->data < key)
            temp = temp->next;
        else
            temp = temp->prev;
    }

    if (temp != nullptr && temp->data == key)
    {
        if (temp == root)
            copy(root);
        else if (prev->prev == temp)
            copy(prev->prev);
        else
            copy(prev->next);
    }
    else if (root != nullptr)
        cout << "\nnode Not Found...";

    return;
}
template <class T>
void BST<T>::copy(node<int> *&node)
{
    node<int> *prev, *temp = node;

    // no next child - single child
    if (node->next == nullptr)
        node = node->prev;

    // no prev child - single chold
    else if (node->prev == nullptr)
        node = node->next;

    // node has both children
    else
    {
        prev = node;
        // find the in-order predecessor
        temp = node->prev;
        while (temp->next != nullptr)
        {
            prev = temp;
            temp = temp->next;
        }
        // copy the prdecessor key
        node->data = temp->data;
        // handle dangling subtrees
        if (prev == node)
            prev->prev = temp->prev;
        else
            prev->next = temp->prev;
    }

    // delete the node
    delete temp;

    return;
}

template <class T>
void BST<T>::replace(int key, int newKey)
{
    if (search(root, key))
    {
        deleteByMerging(root, key);
        insert(newKey, root);
    }
    else
    {
        cout << "node Not Found...";
    }
}

template <class T>
int BST<T>::height(node<int> *current)
  {
    if (current == nullptr)
      return 0;

    else
    {
      int prevHeight = height(current->prev);
      int nextHeight = height(current->next);

      if (prevHeight > nextHeight)
        return (prevHeight + 1);
      else
        return (nextHeight + 1);
    }
  }

void menu()
{
    cout << "\n\t\tBINARY SEARCH TREE";
    cout << "\n1. Insert node";
    cout << "\n2. Preorder Recursion";
    cout << "\n3. Postorder Recursion";
    cout << "\n4. Inorder Recursion";
    cout << "\n5. Preorder Iterative";
    cout << "\n6. Postorder Iterative";
    cout << "\n7. Inorder Iterative";
    cout << "\n8. Delete by copying";
     cout<<"\n9. Delete by merging";
    cout << "\n10. Height of the tree";
    cout << "\n11. Replace element";
    cout << "\n12. Exit";
}
int main()
{
    int d;
    BST<int> *b = new BST<int>();
    while (true)
    {
        menu();
        int ch;
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            b->insert();
            break;
        case 2:;
            b->preorder_recursive(b->root);
            break;
        case 3:
            b->postorder_recursive(b->root);
            break;
        case 4:
            b->inorder_recursive(b->root);
            break;
        case 5:
            b->preorder_iterative();
            break;
        case 6:
            b->postorder_iterative();
            break;
        case 7:
            b->inorder_iterative();
            break;
        case 8:
            cout<<"Enter element to be deleted: ";
            cin>>d;
            b->delete_merging(b->root, d);
            break;
        case 9:
            cout<<"Enter element to be deleted: ";
            cin>>d;
            b->delete_copy(b->root, d);
            break;
        case 10:
            cout<<"Height: "<<b->height(b->root);
            break;
        case 11:
            cout<<"Enter element to be searched: ";
            cin>>d;
            int s;
            cout<<"Enter element to be replaced: ";
            cin>>s;
            b->replace(d,s);
            break;
        case 12:
            return 0;
        }
    }
}