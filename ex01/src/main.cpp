/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 07:39:41 by luis-ffe          #+#    #+#             */
/*   Updated: 2025/01/22 08:37:44 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

int main(int argc, char **argv) 
{
    
	if (argc != 2)
	{
        std::cerr << "Error: Expected RPN expression as argument." << std::endl;
        return 1;
    }

    try
	{
        std::string input = argv[1];
        RPNCalculator RPN;
        int res = RPN.evaluate(input);
        std::cout << res << std::endl;
    }
	catch (const std::exception &e)
	{
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
