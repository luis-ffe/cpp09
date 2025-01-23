/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:02:03 by luis-ffe          #+#    #+#             */
/*   Updated: 2025/01/23 20:48:30 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

template <typename T> PmergeMe<T>::PmergeMe(int ac, char **av)
{
	//has to set the start time
	setStartTimeStamp();
	//then need to get the input by pairs of pairs etc 
	divideElemntsToPairs(ac, av);
}


//divide elements into pairs
template <typename T> void PmergeMe<T>::divideElemntsToPairs(int ac, char **av)
{
	int	num1, num2;
	int i = 1;
	while (i < ac)
	{
		
		if (i == ac - 1)
		{
			_pend.push_back(std::atoi(av[i]));
			return ;
		}
		
		num1 = std::atoi(av[i]);
		num2 = std::atoi(av[i + 1]);
		
		if (num1 >= num2)
		{
			_main.push_back(num1);
			_pend.push_back(num2);
		}
		else
		{
			_main.push_back(num2);
			_pend.push_back(num1);
		}
		i += 2;
	}
}

template <typename T> int PmergeMe<T>::getSize() const
{
	return (this->_main.size());
}

template <typename T> T PmergeMe<T>::getMain(void) const
{
	return (_main);
}

template <typename T> T PmergeMe<T>::getPend(void) const
{
	return (_pend);
}

template <typename T> void PmergeMe<T>::printContainer(T container)
{
	typename T::iterator it;
	it = container.begin();
	while (it != container.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

template <typename T> void PmergeMe<T>::printContainerPend()
{
	typename T::iterator it;
	it = _pend.begin();
	while (it != _pend.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

template <typename T> void PmergeMe<T>::printContainerMain()
{
	typename T::iterator it;
	it = _main.begin();
	while (it != _main.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

template <typename T>
void PmergeMe<T>::recursiveMerge(int left, int right) {
    //if the section has one or no element
    if (left >= right)
        return;
    // Calculate the midpoint
    int mid = left + (right - left) / 2;
    // Recursively sort the left and right halves
    recursiveMerge(left, mid);
    recursiveMerge(mid + 1, right);
    mergeSorted(left, mid, right);
}

template <typename Container>
void PmergeMe<Container>::mergeSorted(int left, int mid, int right) {
    // Create temporary containers for the left and right 
	//main temp
	Container leftMainContainer(_main.begin() + left, _main.begin() + mid + 1);
    Container rightMainContainer(_main.begin() + mid + 1, _main.begin() + right + 1);
	//pend temp
    Container leftPendContainer(_pend.begin() + left, _pend.begin() + mid + 1);
    Container rightPendContainer(_pend.begin() + mid + 1, _pend.begin() + right + 1);

    //Iterators for the original containers where the merged result will be written
    typename Container::iterator mainOutput = _main.begin() + left;
    typename Container::iterator pendOutput = _pend.begin() + left;

    //temporary container iterators left and right parts
    typename Container::iterator leftMainIter = leftMainContainer.begin();
    typename Container::iterator leftPendIter = leftPendContainer.begin();
    typename Container::iterator rightMainIter = rightMainContainer.begin();
    typename Container::iterator rightPendIter = rightPendContainer.begin();

    // Merge the both containers until one reaches the end
    while (leftMainIter != leftMainContainer.end() && rightMainIter != rightMainContainer.end()) {
        if (*leftMainIter <= *rightMainIter) {
            *mainOutput = *leftMainIter;
            *pendOutput = *leftPendIter;
            leftMainIter++;
            leftPendIter++;
        } else {
            *mainOutput = *rightMainIter;
            *pendOutput = *rightPendIter;
            rightMainIter++;
            rightPendIter++;
        }
        mainOutput++;
        pendOutput++;
    }
    //merge remaining elements from the left
    while (leftMainIter != leftMainContainer.end()) {
        *mainOutput = *leftMainIter;
        *pendOutput = *leftPendIter;
        leftMainIter++;
        leftPendIter++;
        mainOutput++;
        pendOutput++;
    }
    //merge remaining from right
    while (rightMainIter != rightMainContainer.end()) {
        *mainOutput = *rightMainIter;
        *pendOutput = *rightPendIter;
        rightMainIter++;
        rightPendIter++;
        mainOutput++;
        pendOutput++;
    }
}

template <typename Container>
void PmergeMe<Container>::insertMerge()
{
	size_t	i, resJacob, distIndex, numberInsert, start;
	if (_pend.empty())
		return ;
	_main.insert(_main.begin(), _pend.front());
	i = 0;
	resJacob = 1;
	distIndex = jacobsThalLogic(resJacob) * 2;
	numberInsert = 1;
	while (i + distIndex < getPend().size()) {
		start = i;
		i += distIndex;
		while (i > start) {
			sortedBinaryInsert(0, i + numberInsert - 1, getPend()[i]);
			numberInsert++;
			i--;
		}
		i += distIndex;
		resJacob++;
		distIndex = jacobsThalLogic(resJacob) * 2;
	}
	start = i;
	i = getPend().size() - 1;
	while (i > start) {
		sortedBinaryInsert(0, i + numberInsert - 1, getPend()[i]);
		numberInsert++;
		i--;
	}
}

template <typename Container>
void PmergeMe<Container>::sortedBinaryInsert(int left, int right, int number) {
	if (left >= right) {
		if (_main[left] > number) {
			_main.insert(_main.begin() + left, number);
		} else {
			_main.insert(_main.begin() + left + 1, number);	
		}
		return ;
	}
	int mid = left + (right - left) / 2;
	if (getMain()[mid] == number) {
		_main.insert(_main.begin() + mid, number);
		return ;
	} else if (number > getMain()[mid]) {
		return sortedBinaryInsert(mid + 1, right, number);
	} else {
		return sortedBinaryInsert(left, mid, number);
	}
}

//jacobs logic main core for final insertion of pend into the final sorted container
template <typename Container> size_t PmergeMe<Container>::jacobsThalLogic(size_t n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	return (jacobsThalLogic(n - 1) + (2 * jacobsThalLogic(n - 2)));
}

template <typename T> void PmergeMe<T>::setEndTimeStamp() {
	endTimeStamp = clock();
}

template <typename T> void PmergeMe<T>::setStartTimeStamp() {
	startTimeStamp = clock();
}

template <typename T> void PmergeMe<T>::printProcessingTime(std::string name) {
	double	processingTime;
	processingTime = double(endTimeStamp - startTimeStamp) / double(CLOCKS_PER_SEC);
	std::cout << "Time to process a range of " << getSize() << " elements with " << name << ": "  << std::fixed << processingTime << std::setprecision(6) << " us" << std::endl;
}

template <typename T> PmergeMe<T>::~PmergeMe(void){}

template <typename T> PmergeMe<T>::PmergeMe(PmergeMe const &copy) {
	*this = copy;
}

template <typename T> const PmergeMe<T> &PmergeMe<T>::operator=(PmergeMe const &copy)
{
	if (this != &copy)
	{
		//Me programerzzzz
	}
	return (*this);
}
