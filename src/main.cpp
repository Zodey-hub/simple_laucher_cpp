#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "settingManager.hpp"
#include "startupManager.hpp"

#define CLEAR_SCREEN system("@cls||clear");

bool is_number(const std::string &s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it))
		++it;
	return !s.empty() && it == s.end();
}

int main()
{
	Setting::Setting setting("settings.txt");
	const size_t apps_size = setting.apps.size();

	std::string input;
	size_t input_int;

	while (true)
	{
		// printing the avaliable apps
		for (size_t i = 0; i < apps_size; i++)
		{
			std::cout << i << ". " << setting.apps[i].name << "\t" << setting.apps[i].path << "\n";
		}

		std::cout << "\nSelect a number to run the application, use q to exit!" << std::endl;
		std::cin >> input;

		// exit handling
		if (!input.compare("q"))
		{
			break;
		}

		CLEAR_SCREEN

		// error handling
		if (is_number(input))
		{
			input_int = std::stoi(input);
			if (input_int <= apps_size)
			{
				std::cout << setting.apps[input_int].path << "\n"
						  << std::endl;
				startupManager::StartApp(setting.apps[input_int]);
				continue;
			}
		}
		std::cout << "Wrong input, try again!\n"
				  << std::endl;
	}

	return 0;
}