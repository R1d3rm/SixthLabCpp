#pragma once
#include <memory>
#include <string>
#include "../primitives/DocumentInterface.h"
#include "../primitives/PrimitiveInterface.h"
#include "../output/OutputInterface.h"

class CoreInterface {
public:
    virtual ~CoreInterface() = default;
    virtual std::shared_ptr<DocumentInterface> createDocument() = 0;
    virtual std::shared_ptr<DocumentInterface> importDocument(const std::string& filename) = 0;
    virtual void exportDocument(const std::shared_ptr<DocumentInterface>& document, const std::string& filename) = 0;
    virtual void addPrimitive(const std::shared_ptr<DocumentInterface>& document, const std::shared_ptr<PrimitiveInterface>& primitive) = 0;
    virtual void deletePrimitive(const std::shared_ptr<DocumentInterface>& document, int primitiveId) = 0;
};