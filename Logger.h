#pragma once

#include "Message.h"
#include <deque>
#include <iostream>

class Logger
{
	public:
		Logger();
		void setLogLevel(Message::Level level);

		// Override this function to implement specific IO hardware
		virtual void print(Message &m);

		// Add a message to the FIFO to be printed
		void log(Message m);

		// Returns the number of available messages in FIFO
		size_t available();


		virtual void run();

	private:
		std::deque<Message> mMessages;
		Message::Level mLogLevel;

};

