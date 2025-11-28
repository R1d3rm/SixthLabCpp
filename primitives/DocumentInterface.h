#pragma once
#include <string>
#include <memory>
#include <vector>
#include "PrimitiveInterface.h"

class DocumentInterface {
public:
    virtual ~DocumentInterface() = default;
    virtual int GetId() const = 0;
    virtual void addPrimitive(std::shared_ptr<PrimitiveInterface> primitive) = 0;
    virtual void deletePrimitive(int id) = 0;
    virtual const std::vector<std::shared_ptr<PrimitiveInterface>>& getPrimitives() const = 0;
};