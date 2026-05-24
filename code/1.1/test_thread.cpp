#include <iostream>
#include <thread>

void func(int x) {
	std::cout << "Param: " << x << '\n'; 
}

int main() {
	
	std::thread t1(func, 10);
	
	std::thread t2([](int a, int b){
		std::cout << "Sum: " << a + b << '\n';
	}, 1, 2);
	
	t1.join();
	t2.join();
	
	return 0;
	
}