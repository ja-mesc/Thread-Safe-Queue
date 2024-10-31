//like queue.cpp but now thread safe by using std::mutex
//this protects the enqueue and dequeue methods ensuring that only one thread can modify the queue at a time
/*

#include <queue>
#include <mutex>
#include <iostream>

class ThreadSafeQueue {
private:
	std::queue<int> q;
	std::mutex mtx;

public:
	void enqueue(int value) {
		std::lock_guard<std::mutex> lock(mtx); //locks mutex
		q.push(value);
	}

	int dequeue() {
		std::lock_guard<std::mutex> lock(mtx); //lock mutex
		if (!q.empty()) {
			int val = q.front();
			q.pop();
			return val;
		}
		return -1; //if queue is empty return -1
	}
};

int main() {
	ThreadSafeQueue q;
	q.enqueue(10);
	q.enqueue(20);

	std::cout << q.dequeue() << std::endl; //10
	std::cout << q.dequeue() << std::endl; //20

	return 0;
}
*/
