#pragma once
namespace HackAssembler
{
	class ISymbolMapper
	{
	public:
		virtual bool map_DestinationInstruction(const std::string& stringMapped, std::string& outPutString) = 0;
		virtual bool map_ComputationInstruction(const std::string& stringMapped, std::string& outPutString) = 0;
		virtual bool map_JumpInstruction(const std::string& stringMapped, std::string& outPutString) = 0;
	};
}