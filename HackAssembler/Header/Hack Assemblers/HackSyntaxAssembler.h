#pragma once
#include <memory>
#include <string>
#include <sstream>
#include "HackSymbolMapper.h"
#include "HackSyntaxParser.h"
#include "BinaryConverter16.h"

namespace HackAssembler
{
	typedef std::shared_ptr<HackAssembler::ISymbolMapper> ptr_Mapper;
	typedef std::shared_ptr<HackAssembler::ISyntaxParser> ptr_Parser;

	class HackSyntaxAssembler
	{
	private:
		std::shared_ptr<HackAssembler::ISymbolMapper> mapper;
		std::shared_ptr<HackAssembler::ISyntaxParser> parser;
		HackAssembler::BinaryConverter16 binaryConverter;

	public:
		HackSyntaxAssembler(HackAssembler::ptr_Mapper mapperPtr, HackAssembler::ptr_Parser parserPtr) :
			mapper(mapperPtr), parser(parserPtr)
		{}
		HackSyntaxAssembler()
		{}

	public:
		void set_Mapper(const ptr_Mapper& mapperPtr);
		void set_Parser(const ptr_Parser& parserPtr);
	public:
		const ptr_Mapper & get_Mapper() const;
		const ptr_Parser & get_Parser() const;
	public:
		bool deAssemble(const std::string& stringAssembled, std::string& stringOutput);
	};



}