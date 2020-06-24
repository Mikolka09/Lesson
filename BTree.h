#pragma once

template<class TKey, class TVal>
class BTreeNode
{
public:
	TKey key;
	TVal value;

	BTreeNode *left = nullptr;
	BTreeNode *right = nullptr;

	BTreeNode(TKey key, TVal val) : key(key), value(val) {}

	void print()
	{
		if (left != nullptr) left->print();
		cout << value << " ";
		if (right != nullptr) right->print();
	}

	TVal* get(TKey &key)
	{
		if (key == this->key) return &value;
		if (key < this->key && left != nullptr) return left->get(key);
		if (key > this->key && right != nullptr) return right->get(key);
	}

};


template<class TKey, class TVal>
class BTree
{
public:
	BTreeNode<TKey, TVal> *root = nullptr;

	bool isEmpry()
	{
		return root;
	}

	void print()
	{
		if (root)
			root->print();
		else
			cout << "Tree Empty!" << endl;

	}

	TVal*get(TKey &key)
	{
		if (root)
			return root->get(key);
		return nullptr;
	}

	bool push(TKey key, TVal val)
	{
		if (!root)
		{
			root = new BTreeNode<TKey, TVal>(key, val);
			return true;
		}
		bool working = true;
		BTreeNode<TKey, TVal> *next = root;
		do
		{
			//go left
			if (key < next->key)
			{
				if (next->left)
				{
					next = next->left;
				}
				else
				{
					next->left = new BTreeNode<TKey, TVal>(key, val);
					working = false;
				}
			} //go right
			else if (key>next->key)
			{
				if (next->right)
				{
					next = next->right;
				}
				else
				{
					next->right = new BTreeNode<TKey, TVal>(key, val);
					working = false;
				}
			}
			else
			{
				return false;
			}
		} while (working);
		return true;
	}

	/*bool push_r(TKey key, TVal val)
	{
		if (!root)
		{
			root = new BTreeNode<TKey, TVal>(key, val);
			return true;
		}
		else if(key<root->key)
		{
			this->
		}
	}*/
};
