#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;

void print(char smb)
{
std::this_thread::sleep_for(
		std::chrono::milliseconds(2000));

std::unique_lock<std::mutex> ulock(mtx);

for(int i = 0; i < 5; i++)
{
	for(int i = 0; i < 10; i++)
	{
		std::cout << smb;
		std::this_thread::sleep_for(
		std::chrono::milliseconds(10));
	}
std::cout << "\n";
}
ulock.unlock();
std::this_thread::sleep_for(
		std::chrono::milliseconds(2000));

}

int main()
{
	std::thread th1(print, '*');
	std::thread th2(print, '#');

	th1.join();
	th2.join();
}



