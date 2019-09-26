#include<string>
#include<sstream>
#include<vector>
#include"StringUtilities.h"
#include <algorithm>

std::vector<std::string> & HackAssembler_Utilities::StringUtilities::split(const std::string &s, char delim, std::vector<std::string> &elems)
{
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

bool HackAssembler_Utilities::StringUtilities::contains(const std::string & s, char containedChar)
{
	return (s.find(containedChar, 0) != s.npos);
}

bool HackAssembler_Utilities::StringUtilities::try_Parse_int(const std::string & s, int & output)
{
	std::stringstream ss(s);
	int outBeforeProcess = output;
	if ((ss >> output).fail() || !(ss >> std::ws).eof())
	{
		output = outBeforeProcess;
		return false;
	}
	return true;
}

bool HackAssembler_Utilities::StringUtilities::try_Parse_double(const std::string & s, double & output)
{
	std::stringstream ss(s);
	double outBeforeProcess = output;
	if ((ss >> output).fail() || !(ss >> std::ws).eof())
	{
		output = outBeforeProcess;
		return false;
	}
	return true;
}

bool HackAssembler_Utilities::StringUtilities::is_WhiteSpace(const std::string& s)
{
	return std::all_of(s.begin(), s.end(), isspace);
}
