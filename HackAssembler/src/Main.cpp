#include<iostream>
#include <string>
#include "HackSyntaxParser.h"
#include "HackSymbolMapper.h";
#include"StringUtilities.h";
#include "HackSyntaxAssembler.h"
#include<memory>
#include<vector>
#include <sstream>



int main()
{
	//std::shared_ptr<HackAssembler::BinaryConverter16> converter = std::make_shared<HackAssembler::BinaryConverter16>();
	
	HackAssembler::SyntaxParser parser;
	HackAssembler::HackSymbolMapper mapper;
	HackAssembler::HackSyntaxAssembler assembler = HackAssembler::HackSyntaxAssembler(std::make_shared<HackAssembler::HackSymbolMapper>(mapper), std::make_shared<HackAssembler::SyntaxParser>(parser));

	
	//HackAssembler::HackSymbolMapper symbolMapper;
    //auto map = symbolMapper.get_computationMap();
    //std::string stringMapped = map["A+1"];
    //std::cout << parser.getDestination() << std::endl;
    //std::cout << parser.getComputation() << std::endl;
    //std::cout << parser.getGotoInstruction() << std::endl;
    //std::cout << parser.getAddressValue() << std::endl;
    //std::cin.get();

	/*std::string test = "D=D+M";
	std::string output;
	assembler.deAssemble(test,output);*/
}