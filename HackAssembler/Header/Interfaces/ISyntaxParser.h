#pragma once
#include<string>
namespace HackAssembler
{
	class ISyntaxParser
	{
	public:
		virtual void parse(const std::string& toBeParsedString) = 0;
		virtual const std::string&  getComputation() const = 0;
		virtual const std::string& getDestination() const = 0;
		virtual const std::string&  getGotoInstruction() const = 0;
		virtual const bool isAInstruction() const = 0;
		virtual const bool isSyntaxError() const = 0;
		virtual const std::string& getAddressValue() const = 0;
	};
}