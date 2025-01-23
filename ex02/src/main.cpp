/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 08:40:59 by luis-ffe          #+#    #+#             */
/*   Updated: 2025/01/23 21:01:49 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

//example use: 
//./PmergeMe $(shuf -i 0-100000 -n 3000 | tr '\n' ' ')
//valgrind ./PmergeMe 5 9 2 5 1 2 3 41 323 1 243 2 245 4 52451 134 13 51435 24 2 424 54 5124 13 23 414334 134 134 2514 536 857 6 57432 5646255  345 6356 25

int	main(int ac, char **av)
{
    std::string container1 = "vector";
    std::string container2 = "deque"; 
	try
	{
        //initial user input parser checks for empty values or something that is not a number
		parse_input(ac, av);
        
        //initializes the object and 
		PmergeMe<std::vector<int> > vector(ac, av);
        
        // std::cout << "PEND:" << std::endl;
        // vector.printContainerPend();
        // std::cout << "MAIN:" << std::endl;
        // vector.printContainerMain();
        
        vector.recursiveMerge(0, vector.getSize() - 1);
        vector.insertMerge();  
        
        // std::cout << "INS PEND:" << std::endl;
        // vector.printContainerPend();
        // std::cout << "INS MAIN:" << std::endl;
        // vector.printContainerMain();
        // std::cout << std::endl;
        //sets the final time stamp fot the first container as it executes in different time from the next one.
        
        vector.setEndTimeStamp();
        //prints the unsorted numbers , has to be valid already passed checks
		std::cout << "Before: ";
        printValidUserInput(ac, av);
        //prints container sorted values
        std::cout << "After: ";
		vector.printContainer(vector.getMain());
        //processing time for the sort	
        vector.printProcessingTime(container1);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
        return 1;
	}

	try
	{
		PmergeMe<std::deque<int> > deque(ac, av);
		deque.recursiveMerge(0, deque.getSize() - 1);
		deque.insertMerge();
        deque.setEndTimeStamp();
		deque.printProcessingTime(container2);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
        return 1;
	}
	return 0;
}
