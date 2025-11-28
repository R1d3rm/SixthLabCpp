#include "Document.h"
#include "PrimitiveInterface.h"

int Document::nextId = 1;
Document::Document() : id(nextId++) {}
int Document::GetId() const { return id; }
void Document::addPrimitive(std::shared_ptr<PrimitiveInterface> primitive) {
    primitives.push_back(primitive);
}
void Document::deletePrimitive(int id) {
    primitives.erase(std::remove_if(primitives.begin(), primitives.end(),
        [id](const std::shared_ptr<PrimitiveInterface>& primitive) {
            return primitive->GetId() == id;
        }), primitives.end());
}
const std::vector<std::shared_ptr<PrimitiveInterface>>& Document::getPrimitives() const {
    return primitives;
}