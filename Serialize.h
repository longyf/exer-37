#ifndef SERIALIZE_H
#define SERIALIZE_H
#include <iostream>
#include "BinaryTreeNode.h"
#include <memory>
using namespace std;

void Serialize(shared_ptr<BinaryTreeNode> pRoot) {
	if (pRoot == nullptr) {
		cout<<"$,";
		return;
	}

	cout<<pRoot->m_nValue<<",";
	Serialize(pRoot->m_pLeft);
	Serialize(pRoot->m_pRight);
}
#endif
