#include <chrono>
#include <iostream>
#include <thread>

class myClass
{
public:

void doWork()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));

	std::cout << "**********DOWORK STARTED**********" << std::endl;

	std::cout << "Id of the thread : " << std::this_thread::get_id() << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));

	std::cout << "**********DOWORK FINISHED**********" << std::endl;
}

void doWork2(int a)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));

	std::cout << "**********\t DOWORK2 STARTED \t**********" << std::endl;

	std::cout << "Id of the thread : " << std::this_thread::get_id() << std::endl;
	std::cout << "parameter value : " << a << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    
	std::cout << "**********\t DOWORK2 FINISHED \t**********" << std::endl;
}

int getSum(int a, int b)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));

	std::cout << "**********\t GETSUM STARTED \t**********" << std::endl;

	std::cout << "Id of the thread : " << std::this_thread::get_id() << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    
	std::cout << "**********\t GETSUM FINISHED \t**********" << std::endl;

	return a+b;
}

};

int main()
{
	myClass m;


	//approach 1
	std::thread th1([&]()
		{
			m.doWork();
		});

	//approach 2
	//std::thread th1(&myClass::doWork, m);

	for(int i = 1; i <= 10; i++)
	{
		std::cout << " id of the thread: " << std::this_thread::get_id() << "\t main works \t" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}


	th1.join();
}
