#pragma once
#include <unordered_map> 
#include"ISymbolMapper.h"

namespace HackAssembler
{
	class HackSymbolMapper :public ISymbolMapper
	{
	private:
		std::unordered_map<std::string, std::string> destinationMap;
		std::unordered_map<std::string, std::string> computationMap;
		std::unordered_map<std::string, std::string> jumpMap;
	public:
		HackSymbolMapper()
		{
			initDestinationMap();
			initComputationMap();
			initjumpMap();
		}
		const std::unordered_map<std::string, std::string>& get_DestinationMap() const;
		const std::unordered_map<std::string, std::string>& get_computationMap() const;
		const std::unordered_map<std::string, std::string>& get_jumpMap() const;
	private:
		void initDestinationMap();
		void initComputationMap();
		void initjumpMap();
	public:
		bool map_DestinationInstruction(const std::string& stringMapped, std::string& outPutString);
		bool map_ComputationInstruction(const std::string& stringMapped, std::string& outPutString);
		bool map_JumpInstruction(const std::string& stringMapped, std::string& outPutString);
	};
}