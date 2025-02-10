#include "JsonLogger.h"

JsonLogger::JsonLogger() : Logger()
{
}

void JsonLogger::print(Message& m)
{
	mDocument.clear();

	mDocument["level"] = m.level();
	if(m.code() != 0)
		mDocument["code"] = m.code();
	mDocument["message"] = m.message();

	std::string out;
	serializeJson(mDocument, out);
	std::cout << out;
}