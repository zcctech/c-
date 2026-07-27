#pragma once
#include<iostream>
template<class T>
class bstreenode {
public:
	bstreenode(const T& ans)
		:key(ans)
	{ }
	bstreenode* left = nullptr;
	bstreenode* right = nullptr;
	T key;
};
template<class T>
class bstree
{
public:
	typedef bstreenode<T> node;
	bstree() = default;
	~bstree()
	{
		_destroy(root);
}
	bstree(const bstree<T>& n)
	{
		root=copy(n.root);
	}
	bstree& operator=(const bstree& n)
	{
		if (this != &n)
		{
			_destroy(root);
			root = copy(n.root);
			
		}

		return *this;
	}
	bool insert(const T& num)
	{
		if (root == nullptr)
		{
			root = new node(num);
			return true;
		}
		node* parent = nullptr;
		node* cur = root;
		while (cur)
		{
			if (num < cur->key)
			{
				parent = cur;
				cur = cur->left;
			}
			else if(num>cur->key)
			{
				parent = cur;
				cur = cur->right;
			}
			else
			{
				return false;
			}
		}
		cur = new node(num);
		if (num < parent->key)
		{
			parent->left = cur;
		}
		else
		{
			parent->right = cur;
		}
		return true;
	}
	node* find(const T& num)
	{
		if (root == nullptr)
		{
			return nullptr;
	}
		
		node* cur = root;
		while (cur)
		{
			if (num < cur->key)
			{
				cur = cur->left;
			}
			else if (num > cur->key)
			{
				cur = cur->right;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}
	bool erase(const T& key)
	{
		
		node* parent = nullptr;
		node* cur = root;
		while (cur)
		{
			if (key < cur->key)
			{
				parent = cur;
				cur = cur->left;
			}
			else if (key > cur->key)
			{
				parent = cur;
				cur = cur->right;
			}
			else
			{
				if (cur->left == nullptr)
				{
					if (root == cur)
					{
						root = cur->right;
					}
					else if (parent->right ==cur)
					{
						parent->right = cur->right;
					}
					else
					{
						parent->left = cur->right;
					}
					delete cur;
					return true;
				}
				else if (cur->right == nullptr)
				{
					if (root == cur)
					{
						root = cur->left;
					}
					else if (parent->right == cur)
					{
						parent->right = cur->left;
					}
					else
					{
						parent->left = cur->left;
					}
					delete cur;
					return true;
				}
				else
				{
					node* replase = cur->right;
					node* replaseparent = cur;
					while (replase->left)
					{
						replaseparent = replase;
						replase = replase->left;
					}
					cur->key = replase->key;
					if (replaseparent->left == replase)
					{
						replaseparent->left = replase->right;
					}
					else
					{
						replaseparent->right = replase->right;
					}
					delete replase;
					return true;
				}



			}
		}
		return false;
	}
	void inorder()
	{
		_inorder(root);
		std::cout<<std::endl;
	}
	
private:
	node* root=nullptr;
	void _inorder(node* theroot)
	{
		if (theroot == nullptr)
		{
			return;
		}
		_inorder(theroot->left);
		std::cout << theroot->key << " ";
		_inorder(theroot->right);
	}
	void _destroy(node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_destroy(root->left);
		_destroy(root->right);
		delete root;
	}
	node* copy(const node* root)
	{
		if (root == nullptr)
		{
			return nullptr;
	}
		node* newnode = new node(root->key);
		newnode->left = copy(root->left);
		newnode->right = copy(root->right);
		return newnode;
	}
};