#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>

class ThreadSafeQueue {
private:
	std::queue<int> q;
	std::mutex mtx;
	std::condition_variable convar;
	//this notifies threads when they can and cannot process certain data, which saves CPU time since the threads do not have to perform continuous checks
public:
	void enqueue(int value) {
		{
			std::lock_guard<std::mutex> lock(mtx);
			q.push(value);
		}
		convar.notify_one(); //notify waiting threads that this function is available
	}

	int dequeue() { 
		
		std::unique_lock<std::mutex> lock(mtx); //this lock can be triggered by the wait mechanism below
		convar.wait(lock, [this] {return !q.empty(); }); //waits for the queue to be non-empty
		
		int val = q.front();
		q.pop();
		return val;
	}
};

ThreadSafeQueue queue;
std::mutex cout_mtx; //a mutex to ensure that the threads remain concurrent during output

void producer(int id) {
	for (int i = 0; i < 5; ++i) {
		queue.enqueue(i + 10 * id);

		std::lock_guard<std::mutex> lock(cout_mtx);
		std::cout << "Producer " << id << " enqueued " << i + 10 * id << std::endl;
	}
}

void consumer(int id) {
	for (int i = 0; i < 5; ++i) {
		int val = queue.dequeue();

		std::lock_guard<std::mutex> lock(cout_mtx);
		std::cout << "Consumer " << id << " dequeued " << val << std::endl;
	}
}

int main() {

	std::thread t1(producer, 1);
	std::thread t2(producer, 2);
	std::thread t3(consumer, 1);
	std::thread t4(producer, 3);
	std::thread t5(consumer, 2);
	std::thread t6(consumer, 3);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();

	return 0;
}