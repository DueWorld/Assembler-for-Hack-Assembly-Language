#include "StringHackUtilities.h"
#include<vector>
#include<StringUtilities.h>
#include<algorithm>

typedef HackAssembler_Utilities::StringUtilities stringUtil;
typedef HackAssembler_Utilities::StringHackUtilities stringHackUtil;

bool HackAssembler_Utilities::StringHackUtilities::tryGetUncommentedLine(const std::string & s, std::string & outputString)
{
	bool isWhite = HackAssembler_Utilities::StringUtilities::is_WhiteSpace(s);
	bool isComment = s.rfind("//", 0) == 0;
	if (!isWhite && !isComment)
	{
		std::vector<std::string> d;
		HackAssembler_Utilities::StringUtilities::split(s, '//', d);
		outputString = d.front();
		outputString.erase(std::remove(outputString.begin(), outputString.end(), ' '), outputString.end());
		return true;
	}
	else
		return false;
}

bool HackAssembler_Utilities::StringHackUtilities::tryGetJumbSymbol(const std::string & nonCommentString, std::string & outputString)
{
	if (isJumpSymbol(nonCommentString))
	{
		outputString = nonCommentString;
		outputString.erase(std::remove(outputString.begin(), outputString.end(), '('), outputString.end());
		outputString.erase(std::remove(outputString.begin(), outputString.end(), ')'), outputString.end());
		return true;
	}
	else
		return false;
}

bool HackAssembler_Utilities::StringHackUtilities::tryGetAddressSymbol(const std::string & nonCommentString, std::string & outputString)
{
	/*int x = 0;
	if (HackAssembler_Utilities::StringUtilities::try_Parse_int(nonCommentString, x))
	{
		outputString = std::to_string(x);

	}
	else
	{
		outputString = nonCommentString;
	}*/

	return true;
}

bool HackAssembler_Utilities::StringHackUtilities::tryGetSymbol(const std::string & nonCommentString, std::string & outputString)
{
	if (isJumpSymbol(nonCommentString))
	{

	}
	else
		return false;
}

bool HackAssembler_Utilities::StringHackUtilities::isJumpSymbol(const std::string nonCommentString)
{
	return stringUtil::contains(nonCommentString, '(');
}
