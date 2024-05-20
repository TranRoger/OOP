#pragma once

#include <iostream>
#include <map>
#include "../Entity/Object.h"
#include "IParsable.h"

using std::string, std::map;

class ParserFactory: public Object {
private:
	map<string, IParsable*> _container;

public:
	void registerWith(IParsable* parser) {
		_container.insert({ parser->parsedObjectName(), parser });
	}

	IParsable* create(string type) {
		return _container[type];
	}

	string toString() {
		return "Parse Factory";
	}
};