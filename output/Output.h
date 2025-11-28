#pragma once
#include "OutputInterface.h"

class Output : public OutputInterface {
public:
    void printDocumentInfo(const DocumentInterface& document) const override;
    void printPrimitiveInfo(int primitiveId, const std::string& type) const override;
};