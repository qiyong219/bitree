//排序二叉树
#include "stdafx.h"
#include <iostream>
using namespace std;
typedef struct node
{
	int data;
	node*left;
	node *right;
	//node *father;
}node,*node_ptr;

class BiTree
{
	
public:
	node_ptr root;
    node_ptr getRoot(){ return root;}  

	bool hasFind1 = false;
	bool hasFind2 = false;
	bool isFirst = true;
	BiTree(){
		root=nullptr;
	}
	void insert(node_ptr &T, int key );
	int preorder(node_ptr);
	int inorder(node_ptr);
	//int postorder(node **);
	int findValue(node_ptr T, int value1, int value2);
	int findParent(node_ptr, int, int);
	int findParent2(node_ptr, int, int,int&);
	bool isBalanced(node *T, int &depth);
};

 void BiTree::insert(node_ptr &T, int key )//T为二叉树根节点
{
	if(T==nullptr){
		T=new node;
		T->data=key;
		T->left = nullptr;
		T->right = nullptr;
	}
	else if(key < T->data){
		insert(T->left, key );
	}
	else{
		insert(T->right, key );
	}
}

int BiTree::preorder(node *tree)
{
	if(tree==nullptr)
	{
		return 0;
	}
	else
	{
		std::cout<<tree->data<<" ";
		preorder(tree->left);
		preorder(tree->right);
	}
}
int BiTree::inorder(node *T)
{
	if(T==nullptr)
	{
		return 0;
	}
	else{
		inorder(T->left);
		std::cout<<T->data<<std::endl;
		inorder(T->right);

	}
}

int BiTree::findParent(node_ptr T, int value1, int value2)
{
	if (T == nullptr) return -1;
	if (T->data == value1 || T->data == value2) return T->data;
	int cnt;
	cnt = findValue(T->left, value1, value2);
	if (cnt == 1) return T->data;
	else if (cnt==2) 
		findParent(T->left, value1, value2);
	else findParent(T->right, value1, value2);
}

int BiTree::findParent2(node_ptr T, int value1, int value2,int &result)
{
	int tmp;
	if (T == nullptr) return -1;
	
	tmp = findParent2(T->left, value1, value2, result);
	if (hasFind1&&hasFind2) {
		return tmp;
	}

	tmp = findParent2(T->right, value1, value2, result);
	if (hasFind1&&hasFind2) {
		return tmp;
	}


	if (T->data == value1){
		hasFind1 = true;
		cout << "has find first" << endl;
	}
	if (T->data == value2){
		hasFind2 = true;
		cout << "has find second" << endl;
	}
	if (hasFind1&&hasFind2&&isFirst) {
		result = T->data;
		isFirst = false;
		cout << "has find " << result << endl;
	}

	if (hasFind1&&hasFind2) {
		tmp = T->data;
		return tmp;
	}

	return -1;

}


int BiTree::findValue(node_ptr T, int value1, int value2){
	if (T == nullptr) return 0;
	int cnt = 0;
	cnt += findValue(T->left, value1, value2);
	cnt += findValue(T->right, value1, value2);
	if (T->data == value1 || T->data == value2) cnt += 1;
	return cnt;
}


bool BiTree::isBalanced(node *T,int &depth){
	int ldep,rdep;
	if (T == nullptr) {
		depth = 0;
		return true;
	}
	bool islb = isBalanced(T->left, ldep);
	bool isrb = isBalanced(T->right, rdep);
	depth = ldep > rdep ? ldep + 1 : rdep + 1;
	cout << T->data << " DEPTH IS " << depth << endl;
	if (!(islb&&isrb)) return false;
	if (abs(ldep - rdep) > 1) return false;
	else return true;
}