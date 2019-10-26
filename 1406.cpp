#include <iostream>
#include <list>
using namespace std;
// 백준 1406번 문제
// 리스트를 활용한 커서 이동 문제

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
		case 'P': // 해당 커서에 문자를 추가한다
			cin >> a;
			line.insert(pos, a);
			break;
		case 'L': // 커서를 좌측으로 옮긴다
			if (pos == line.begin())
				break;
			--pos;
			break;
		case 'D': // 커서를 우측으로 옮긴다
			if (pos == line.end())
				break;
			++pos;
			break;
		case 'B': // 해당 커서에 있는 문자를 삭제한다
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