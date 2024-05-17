#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class CItem {
public:
    virtual void print(const bool&) = 0;
    virtual CItem* findByName(const std::string&) = 0;
    virtual void setHidden(const bool&, const bool&) = 0;
    virtual std::string name() = 0;
    virtual bool isHidden() = 0;
    virtual int size() = 0;
};

class CFile : public CItem {
private:
    std::string _name;
    int _size;
    bool _readOnly;
    bool _hidden;
public:    
    CFile(const std::string&, const int&);
    
    CItem* findByName(const std::string&) override;
    void print(const bool&) override;
    void setHidden(const bool&, const bool&) override;
    std::string name() override;
    bool isHidden() override;
    int size() override;
};

class CFolder : public CItem {
private:
    std::string _name;
    int _size;
    bool _hidden;
    std::vector<CItem*> _components;
public:
    CFolder(const std::string&);

    void add(CItem*);
    CItem* removeByName(const std::string&);
    CItem* findByName(const std::string&) override;
    void print(const bool&);

    void setHidden(const bool&, const bool&) override;
    std::string name() override;
    bool isHidden() override;
    int size() override;
};

class Indent { // print organized folder tree
public:
    static int indent;
    static void tab() {
        for (int i = 0; i < indent; i++) {
            std::cout << "    ";
        }
    }
};