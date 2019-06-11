#pragma once

#include <string>

namespace Tools
{
	class Logger
	{
	public:
		Logger();
		~Logger();
		static void log(std::string);
	};
}


