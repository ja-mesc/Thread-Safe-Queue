/*
#include <iostream>
#include <thread>


void print_numbers(int n) { //threads run concurrently without mutex
	for (int i = 0; i < n; i++) {
		std::cout << "Thread " << std::this_thread::get_id() << " prints " << i << std::endl;
	}
}



int main() {
	std::thread t1(print_numbers, 5); //starts a thread
	std::thread t2(print_numbers, 5); //starts another thread

	
	t1.join(); //waits for t1 to finish
	t2.join(); //waits for t2 to finish;


	return 0;

}
*/ //notice - you get a total fucking mess!