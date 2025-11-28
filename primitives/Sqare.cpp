#include "Sqare.h"
#include <iostream>

int Square::nextId = 1;

Square::Square(double sideLength) : id(nextId++), sideLength(sideLength) {}

int Square::GetId() const { return id; }

std::string Square::GetType() const { return "Square"; }
void Square::draw() const {
    std::cout << "Square " << id << ":\n Side Length: " << sideLength << std::endl;
}