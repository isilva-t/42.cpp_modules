#pragma once

#define GREEN "\e[1;3;32m"
#define YELLOW "\e[1;3;93m"
#define CYAN "\e[1;3;36m"
#define RESET "\e[0m"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <climits>

#include <deque>
#include <vector>


class PmergeMe{

private:
	std::vector<int>	_vector_main;
	std::vector<std::pair<int, int> >	_vector_pend;

	std::deque<int>		_deque_main;
	std::deque<std::pair<int, int> >	_deque_pend;

	bool	_odd;
	int		_last;
	bool	_print;
	size_t	_comp_1_pairing;
	size_t	_comp_2_sort_pairs;
	size_t	_comp_3_insert_pend;
	size_t	_space_print;

	//// vector
	void	_sort_vector(int ac, char **av, bool print_subject);
	void	_parseNumbers_vector(int ac, char **av,
					std::vector<int>& main, std::vector<std::pair<int, int> >& pend);
	void	_sortMain_vector(std::vector<int>& main, std::vector<std::pair<int, int> >& pend, 
					int start, int end);
	void	_mergeSort_vector(std::vector<int>& main, std::vector<std::pair<int, int> >& pend,
					int start, int mid, int end);
	void	_insertSort_vector(std::vector<int>& main, std::vector<std::pair<int, int> >& pend);
	size_t	_findInsertPos_vector(std::vector<int>& main, int to_insert, size_t R);
	size_t	_insertPend_vector(std::vector<int>& main, int to_insert, size_t end);
	void	_jacobsthalGen_vector(std::vector<size_t>& jacobsthal, size_t size);

	//// deque
	void	_sort_deque(int ac, char **av, bool print_subject);
	void	_sortMain_deque(std::deque<int>& main, std::deque<std::pair<int, int> >& pend, 
					int start, int end);
	void	_mergeSort_deque(std::deque<int>& main, std::deque<std::pair<int, int> >& pend,
					int start, int mid, int end);
	void	_insertSort_deque(std::deque<int>& main, std::deque<std::pair<int, int> >& pend);
	size_t	_findInsertPos_deque(std::deque<int>& main, int to_insert, size_t R);
	size_t	_insertPend_deque(std::deque<int>& main, int to_insert, size_t end);
	void	_jacobsthalGen_deque(std::deque<size_t>& jacobsthal, size_t size);
	void	_parseNumbers_deque(int ac, char **av,
					std::deque<int>& main, std::deque<std::pair<int, int> >& pend);

	void	_printBeforeAfter(char **av, const std::string& name);
	void	_printTime(const std::string& name, clock_t elapsed) const;
	void	_printTimeDetails() const;

	void	_db(const std::string& debug);
	void	_printCompares() const;
	void	_resetCompares();

	template <typename T, typename U>
	void	_printContainer(T& main, U& pend, std::string str)
	{
		if(!_print)
			return;
		typename T::iterator it = main.begin();
		typename T::iterator ite = main.end();
		
		std::cout << std::endl;
		std::cout << GREEN << std::setw(20) << str << std::setw(10) << "main : ";
		for(; it != ite; it++)
			std::cout << std::setw(3) << *it << " ";
		std::cout << std::endl;
		it = main.begin();
		typename U::iterator p_it = pend.begin();
		typename U::iterator p_ite = pend.end();
		std::cout << CYAN << std::setw(20) << str << std::setw(10) << "pendant : ";
		for(; it != ite; it++)
		{
			p_it = pend.begin();
			bool print_space = true;
			for(; p_it != p_ite; p_it++)
			{
				if (p_it->first >= 0 && p_it->second == *it)
				{
					std::cout << std::setw(3) << p_it->first << " ";
					print_space = false;
					break ;
				}
			}
			if(print_space)
				std::cout << std::setw(3) << "" << " ";
		}
		if(_odd && main.size() <= pend.size())
			std::cout << std::setw(3) << _last;
		else
		{
			p_it = pend.begin();
			for(; p_it != p_ite; p_it++)
				if(p_it + 1 == p_ite && p_it->first > 0)
					std::cout << std::setw(3) << p_it->first << " ";
		}
		std::cout << RESET << std::endl;
		_printCompares();
	}

	template <typename T>
	void	_printSingleC(T& cont, std::string str)
	{
		if(!_print)
			return;
		typename T::iterator it = cont.begin();
		typename T::iterator ite = cont.end();
		
		std::cout << YELLOW << std::endl << std::setw(30) << str ;
		for(; it != ite; it++)
			std::cout << std::setw(3) << *it << " ";
		std::cout << RESET << std::endl;
	}

	template <typename T>
	void	_isSorted(T& cont)
	{
		if(!_print)
			return;
		typename T::iterator it = cont.begin();
		typename T::iterator ite = cont.end();
		it++;
		while(it != ite)
		{
			if(*it < *(it - 1))
				{
				std::cout << "|_|_|_|_|_|_|_|_UNsorted_|_|_|_|_|_|_|_|" << std::endl;
				return;
			}
			it++;
		}
		std::cout << "************ !!SORTED!! ************" << std::endl;
	}
	
		
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
public:
	PmergeMe();
	~PmergeMe();

	void	sort(int ac, char **av, bool print_subject);
};
