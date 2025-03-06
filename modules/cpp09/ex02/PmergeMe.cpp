#include "PmergeMe.hpp"

PmergeMe::PmergeMe() 
	: 
	_vector_main(),
	_vector_pend(),
	_deque_main(),
	_deque_pend(),
	_odd(false),
	_last(-1),
	_print(false),
	_comp_1_pairing(0),
	_comp_2_sort_pairs(0),
	_comp_3_insert_pend(0),
	_space_print(0)
{}

PmergeMe::PmergeMe(const PmergeMe& other)
	: 
	_vector_main(other._vector_main),
	_vector_pend(other._vector_pend),
	_deque_main(other._deque_main),
	_deque_pend(other._deque_pend),
	_odd(other._odd),
	_last(other._last),
	_print(other._print),
	_comp_1_pairing(other._comp_1_pairing),
	_comp_2_sort_pairs(other._comp_2_sort_pairs),
	_comp_3_insert_pend(other._comp_3_insert_pend),
	_space_print(other._space_print)
{}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other)
{
	if(this != &other)
	{
		_vector_main = other._vector_main;
		_vector_pend = other._vector_pend;
		_deque_main = other._deque_main;
		_deque_pend = other._deque_pend;
		_odd = other._odd;
		_last = other._last;
		_print = other._print;
		_comp_1_pairing = other._comp_1_pairing;
		_comp_2_sort_pairs = other._comp_2_sort_pairs;
		_comp_3_insert_pend = other._comp_3_insert_pend;
		_space_print = other._space_print;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

///////////////////////////////////////////////////////////////////

void	PmergeMe::sort(int ac, char **av, bool print_subject)
{
	_print = !print_subject;

	if(_print)
	{
		std::cout << "\t\t  INPUT : ";
		for(int i = 0; av[i]; i++)
			 std::cout << std::setw(2) << av[i] << " ";
		std::cout << std::endl;
	}

	clock_t end = 0;
	clock_t start = clock();
	_sort_vector(ac, av, print_subject);
	end = clock();

	_printBeforeAfter(av, "vector");
	_printTime("vector", end - start);
	
	start = clock();
	_sort_deque(ac, av, print_subject);
	end = clock();

	_printTime("deque", end - start);
}

void	PmergeMe::_printBeforeAfter(char **av, const std::string& name)
{
	const std::string BEFORE = "Before:  ";
	const std::string AFTER  = "After:   ";

	std::cout << BEFORE;
	for(int i = 0; av[i]; i++)
		std::cout << av[i] << " ";
	std::cout << std::endl;
	std::cout << AFTER;
	if(name == "deque")
	{
		std::deque<int>::iterator it = _deque_main.begin();
		std::deque<int>::iterator ite = _deque_main.end();
		while(it != ite)
		{
			std::cout << *it << " ";
			it++;
		}
		std::cout << std::endl;
	}
	else
	{
		std::vector<int>::iterator it = _vector_main.begin();
		std::vector<int>::iterator ite = _vector_main.end();
		while(it != ite)
		{
			std::cout << *it << " ";
			it++;
		}
		std::cout << std::endl;
	}
}

void	PmergeMe::_printTime(const std::string& name, clock_t elapsed) const
{
	const std::string TIME_PROCESS = "Time to process a range of ";
	const std::string ELEM_WITH = " elements with std::[";
	const std::string COLON = "] : ";
	const std::string MS = " ms\n";
	
	std::cout << std::fixed << std::setprecision(5);
	double clocks_p_s = static_cast<double>(CLOCKS_PER_SEC);

	if(name == "deque")
	{
		std::cout << TIME_PROCESS << _deque_main.size()
			<< ELEM_WITH << std::setw(6) << name << COLON
			<< static_cast<double>(elapsed) / clocks_p_s * 1000 << MS;

	}
	else
	{
		std::cout << TIME_PROCESS << _vector_main.size()
			<< ELEM_WITH << std::setw(6) << name << COLON
			<< static_cast<double>(elapsed) / clocks_p_s * 1000 << MS;
	}
}

void	PmergeMe::_printCompares() const
{
	std::cout << std::setw(15) << "pairing compares:  " << std::setw(10) << std::left << _comp_1_pairing
		<<   std::setw(15) << "sorting pairs:     " << std::setw(10) <<_comp_2_sort_pairs
		<<   std::setw(15) << "inserting pendant: " << std::setw(10) <<_comp_3_insert_pend 
		<<   std::setw(15) << "total compares:    "
		<< std::setw(10) <<_comp_1_pairing + _comp_2_sort_pairs + _comp_3_insert_pend 
		<< RESET << std::endl;
}

void	PmergeMe::_db(const std::string& debug)
{
	std::cout << debug << std::endl;
}

///////////////////////////////////////////////////////////////////////
/////////////////////// vector sorting /////////////////////////////////

void	PmergeMe::_sort_vector(int ac, char **av, bool print_subject)
{
	_print = !print_subject;
	_resetCompares();
	
	_parseNumbers_vector(ac, av, _vector_main, _vector_pend);

	_printContainer(_vector_main, _vector_pend, "After parsing ");

	if(ac > 2)
	{
		_sortMain_vector(_vector_main, _vector_pend, 0, _vector_main.size() - 1);
		if(_odd)
			_vector_pend.push_back(std::pair<int, int>(_last, INT_MAX));
		_printContainer(_vector_main, _vector_pend, "Pairs sorted  ");
		_insertSort_vector(_vector_main, _vector_pend);
	}

	//_printContainer(_vector_main, _vector_pend, "Final:  ");
	_isSorted(_vector_main);
}

void	PmergeMe::_parseNumbers_vector(int ac, char **av,
					std::vector<int>& main, std::vector<std::pair<int, int> >& pend)
{
	if ( (_odd = ac % 2 == 1) )
	{
		std::istringstream ss_last(av[ac - 1]);
		if (!(ss_last >> _last && ss_last.eof() && _last >= 0))
			throw std::exception();
	}
	else
		_last = -1;
	if( ac == 1 )
	{
		main.push_back(_last);
	}
	else
	{
		for(int i = 1; i < (ac - _odd); i += 2)
		{
			std::istringstream ss_L(av[i - 1]);
			std::istringstream ss_R(av[i]);
			int	L;
			int	R;

			if( !	(
				ss_L >> L && ss_L.eof()
				&& ss_R >> R && ss_R.eof()
				&& L >= 0 && R >= 0))
			{
				throw std::exception();
			}
			_comp_1_pairing++;
			if(ac == 2)
			{
				if(L > R)
				{
					main.push_back(R);
					main.push_back(L);
				}
				else
				{
					main.push_back(L);
					main.push_back(R);
				}
				break ;
			}
			if(L > R)
			{
				main.push_back(L);
				pend.push_back(std::make_pair(R, L));
			}
			else
			{
				main.push_back(R);
				pend.push_back(std::make_pair(L, R));
			}
		}
	}
}

/////////////////////// pair sorting /////////////////////////////////

void	PmergeMe::_sortMain_vector(std::vector<int>& main,
				std::vector<std::pair<int, int> >& pend,
				int start, int end)
{
	if (start >= end)
		return;

	int mid = start + (end - start) / 2;
	_sortMain_vector(main, pend, start, mid);
	_sortMain_vector(main, pend, mid + 1, end);

	_mergeSort_vector(main, pend, start, mid, end);
}

void	PmergeMe::_mergeSort_vector(std::vector<int>& main,
				 std::vector<std::pair<int, int> >& pend,
				 int start, int mid, int end)
{
	std::vector<int>L_main(main.begin() + start, main.begin() + mid + 1);
	std::vector<int>R_main(main.begin() + mid + 1, main.begin() + end + 1);

	std::vector<std::pair<int, size_t> >L_pend(pend.begin() + start, pend.begin() + mid + 1);
	std::vector<std::pair<int, size_t> >R_pend(pend.begin() + mid + 1, pend.begin() + end + 1);

	size_t Li = 0, Ri = 0, m = start;

	while ( Li < L_main.size() && Ri < R_main.size() )
	{
		if (L_main[Li] <= R_main[Ri])
		{
			main[m] = L_main[Li];
			pend[m] = L_pend[Li++];
		}
		else
		{
			main[m] = R_main[Ri];
			pend[m] = R_pend[Ri++];
		}
		_comp_2_sort_pairs++;
		m++;
	}
	while (Li < L_main.size())
	{
		main[m] = L_main[Li];
		pend[m++] = L_pend[Li++];
	}
	while (Ri < R_main.size())
	{
		main[m] = R_main[Ri];
		pend[m++] = R_pend[Ri++];
	}
}

//////////////////////////// Insertion sort /////////////////////////////

void	PmergeMe::_insertSort_vector(std::vector<int>& main, std::vector<std::pair<int, int> >& pend)
{
	std::vector<size_t> jacobsthal;
	_jacobsthalGen_vector(jacobsthal, pend.size());// - _odd);

	_printSingleC(jacobsthal, "jacobsthal(n == n-1) &remain: ");

	std::vector<size_t> main_index;
	std::vector<std::pair<int, int> >::iterator it = pend.begin();
	std::vector<std::pair<int, int> >::iterator ite = pend.end();
	for (size_t i = 0; it != ite; it++, i++)
	{
		if(main_index.size() == main.size())
			break ;
		main_index.push_back(i);
	}
	if (_odd)
	{
		main_index.push_back(main.size());
	}

	std::vector<size_t>::iterator jac_it = jacobsthal.begin();
	std::vector<size_t>::iterator jac_ite = jacobsthal.end();

	if(pend.size() == 2) 
	{
		main.insert(main.begin(), pend.begin()->first);
		_insertPend_vector(main, (pend.begin() + 1)->first, main.size() - 1);
	}
	else
	{
		std::vector<size_t>::iterator main_index_it;
		std::vector<size_t>::iterator main_index_ite;
		bool	first_insert = true;
		size_t change_index = 0;
		for (; jac_it != jac_ite; jac_it++)
		{
			if(first_insert)
			{
				first_insert = false;
				main.insert(main.begin(), pend[*jac_it].first);
			}
			else
			{
				change_index = _insertPend_vector(
					main, pend[*jac_it].first, main_index[*jac_it]);
			}
			pend[*jac_it].first = -1;
			_printContainer(main, pend, "inserting:  ");
			main_index_it = main_index.begin();
			main_index_ite = main_index.end();
			while(main_index_it != main_index_ite)
			{
				if(*main_index_it >= change_index)
					*main_index_it += 1;
				main_index_it++;
			}
		}
	}
	pend.clear();
}

void	PmergeMe::_jacobsthalGen_vector(std::vector<size_t>& jacobsthal, size_t size)
{
	if (size < 2)
		return;

	size_t j0 = 0;
	size_t j1 = 1;
	size_t jn = 0;
	size_t temp = 0;

	//0, 1, 1, 3, 5, 11, 21, 43, 85, 171... jacobsthal sequence 
	//0, 2, 4, 10, 20, 42, 84, 170... jacobsthal in array
	//0, 2, 1, 4, 3, 10, 9, 8, 7, 6, 5, 20... my generated sequence
	while (jacobsthal.size() < size)
	{
		temp = jn;
		jn = j1 + 2 * j0;
		j0 = j1;
		j1 = jn;

		if (jn >= size)
			jn = size;
		jacobsthal.push_back(jn - 1);
		if(jn >= 2)
			for(size_t j = jn - 1; temp < j && jacobsthal.size() < size; j--)
				jacobsthal.push_back(j - 1);
	}
}

size_t	PmergeMe::_findInsertPos_vector(std::vector<int>& main, int to_insert, size_t end)
{
	int L = 0;
	int R = static_cast<int>(end);

	// has issue here on this condition, detected on 
	// third evaluation of previous submission, 
	// that was leading on conditional jump detected on valgrind.
	// I need this condition, when I need to put last number of pendant,
	// when the total amount of numbers inserterd is odd,
	// because last number, don't have a pair on main chain.
	if(main.end() == main.begin() + end)
	{
		R--;
	}
	while (L <= R)
	{
		int mid = L + (R - L) / 2;
		if (main[mid] == to_insert)
		{
			_comp_3_insert_pend++;
			return mid;
		}
		if (main[mid] < to_insert)
		{
			_comp_3_insert_pend++;
			L = mid + 1;
		}
		else
		{
			_comp_3_insert_pend++;
			R = mid - 1;
		}
	}
	return static_cast<size_t>(L);
}

size_t	PmergeMe::_insertPend_vector(std::vector<int>& main, int to_insert, size_t end)
{
	size_t pos = _findInsertPos_vector(main, to_insert, end);

	main.insert(main.begin() + pos, to_insert);
	return pos;
}

///////////////////////////////////////////////////////////////////////
/////////////////////// deque sorting /////////////////////////////////

void	PmergeMe::_sort_deque(int ac, char **av, bool print_subject)
{
	_print = !print_subject;
	_resetCompares();
	
	_parseNumbers_deque(ac, av, _deque_main, _deque_pend);

	_printContainer(_deque_main, _deque_pend, "After parsing ");

	if(ac > 2)
	{
		_sortMain_deque(_deque_main, _deque_pend, 0, _deque_main.size() - 1);
		if(_odd)
			_deque_pend.push_back(std::pair<int, int>(_last, INT_MAX));
		_printContainer(_deque_main, _deque_pend, "Pairs sorted  ");
		_insertSort_deque(_deque_main, _deque_pend);
	}

	//_printContainer(_deque_main, _deque_pend, "Final:  ");
	_isSorted(_deque_main);
}

void	PmergeMe::_parseNumbers_deque(int ac, char **av,
					std::deque<int>& main, std::deque<std::pair<int, int> >& pend)
{
	if ( (_odd = ac % 2 == 1) )
	{
		std::istringstream ss_last(av[ac - 1]);
		if (!(ss_last >> _last && ss_last.eof() && _last >= 0))
			throw std::exception();
	}
	else
		_last = -1;
	if( ac == 1 )
	{
		main.push_back(_last);
	}
	else
	{
		for(int i = 1; i < (ac - _odd); i += 2)
		{
			std::istringstream ss_L(av[i - 1]);
			std::istringstream ss_R(av[i]);
			int	L;
			int	R;

			if( !	(
				ss_L >> L && ss_L.eof()
				&& ss_R >> R && ss_R.eof()
				&& L >= 0 && R >= 0))
			{
				throw std::exception();
			}
			_comp_1_pairing++;
			if(ac == 2)
			{
				if(L > R)
				{
					main.push_back(R);
					main.push_back(L);
				}
				else
				{
					main.push_back(L);
					main.push_back(R);
				}
				break ;
			}
			if(L > R)
			{
				main.push_back(L);
				pend.push_back(std::make_pair(R, L));
			}
			else
			{
				main.push_back(R);
				pend.push_back(std::make_pair(L, R));
			}
		}
	}
}


/////////////////////// pair sorting /////////////////////////////////

void	PmergeMe::_sortMain_deque(std::deque<int>& main,
				std::deque<std::pair<int, int> >& pend,
				int start, int end)
{
	if (start >= end)
		return;

	int mid = start + (end - start) / 2;
	_sortMain_deque(main, pend, start, mid);
	_sortMain_deque(main, pend, mid + 1, end);

	_mergeSort_deque(main, pend, start, mid, end);
}

void	PmergeMe::_mergeSort_deque(std::deque<int>& main,
				 std::deque<std::pair<int, int> >& pend,
				 int start, int mid, int end)
{
	std::deque<int>L_main(main.begin() + start, main.begin() + mid + 1);
	std::deque<int>R_main(main.begin() + mid + 1, main.begin() + end + 1);

	std::deque<std::pair<int, size_t> >L_pend(pend.begin() + start, pend.begin() + mid + 1);
	std::deque<std::pair<int, size_t> >R_pend(pend.begin() + mid + 1, pend.begin() + end + 1);

	size_t Li = 0, Ri = 0, m = start;

	while ( Li < L_main.size() && Ri < R_main.size() )
	{
		if (L_main[Li] <= R_main[Ri])
		{
			main[m] = L_main[Li];
			pend[m] = L_pend[Li++];
		}
		else
		{
			main[m] = R_main[Ri];
			pend[m] = R_pend[Ri++];
		}
		_comp_2_sort_pairs++;
		m++;
	}
	while (Li < L_main.size())
	{
		main[m] = L_main[Li];
		pend[m++] = L_pend[Li++];
	}
	while (Ri < R_main.size())
	{
		main[m] = R_main[Ri];
		pend[m++] = R_pend[Ri++];
	}
}

//////////////////////////// Insertion sort /////////////////////////////

void	PmergeMe::_insertSort_deque(std::deque<int>& main, std::deque<std::pair<int, int> >& pend)
{
	std::deque<size_t> jacobsthal;
	_jacobsthalGen_deque(jacobsthal, pend.size());// - _odd);

	_printSingleC(jacobsthal, "jacobsthal(n == n-1) &remain: ");

	std::deque<size_t> main_index;
	std::deque<std::pair<int, int> >::iterator it = pend.begin();
	std::deque<std::pair<int, int> >::iterator ite = pend.end();
	for (size_t i = 0; it != ite; it++, i++)
	{
		if(main_index.size() == main.size())
			break ;
		main_index.push_back(i);
	}
	if (_odd)
	{
		main_index.push_back(main.size());
	}

	std::deque<size_t>::iterator jac_it = jacobsthal.begin();
	std::deque<size_t>::iterator jac_ite = jacobsthal.end();

	if(pend.size() == 2) 
	{
		main.insert(main.begin(), pend.begin()->first);
		_insertPend_deque(main, (pend.begin() + 1)->first, main.size() - 1);
	}
	else
	{
		std::deque<size_t>::iterator main_index_it;
		std::deque<size_t>::iterator main_index_ite;
		bool	first_insert = true;
		size_t change_index = 0;
		for (; jac_it != jac_ite; jac_it++)
		{
			if(first_insert)
			{
				first_insert = false;
				main.insert(main.begin(), pend[*jac_it].first);
			}
			else
			{
				change_index = _insertPend_deque(
					main, pend[*jac_it].first, main_index[*jac_it]);
			}
			pend[*jac_it].first = -1;
			_printContainer(main, pend, "inserting:  ");
			main_index_it = main_index.begin();
			main_index_ite = main_index.end();
			while(main_index_it != main_index_ite)
			{
				if(*main_index_it >= change_index)
					*main_index_it += 1;
				main_index_it++;
			}
		}
	}
	pend.clear();
}

void	PmergeMe::_jacobsthalGen_deque(std::deque<size_t>& jacobsthal, size_t size)
{
	if (size < 2)
		return;

	size_t j0 = 0;
	size_t j1 = 1;
	size_t jn = 0;
	size_t temp = 0;

	//0, 1, 1, 3, 5, 11, 21, 43, 85, 171... jacobsthal sequence 
	//0, 2, 4, 10, 20, 42, 84, 170... jacobsthal in array
	//0, 2, 1, 4, 3, 10, 9, 8, 7, 6, 5, 20... my generated sequence
	while (jacobsthal.size() < size)
	{
		temp = jn;
		jn = j1 + 2 * j0;
		j0 = j1;
		j1 = jn;

		if (jn >= size)
			jn = size;
		jacobsthal.push_back(jn - 1);
		if(jn >= 2)
			for(size_t j = jn - 1; temp < j && jacobsthal.size() < size; j--)
				jacobsthal.push_back(j - 1);
	}
}

size_t	PmergeMe::_findInsertPos_deque(std::deque<int>& main, int to_insert, size_t end)
{
	int L = 0;
	int R = static_cast<int>(end);

	// has issue here on this condition, detected on 
	// third evaluation of previous submission, 
	// that was leading on conditional jump detected on valgrind.
	// I need this condition, when I need to put last number of pendant,
	// when the total amount of numbers inserterd is odd,
	// because last number, don't have a pair on main chain.
	if(main.end() == main.begin() + end)
	{
		R--;
	}
	while (L <= R)
	{
		int mid = L + (R - L) / 2;
		if (main[mid] == to_insert)
		{
			_comp_3_insert_pend++;
			return mid;
		}
		if (main[mid] < to_insert)
		{
			_comp_3_insert_pend++;
			L = mid + 1;
		}
		else
		{
			_comp_3_insert_pend++;
			R = mid - 1;
		}
	}
	return static_cast<size_t>(L);
}

size_t	PmergeMe::_insertPend_deque(std::deque<int>& main, int to_insert, size_t end)
{
	size_t pos = _findInsertPos_deque(main, to_insert, end);

	main.insert(main.begin() + pos, to_insert);
	return pos;
}

//////////////// another helper ////////////////
void	PmergeMe::_resetCompares()
{
	_comp_1_pairing = 0;
	_comp_2_sort_pairs = 0;
	_comp_3_insert_pend = 0;
}
