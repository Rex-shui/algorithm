#include <iostream>
#include <vector>
using namespace std;

//log 2 n
int binarySearch(vector<int> v, int key);

int main()
{
	vector<int> v = { 4,5 };

	int loc = binarySearch(v, 5);

	if (loc != -1)
		cout << "key的位置为：v[" << loc << "]" << endl;
	else
		cout << "没有找到该数" << endl;

	return 0;
}

int binarySearch(vector<int> v, int key)
{
	int low = 0;
	int high = v.size() - 1;
	
	while (low <= high) {
		int mid = (low + high) / 2;

		if (v[mid] == key)
			return mid;

		if (v[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}

	return -1;
}
