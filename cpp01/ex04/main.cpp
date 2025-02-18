/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: j <j@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:20:11 by j                 #+#    #+#             */
/*   Updated: 2025/02/18 15:54:33 by j                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./replace [filename] [s1] [s2]" << std::endl;
		return (1);
	}

	std::string filename_str = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (filename_str.empty() || s1.empty() || s2.empty())
	{
		std::cerr << "Error: empty argument" << std::endl;
		return (1);
	}

	std::ifstream filename(filename_str);
	if (!filename.is_open())
	{
		std::cerr << "Error: could not open " << filename_str << std::endl;
		return (1);
	}

	std::string outfile = filename_str + ".replace";
	std::ofstream filename_replace(outfile);
	if (!filename_replace.is_open())
	{
		filename.close();
		std::cerr << "Error: could not open " << outfile << std::endl;
		return (1);
	}
	std::string content;
	content = readFile(filename);
	if (content.empty())
	{
		std::cerr << "Error: empty file" << std::endl;
		filename.close();
		filename_replace.close();
		return (1);
	}
	std::string result = findReplace(content, s1, s2);
	filename_replace << result;
	filename_replace.close();
	filename.close();
	return (0);
}
