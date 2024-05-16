#pragma once

#include <iostream>
#include <vector>
#include <string>

class CItem {
public:
    virtual void print(const bool&) = 0;
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
    CItem* findByName(const std::string&);
    void print(const bool&);

    void setHidden(const bool&, const bool&) override;
    std::string name() override;
    bool isHidden() override;
    int size() override;
};