/*

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
int counter = 0;


void increment(int n) { //only one thread at a time can increment n due to mutex locking
	for (int i = 0; i < n; ++i) {
		std::lock_guard<std::mutex> lock(mtx); //lock the mutex
		++counter;
		//std::cout << "Thread " << std::this_thread::get_id() << " prints " << counter << std::endl;
		//notice how the threads run smoothly, without screwing with eachother.
		//we are synchronising access to shared data in a way that prevents race conditions
	}
}

int main() {
	

	std::thread t3(increment, 5);
	std::thread t4(increment, 5);

	
	t3.join();
	t4.join();

	std::cout << "Final Counter: " << counter << std::endl;

	return 0;

}

*/