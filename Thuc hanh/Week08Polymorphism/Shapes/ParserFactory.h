#pragma once

#include <iostream>
#include <map>
#include "Object.h"
#include "Parse.h"

class ParserFactory {
private:
    std::map<std::string, std::shared_ptr<IParsable>> _container; 
protected:
    ParserFactory() { }
    static ParserFactory* instance;
public:
    ParserFactory(ParserFactory &other) = delete;

    void operator= (const ParserFactory& other) = delete;

    static ParserFactory* getInstance() {
        if (nullptr == instance) {
            instance = new ParserFactory;
        }
        return instance;
    }

    void registerWith(shared_ptr<IParsable> parser) {
        _container.insert(
            {parser->parsedObjectName(), parser}
        );
    }

    std::shared_ptr<IParsable> create(std::string type) {
        return _container[type];
    }

    ~ParserFactory() {
        delete instance;
    }
};