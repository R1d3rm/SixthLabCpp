#pragma once
#include "CoreInterface.h"
#include <unordered_map>

class Core : public CoreInterface {
public:
    Core(std::shared_ptr<OutputInterface> output);
    ~Core() override = default;

    std::shared_ptr<DocumentInterface> createDocument() override;
    std::shared_ptr<DocumentInterface> importDocument(const std::string& filename) override;
    void exportDocument(const std::shared_ptr<DocumentInterface>& document, const std::string& filename) override;
    void addPrimitive(const std::shared_ptr<DocumentInterface>& document, const std::shared_ptr<PrimitiveInterface>& primitive) override;
    void deletePrimitive(const std::shared_ptr<DocumentInterface>& document, int primitiveId) override;

private:
    static int nextId;
    std::shared_ptr<OutputInterface> output;
    std::unordered_map<int, std::shared_ptr<DocumentInterface>> documents;
};