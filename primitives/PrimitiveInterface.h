#pragma once
#include <string>

class PrimitiveInterface {
public:
    virtual ~PrimitiveInterface() = default;
    virtual int GetId() const = 0;
    virtual std::string GetType() const = 0;
    virtual void draw() const = 0;
};