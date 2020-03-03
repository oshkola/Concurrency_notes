#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

std::mutex mtx;

void decreaseValue(int a)
{

mtx.lock();

std::cout << a << " " << std::endl;

std::this_thread::sleep_for(std::chrono::milliseconds(200));


if (a <= 1)
{
	std::cout << "\n";
	mtx.unlock();
	return;
}
--a;

decreaseValue(a);
mtx.unlock();
}


int main()
{
	std::thread th1(decreaseValue, 10);
	std::thread th2(decreaseValue, 10);

	th1.join();
	th2.join();
}
