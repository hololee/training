#include <iostream>

using namespace std;

int main(void)
{
	// pointer test.
	int a = 1234;

	int *pointer = &a;

	while (1)
	{

		// 계속 입력 받기.
		std::cin >> a;

		std::cout << "output : " << a << "\n";
		std::cout << "output : " << pointer << "\n";
		std::cout << "output : " << *pointer << "\n";
	}

	return 0;
}
