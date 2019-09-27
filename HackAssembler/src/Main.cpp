#include<iostream>
#include <string>
#include<memory>
#include<vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include "HackSyntaxParser.h"
#include "HackSymbolMapper.h"
#include "HackSyntaxAssembler.h"

int main()
{
	HackAssembler::SyntaxParser parser;
	HackAssembler::HackSymbolMapper mapper;
	HackAssembler::HackSyntaxAssembler assembler = HackAssembler::HackSyntaxAssembler(std::make_shared<HackAssembler::HackSymbolMapper>(mapper), std::make_shared<HackAssembler::SyntaxParser>(parser));

	std::ifstream fStream;
	fStream.open("E:\\Tech\\Important Coding Courses\\CS\\nand2tetris\\nand2tetris\\projects\\06\\pong\\PongL.asm");

	std::ofstream myfile;
	myfile.open("E:\\Tech\\Important Coding Courses\\CS\\nand2tetris\\nand2tetris\\projects\\06\\pong\\PongComppL.hack");

	std::string out;
	for (std::string line; std::getline(fStream, line); )
	{
		if (assembler.deAssemble(line, out))
			myfile << out.c_str() << std::endl;
	}

	myfile.close();
	fStream.close();
}