#include <iostream>
using namespace std;
// 백준 알고리즘 1991번 문제
// 이진 트리를 이용하여 후위 탐색, 전위 탐색, 중위 탐색을 하는 알고리즘

BTreeNode nodes[26];

class BTreeNode {
private:
	char data;
	BTreeNode* left; // 좌측 노드
	BTreeNode* right; // 우측 노드
public:
	BTreeNode()
	{
		data = 0;
		left = NULL;
		right = NULL;
	}
	char getData() { return data; }
	void setData(char data) { this->data = data; }
	BTreeNode* getLeftSubTree() { return left; } // 좌측 서브트리를 연결
	BTreeNode* getRightSubTree() { return right; } // 우측 서브트리를 연결

	void makeLeftSubTree(BTreeNode* sub)
	{
		if (this->left != NULL)
			delete left;

		left = sub;
	} // 새로운 좌측 서브트리를 생성

	void makeRightSubTree(BTreeNode* sub)
	{
		if (this->right != NULL)
			delete right;

		right = sub;
	} // 새로운 좌측 서브트리를 생성
}; // 이진트리 클래스

void makeNode(char root, char left, char right)
{
	nodes[root - 65].setData(root);
	if (left != '.')
		nodes[root - 65].makeLeftSubTree(&nodes[left - 65]);
	if (right != '.')
		nodes[root - 65].makeRightSubTree(&nodes[right - 65]);
} // 특정 상황에 맞게 노드에 정보를 대입하는 함수

void InorderTraverse(BTreeNode* bt)
{
	if (bt == NULL)
		return;
	

	InorderTraverse(bt->getLeftSubTree());
	cout << bt->getData();
	InorderTraverse(bt->getRightSubTree());
} // 중위 탐색

void PreorderTraverse(BTreeNode* bt)
{
	if (bt == NULL)
		return;

	cout << bt->getData();
	PreorderTraverse(bt->getLeftSubTree());
	PreorderTraverse(bt->getRightSubTree());
} // 전위 탐색

void PostorderTraverse(BTreeNode* bt)
{
	if (bt == NULL)
		return;

	PostorderTraverse(bt->getLeftSubTree());
	PostorderTraverse(bt->getRightSubTree());
	cout << bt->getData();
} // 후위 탐색

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