#include "Serializer.hpp"
#include <iomanip>
#include <iostream>

int main(void)
{
	//uncoment above, it will not compile, class not initializable
	//Serializer lets_try;

	// DATA INITALIZE
	Data* original = new Data;
	original->name = "Osvald";
	original->age = 42;
	original->height = 1.60;
	original->weight = 75;
	original->job = "agricultural engineer";
	uintptr_t uint_saved_ptr = 0;
	Data* recovered = NULL;

	// SHOW BEFORE STORE POINTER IN UINT_PTR_T
	std::cout << "\nOriginal PTR: "
		<< original->name << " has "
		<< original->age << " years and has "
		<< original->height << "m height, with "
		<< original->weight << "kg, and works as "
		<< original->job << ".\n\n";

	std::cout << std::setw(20) << "original ptr:" 
		<< std::setw(20) << original << "\n\n";

	uint_saved_ptr = Serializer::serialize(original);
	
	std::cout << std::setw(20) << "uint_saved_ptr:" 
		<< std::setw(20) << uint_saved_ptr << "\n";
	std::cout << std::setw(20) << "uint_saved_ptr HEX:" 
		<< std::hex << std::setw(20) 
		<< uint_saved_ptr << std::dec << "\n\n";

	recovered = Serializer::deserialize(uint_saved_ptr);

	// SHOW AFTER OTHER RECOVER POINTER BACK
	std::cout << std::setw(20) <<  "recovered ptr:" 
		<< std::setw(20) << recovered << "\n\n";

	std::cout << "Recovered PTR: "
		<< recovered->name << " has "
		<< recovered->age << " years and has "
		<< recovered->height << "m height, with "
		<< recovered->weight << "kg, and works as "
		<< recovered->job << ".\n\n";

	delete original;

	return 0;
}
