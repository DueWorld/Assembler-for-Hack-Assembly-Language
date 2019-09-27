#pragma once
#include<string>
namespace HackAssembler_Utilities
{
	class StringHackUtilities
	{
	public:
		static bool tryGetUncommentedLine(const std::string & s, std::string & outputString);
		static bool tryGetJumbSymbol(const std::string & nonCommentString, std::string & outputString);
		static bool tryGetAddressSymbol(const std::string & nonCommentString, std::string & outputString);
		static bool tryGetSymbol(const std::string & nonCommentString, std::string & outputString);
		static bool isJumpSymbol(const std::string nonCommentString);
	private:
		StringHackUtilities() {}
	};

}