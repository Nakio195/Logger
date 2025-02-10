#pragma once
#include "Logger.h"
#include <string>
#include "ArduinoJson-v7.3.0.h"

class JsonLogger : public Logger
{
	public:
		JsonLogger();

		void print(Message &m) override;

	private:
		JsonDocument mDocument;
};

