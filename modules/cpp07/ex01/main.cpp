#include "iter.hpp"
#include <iostream>

template<typename Whatever>
void printElement(const Whatever& what_comes)
{
    std::cout << what_comes << " ";
}

template<typename Whatever>
void doubleValue(Whatever& what_comes)
{
    what_comes *= 2;
}

void uppercaseChar(char& c)
{
    c = std::toupper(static_cast<unsigned char>(c));
}

int main( void )
{
	std::cout << "\n===== Test 1: Integer array ======\n";
	int intArr[] = {1, 2, 3, 4, 5};
	size_t intLen = sizeof(intArr) / sizeof(intArr[0]);

	std::cout << "Original array: ";
	::iter(intArr, intLen, printElement<int>);

	::iter(intArr, intLen, doubleValue<int>);

	std::cout << "\nAfter doubling: ";
	::iter(intArr, intLen, printElement<int>);
	std::cout << "\n";


	std::cout << "\n====== Test 2: Float array =======\n";
	float floatArr[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	size_t floatLen = sizeof(floatArr) / sizeof(floatArr[0]);

	std::cout << "Original array: ";
	iter(floatArr, floatLen, printElement<float>);

	iter(floatArr, floatLen, doubleValue<float>);

	std::cout << "\nAfter doubling: ";
	iter(floatArr, floatLen, printElement<float>);
	std::cout << "\n";


	std::cout << "\n====== Test 3: String array =======\n";
        std::string str = "hello";
	size_t len = str.length();

	std::cout << "Original array: ";
	iter(str, len, printElement<char>);

	iter(str, len, uppercaseChar);

	std::cout << "\nAfter uppercase: ";
	iter(str, len, printElement<char>);
	std::cout << "\n\n";

	return 0;
}
