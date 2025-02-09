#include "Logger.h"

Logger::Logger(Message::Level logLevel) : mLogLevel(logLevel)
{
}

void Logger::setLogLevel(Message::Level level)
{
	mLogLevel = level;
}

void Logger::print(Message m)
{
	std::cout << m.toString();
}

void Logger::log(Message m)
{
	mMessages.push_back(m);
}

