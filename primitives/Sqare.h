#pragma once
#include "PrimitiveInterface.h"
#include <string>

class Square : public PrimitiveInterface {
public:
	Square(double sideLength);
	~Square() override = default;

	int GetId() const override;
	std::string GetType() const override;
	void draw() const override;

private:
	static int nextId;
	int id;
	double sideLength;
};