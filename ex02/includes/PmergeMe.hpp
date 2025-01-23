/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:04:49 by luis-ffe          #+#    #+#             */
/*   Updated: 2025/01/23 20:52:04 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <bits/stdc++.h>
#include <climits>
#include <deque>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

template <typename T> class PmergeMe
{
  private:
    // parallele containers for pairing input
	T _main;
	T _pend;
    //clock time stamps
	clock_t startTimeStamp;
	clock_t endTimeStamp;
    //block empty instanciation
    PmergeMe(void);
    
    //initialize paired _main and _pend paralele containers
	void divideElemntsToPairs(int ac, char **av);

  public:
    //constructor
	PmergeMe(int ac, char **av);
    //destructor
	~PmergeMe();
	//copy constructor
    PmergeMe(PmergeMe const &copy);
    //assignment operator
    PmergeMe const &operator=(PmergeMe const &copy);

    // getters
    T getMain() const;
	T getPend() const;
    int getSize() const;
    //setters for time stamps
    void setEndTimeStamp();
    void setStartTimeStamp();
    
    //Print container values
    void printContainer(T container);

    //test methods for debugging
    void printContainerMain();
    void printContainerPend();

    //math for the processing time calculation
    void printProcessingTime(std::string name);

    // -- functional execution methods --

    //divides the problem in 2 parts recursively and then starts the merging until just one is left
    //using paralel containers
	void recursiveMerge(int left, int right);
    // creates temporary holders for both halves of each container 
    // and assigns all the elements in sorted order to the containers
    void mergeSorted(int left, int mid, int right);
    
    // inserts into main the elements of pend at the correct position using jacobsthal logic to perform a Sorted binary insert
	void insertMerge(void);
    void sortedBinaryInsert(int left, int right, int number); //carefull has to be recursive
    size_t jacobsThalLogic(size_t n);
};

//utils
void	printValidUserInput(int ac, char **av);
bool	isValidNumber(int ac, char **av);
bool	isValidInt(int ac, char **av);
void	parse_input(int ac, char **av);
#include "../src/PmergeMe.tpp"