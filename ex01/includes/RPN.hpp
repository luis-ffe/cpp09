/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 08:34:08 by luis-ffe          #+#    #+#             */
/*   Updated: 2025/01/22 09:50:33 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <string>
#include <cctype>

class RPNCalculator
{
private:
    std::stack<int> stack;

public:
	RPNCalculator();
	~RPNCalculator();
	RPNCalculator(const RPNCalculator &obj);
	RPNCalculator & operator=(const RPNCalculator &obj);
    void pushNumber(const std::string &token);
    void performOperation(const std::string &token);
    void validateResult() const;
    int evaluate(const std::string &input);
};
