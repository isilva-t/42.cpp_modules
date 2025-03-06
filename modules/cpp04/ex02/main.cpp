#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << std::endl
		<< YELLOW << "################## Cat Class copy example ###################"
		<< RESET << std::endl << std::endl;
	{
		AAnimal* teddy = new Cat();
		std::cout << std::endl;

		AAnimal* cpy_teddy = new Cat(*dynamic_cast<Cat*>(teddy));
		std::cout << std::endl;

		Cat another_cpy_teddy = *dynamic_cast<Cat*>(teddy);
		std::cout << std::endl;

		Cat* teddy_ptr = dynamic_cast<Cat*>(teddy);
		Cat* cpy_teddy_ptr = dynamic_cast<Cat*>(cpy_teddy);

		teddy->makeSound();
		cpy_teddy->makeSound();
		std::cout << std::endl;
		
		std::cout << "before, teddy idea 5 is: " << teddy_ptr->getIdea(5) << std::endl;
		std::cout << "before, cpy_teddy idea 5 is: " << cpy_teddy_ptr->getIdea(5) << std::endl;
		std::cout << "before, another_cpy_teddy idea 5 is: " << another_cpy_teddy.getIdea(5) << std::endl;
		
		teddy_ptr->setIdea(5, "What happen to 5th idea of teddy?");
		another_cpy_teddy.setIdea(5, "And What happen to 5th idea of another_cpy_teddy?");
		std::cout << std::endl;
		
		std::cout << "and now, teddy idea 5 is: " << teddy_ptr->getIdea(5) << std::endl;
		std::cout << "and now, cpy_teddy idea 5 is: " << cpy_teddy_ptr->getIdea(5) << std::endl;
		std::cout << "and now, another_cpy_teddy idea 5 is: " << another_cpy_teddy.getIdea(5) << std::endl;
		std::cout << std::endl;

		std::cout << "EDGE TESTS for setting/getting ideas" << std::endl;
		teddy_ptr->setIdea(150, "must not set");
		teddy_ptr->setIdea(10, "");
		teddy_ptr->getIdea(-15);
	
		std::cout << std::endl;
		delete teddy;

		std::cout << std::endl;
		delete cpy_teddy;

		std::cout << std::endl;
	}
		std::cout << std::endl;

	std::cout << std::endl
		<< YELLOW << "################## Dog Class copy example ###################"
		<< RESET << std::endl << std::endl;
	{
		AAnimal* bean = new Dog();
		std::cout << std::endl;

		AAnimal* cpy_bean = new Dog(*dynamic_cast<Dog*>(bean));
		std::cout << std::endl;

		Dog another_cpy_bean = *dynamic_cast<Dog*>(bean);
		std::cout << std::endl;

		Dog* bean_ptr = dynamic_cast<Dog*>(bean);
		Dog* cpy_bean_ptr = dynamic_cast<Dog*>(cpy_bean);

		bean->makeSound();
		cpy_bean->makeSound();
		std::cout << std::endl;
		
		std::cout << "before, bean idea 5 is: " << bean_ptr->getIdea(5) << std::endl;
		std::cout << "before, cpy_bean idea 5 is: " << cpy_bean_ptr->getIdea(5) << std::endl;
		std::cout << "before, another_cpy_bean idea 5 is: " << another_cpy_bean.getIdea(5) << std::endl;
		
		bean_ptr->setIdea(5, "What happen to 5th idea of bean?");
		another_cpy_bean.setIdea(5, "And What happen to 5th idea of another_cpy_bean?");
		std::cout << std::endl;
		
		std::cout << "and now, bean idea 5 is: " << bean_ptr->getIdea(5) << std::endl;
		std::cout << "and now, cpy_bean idea 5 is: " << cpy_bean_ptr->getIdea(5) << std::endl;
		std::cout << "and now, another_cpy_bean idea 5 is: " << another_cpy_bean.getIdea(5) << std::endl;
		std::cout << std::endl;

		std::cout << "edge tests for setting/getting ideas" << std::endl;
		bean_ptr->setIdea(-150, "must not set");
		bean_ptr->setIdea(0, "");
		bean_ptr->getIdea(0);
	
		std::cout << std::endl;
		delete bean;

		std::cout << std::endl;
		delete cpy_bean;

		std::cout << std::endl;
	}
	std::cout << std::endl
		<< YELLOW << "################## Array with Cute Cat's and Dogs! ###################"
		<< RESET << std::endl << std::endl;
	{
		AAnimal* group[6];
		std::cout << std::endl;
		
		std::cout << std::endl;
		
		std::cout << "after var declarations..." << std::endl;
		
		std::cout << std::endl << std::endl;


		for (int i = 0; i < 6; i++)
		{
			if (i % 2 == 0)
				group[i] = new Dog();
			else
				group[i] = new Cat();
			std::cout << std::endl;
		}

		std::cout << std::endl;
	
		for (int i = 0; i < 6; i++)
			group[i]->makeSound();

		std::cout << std::endl;

		for (int i = 0; i < 6; i++)
		{
			std::cout << std::endl;
			delete group[i];
		}
		std::cout << std::endl << std::endl;
	}
	return 0;
}
