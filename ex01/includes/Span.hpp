/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 07:40:00 by luis-ffe          #+#    #+#             */
/*   Updated: 2025/01/06 07:48:18 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

# include <iostream>
# include <cstdlib>
# include <iomanip>
# include <climits>
# include <exception>
# include <algorithm>
# include <vector>

using std::string;
using std::cout;
using std::endl;

class Span
{
	public:
		Span(unsigned int N);
		Span(const Span &original);
		~Span();

		Span &operator=(const Span &rhs);
		void addNumber(unsigned int N);
		void addVector(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		void printDataNumbers();
		void printSortedDataNumbers();
		unsigned int shortestSpan();
		unsigned int longestSpan();

	private:
		unsigned int maxNumbers;
		unsigned int filledNumbers;
		std::vector<unsigned int> data;
};
