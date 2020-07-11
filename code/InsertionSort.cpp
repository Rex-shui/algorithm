#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> v);
void insertionSort(vector<int> v);

int main()
{
	vector<int> v = { 5,4,3,2,1,7,6,9,8 };
	insertionSort(v);
	return 0;
}

void insertionSort(vector<int> v)
{
	int len = v.size();
	int i, key, j;

	for (i = 1; i < len; i++) {		//将i=0的位置当作一个有序数列
		key = v[i];					//当前要插入的记录
		j = i - 1;					//从0~i-1中寻找key的正确插入位置

		while (j >= 0 && key < v[j]) {
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = key;
	}

	print(v);
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
/***********************************
优化-使用二分查找的插入排序
可以先用二分查找找出key在有序序列中的正确位置
后移
将key放入正确位置
***********************************/
