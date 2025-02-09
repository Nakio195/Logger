#pragma once

#include <stdint.h>
#include <string>

class Message
{
	public:
		enum Level{Debug, Info, Warning, Error, Critical};
		Message(Level type);
		
		Level level();
		void setLevel(Level level);
	
		std::string toString();
		std::string levelToString();

		Message& operator<<(Level level);
		Message& operator<<(std::string text);
		Message& operator<<(uint32_t number);

	protected:
		Level mLevel;
		uint32_t mCode;
		std::string mMessage;
};

