
#include "../includes/BitcoinExchange.hpp"
#include <map>
#include <iostream>

BitcoinExchanger::BitcoinExchanger() {}

BitcoinExchanger::~BitcoinExchanger() {}

BitcoinExchanger::BitcoinExchanger(BitcoinExchanger const &obj)
{
    this->_DataBase = obj._DataBase;
}

BitcoinExchanger &BitcoinExchanger::operator=(BitcoinExchanger const &obj)
{
    if(this != &obj)
    {
        this->_DataBase = obj._DataBase;
    }
    return *this;
}

void BitcoinExchanger::PopulateDataBase(void)
{
    std::ifstream file("data.csv");
    std::string line;

    if(!file.is_open())
        throw BadDatabaseException();

    if (std::getline(file, line))
        std::cout << "";
    else
        throw BadDatabaseException();

    while(std::getline(file, line) && !file.eof())
    {
        size_t commaPos = line.find(",");

        std::string date = line.substr(0, commaPos);
        std::string coinValue = line.substr(commaPos + 1);
        std::istringstream valueStream(coinValue);
        float value = 0.0f;
        valueStream >> value;
        if (valueStream.fail())
        {
            std::cout << "Excepion here " << std::endl;
            return;
        }
        _DataBase[date] = value;
    }
    file.close();
}

void BitcoinExchanger::DevTools(void)
{
    std::map<std::string, float>::iterator it;
    for(it = _DataBase.begin(); it != _DataBase.end(); it++) 
    { 
        std::cout << "DATE: " << it->first << " | Value: " << it->second << std::endl;
    }
    return ;
}


void BitcoinExchanger::CalculatePrice(std::string line)
{
    struct tm tm;
    float number;
    std::stringstream ss(line);
    std::string word;
    std::map<std::string, float>::iterator it;
    std::string date;
    std::string valueStr;

    std::getline(ss, date, '|');
    if (!std::getline(ss, valueStr))
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return ;
    }

    // whitespaces handling
    date.erase(0, date.find_first_not_of(" \t"));
    date.erase(date.find_last_not_of(" \t") + 1);
    valueStr.erase(0, valueStr.find_first_not_of(" \t"));
    valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

    if (!strptime(date.c_str(), "%Y-%m-%d", &tm))
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return ;
    }
    number = strtof(valueStr.c_str(), NULL);
    if (number < 0)
        throw NegativeNumberException();
    else if (number > 1000)
        throw NumberOutOfRangeException();

    it = this->_DataBase.find(date);
    if (it == this->_DataBase.end())
    {
        it = this->_DataBase.lower_bound(date);
        if (it == this->_DataBase.begin())
        {
            std::cout << "Error: no date\n";
            return;
        }
        --it;
    }
    std::cout << date << " => " << number << " = "<< it->second * number << std::endl;
}

const char *BitcoinExchanger::NegativeNumberException::what() const throw()
{
    return "Error: not a positive number.\n";
}

const char *BitcoinExchanger::NumberOutOfRangeException::what() const throw()
{
    return "Error: too large a number.\n";
}

const char *BitcoinExchanger::BadDatabaseException::what() const throw()
{
    return "Error: in database csv\n";
}