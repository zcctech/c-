#pragma once
#include<cassert>
#include<iostream>
enum color
{
	RED,
	BLACK
};
template<class v>
struct BTtreenode
{
	typedef BTtreenode<v> node;
	BTtreenode(const v& data)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_data(data)
	{ }
	
	color thenode = RED;
	node* _right;
	node* _left;
	node* _parent;
	v _data;
};
template<class k,class v,class KeyofT>
struct BTtree
{
	template<class T, class ref, class ptr>
	struct Iterator_BTtree
	{
		typedef BTtreenode<T> node;
		typedef Iterator_BTtree<T, ref, ptr> self;
		node* _node;
		
		Iterator_BTtree(node* pos)
			:_node(pos)
		{
		}
		ref operator*()
		{
			return _node->_data;
		}
		ptr operator->()
		{
			return &_node->_data;
		}
		self& operator++()
		{
			if (_node->_right)
			{
				node* parent = _node;
				_node = _node->_right;
				while (_node)
				{
					parent = _node;
					_node = _node->_left;
				}
				_node = parent;
			}
			else
			{
				node* parent = _node->_parent;
				while (parent && parent->_right == _node)
				{
					_node = parent;
					parent = parent->_parent;
				}
				_node = parent;
			}
			
			return *this;
		}
		
		
		bool operator!=(const self& a)const
		{
			return _node != a._node;
		}
		bool operator==(const self& a)const
		{
			return _node == a._node;
		}
		
	};
	typedef Iterator_BTtree<v, v&, v*> iterator;
	typedef Iterator_BTtree<v, const v&, const v*> const_iterator;
	iterator begin()
	{
		node* cur = _root;
		while (cur&&cur->_left)
		{
			cur = cur->_left;
		}
		return iterator(cur);
	}
	iterator end()
	{
		return iterator(nullptr);
	}
	typedef BTtreenode<v> node;
	void inorder()
	{
		_inorder(_root);
	}
	bool insert(const v& data)
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
			if (Kot(cur->_data) > Kot(data))
			{
				parent = cur;
				cur = cur->_left;

			}
			else if (Kot(cur->_data) < Kot( data))
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
		if (Kot(parent->_data )> Kot(data))
		{
			parent->_left = newnode;
		}
		else if(Kot(parent->_data) < Kot(data))
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
	node* find(const k& value)
	{
		node* cur = _root;
		while (cur)
		{
			if (Kot(cur->_data) > value)
			{
				cur = cur->_left;
			}
			else if (Kot(cur->_data) < value)
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
	KeyofT Kot;
};


