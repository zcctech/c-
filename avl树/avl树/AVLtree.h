#pragma once
#include<iostream>
#include<cassert>
template<class k,class v>
class AVLtreenode
{public:
	AVLtreenode(const k& key, const v& value = v())
		:_key(key)
		,_value(value)
	{
		_left = nullptr;
		_right = nullptr;
		_parent = nullptr;
		_bf = 0;
	}
	
	int _bf;
	k _key;
	v _value;
	AVLtreenode* _left;
	AVLtreenode* _right;
	AVLtreenode* _parent;
};
template<class k, class v>
class AVLtree
{public:
	typedef AVLtreenode<k,v> node;

	
	void inorder()
	{
		_inorder(_root);
	}
    bool insert(const k& key, const v& value)
    {
		node* cur = _root;
		node* parent = nullptr;
		while (cur)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}
		node* newnode = new node(key, value);
		if (parent == nullptr)
		{
			_root = newnode;
			return true;
		}
		else if (parent->_key > key)
		{
			parent->_left = newnode;
			newnode->_parent = parent;
		}
		else if (parent->_key < key)
		{
			parent->_right = newnode;
			newnode->_parent = parent;
		}
		else
		{
			assert(false);
		}
		node* child = newnode;
		while (parent)
		{
			if (child == parent->_left)
			{
				parent->_bf--;
				
			}
			else if (child == parent->_right)
			{
				parent->_bf++;
				
			}
			else
			{
				assert(false);
			}



			if (parent->_bf == 0)
			{
				break;
			}
			if (parent->_bf == 1 || parent->_bf == -1)
			{
				child = parent;
				parent = parent->_parent;
				continue;
			}
			else if (parent->_bf == -2 && child->_bf == -1)
			{
				rotateR(parent);
				break;
			}
			else if (parent->_bf == 2 && child->_bf == 1)
			{
				rotateL(parent);
				break;
			}
			else if (parent->_bf == -2 && child->_bf == 1)
			{
				
				rotateLR(parent);
				
				break;
			}
			else if (parent->_bf == 2 && child->_bf == -1)
			{
				rotateRL(parent);
				break;
			}
			else
			{
				assert(false);
			}
			
		}
		return true;
    }
private:
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
		
		root->_bf = 0;
		subL->_bf = 0;
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
		if (parent==nullptr)
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
		subR->_bf = 0;
		root->_bf = 0;
	}
	void rotateLR(node* root)
	{
		node* rroot = root;
		node* rsubL = root->_left;
		int change = root->_left->_right->_bf;
		rotateL(root->_left);
		rotateR(root);
		if (change == -1)
			rroot->_bf = 1;
		else if (change == 1)
			rsubL->_bf = -1;
		else if(change==0)
		{
			
		}
		else
		{
			assert(false);
		}

	}
	void rotateRL(node* root)
	{
		node* rroot = root;
		node* rsubR = root->_right;
		int change = root->_right->_left->_bf;
		rotateR(root->_right);
		rotateL(root);
		if (change == 1)
			rroot->_bf = -1;
		else if (change == -1)
			rsubR->_bf = 1;
		else if (change == 0)
		{

		}
		else
		{
			assert(false);
		}

	}
	void _inorder(node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_inorder(root->_left);
		std::cout << root->_key<<":" << root->_value << std::endl;
		_inorder(root->_right);
	}
	node* _root=nullptr;
};
