#include<iostream>
#include<ctime>
#include<string>
#include<vector>
#include<map>
#include<sstream>
#include<iomanip>
#pragma warning(disable : 4996)

int main()
{
	bool end = true;
	std::string name;
	int day = 0;
	std::vector<std::string> names;
	std::map<int, std::map<int, std::vector<std::string>>> birthday;
	while (end)
	{
		std::cout << "Enter a friend's name - ";
		std::cin >> name;
		if (name == "end")
		{
			end = false;
		}
		else
		{
			std::string data;
			int year;
			char temp;
			int day;
			int month;
			std::cout << "Enter your date of birth(YYYY/M/D) - ";
			std::cin >> data;
			std::stringstream timer(data);
			timer >> year >> temp >> month >> temp >> day;
			birthday[month][day].push_back(name);
		}
	}
	std::map<int, std::map<int, std::vector<std::string>>>::const_iterator find_birthday;
	std::time_t timer = time(nullptr);
	std::tm t = *std::localtime(&timer);
	int temp_month = t.tm_mon;
	int temp_day = t.tm_mday;
	find_birthday = birthday.lower_bound(temp_month);
	bool not_birthday= true;
	while (find_birthday != birthday.end())
	{
		if ((find_birthday->first)-1 > t.tm_mon)
		{
			std::cout <<"Month " << find_birthday->first << " " <<"Day "<< find_birthday->second.lower_bound(0)->first << std::endl;
			for (const auto& names : find_birthday->second.lower_bound(0)->second)
				std::cout << names << std::endl;
			not_birthday = false;
		}
		else if ((find_birthday->first)-1 == t.tm_mon)
		{
			auto beg = find_birthday->second.lower_bound(temp_day);
			if (beg != find_birthday->second.end())
			{
				
				std::cout << "Month " << find_birthday->first << " " << "Day " << find_birthday->second.lower_bound(0)->first << std::endl;
				if (beg->first == temp_day)
					std::cout << "Today is the birthday !!!!!\n";
				for (const auto& names : find_birthday->second.lower_bound(temp_day)->second)
					std::cout << names << std::endl;
				not_birthday = false;
				break;
			}

		}
		find_birthday++;
	}
	if (not_birthday)
	{
		std::cout << "There are no birthdays until the end of this year\n";
	}
}