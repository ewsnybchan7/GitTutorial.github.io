#include <iostream>
#include <stack>
#include <queue>
using namespace std;

bool graph[1001][1001];
bool check[1001];
queue<int> q;

void DFS(int start)
{
	check[start] = true;
	cout << start << " ";

	for (int i = 1; i < 1001; i++)
	{
		if (graph[start][i])
		{
			int next_idx = i;

			if (check[next_idx] == false) {
				DFS(next_idx);
			}
		}
	}
}

void BFS()
{
	if (q.empty()) return;
	int temp = q.front();
	q.pop();
	cout << temp << " ";
	check[temp] = true;

	for (int i = 1; i < 1001; i++)
	{
		if (graph[temp][i] && check[i] == false)
		{
			q.push(i);
			check[i] = true;
		}
	}
	BFS();
}

int main()
{
	int N, M, V;
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int start, end;
		cin >> start >> end;
		graph[start][end] = true;
		graph[end][start] = true;
	}

	for (int i = 1; i < N + 1; i++)
	{
		check[i] = false;
	}

	DFS(V);
	cout << endl;

	for (int i = 1; i < N + 1; i++)
	{
		check[i] = false;
	}
	q.push(V);
	BFS();
}