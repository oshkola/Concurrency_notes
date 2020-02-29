#include <iostream>
#include <unistd.h>
#include <thread>

void doWork()
{
	std::cout << "******DOWORK STARTED****** \n";

	for (int i = 1; i <= 20; i++)
	{
		std::cout << "doWork(): \t" << i << "\n";
		usleep(1000000);
	}

	std::cout << "******DOWORK() FINISHED****** \n";
}

int main()
{
	std::thread th1(doWork);

	for (int i = 1; i <= 20; i++)
	{
		std::cout << "main(): \t" << i << "\n";
		usleep(500000);
	}
	
	th1.join();
}
