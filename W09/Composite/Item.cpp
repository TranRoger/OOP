#include "Item.h"

// CFile method implementation

// constructor
CFile::CFile(const std::string& name, const int& size) : 
    _name(name), _size(size), _readOnly(false), _hidden(false) { }

// method
CItem* CFile::findByName(const std::string& name) {
    if (!_hidden && name == _name) return this;
    return nullptr;
}

void CFile::print(const bool& printHidden) {
    if (printHidden || !this->_hidden) { // only when function call does not print hidden file and the file is hidden does the function print nothing
        Indent::indent++;
        Indent::tab();
        std::cout << _name << "--> Size: " << _size << "Bytes" << std::endl;
        Indent::indent--;
    }
}

void CFile::setHidden(const bool& hidden, const bool& toChildren) {
    this->_hidden = hidden;
}

std::string CFile::name() {
    return this->_name;
}

bool CFile::isHidden() {
    return this->_hidden;
}

int CFile::size() {
    return this->_size;
}

// CFolder method implementation

// constructor
CFolder::CFolder(const std::string& name) :
    _name(name), _size(0), _hidden(false) { _components.resize(0); }

// method
void CFolder::add(CItem* item) {
    for (auto i : _components) {
        if (item->name() == i->name()) {
            std::cout << "File or folder is already existed." << std::endl;
            return;
        }
    }
    this->_components.push_back(item);
    this->_size += item->size();
}

CItem* CFolder::removeByName(const std::string& name) {
    for (auto i = _components.begin(); i != _components.end(); i++) { // use iterator to loop through vector and find for file or folder with given name
        if ((*i)->name() == name) {
            CItem* result = *i;
            _components.erase(i);
            return result;
        }
    }
    return nullptr; // return nullptr if no file with given name was found
}

CItem* CFolder::findByName(const std::string& name) {
    if (!_hidden && name == _name) return this;
    for (auto i : _components) {
        CItem* r = i->findByName(name);
        if (nullptr != r) return r;
    }
    return nullptr; // return nullptr if no file or folder was found
}

void CFolder::print(const bool& printHidden) {
    if (!printHidden && _hidden) return;
    Indent::indent++;
    Indent::tab();
    std::cout << _name << "--> Size: " << _size << " Bytes" << std::endl;
    for (auto i : _components) {
        i->print(printHidden);
    }
    Indent::indent--;
}

void CFolder::setHidden(const bool& hidden, const bool& toChildren) {
    this->_hidden = hidden;
    if (!toChildren) {
        for (auto i : _components) {
            i->setHidden(hidden, toChildren);
        }
    }
}

std::string CFolder::name() {
    return this->_name;
}

bool CFolder::isHidden() {
    return this->_hidden;
}

int CFolder::size() {
    return this->_size;
}
