/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:20:52 by luis-ffe          #+#    #+#             */
/*   Updated: 2025/01/23 20:15:18 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

void	printValidUserInput(int ac, char **av)
{
	for(int i = 1; i < ac; i++ )
		std::cout << av[i] << " ";
	std::cout << std::endl;
}

bool	isValidNumber(int ac, char **av) {
	int	j;
	for(int i = 1; i < ac; i++ ) {
		j = 0;
		while (av[i][j] != '\0') {
			if (av[i][j] < '0' || av[i][j] > '9')
				return (false);
			j++;
		}
	}
	return true;
}

bool	isValidInt(int ac, char **av) {
	for(int i = 1; i < ac; i++) {
		if (std::strtol(av[i], NULL, 10) > INT_MAX || std::strtol(av[i], NULL, 10) < 0)
			return (false);
	}
	return true;
}

void	parse_input(int ac, char **av)
{
    //if there arre no erguments to the program error
	if (ac < 2) {   
		throw std::invalid_argument("Error");
    }
	for (int i = 1; i < ac; ++i) {
		if (std::string(av[i]).empty()) {
			throw std::invalid_argument("Error");
		}
	}
    if (!isValidNumber(ac, av)) {
		throw std::invalid_argument("Error");
	}
	else if (!isValidInt(ac, av)) {
		throw std::invalid_argument("Error");
	}
	return ;
}
