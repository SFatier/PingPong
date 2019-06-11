#include "Logger.h"
#include <iostream>

namespace Tools
{
	Logger::Logger()
	{
	}


	Logger::~Logger()
	{
	}

	/*static*/ void Logger::log(std::string str)
	{
		std::cout << str << std::endl;
	}
}

