#include <iostream>
#include <list>
using namespace std;

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
		case 'P':
			cin >> a;
			line.insert(pos, a);
			break;
		case 'L':
			if (pos == line.begin())
				break;
			--pos;
			break;
		case 'D':
			if (pos == line.end())
				break;
			++pos;
			break;
		case 'B':
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