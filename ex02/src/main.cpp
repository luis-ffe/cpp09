/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 08:40:59 by luis-ffe          #+#    #+#             */
/*   Updated: 2025/01/06 08:41:00 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/MutantStack.hpp"

static void enter_to_continue()
{
	cout << "\n\nPress |ENTER| to continue" << endl;
	std::cin.get();
	system("clear");
}

static void PrintListElements(std::list<int> &lst)
{
	std::list<int>::reverse_iterator it = lst.rbegin();
	std::list<int>::reverse_iterator ite = lst.rend();
	
	cout << "Iterating through List" << endl;

 	for(; it != ite; ++it)
	{
		cout << "Element: " << *it << endl;
	}
}

static void PrintStackElements(MutantStack<int> &mstack)
{
	MutantStack<int>::reverse_iterator it = mstack.rbegin();
	MutantStack<int>::reverse_iterator ite = mstack.rend();
	
	cout << "Iterating through Stack" << endl;

 	for(; it != ite; ++it)
	{
		cout << "Element: " << *it << endl;
	}
}

static void SubjectTest()
{
	try
	{
		MutantStack<int> mstack;
		cout << "Pushing 5, 17 to Stack" << endl;
		mstack.push(5);
		mstack.push(17);
		cout << "Top of Stack: " << endl;
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		cout  << "Stack size: " << endl;
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		cout << "Iterating through Stack" << endl;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	enter_to_continue();
}

static void SubjectTestRemixed()
{
	try
	{
		MutantStack<int> mstack;
		
		cout  << "Pushing 5, 17 to Stack" << endl;
		mstack.push(5);
		mstack.push(17);

		cout << endl;
		PrintStackElements(mstack);
		cout << endl;
		
		cout <<  "Top of Stack: " << mstack.top() << endl << endl;
		
		cout << "Poping from Stack" <<  endl;
		mstack.pop();
		cout << endl;
		PrintStackElements(mstack);
		cout << endl;
		
		cout << "Stack size: " << mstack.size() << endl << endl;
		
		cout << "Pushing 3, 5, 737, 0 to Stack" <<  endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		
		cout << endl;
		PrintStackElements(mstack);
		cout << endl;
		std::stack<int> s(mstack);
	}
	catch(const std::exception& e)
	{
		std::cerr <<  e.what() << '\n';
	}
	enter_to_continue();
}

static void TestWithList()
{
	try
	{
		cout <<  "--- Test With List ---" << endl ;
		std::list<int> lst;
		
		cout << "Pushing 5, 17 to List" << endl;
		lst.push_back(5);
		lst.push_back(17);
	
		cout << endl;
		PrintListElements(lst);
		cout << endl;
		
		cout << "Top of List: " << lst.back() << endl << endl;
		
		cout <<  "Poping from List" << endl;
		lst.pop_back();
		
		cout << endl;
		PrintListElements(lst);
		cout << endl;
		
		cout << "List size: " << lst.size() << endl << endl;


		cout << "Pushing 3, 5, 737, 0 to List" << endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);

		cout << endl;
		PrintListElements(lst);
		cout << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr <<  e.what() << '\n';
	}
	enter_to_continue();
}

int main()
{
	SubjectTest();
	SubjectTestRemixed();
	TestWithList();
	return (0);
}