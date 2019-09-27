#pragma once
#include"ISyntaxParser.h"
#include "ISymbolMapper.h"

namespace HackAssembler
{
	class SyntaxParser : public ISyntaxParser
	{
	private:
		std::string destination;
		std::string computation;
		std::string gotoInstruction;
		std::string addressValue;
		bool aInstruction;
		bool syntaxError;
	public:
		SyntaxParser();
	public:
		void parse(const std::string& toBeParsedString) override;
	public:
		const std::string& getDestination() const override;
		const std::string&  getComputation() const override;
		const std::string&  getGotoInstruction() const override;
		const bool isAInstruction() const override;
		const bool isSyntaxError() const override;
		const std::string& getAddressValue() const override;
	private:
		void deduceAorCInstruction(const std::string& targetString);
	};












}