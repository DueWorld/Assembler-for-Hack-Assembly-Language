#include<iostream>
#include <string>
#include<memory>
#include<vector>
#include <sstream>
#include<iostream>
#include <fstream>
#include "HackSyntaxParser.h"
#include "HackSymbolMapper.h";
#include"StringUtilities.h";
#include "HackSyntaxAssembler.h"
#include "ISyntaxParser.h"

int main()
{
	HackAssembler::SyntaxParser parser;
	HackAssembler::HackSymbolMapper mapper;
	HackAssembler::HackSyntaxAssembler assembler = HackAssembler::HackSyntaxAssembler(std::make_shared<HackAssembler::HackSymbolMapper>(mapper), std::make_shared<HackAssembler::SyntaxParser>(parser));

	std::ifstream fStream;
	fStream.open("Enter your text here");

	std::ofstream myfile;
	myfile.open("Enter your text here");

	std::string out;
	for (std::string line; std::getline(fStream, line); )
	{
		if (assembler.deAssemble(line, out))
			myfile<<out.c_str()<<std::endl;		
	}

	myfile.close();
	fStream.close();
}