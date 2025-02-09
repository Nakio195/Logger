#include "Message.h"

Message::Message(Level level)
{
	mLevel = level;
	mCode = 0;
	mMessage = "";
}

Message::Level Message::level()
{
	return mLevel;
}
void Message::setLevel(Level level)
{
	mLevel = level;
}

std::string Message::toString()
{
	std::string out;

	out += levelToString();
	if(mCode != 0)
	{
		out += " - ";
		out += std::to_string(mCode);
	}

	if(!mMessage.empty())
	{
		out += " : ";
		out += mMessage;
	}

	out += "\n";

	return out;
}

std::string Message::levelToString()
{
	switch (mLevel)
	{
		case Info:
			return std::string("[INFO]");
		case Warning:
			return std::string("[WARN]");
		case Error:
			return std::string("[ERROR]");
		case Critical:
			return std::string("[CRITICAL]");
		case Debug:
			return std::string("[DEBUG]");
		default:
			return std::string("[UNKNOWN]");
	}
}

Message& Message::operator<<(Level level)
{
	mLevel = level;
	return *this;
}

Message& Message::operator<<(std::string text)
{
	mMessage += text + " ";
	return *this;
}

Message& Message::operator<<(uint32_t number)
{
	mMessage += std::to_string(number) + " ";
	return *this;
}


