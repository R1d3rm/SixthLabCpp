#include "Output.h"
#include "../primitives/DocumentInterface.h"
#include <iostream>

void Output::printDocumentInfo(const DocumentInterface& document) const {
    std::cout << "--- Document ID: " << document.GetId() << " ---" << std::endl;
    const auto& primitives = document.getPrimitives();
    std::cout << "Number of primitives: " << primitives.size() << std::endl;
    for (const auto& primitive : primitives) {
        primitive->draw();
    }
}

void Output::printPrimitiveInfo(int primitiveId, const std::string& type) const {
    std::cout << "Primitive " << type << " (ID: " << primitiveId << ") added" << std::endl;
}