#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << std::endl
		<< YELLOW << "################## Subject example ###################"
		<< RESET << std::endl << std::endl;
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		std::cout << std::endl;

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << meta->getType() << " " << std::endl;
		
		i->makeSound(); //will output the cat sound!
		j->makeSound(); //will output the dog sound
		meta->makeSound();
		
		std::cout << std::endl;

		delete j;
		delete i;
		delete meta;
	}

	std::cout << std::endl
		<< YELLOW << "################## Wrong Class example ###################"
		<< RESET << std::endl << std::endl;
	{
		const WrongAnimal* meta = new WrongAnimal();
		std::cout << std::endl;
			
		const Animal* j = new Dog();
		std::cout << std::endl;
		
		const WrongAnimal* i = new WrongCat();
		std::cout << std::endl;

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << meta->getType() << " " << std::endl;
		
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		
		std::cout << std::endl;

		delete j;
		std::cout << std::endl;
		delete i;
		std::cout << std::endl;
		delete meta;
	}
	return 0;
}
