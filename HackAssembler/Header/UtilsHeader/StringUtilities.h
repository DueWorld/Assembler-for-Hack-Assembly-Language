#pragma once
#include<vector>
#include<string>

namespace HackAssembler_Utilities
{
	class StringUtilities
	{
	public:
		static std::vector<std::string> & split(const std::string &s, char delim, std::vector<std::string> &elems);
		static bool contains(const std::string & s, char contained);
		static bool try_Parse_int(const std::string & s, int& output);
		static bool try_Parse_double(const std::string & s, double & output);
		static bool is_WhiteSpace(const std::string& s);
		static bool parsable_toInt(const std::string & s);

	private:
		StringUtilities() {}
	};

}