#pragma once
#include <iostream>
#include <fstream>

namespace HackAssembler
{
	class ISymbolMapper
	{
	public:
		virtual bool map_DestinationInstruction(const std::string& stringMapped, std::string& outPutString) = 0;
		virtual bool map_ComputationInstruction(const std::string& stringMapped, std::string& outPutString) = 0;
		virtual bool map_JumpInstruction(const std::string& stringMapped, std::string& outPutString) = 0;
		virtual void map_Symbol(const std::string& stringToBeMapped, std::string& outPutString)=0;
		virtual void init_SymbolTable(std::ifstream & stream, const std::string& filePath) =0;
	};
}