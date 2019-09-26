#include "BinaryConverter16.h"
#include<string>

//////////////////////////////////////////////////////////
//Converts the given binary into a 16 bit binary format.
//////////////////////////////////////////////////////////
std::string HackAssembler::BinaryConverter16::ConvertTo16BitBinary(const std::string & targetString)
{
	std::string binaryString;
	int number = std::stoi(targetString);
	for (int i = 0; i < 16; i++)
	{
		if (number != 0)
			binaryString.insert(0,std::to_string(number % 2));
		else
			binaryString.insert(0, 1,'0');
		number = number / 2;
	}
	return binaryString;
}
