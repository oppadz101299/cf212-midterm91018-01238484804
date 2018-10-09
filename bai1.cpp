#include <iostream>
using namespace std;
#include <queue>
#include <stack>

template <class T>
class Node
{
    public:
        T data;
        Node *left;
        Node *right;
    public:
        Node(T data)
        {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }
};

template <class T>
class Tree
{
    private:
        Node<T> * root;
    public:
        Tree();
        bool ktSNT(T data);
        void insert(T value);
        void BFS()const;;
        ~Tree();
};

template<class T>
Tree<T>::Tree()
{
    this -> root = NULL;
}

template<class T>
Tree<T>::~Tree(){}

template<class T>
bool Tree<T>::ktSNT(T data){
	bool flag=true;
	for(int i=0;i<data;++i)
	{
		if(data%i==0){
			flag=false;
			break;
			
		}
	}
	return flag;
}

template<class T>
void Tree<T>::insert(T value)
{
    if (!this -> root) 
        this -> root = new Node<T>(value);
    else
    {
        queue<Node<T> *> Q;
        Q.push(this -> root);
        while(true)
        {
            Node<T> * p = Q.front();
            cout<<"(*) "<<p -> data<<" "<<p -> left<<" "<<p-> right<<endl;
            if(p -> left == NULL)
            {
                p -> left = new Node<T>(value);
                return;
            }else
            {
                Q.push(p->left);
            }
            if(p -> right == NULL)
            {
                p -> right = new Node<T>(value);
                return;
            }else
            {
                Q.push(p->right);
            }
        }
    }
}

template<class T>
void Tree<T>::BFS()const
{
    queue<Node<T> *> Q;
    Q.push(this -> root);
    while(!Q.empty())
    {
        cout<<Q.front() -> data<<" ";
        if(Q.front()->left!=NULL)
            Q.push(Q.front()->left);
        if(Q.front()->right!=NULL)
            Q.push(Q.front()->right);
        Q.pop();
    }
}

int main()
{
	Tree<float> a;

	a.insert(2);
	a.insert(3);
	a.insert(6);
	a.insert(9);

	a.BFS();
}
