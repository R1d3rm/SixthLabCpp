#include "Core.h"
#include "../primitives/Document.h"
#include <iostream>
#include <fstream>

int Core::nextId = 1;

Core::Core(std::shared_ptr<OutputInterface> output) : output(output) {}

std::shared_ptr<DocumentInterface> Core::createDocument() {
    auto doc = std::make_shared<Document>();
    documents[doc->GetId()] = doc;
    std::cout << "Document created with ID: " << doc->GetId() << std::endl;
    return doc;
}

std::shared_ptr<DocumentInterface> Core::importDocument(const std::string& filename) {
    std::cout << "Importing document from file: " << filename << std::endl;
    auto doc = std::make_shared<Document>();
    documents[doc->GetId()] = doc;
    return doc;
}

void Core::exportDocument(const std::shared_ptr<DocumentInterface>& document, const std::string& filename) {
    std::cout << "Exporting document " << document->GetId() << " to file: " << filename << std::endl;
}

void Core::addPrimitive(const std::shared_ptr<DocumentInterface>& document, const std::shared_ptr<PrimitiveInterface>& primitive) {
    if (document) {
        document->addPrimitive(primitive);
        output->printPrimitiveInfo(primitive->GetId(), primitive->GetType());
        std::cout << "Primitive added to document " << document->GetId() << std::endl;
    }
}

void Core::deletePrimitive(const std::shared_ptr<DocumentInterface>& document, int primitiveId) {
    if (document) {
        document->deletePrimitive(primitiveId);
        std::cout << "Primitive " << primitiveId << " removed from document " << document->GetId() << std::endl;
    }
}
