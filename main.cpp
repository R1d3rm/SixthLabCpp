#include <iostream>
#include <memory>
#include "core/Core.h"
#include "output/Output.h"
#include "primitives/Circle.h"
#include "primitives/Sqare.h"

    std::shared_ptr<DocumentInterface> handleCreateDocument(const std::shared_ptr<CoreInterface>& core) {
        std::cout << "\nCreating new document..." << std::endl;
        return core->createDocument();
    }

    std::shared_ptr<DocumentInterface> handleImportDocument(const std::shared_ptr<CoreInterface>& core, const std::string& filename) {
        std::cout << "\nImporting document from: " << filename << std::endl;
        return core->importDocument(filename);
    }

    void handleExportDocument(const std::shared_ptr<CoreInterface>& core, 
                             const std::shared_ptr<DocumentInterface>& doc, 
                             const std::string& filename) {
        std::cout << "\nExporting document to: " << filename << std::endl;
        core->exportDocument(doc, filename);
    }

    void handleAddCircle(const std::shared_ptr<CoreInterface>& core,
                        const std::shared_ptr<DocumentInterface>& doc,
                        double radius) {
        std::cout << "\nAdding Circle with radius: " << radius << std::endl;
        auto circle = std::make_shared<Circle>(radius);
        core->addPrimitive(doc, circle);
    }

    void handleAddSquare(const std::shared_ptr<CoreInterface>& core,
                        const std::shared_ptr<DocumentInterface>& doc,
                        double sideLength) {
        std::cout << "\nAdding Square with side length: " << sideLength << std::endl;
        auto square = std::make_shared<Square>(sideLength);
        core->addPrimitive(doc, square);
    }

    void handleDeletePrimitive(const std::shared_ptr<CoreInterface>& core,
                               const std::shared_ptr<DocumentInterface>& doc,
                               int primitiveId) {
        std::cout << "\nDeleting primitive with ID: " << primitiveId << std::endl;
        core->deletePrimitive(doc, primitiveId);
    }

    void handleDisplayDocument(const std::shared_ptr<OutputInterface>& output,
                              const std::shared_ptr<DocumentInterface>& doc) {
        std::cout << "\nDisplaying document..." << std::endl;
        output->printDocumentInfo(*doc);
    }


int main(int argc, char** argv) {
    std::cout << "===== Vector Graphics Editor Architecture (MVC) =====" << std::endl;
    std::cout << "Project: Graphic Vector Editor Mockup" << std::endl;
    std::cout << "Architecture: Model-View-Controller with Polymorphism" << std::endl;
    std::cout << "=====================================================" << std::endl;

    auto output = std::make_shared<Output>();
    auto core = std::make_shared<Core>(output);
    std::cout << "\n--- Script 1: Create New Document ---" << std::endl;
    auto document1 = handleCreateDocument(core);
    std::cout << "\n--- Script 2: Add Primitives ---" << std::endl;
    handleAddCircle(core, document1, 5.0);
    handleAddCircle(core, document1, 3.5);
    handleAddSquare(core, document1, 4.0);

    std::cout << "\n--- Script 3: Display Document ---" << std::endl;
    handleDisplayDocument(output, document1);

    std::cout << "\n--- Script 4: Delete Primitive ---" << std::endl;
    handleDeletePrimitive(core, document1, 1);

    std::cout << "\n--- Script 5: Display Document After Deletion ---" << std::endl;
    handleDisplayDocument(output, document1);

    std::cout << "\n--- Script 6: Export Document ---" << std::endl;
    handleExportDocument(core, document1, "document1.vge");

    std::cout << "\n--- Script 7: Create Another Document ---" << std::endl;
    auto document2 = handleCreateDocument(core);
    handleAddSquare(core, document2, 7.0);
    handleAddCircle(core, document2, 2.5);

    std::cout << "\n--- Script 8: Display Second Document ---" << std::endl;
    handleDisplayDocument(output, document2);

    std::cout << "\n--- Script 9: Import Document ---" << std::endl;
    auto document3 = handleImportDocument(core, "existing_document.vge");

    std::cout << "\n===== Program Completed Successfully =====" << std::endl;
    return 0;
}
