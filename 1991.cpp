#include <iostream>
using namespace std;

BTreeNode nodes[26];

class BTreeNode {
private:
	char data;
	BTreeNode* left;
	BTreeNode* right;
public:
	BTreeNode()
	{
		data = 0;
		left = NULL;
		right = NULL;
	}
	char getData() { return data; }
	void setData(char data) { this->data = data; }
	BTreeNode* getLeftSubTree() { return left; }
	BTreeNode* getRightSubTree() { return right; }

	void makeLeftSubTree(BTreeNode* sub)
	{
		if (this->left != NULL)
			delete left;

		left = sub;
	}

	void makeRightSubTree(BTreeNode* sub)
	{
		if (this->right != NULL)
			delete right;

		right = sub;
	}
};

void makeNode(char root, char left, char right)
{
	nodes[root - 65].setData(root);
	if (left != '.')
		nodes[root - 65].makeLeftSubTree(&nodes[left - 65]);
	if (right != '.')
		nodes[root - 65].makeRightSubTree(&nodes[right - 65]);
}

void InorderTraverse(BTreeNode* bt)
{
	if (bt == NULL)
		return;
	

	InorderTraverse(bt->getLeftSubTree());
	cout << bt->getData();
	InorderTraverse(bt->getRightSubTree());
}

void PreorderTraverse(BTreeNode* bt)
{
	if (bt == NULL)
		return;

	cout << bt->getData();
	PreorderTraverse(bt->getLeftSubTree());
	PreorderTraverse(bt->getRightSubTree());
}

void PostorderTraverse(BTreeNode* bt)
{
	if (bt == NULL)
		return;

	PostorderTraverse(bt->getLeftSubTree());
	PostorderTraverse(bt->getRightSubTree());
	cout << bt->getData();
}

int main()
{
	int N;
	char root, left, right;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> root >> left >> right;
		makeNode(root, left, right);
	}
	
	PreorderTraverse(&nodes[0]);
	cout << '\n';
	InorderTraverse(&nodes[0]);
	cout << '\n';
	PostorderTraverse(&nodes[0]);

	return 0;
}