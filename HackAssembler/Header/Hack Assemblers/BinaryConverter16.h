#pragma once
#include<string>
namespace HackAssembler
{
    class BinaryConverter16
	{
	public:
			BinaryConverter16()
		{}
	public:
		std::string ConvertTo16BitBinary(const std::string& targetString);
	};
}