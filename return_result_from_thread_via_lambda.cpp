#include <chrono>
#include <iostream>
#include <thread>

int getSum(int a, int b)
{
	std::cout << "******CHANGEINPUT STARTED****** \n";

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	std::cout << "******DOWORK() FINISHED****** \n";

	return a + b;
}


int main()
{
	int result;

	auto f = [&result](){ result = getSum(5,7); };

	std::thread th1(f);

	th1.join();

	std::cout << "result from main:  = " << result << "\n";
}
