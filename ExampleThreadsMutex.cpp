
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>


std::mutex mtx;

void sum_products(int first_limit, int second_limit)
{
	mtx.lock();
	long long sum = 0;
	for(int a = 1; a != first_limit; a ++)
		for(int b = 1; b != second_limit; b++)
			sum += a * b;
	std::cout<<"Sum of products: "<<sum<<std::endl;
	mtx.unlock();
}

int main()
{
	const unsigned a = 3;
	const unsigned b = 300;
	std::vector<std::thread> vector_threads;
	unsigned number_threads;
	std::cout<<"Number of function call ";
	std::cin>>number_threads;
	for(unsigned t_id = 0 ; t_id != number_threads; t_id++)
	{
		vector_threads.push_back(std::thread(sum_products, a, b));
	}


	for(auto &th : vector_threads)
		th.join();
	return 0;
}



