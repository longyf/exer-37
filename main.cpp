#include <iostream>
#include "BinaryTreeNode.h"
//#include "Serialize.h"
#include "Deserialize.h"
#include <memory>
#include <string>
using namespace std;

void print(BinaryTreeNode *pRoot) {
	if (pRoot != nullptr) {
		print(pRoot->m_pLeft);
		cout<<pRoot->m_nValue<<" ";
		print(pRoot->m_pRight);
	}
}

int main() {
/*	shared_ptr<BinaryTreeNode> p1 = make_shared<BinaryTreeNode> (BinaryTreeNode(1));
	shared_ptr<BinaryTreeNode> p2 = make_shared<BinaryTreeNode> (BinaryTreeNode(2));
	shared_ptr<BinaryTreeNode> p3 = make_shared<BinaryTreeNode> (BinaryTreeNode(3));
	shared_ptr<BinaryTreeNode> p4 = make_shared<BinaryTreeNode> (BinaryTreeNode(4));
	shared_ptr<BinaryTreeNode> p5 = make_shared<BinaryTreeNode> (BinaryTreeNode(5));
	shared_ptr<BinaryTreeNode> p6 = make_shared<BinaryTreeNode> (BinaryTreeNode(6));
	p1->m_pLeft = p2;
	p1->m_pRight = p3;
	p2->m_pLeft = p4;
	p3->m_pLeft = p5;
	p3->m_pRight = p6;

	Serialize(p1);
	cout<<endl;*/

	string fileName = "test.txt";

	ifstream fileIn;
	fileIn.open(fileName);
	char ch;
	while (!fileIn.eof()) {
		fileIn>>ch;
		cout<<ch;
	}
	fileIn.close();
	cout<<endl;
	
	ifstream fileIn2;
	fileIn2.open(fileName);
	BinaryTreeNode *pNewRoot = nullptr;
	Deserialize(&pNewRoot, fileIn2);
	fileIn2.close();
	print(pNewRoot);
	return 0;
}
