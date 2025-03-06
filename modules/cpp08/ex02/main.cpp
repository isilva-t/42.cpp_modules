#include "MutantStack.hpp"

#include <iostream>
#include <list>

int subject_main()
{
	std::cout << "\nSubject MutantStack main:\n";

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}

void list_test()
{
	std::cout << "\nList test:\n";
	
	std::list<int> lst;

	lst.push_back(5);				//push
	lst.push_back(17);				//push
	std::cout << lst.back() << std::endl;	//top
	lst.pop_back();				//pop
	std::cout << lst.size() << std::endl;
	lst.push_back(3);				//push
	lst.push_back(5);				//push
	lst.push_back(737);				//push
	//[...]
	lst.push_back(0);				//push
	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int, std::list<int> > s(lst);
}

int main()
{
	subject_main();
	list_test();
	return 0;
}
