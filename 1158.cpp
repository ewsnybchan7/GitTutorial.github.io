#include <iostream>
#include <list>
using namespace std;
// 백준 1158번 문제
// 리스트를 활용한 알고리즘
// 사람들이 원형으로 있을 때, N번째 사람마다 사람이 없어질 경우
// 어떤 순서로 빠져나갈지 출력하는 알고리즘 문제

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