/*
#include <queue>
#include <iostream>

class Queue {
private:
	std::queue<int> q;

public:
	void enqueue(int value) {
		q.push(value);
	}

	int dequeue() {
		if (!q.empty()) {
			int val = q.front();
			q.pop();
			return val;
		}
		return -1; //return -1 if the queue is empty
	}
};

int main() {
	Queue q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(87);
	q.dequeue();

	std::cout << q.dequeue() << std::endl; //20
	std::cout << q.dequeue() << std::endl; //87

	return 0;
}
*/
