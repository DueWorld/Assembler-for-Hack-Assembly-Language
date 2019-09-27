#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include "HackSyntaxParser.h"
#include "HackSymbolMapper.h"
#include "HackSyntaxAssembler.h"



int main()
{
	std::shared_ptr<HackAssembler::HackSymbolMapper> mapperPtr = std::make_shared<HackAssembler::HackSymbolMapper>();
	HackAssembler::HackSyntaxAssembler assembler = HackAssembler::HackSyntaxAssembler(mapperPtr, std::make_shared<HackAssembler::SyntaxParser>());
	char* readPath = "YOUR PATH FROM ARG";
	char* writePath = "YOUR PATH FROM ARG";
	std::ifstream fStream;

	mapperPtr->init_SymbolTable(fStream, readPath);
	fStream.open(readPath);

	std::ofstream myfile;
	myfile.open(writePath);

	std::string out;
	for (std::string line; std::getline(fStream, line); )
	{
		if (assembler.deAssemble(line, out))
			myfile << out.c_str() << std::endl;
	}
	
	myfile.close();
	fStream.close();
}