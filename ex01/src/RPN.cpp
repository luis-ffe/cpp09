/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 08:37:37 by luis-ffe          #+#    #+#             */
/*   Updated: 2025/01/22 10:02:26 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"


RPNCalculator::RPNCalculator(){}

RPNCalculator::~RPNCalculator(){}

RPNCalculator::RPNCalculator(const RPNCalculator &obj)
{
	this->stack = obj.stack;
}

RPNCalculator &RPNCalculator::operator=(const RPNCalculator &obj)
{
	if (this != &obj)
	{
        this->stack = obj.stack;
    }
    return *this;
}

//pushes numbers to the stack after validating them from the string token

void RPNCalculator::pushNumber(const std::string &token)
{
    std::stringstream ss(token);
    int number;
    ss >> number;

    if (ss.fail() || !ss.eof())
        throw std::invalid_argument("Error");
    stack.push(number);
}

// this gets the 2 top numbers from the stack
//performs the operation sinalized by the input token or in case it is not identified throws error

void RPNCalculator::performOperation(const std::string &token)
{
	if (stack.size() < 2)
		throw std::invalid_argument("Error");

	int operand2 = stack.top();
	stack.pop();
	int operand1 = stack.top();
	stack.pop();

	if (token == "+")
		stack.push(operand1 + operand2);
	else if (token == "-")
		stack.push(operand1 - operand2);
	else if (token == "*" || token == "%")
		stack.push(operand1 * operand2);
	else if (token == "/")
	{
		//not valid operator
		if (operand2 == 0)
			throw std::invalid_argument("Error");
		stack.push(operand1 / operand2);
	}
	else
		throw std::invalid_argument("Error");
}


//simple validantion stack must have just 1 number left from the calculations reults
void RPNCalculator::validateResult() const
{
	if (stack.size() != 1)
		throw std::invalid_argument("Error");
}

//this method takes the user input string and evaluates it step by step
int RPNCalculator::evaluate(const std::string &expression)
{
	std::istringstream tokens(expression);
	std::string token;

	//goes through each element of the string (token)
	while (tokens >> token)
	{
		//adjusted to be valid for negative numbers and numbers in case it something else performs operation
		if (isdigit(token[0]) || (token.length() > 1 && token[0] == '-' && isdigit(token[1])))
			pushNumber(token);
		else
		{
			//performs operations using the top stack
			performOperation(token);
		}
	}

	validateResult();
	return stack.top();
}
