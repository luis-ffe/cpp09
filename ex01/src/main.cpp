/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 07:39:41 by luis-ffe          #+#    #+#             */
/*   Updated: 2025/01/06 07:56:55 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"


static void enter_to_continue()
{
	cout << "\n\nPress |ENTER| to continue" << endl;
	std::cin.get();
	system("clear");
}

static void SubjectTest()
{
	try
	{
		Span sp = Span(5);

		cout << "Adding numbers to the vector..." << endl;
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		cout << endl;
		cout << "Testing Member Functions..." << endl;
		cout << "Vector Values:";
		sp.printDataNumbers();
		
		cout << endl;
		cout << "Sorted Vector Values:";
		sp.printSortedDataNumbers();

		cout << endl;
		cout << "Shortest Span: " << sp.shortestSpan() << endl;
		cout << "Longest Span: " << sp.longestSpan() << endl;
	}
	catch (std::exception &e)
	{
		cout << e.what() << endl;
	}
	enter_to_continue();
}

static void SpanUsingIterators()
{

	try
	{
		std::vector<int> v;
		std::vector<int>::iterator begin;
		std::vector<int>::iterator end;

		cout << "Adding numbers to V vector..." << endl;
		for(unsigned int i = 0; i < 10; i++)
		{
			v.push_back(rand() % 100);
			cout << "Vector Value: " << v[i] << endl;
		}

		Span span(10);

		begin = v.begin();
		end = v.end();

		cout << endl;
		cout << "Adding numbers to data vector using range of iterators..." << endl;
		span.addVector(begin, end);

		cout << endl;
		cout << "Testing Member Functions..." << endl;
		cout << "Span Data Values:";
		span.printDataNumbers();

		cout << endl;
		cout <<"Sorted Vector Values:";
		span.printSortedDataNumbers();

		cout << endl;
		cout << "Shortest Span: "  << span.shortestSpan() << endl;
		cout << "Longest Span: " << span.longestSpan() << endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	enter_to_continue();
}

static void TestExceptions()
{
	try
	{
		Span sp = Span(5);

		cout << "Add Numbers Exception" << endl;
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(11);
	}
	catch (std::exception &e)
	{
		cout << e.what() << endl;
	}

	try
	{
		Span sp(1);

		cout << endl;
		cout << "Shortest/Longest Span Exception" << endl;
		sp.addNumber(5);

		cout << endl;
		cout << "Shortest Span: " << sp.shortestSpan() << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	enter_to_continue();
}

int main()
{
	SubjectTest();
	SpanUsingIterators();
	TestExceptions();
	return (0);
}