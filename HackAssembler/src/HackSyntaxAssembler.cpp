#include "HackSyntaxAssembler.h"

void HackAssembler::HackSyntaxAssembler::set_Mapper(const ptr_Mapper& mapperPtr)
{
	this->mapper = mapperPtr;
}

void HackAssembler::HackSyntaxAssembler::set_Parser(const ptr_Parser& parserPtr)
{
	this->parser = parserPtr;
}

const ptr_Mapper & HackAssembler::HackSyntaxAssembler::get_Mapper() const
{
	return this->mapper;
}

const ptr_Parser & HackAssembler::HackSyntaxAssembler::get_Parser() const
{
	return this->parser;
}

bool HackAssembler::HackSyntaxAssembler::deAssemble(const std::string & stringAssembled, std::string & stringOutput)
{
	this->parser->parse(stringAssembled);
	if (parser->isSyntaxError())
		return false;

	else if (parser->isAInstruction())
	{
		stringOutput = this->binaryConverter.ConvertTo16BitBinary(parser->getAddressValue());
	}
	else
	{
		stringOutput = "111";
		std::string comp;
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
