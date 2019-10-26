#include <iostream>
using namespace std;
// ���� �˰��� 1920�� ����
// ���� ���� �˰��� ����

void MergeCombine(int arr[], int left, int mid, int right)
{
	int Lidx = left; // ���� �迭 index
	int Ridx = mid + 1; // ������ �迭 index
	int Sidx = left; //sortArr�� index

	int* sortArr = new int[right + 1];

	while (Lidx <= mid && Ridx <= right) // �ӽ� �迭���ٰ� ������ ���� �־��ش�
	{
		if (arr[Lidx] <= arr[Ridx])
			sortArr[Sidx] = arr[Lidx++];
		else
			sortArr[Sidx] = arr[Ridx++];

		Sidx++;
	}

	if (Lidx > mid) // ���� �迭�� �� �־����� ������ �迭�� ���� ���� �ӽ� �迭���ٰ� �ִ´�
	{
		for (int i = Ridx; i <= right; i++, Sidx++)
			sortArr[Sidx] = arr[i];
	}
	else // ������ �迭�� �� �־����� ���� �迭�� ���� ���� �ӽ� �迭���ٰ� �ִ´�
	{
		for (int i = Lidx; i <= mid; i++, Sidx++)
			sortArr[Sidx] = arr[i];
	}

	for (int i = left; i <= right; i++)
		arr[i] = sortArr[i];

	delete[] sortArr;
}

void MergeSort(int arr[], int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;

		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		MergeCombine(arr, left, mid, right);
	}
}

void BSearch(int arr[], int len, int target)
{
	int first = 0;
	int last = len - 1;
	int mid;

	while (first <= last)
	{
		mid = (first + last) / 2;

		if (target == arr[mid])
		{
			cout << 1 << '\n';
			return;
		}
		else
		{
			if (target < arr[mid])
				last = mid - 1;
			else
				first = mid + 1;
		}
	}

	cout << 0 << '\n';
}

int main()
{
	int N, M, num;
	int A[100000];

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	MergeSort(A, 0, N - 1);

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> num;
		BSearch(A, N, num);
	}
}