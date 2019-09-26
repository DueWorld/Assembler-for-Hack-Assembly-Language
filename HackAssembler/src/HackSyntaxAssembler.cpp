#include "HackSyntaxAssembler.h"
#include"StringUtilities.h"
#include<vector>
#include<algorithm>

void HackAssembler::HackSyntaxAssembler::set_Mapper(const ptr_Mapper& mapperPtr)
{
	this->mapper = mapperPtr;
}

void HackAssembler::HackSyntaxAssembler::set_Parser(const ptr_Parser& parserPtr)
{
	this->parser = parserPtr;
}

const HackAssembler::ptr_Mapper & HackAssembler::HackSyntaxAssembler::get_Mapper() const
{
	return this->mapper;
}

const HackAssembler::ptr_Parser & HackAssembler::HackSyntaxAssembler::get_Parser() const
{
	return this->parser;
}

bool HackAssembler::HackSyntaxAssembler::deAssemble(const std::string & stringAssembled, std::string & stringOutput)
{
	std::string comp;
	if (!tryGetUncommentedLine(stringAssembled, comp))
		return false;

	else {

		this->parser->parse(comp);

		if (parser->isSyntaxError())
			return false;

		else if (parser->isAInstruction())
		{
			stringOutput = this->binaryConverter.ConvertTo16BitBinary(parser->getAddressValue());
		}

		else
		{
			stringOutput = "111";

			if (this->mapper->map_ComputationInstruction(this->parser->getComputation(), comp))
				stringOutput.append(comp);
			else
				return false;
			if (this->mapper->map_DestinationInstruction(this->parser->getDestination(), comp))
				stringOutput.append(comp);
			else
				return false;
			if (this->mapper->map_JumpInstruction(this->parser->getGotoInstruction(), comp))
				stringOutput.append(comp);
			else
				return false;

			return true;
		}
	}
}

bool HackAssembler::HackSyntaxAssembler::tryGetUncommentedLine(const std::string & s, std::string & outputString)
{
	bool isWhite = HackAssembler_Utilities::StringUtilities::is_WhiteSpace(s);
	bool isComment = s.rfind("//", 0) == 0;
	if (!isWhite && !isComment)
	{
		std::vector<std::string> d;
		HackAssembler_Utilities::StringUtilities::split(s, '//', d);
		outputString = d.front();
		outputString.erase(std::remove(outputString.begin(), outputString.end(), ' '), outputString.end());
	}
	else
		return false;
}

