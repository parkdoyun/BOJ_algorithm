#include <iostream>
#include <vector>
using namespace std;
//백준 - 1991 트리 순회
typedef char T;
class node
{
	T data;
	node *left;
	node *right;
	node *par;
public:
	node()
	{
		left = NULL;
		right = NULL;
		par = NULL;
	}
	bool isRoot()
	{
		return this->par == NULL;
	}
	bool isExternal()
	{
		return this->left == NULL && this->right == NULL;
	}
	T getData()
	{
		return this->data;
	}
	void setData(T e)
	{
		this->data = e;
	}
	void setParent(node *v)
	{
		this->par = v;
		if (v->left == NULL)
		{
			v->left = this;
		}
		else if (v->right == NULL)
		{
			v->right = this;
		}
	}
	void insertChild(node *v)
	{
		if (this->left == NULL)
		{
			this->left = v;
			v->par = this;
		}
		else if (this->right == NULL)
		{
			this->right = v;
			v->par = this;
		}

	}
	void delChild(node *v)
	{
		if (v == this->left)
		{
			v->left->par = this;
			this->left = v->left;
		}
		else if (v == this->right)
		{
			v->left->par = this;
			this->right = v->left;
		}
		delete v;
	}
	int depth()
	{
		if (isRoot())
		{
			return 0;
		}
		return par->depth() + 1;
	}
	friend class Tree;
};
class Tree
{
public:
	Tree()
	{
		root = new node;
		//root = NULL; 하면 nullptr에러 발생.

	}
	~Tree()
	{
		DeleteTree(root);
		//delete root;
	}
	void DeleteTree(node *v)
	{
		if (v->isExternal()) // 이게 더 정확한 듯..?
		{
			delete v;
			return;
		}
		if (v->left != NULL)
		{
			DeleteTree(v->left);
		}
		if (v->right != NULL)
		{
			DeleteTree(v->right);
		}
	}
	void preOrder(node *v, vector<node *> &p)
	{
		p.push_back(v);
		if (v->left != NULL)
		{
			preOrder(v->left, p);
		}
		if (v->right != NULL)
		{
			preOrder(v->right, p);
		}
	}
	void inOrder(node *v, vector<node *> &p)
	{
		if (v->left != NULL)
		{
			inOrder(v->left, p);
		}
		p.push_back(v);
		if (v->right != NULL)
		{
			inOrder(v->right, p);
		}
	}
	void postOrder(node *v, vector<node *> &p)
	{
		if (v->left != NULL)
		{
			postOrder(v->left, p);
		}
		if (v->right != NULL)
		{
			postOrder(v->right, p);
		}
		p.push_back(v);
	}
	node *searchNode(T d)
	{
		node *r;
		vector<node *> pl;
		preOrder(root, pl);
		for (int i = 0; i < pl.size(); i++)
		{
			if (pl[i]->data == d)
			{
				r = pl[i];
				break;
			}
		}
		return r;
	}
	int depth(T d)
	{
		node *r = searchNode(d);
		return r->depth();
	}
	vector<node *> positions()
	{
		vector<node *> pl;
		preOrder(root, pl);
		return pl;
	}
	void printList(vector<node *> p)
	{
		for (int i = 0; i < p.size(); i++)
		{
			cout << p[i]->data;
		}
		cout << endl;
	}
	void printChild(T d)
	{
		node *r = searchNode(d);
		vector<node *> pl;
		preOrder(r, pl);
		for (int i = 0; i < pl.size(); i++)
		{
			if (pl[i] == r)
			{
				continue;
			}
			cout << pl[i]->data << ' ';
		}
		cout << endl;
	}
	void insertNode(T parent_d, T d)
	{
		node *p = searchNode(parent_d);
		node *n = new node;
		n->data = d;
		n->par = p;
		if (p->left == NULL)
		{
			p->left = n;
		}
		else if (p->right == NULL)
		{
			p->right = n;
		}
		else
		{
			DeleteTree(p->left);
			p->left = n;
		}
	}
	void insertLeft(T parent_d, T d)
	{
		node *p = searchNode(parent_d);
		node *n = new node;
		n->data = d;
		n->par = p;
		p->left = n;
	}
	void insertRight(T parent_d, T d)
	{
		node *p = searchNode(parent_d);
		node *n = new node;
		n->data = d;
		n->par = p;
		p->right = n;
	}
	node* getRoot()
	{
		return root;
	}
	void setRoot(T d)
	{
		root->setData(d);
	}
	int height(node *v)
	{
		if (v->isExternal())
		{
			return 0;
		}
		int res = 0;
		if (v->left != NULL && v->right != NULL)
		{
			res = (height(v->left) > height(v->right) ? height(v->left) : height(v->right));
			res++;
		}
		else if (v->left == NULL && v->right != NULL)
		{
			res = height(v->right) + 1;
		}
		else if (v->left != NULL && v->right == NULL)
		{
			res = height(v->left) + 1;
		}
		return res;
	}
	int TreeHeight()
	{
		return height(root);
	}
private:
	node *root;
};
int main()
{
	int node_n;
	cin >> node_n;
	Tree t1;
	for (int i = 0; i < node_n; i++)
	{
		char c[3];
		cin >> c[0] >> c[1] >> c[2];
		if (i == 0)
		{
			t1.setRoot(c[0]);

		}
		if (c[1] != '.')
		{
			t1.insertLeft(c[0], c[1]);
		}
		if (c[2] != '.')
		{
			t1.insertRight(c[0], c[2]);
		}
		
		
	}
	vector<node *> p;
	t1.preOrder(t1.getRoot(), p);
	t1.printList(p);
	p.clear();
	t1.inOrder(t1.getRoot(), p);
	t1.printList(p);
	p.clear();
	t1.postOrder(t1.getRoot(), p);
	t1.printList(p);
	p.clear();
	
	return 0;
}