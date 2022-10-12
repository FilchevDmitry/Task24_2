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
			std::cin>>data;
			std::stringstream timer(data);
			timer >> year >>temp>>month>>temp>>day;		
			birthday[month][day].push_back(name);
		}
	}
		std::map<int, std::map<int,std::vector<std::string>>>::const_iterator find_birthday;
		std::time_t timer = time(nullptr);
		std::tm t = *std::localtime(&timer);
		int temp_month = t.tm_mon;
		int temp_day=t.tm_mday;
		find_birthday = birthday.lower_bound(temp_month);
		if (find_birthday != birthday.end())
		{
			std::cout << find_birthday->second.lower_bound(temp_day)->second.at(0) << std::endl;
		}
}
