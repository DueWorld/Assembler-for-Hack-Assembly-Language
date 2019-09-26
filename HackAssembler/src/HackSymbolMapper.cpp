#include "..\Header\Hack Assemblers\HackSymbolMapper.h"

const std::unordered_map<std::string, std::string>& HackAssembler::HackSymbolMapper::get_DestinationMap() const
{
	return this->destinationMap;
 }

const std::unordered_map<std::string, std::string>& HackAssembler::HackSymbolMapper::get_computationMap() const
{
	return this->computationMap;
}

const std::unordered_map<std::string, std::string>& HackAssembler::HackSymbolMapper::get_jumpMap() const
{
	return this->jumpMap;
}

void HackAssembler::HackSymbolMapper::initDestinationMap()
{
	this->destinationMap.emplace("NULL", "000");
	this->destinationMap.emplace("M", "001");
	this->destinationMap.emplace("D", "010");
	this->destinationMap.emplace("MD", "011");
	this->destinationMap.emplace("A", "100");
	this->destinationMap.emplace("AM", "101");
	this->destinationMap.emplace("AD", "110");
	this->destinationMap.emplace("AMD", "111");

}

void HackAssembler::HackSymbolMapper::initComputationMap()
{
	this->computationMap.emplace("0", "0101010");
	this->computationMap.emplace("1", "0111111");
	this->computationMap.emplace("-1","0111010");
	this->computationMap.emplace("D", "0001100");
	this->computationMap.emplace("A", "0110000");
	this->computationMap.emplace("!D","0001101");
	this->computationMap.emplace("!A","0110001");
	this->computationMap.emplace("-D","0001111");
	this->computationMap.emplace("-A","0110011");
	this->computationMap.emplace("D+1","0011111");
	this->computationMap.emplace("A+1","0110111");
	this->computationMap.emplace("D-1","0001110");
	this->computationMap.emplace("A-1","0110010");
	this->computationMap.emplace("D+A","0000010");
	this->computationMap.emplace("D-A","0010011");
	this->computationMap.emplace("A-D","0000111");
	this->computationMap.emplace("D&A","0000000");
	this->computationMap.emplace("D|A","0010101");
	this->computationMap.emplace("M", "1110000");
	this->computationMap.emplace("!M", "1110001");
	this->computationMap.emplace("-M", "1110011");
	this->computationMap.emplace("M+1", "1110111");
	this->computationMap.emplace("M-1", "1110010");
	this->computationMap.emplace("D+M", "1000010");
	this->computationMap.emplace("D-M", "1010011");
	this->computationMap.emplace("M-D", "1000111");
	this->computationMap.emplace("D&M", "1000000");
	this->computationMap.emplace("D|M", "1010101");

}

void HackAssembler::HackSymbolMapper::initjumpMap()
{
	this->jumpMap.emplace("NULL", "000");
	this->jumpMap.emplace("JGT", "001");
	this->jumpMap.emplace("JEQ", "010");
	this->jumpMap.emplace("JGE", "011");
	this->jumpMap.emplace("JLT", "100");
	this->jumpMap.emplace("JNE", "101");
	this->jumpMap.emplace("JLE", "110");
	this->jumpMap.emplace("JMP", "111");
}

bool HackAssembler::HackSymbolMapper::map_DestinationInstruction(const std::string & stringMapped, std::string& outPutString)
{
	if (this->destinationMap[stringMapped].empty())
		return false;
	else
	{
		outPutString = this->destinationMap[stringMapped];
		return true;
	}
}

bool HackAssembler::HackSymbolMapper::map_ComputationInstruction(const std::string & stringMapped, std::string& outPutString)
{
	if (this->computationMap[stringMapped].empty())
		return false;
	else
	{
		outPutString = this->computationMap[stringMapped];
		return true;
	}
}

bool HackAssembler::HackSymbolMapper::map_JumpInstruction(const std::string & stringMapped, std::string& outPutString)
{
	if (this->jumpMap[stringMapped].empty())
		return false;
	else
	{
		outPutString = this->jumpMap[stringMapped];
		return true;
	}
}

