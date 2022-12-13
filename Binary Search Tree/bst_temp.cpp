#include <iostream>
using namespace std;
#define MAX_SIZE 100

template <class T>
class Node
{
public:
	T data;
	Node *prev, *next;
	Node()
	{
		prev = NULL;
		next = NULL;
	}
};

template <class T>
class Stack
{
protected:
  int tos, size;
  T arr[MAX_SIZE];

public:
  Stack(int size = 30)
  {
    this->tos = -1;
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

  T top()
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
      cout << "ERROR: Queue Finished\n";
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
class BST{
public:
	Node<T> *root, *p, *q, *p1, *r, *temp;
	Stack<Node<T> *> stack;
	Queue<Node<T> *> queue;

	BST()
	{
		root = NULL;
	}
	void insert();
	void preorder_recursive(Node<T> *);
	void postorder_recursive(Node<T> *);
	void inorder_recursive(Node<T> *);
	void preorder_iterative(Node<T> *);
	void postorder_iterative(Node<T> *);
	void inorder_iterative(Node<T> *);
	void preorder_iterative();
	void postorder_iterative();
	void inorder_iterative();
	void breadth_first_traversal();
	bool search(Node<T> *node, T key);
	void delete_merging(Node<T> *temp, T key);
	void merge(Node<T> *&node);
	void delete_copy(Node<T> *temp, T key);
	void copy(Node<T> *&node);
	void replace(T key);
	int height(Node<T> *current);
};

template <class T>
void BST<T>:: insert()
{
	q = new Node<T>;
    cout << "Enter the element: ";
    T d;
    cin >> d;
    q->prev = q->next = NULL;
    q->data = d;
    if (root == NULL){
        root = q;
    }else{
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
bool BST<T>::search(Node<T> *node, T key)
{
	if (node == NULL)
		return false;

	if (node->data == key)
		return true;

	bool prev = search(node->prev, key);
	if (prev)
		return true;
	bool next = search(node->next, key);
	return next;
}

template <class T>
void BST<T>::inorder_recursive(Node<T> *root)
{
	if (root != NULL)
	{
		inorder_recursive(root->prev);
		cout << root->data << " ";
		inorder_recursive(root->next);
	}
}

template <class T>
void BST<T>::preorder_recursive(Node<T> *root)
{
	if (root != NULL)
	{
		cout << root->data << " ";
		preorder_recursive(root->prev);
		preorder_recursive(root->next);
	}
}

template <class T>
void BST<T>::postorder_recursive(Node<T> *root)
{
	if (root != NULL)
	{
		postorder_recursive(root->prev);
		postorder_recursive(root->next);
		cout << root->data << " ";
	}
}

template <class T>
void BST<T>::inorder_iterative()
{
	Node<T> *current = root;
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
void BST<T>::preorder_iterative(){
	Node<T> *node, *temp = root;
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
	Node<T> *temp = root;
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
	Node<T> *current = root;
	if (current == NULL)
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
int BST<T>::height(Node<T> *current)
{
	if (current == NULL)
		return 0;

	else
	{
		int prevH = height(current->prev);
		int nextH = height(current->next);

		if (prevH > nextH)
			return (prevH + 1);
		else
			return (nextH + 1);
	}
}

template <class T>
void BST<T>::delete_merging(Node<T> *temp, T key)
{
	Node<T> *prev = NULL;
	while (temp != NULL)
	{
		if (temp->data == key)
			break;
		prev = temp;
		if (temp->data < key)
			temp = temp->next;
		else
			temp = temp->prev;
	}

	if (temp != NULL && temp->data == key)
	{
		if (temp == root)
			merge(root);
		else if (prev->prev == temp)
			merge(prev->prev);
		else
			merge(prev->next);
	}
	else if (root != NULL)
		cout << "\nNode Not Found...";

	return;
}

template <class T>
void BST<T>::merge(Node<T> *&node)
{
	Node<T> *temp = node;

	if (node == NULL)
		return;
	if (node->next == NULL)
		node = node->prev;
	else if (node->prev == NULL)
		node = node->next;
	else
	{
		temp = node->prev;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = node->next;
		temp = node;
		node = node->prev;
	}
	delete temp;

	return;
}

template <class T>
void BST<T>::delete_copy(Node<T> *temp, T key)
{
	Node<int> *prev = NULL;

	while (temp != NULL && temp->data != key)
	{
		prev = temp;
		if (temp->data < key)
			temp = temp->next;
		else
			temp = temp->prev;
	}

	if (temp != NULL && temp->data == key)
	{
		if (temp == root)
			copy(root);
		else if (prev->prev == temp)
			copy(prev->prev);
		else
			copy(prev->next);
	}
	else if (root != NULL)
		cout << "\nNode Not Found...";

	return;
}

template <class T>
void BST<T>::copy(Node<T> *&node)
{
	Node<int> *prev, *temp = node;
	if (node->next == NULL)
		node = node->prev;
	else if (node->prev == NULL)
		node = node->next;
	else
	{
		prev = node;
		temp = node->prev;
		while (temp->next != NULL)
		{
			prev = temp;
			temp = temp->next;
		}
		node->data = temp->data;
		if (prev == node)
			prev->prev = temp->prev;
		else
			prev->next = temp->prev;
	}
	delete temp;

	return;
}

template <class T>
void BST<T>::replace(T key)
{
	if (search(root, key))
	{
		delete_merging(root, key);
		cout<<"Enter the new key: ";
		insert();
	}
	else
	{
		cout << "Node Not Found...";
	}
}

void menu()
{
	cout<<"\n--------------------------\n";
    cout << "\t\tBINARY SEARCH TREE";
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
    cout << "\n12. Level by level traversal";
    cout << "\n13. Exit";
	cout<<"\n--------------------------";
}

int main(){
	BST<int> *b = new BST<int>();
	int ch, data;
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
            cin>>data;
            b->delete_merging(b->root, data);
            break;
        case 9:
            cout<<"Enter element to be deleted: ";
            cin>>data;
            b->delete_copy(b->root, data);
            break;
        case 10:
            cout<<"Height: "<<b->height(b->root);
            break;
        case 11:
            cout<<"Enter element to be searched: ";
            cin>>data;
            b->replace(data);
            break;
		case 12:
			b->breadth_first_traversal();
			break;
        case 13:
            return 0;
        }
    }
}