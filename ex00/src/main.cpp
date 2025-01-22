
#include "../includes/BitcoinExchange.hpp"
#include <map>
#include <iostream>

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << "Error:c ould not open file." << std::endl;
		return 0;
	}

	BitcoinExchanger bitcoin;
	try
	{
		bitcoin.PopulateDataBase();
		//bitcoin.DevTools();
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what();
		return 1;
	}

    std::string line;
    std::fstream file(argv[1]);
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file" << std::endl;
        return (1);
    }

	std::getline(file, line);
	while(!file.eof() && std::getline(file, line)) 
	{
        if (line.empty() || (line.find_first_not_of(" \t") == std::string::npos))
            continue;
		try
		{
			bitcoin.CalculatePrice(line);
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what();
		}
	}
	file.close();
	return 0;
}
