#include "HackSyntaxAssembler.h"
#include"StringUtilities.h"
#include<StringHackUtilities.h>
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
	bool validInstruction = HackAssembler_Utilities::StringHackUtilities::tryGetUncommentedLine(stringAssembled, comp);
	bool symbolJump = HackAssembler_Utilities::StringHackUtilities::isJumpSymbol(comp);

	if (!validInstruction || symbolJump)
		return false;

	this->parser->parse(comp);

	if (parser->isSyntaxError())
		return false;

	if (parser->isAInstruction())
	{
		mapper->map_Symbol(parser->getAddressValue(), stringOutput);
		stringOutput = this->binaryConverter.ConvertTo16BitBinary(stringOutput);
		return true;
	}

	stringOutput = "111";

	if (!mapper->map_ComputationInstruction(parser->getComputation(), comp))
		return false;

	stringOutput.append(comp);

	if (!mapper->map_DestinationInstruction(parser->getDestination(), comp))
		return false;

	stringOutput.append(comp);

	if (!mapper->map_JumpInstruction(parser->getGotoInstruction(), comp))
		return false;

	stringOutput.append(comp);

	return true;
}


