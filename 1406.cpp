#include <iostream>
#include <list>
using namespace std;
// ���� 1406�� ����
// ����Ʈ�� Ȱ���� Ŀ�� �̵� ����

int main()
{
	char a;
	list<char> line;
	list<char>::iterator pos;
	int N;

	while (1)
	{
		cin.get(a);
		if (a == '\n') break;
		else line.push_back(a);
	}
	
	cin >> N;

	pos = line.end();

	for (int i = 0; i < N; i++)
	{
		cin >> a;

		switch (a)
		{
		case 'P': // �ش� Ŀ���� ���ڸ� �߰��Ѵ�
			cin >> a;
			line.insert(pos, a);
			break;
		case 'L': // Ŀ���� �������� �ű��
			if (pos == line.begin())
				break;
			--pos;
			break;
		case 'D': // Ŀ���� �������� �ű��
			if (pos == line.end())
				break;
			++pos;
			break;
		case 'B': // �ش� Ŀ���� �ִ� ���ڸ� �����Ѵ�
			if (pos == line.begin())
				break;
			pos = line.erase(--pos);
			break;
		default:
			break;
		}
	}

	for (pos = line.begin(); pos != line.end(); ++pos)
	{
		cout << *pos;
	}
}