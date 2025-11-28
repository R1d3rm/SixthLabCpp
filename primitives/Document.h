#pragma once
#include "DocumentInterface.h"
#include <vector>
#include <memory>
#include <algorithm>

class Document : public DocumentInterface {
public:
    Document();
    ~Document() override = default;
    int GetId() const override;
    void addPrimitive(std::shared_ptr<PrimitiveInterface> primitive) override;
    void deletePrimitive(int id) override;
    const std::vector<std::shared_ptr<PrimitiveInterface>>& getPrimitives() const override;

private:
    static int nextId;
    int id;
    std::vector<std::shared_ptr<PrimitiveInterface>> primitives;
};