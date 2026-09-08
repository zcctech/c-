#pragma once
#include<cassert>
#include<iostream>
enum color
{
	RED,
	BLACK
};
template<class T>
struct BTtreenode
{
	typedef BTtreenode<T> node;
	BTtreenode(const T& data)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_data(data)
	{ }
	
	color thenode = RED;
	node* _right;
	node* _left;
	node* _parent;
	T _data;
};
template<class T>
struct BTtree
{
	typedef BTtreenode<T> node;
	void inorder()
	{
		_inorder(_root);
	}
	bool insert(const T& data)
	{
		node* newnode = new node(data);
		if (_root == nullptr)
		{
			newnode->thenode = BLACK;
			_root = newnode;
			return true;
		}
		node* cur = _root;
		node* parent = nullptr;
		while (cur)
		{
			if (cur->_data > data)
			{
				parent = cur;
				cur = cur->_left;

			}
			else if (cur->_data < data)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				delete newnode;
				return false;
			}
		}
		if (parent->_data > data)
		{
			parent->_left = newnode;
		}
		else if(parent->_data < data)
		{
			parent->_right = newnode;
		}
		else
		{
			assert(false);
		}
		cur = newnode;
		cur->_parent = parent;
		//下面更新红黑树
		
		while (parent&&parent->thenode!= BLACK)
		{
			if (cur->thenode == BLACK)
			{
				return true;
			}

			if (parent->thenode == RED)
			{
				node* grandparent = parent->_parent;
				node* uncle = nullptr;
				if (grandparent->_left == parent)
				{
					uncle = grandparent->_right;
				}
				else if (grandparent->_right == parent)
				{
					uncle = grandparent->_left;
				}
				//叔叔存在且为红色
				if (uncle && uncle->thenode == RED)
				{
					grandparent->thenode = RED;
					parent->thenode = uncle->thenode = BLACK;
					cur = grandparent;
					parent = cur->_parent;
					continue;
				}
				//叔叔存在且为黑色或者叔叔不存在
				//判断旋转类型
				else if ((uncle && uncle->thenode == BLACK) || uncle == nullptr)
				{
					if (grandparent->_left == parent && parent->_left == cur)
					{
						//对祖先进行右单旋
						rotateR(grandparent);
						grandparent->thenode = RED;
						parent->thenode = BLACK;
					}
					else if (grandparent->_right == parent && parent->_right == cur)
					{
						//对祖先进行左单旋
						rotateL(grandparent);
						grandparent->thenode = RED;
						parent->thenode = BLACK;
					}
					else if (grandparent->_left == parent && parent->_right == cur)
					{
						rotateL(parent);
						rotateR(grandparent);
						grandparent->thenode = RED;
						cur->thenode = BLACK;
					}
					else if(grandparent->_right == parent && parent->_left == cur)
					{
						rotateR(parent);
						rotateL(grandparent);
						grandparent->thenode = RED;
						cur->thenode = BLACK;
					}
					else
					{
						assert(false);
					}
				}


			}
		}
		_root->thenode = BLACK;
		return true;
		
	}
	void rotateR(node* root)
	{
		node* subL = root->_left;
		node* subLR = subL->_right;
		node* parent = root->_parent;
		root->_left = subLR;
		if (subLR)
		{
			subLR->_parent = root;
		}
		subL->_right = root;
		subL->_parent = root->_parent;
		if (parent == nullptr)
		{
			// root 原本是整棵树的根
			_root = subL;
		}
		else if (parent->_left == root)
		{
			parent->_left = subL;
		}
		else if (parent->_right == root)
		{
			parent->_right = subL;
		}
		else
		{
			assert(false);
		}
		root->_parent = subL;
	}
	void rotateL(node* root)
	{
		node* subR = root->_right;
		node* subRL = subR->_left;
		node* parent = root->_parent;
		root->_right = subRL;
		if (subRL)
		{
			subRL->_parent = root;
		}
		subR->_left = root;
		root->_parent = subR;
		subR->_parent = parent;
		if (parent == nullptr)
		{
			_root = subR;

		}
		else if (parent->_left == root)
		{

			parent->_left = subR;
		}
		else if (parent->_right == root)
		{

			parent->_right = subR;
		}
		else
		{
			assert(false);
		}
	}
	node* find(const T& v)
	{
		node* cur = _root;
		while (cur)
		{
			if (cur->_data > v)
			{
				cur = cur->_left;
			}
			else if (cur->_data < v)
			{
				cur = cur->_right;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}

private:
	void _inorder(node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_inorder(root->_left);
		std::cout << root->_data << " ";
		_inorder(root->_right);

	}
	node* _root=nullptr;
};
