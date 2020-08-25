#include <iostream>
using namespace std;

class CirQueue {
private:
	int arr[20];
	int front;
	int rear;
	int count;
public:
	bool isEmpty(){
		if(0 == count) return true;
		return false;
	}
	bool isFull() {
		if(20 == count) return true;
		return false;
	}
	int elements(){
		//return (rear + 20 - front) % 20;	//需要牺牲一个元素
		return count;
	}
	CirQueue() {
		front = 0;
		rear = 0;
		count = 0;
	}
	void add(int data){
		if(isFull()) {
			cout << "Queue is full" << endl;
			return;
		}
		arr[rear] = data;
		rear = (rear + 1) % 20;
		++count;
	}
	int del() {
		if(isEmpty()) return -1;
		int del = arr[front];
		arr[front] = 0;
		front = (front + 1) % 20;
		--count;
		return del;
	}
	int getFront(){
		return front;
	}
};

int main()
{
	CirQueue c;
	for(int i=0;i<19;i++){
		c.add(10);
	}
	c.add(10);
	c.del();c.del();c.del();c.del();c.del();c.del();c.del();c.del();c.del();
	cout << c.elements() << endl;
	cout << c.getFront() << endl;
	//cout << c.del() << endl;
	//cout << c.del() << endl;
	//cout << c.del() << endl;

	
	system("pause");
	return 0;
}