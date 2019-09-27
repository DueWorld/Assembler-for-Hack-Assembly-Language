#include"HackSyntaxParser.h"
#include"StringUtilities.h"
#include <vector>

typedef HackAssembler_Utilities::StringUtilities stringUtil;

HackAssembler::SyntaxParser::SyntaxParser()
{
	this->syntaxError = false;
	this->aInstruction = false;
}

void HackAssembler::SyntaxParser::parse(const std::string & toBeParsedString)
{
	this->deduceAorCInstruction(toBeParsedString);
	if (aInstruction)
	{
		//int integer = 0;
		std::string addressValCandidate = toBeParsedString.substr(1);
		/*if (stringUtil::try_Parse_int(addressValCandidate, integer))
		{*/
			this->addressValue = addressValCandidate;
			this->destination = "NA";
			this->computation = "NA";
			this->gotoInstruction = "NA";
	/*	}
		else
			this->syntaxError = true;*/
	}
	else
	{
		std::vector<std::string> container;

		bool foundEquals = stringUtil::contains(toBeParsedString, '=');
		bool foundSemiColon = stringUtil::contains(toBeParsedString, ';');

		if (foundEquals&& foundSemiColon)
		{
			HackAssembler_Utilities::StringUtilities::split(toBeParsedString, '=', container);
			std::string returnedString(toBeParsedString);

			this->destination = container.front();
			container.clear();

			size_t pos = returnedString.find('=');
			returnedString.erase(0, pos + 1);

			HackAssembler_Utilities::StringUtilities::split(returnedString, ';', container);
			this->computation = container.front();
			this->gotoInstruction = container.back();
		}
		else if (foundEquals && !foundSemiColon)
		{
			HackAssembler_Utilities::StringUtilities::split(toBeParsedString, '=', container);
			this->destination = container.front();
			this->computation = container.back();
			this->gotoInstruction = "NULL";
		}
		else if (foundSemiColon && !foundEquals)
		{
			HackAssembler_Utilities::StringUtilities::split(toBeParsedString, ';', container);
			this->computation = container.front();
			this->gotoInstruction = container.back();
			this->destination = "NULL";
		}
		else
		{
			this->syntaxError = true;
		}

		this->addressValue = "NA";
	}
}

const std::string & HackAssembler::SyntaxParser::getDestination() const
{
	return this->destination;
}

const std::string & HackAssembler::SyntaxParser::getComputation() const
{
	return this->computation;
}

const std::string & HackAssembler::SyntaxParser::getGotoInstruction() const
{
	return this->gotoInstruction;
}

const bool HackAssembler::SyntaxParser::isAInstruction() const
{
	return aInstruction;
}

const bool HackAssembler::SyntaxParser::isSyntaxError() const
{
	return this->syntaxError;
}

const std::string & HackAssembler::SyntaxParser::getAddressValue() const
{
	return addressValue;
}

void HackAssembler::SyntaxParser::deduceAorCInstruction(const std::string & targetString)
{
	if (targetString.rfind("@", 0) == 0)
		this->aInstruction = true;
	else
		this->aInstruction = false;
}
