// bitree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "BiTree.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	BiTree A;
	int a=0;
	while(1)
	{
		std::cin>>a;
		if(a==-1) break;
		A.insert(A.root,a);

	}
	A.inorder(A.root);

	int reuslt;
	int RET = A.findParent2(A.root, 4, 5, reuslt);

	cout << "THE RET IS" << RET << endl;
	cout << "THE REsultT IS " << reuslt << endl;
	int depth;
	cout << "balancer" << A.isBalanced(A.root, depth) << endl;
	cout << "depth" << depth << endl;
	return 0;
}

