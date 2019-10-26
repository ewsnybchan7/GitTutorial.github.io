#include <iostream>
#include <list>
using namespace std;

list<int> people;
list<int>::iterator pos;

int main()
{
	int N, K;
	cin >> N >> K;

	for(int i=0; i<=N; i++)
		people.push_back(i);

	pos = people.begin();
	cout << "<";
	while (1)
	{
		for (int i = 0; i < K; i++)
		{
			if (pos == (--people.end()))
				pos = (++people.begin());
			else
				pos++;
		}

		int temp = *pos;
		pos = people.erase(pos);
		pos--;
		if (people.size() == 1)
		{
			cout << temp << ">";
			break;
		}
		else cout << temp << ", ";
	}
}