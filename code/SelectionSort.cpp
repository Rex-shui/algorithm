#include <iostream>
#include <vector>
using namespace std;

//选择排序
//1、选择最小（最大）
//2、交换

void swap(int &x, int &y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

void print(vector<int> v);

void selectionSort(vector<int> v);

int main()
{
	vector<int> v = { 1,5,6,2,8,4 };
	selectionSort(v);

	return 0;
}

void print(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

void selectionSort(vector<int> v)
{
	int len = v.size();

	int i, j, min_idx;

	for (i = 0; i < len - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < len; j++)
		{
			if (v[j] < v[min_idx])
				min_idx = j;
		}
		swap(v[i], v[min_idx]);

		print(v);
	}
	
}
