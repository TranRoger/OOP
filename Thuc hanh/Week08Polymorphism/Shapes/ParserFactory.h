#pragma once

#include <iostream>
#include <map>
#include "Object.h"
#include "Parse.h"

class ParserFactory {
private:
    std::map<std::string, IParsable*> _container; 
public:
    void registerWith(IParsable* parser) {
        _container.insert(
            {parser->parsedObjectName(), parser}
        );
    }

    IParsable *create(std::string type) {
        return _container[type];
    }

    ~ParserFactory() {
        for (auto &p : _container) {
        delete p.second;
        }
    }
};