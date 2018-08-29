#ifndef DESERIALIZE_H
#define DESERIALIZE_H
#include <iostream>
#include <fstream>
#include <memory>
#include "BinaryTreeNode.h"
using namespace std;
bool ReadStream(istream &stream, int *number) {
	if (stream.eof())
		return false;

	char buffer[32];
	buffer[0] = '\0';

	char ch;
	stream>>ch;
	int i = 0;
	while (!stream.eof() && ch != ',') {
		buffer[i++] = ch;
		stream>>ch;
	}

	bool isNumeric = false;
	if (i > 0 && buffer[0] != '$') {
		*number = atoi(buffer);
		isNumeric = true;
	}

	return isNumeric;
}

void Deserialize(BinaryTreeNode **pRoot, istream &stream) {
	int number;
	if (ReadStream(stream, &number)) {
		*pRoot = new BinaryTreeNode();
		(*pRoot)->m_nValue = number;

		Deserialize(&((*pRoot)->m_pLeft), stream);
		Deserialize(&((*pRoot)->m_pRight), stream);
	}
}

#endif
