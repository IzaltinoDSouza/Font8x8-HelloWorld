#include <iostream>
#include <string>

#include "font8x8.h"

const int fontSize{8};

std::string font8x8LineByLine(uint8_t font[fontSize],int line)
{
	if(line >= fontSize)
		return {};
	
	std::string buffer;
	buffer.reserve(fontSize*line);
	for(int bitPos = 0;bitPos < fontSize;++bitPos){
		buffer += (((font[line] >> bitPos) & 1) ? '#' : ' ');
	}
	return buffer;
}

std::string font8x8String(const std::string &str)
{
	std::string buffer;
	for(int line = 0;line < fontSize;++line){
		for(const uint8_t &c : str){
			buffer += font8x8LineByLine(font8x8_basic[c],line);
			buffer += "  ";
		}
		buffer += '\n';
	}
	return buffer;
}

int main()
{	
	std::cout << font8x8String("Hello World") << '\n';
}