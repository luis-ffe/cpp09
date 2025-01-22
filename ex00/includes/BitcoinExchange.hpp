
#pragma once
#include <iostream>
#include <exception>
#include <map>
#include <fstream>
#include <ctime>
#include <bits/stdc++.h>

class BitcoinExchanger
{
    private:
        std::map<std::string, float> _DataBase;

    public:
        BitcoinExchanger();
        ~BitcoinExchanger();
        BitcoinExchanger(BitcoinExchanger const &obj);
        BitcoinExchanger &operator=(BitcoinExchanger const &obj);

        // method to fill the map with the CSV values. Using map as it is a associative container great for correlation uses.
        void PopulateDataBase(void);
        void DevTools(void);
        void CalculatePrice(std::string line);

        //exceptions
        class NegativeNumberException : public std::exception
        {
        public:
            const char *what() const throw();
        };

        class NumberOutOfRangeException : public std::exception
        {
            const char *what() const throw();
        };

        class BadDatabaseException : public std::exception
        {
        public:
            const char *what() const throw();
        };
};