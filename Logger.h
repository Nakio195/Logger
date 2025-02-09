#pragma once

#include "Message.h"
#include <deque>
#include <iostream>

class Logger
{
	public:
		Logger(Message::Level logLevel);
		void setLogLevel(Message::Level level);

		// Override this function to implement specific IO hardware
		virtual void print(Message m);

		void log(Message m);

	private:
		std::deque<Message> mMessages;
		Message::Level mLogLevel;

};

