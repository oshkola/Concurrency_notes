#include <chrono>
#include <iostream>
#include <thread>

int getSum(int a, int b)
{
	std::cout << "******GETSUM STARTED******" << std::endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	std::cout << "******GETSUM FINISHED******" << std::endl;

	return a + b;
}


int main()
{
	int result;

	std::thread th1([&result]()
	{
	    result = getSum(2,5);
	});

	th1.join();

	std::cout << "result from main:  = " << result << std::endl;
}
