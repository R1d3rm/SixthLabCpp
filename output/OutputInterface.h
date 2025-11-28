#pragma once
#include <string>
#include <memory>

class DocumentInterface;

class OutputInterface {
public:
    virtual ~OutputInterface() = default;
    virtual void printDocumentInfo(const DocumentInterface& document) const = 0;
    virtual void printPrimitiveInfo(int primitiveId, const std::string& type) const = 0;
};