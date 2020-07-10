#include <iostream>
#include <vector>
using namespace std;

void swap(int &i, int &j)
{
	int temp;
	temp = i;
	i = j;
	j = temp;
}

void print(vector<int> v)
{
	int len = v.size();
	for (int i = 0; i < len; i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

//普通的冒泡排序
void sort(vector<int> v);

//优化-当数组已经为有序的情况
void sort2(vector<int> v);

//优化*2-后半段为有序的情况
void sort3(vector<int> v);

int main()
{
	vector<int> v = { 5,4,3,2,1,7,6,9,8 };
	sort(v);	//循环36次，8+7+...+1=（8+1）*8/2=36
	sort2(v);	//循环30次，8+7+6+5+4=30
	sort3(v);	//循环18次

	return 0;
}

//O(n^2)
void sort(vector<int> v)
{
	int count = 0;
	int len = v.size();
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			count++;
			if (v[j] > v[j + 1])
			{
				swap(v[j], v[j + 1]);
			}
		}
	}
	cout << "循环次数:" << count << endl;
	print(v);
}

void sort2(vector<int> v)
{
	int count = 0;
	int len = v.size();
	bool swapped;

	for (int i = 0; i < len - 1; i++)
	{
		swapped = false;
		for (int j = 0; j < len - i - 1; j++)
		{
			count++;
			if (v[j] > v[j + 1])
			{
				swap(v[j], v[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
	cout << "循环次数:" << count << endl;
	print(v);
}

void sort3(vector<int> v)
{
	int count = 0;
	int len = v.size();
	bool swapped;
	int lastSwappedIndex = 0;
	int sortBorder = len - 1;

	for (int i = 0; i < len - 1; i++)
	{
		swapped = false;
		for (int j = 0; j < sortBorder; j++)
		{
			count++;
			if (v[j] > v[j + 1])
			{
				swap(v[j], v[j + 1]);
				swapped = true;
				lastSwappedIndex = j;
			}
		}
		sortBorder = lastSwappedIndex;
		if (swapped == false)
			break;
	}
	cout << "循环次数:" << count << endl;
	print(v);
}

