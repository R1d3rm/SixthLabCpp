#include "Circle.h"
#include <iostream>

int Circle::nextId = 1;

Circle::Circle(double radius) : id(nextId++), radius(radius) {}

int Circle::GetId() const { return id; }

std::string Circle::GetType() const { return "Circle"; }

void Circle::draw() const {
    std::cout << "Circle " << id << ":\n Radius: " << radius << std::endl;
}