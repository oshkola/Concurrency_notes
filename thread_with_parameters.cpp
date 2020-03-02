#include <chrono>
#include <iostream>
#include <unistd.h>
#include <thread>


void doWork(int a, int b)
{
	std::cout << "******DOWORK STARTED****** \n";

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	std::cout << "doWork(): thread id = " << std::this_thread::get_id() << "\n";

	std::cout << "a + b = " << a + b << "\n";

	std::cout << "******DOWORK() FINISHED****** \n";
}


int main()
{
	int a = 7, b = 8;

	std::thread th1(doWork, a, b);

	std::cout << "main: thread id = " << std::this_thread::get_id() << "\n";
	for (int i = 1; i <= 20; i++)
	{
		std::cout << "main(): \t" << i << "\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	th1.join();
}
