#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, result = 9999;
vector<pair<int, int>> xychicken;
bool opencheck[14];
vector<pair<int, int>> xyhouse;
const int blank = 0;
const int house = 1;
const int chicken = 2;

int distance(int housex, int housey)
{
	int temp = 9999;

	for (int i = 0; i < xychicken.size(); i++)
	{
		if (opencheck[i] == true)
		{
			temp = min(temp, abs(housey - xychicken[i].second) + abs(housex - xychicken[i].first));
		}
	}

	return temp;
}

void checkmin(int num)
{
	if (num == M)
	{
		int temp = 0;

		for (int i = 0; i < xyhouse.size(); i++)
		{
			temp += distance(xyhouse[i].first, xyhouse[i].second);
		}

		result = min(temp, result);
		return;
	}

	for (int i = 0; i < xychicken.size(); i++)
	{
		if (opencheck[i] == false)
		{
			opencheck[i] = true;
			checkmin(num + 1);
			opencheck[i] = false;
		}
	}

}

int main()
{
	cin >> N >> M;
	int mapcheck;
	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			cin >> mapcheck;
			if (mapcheck == house)
				xyhouse.push_back(make_pair(x, y));
			else if (mapcheck == chicken)
				xychicken.push_back(make_pair(x, y));
		}
	}

	for (int i = 0; i < 14; i++)
		opencheck[i] = false;
	checkmin(0);

	cout << result << endl;
}