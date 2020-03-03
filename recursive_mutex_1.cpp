#include <iostream>
#include <thread>
#include <chrono>

void decreaseValue(int a)
{
    
std::cout << a << " " << std::endl;

std::this_thread::sleep_for(std::chrono::milliseconds(200));


if (a <= 1)
{
	std::cout << "\n";
	return;
}
--a;

decreaseValue(a);
}

int main()
{
	std::thread th1(decreaseValue, 10);

	std::thread th2(decreaseValue, 10);

	th1.join();
	th2.join();
}
