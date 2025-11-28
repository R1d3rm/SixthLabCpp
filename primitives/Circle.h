#pragma once
#include "PrimitiveInterface.h"
#include <string>

class Circle : public PrimitiveInterface {
public:
	Circle(double radius);
	~Circle() override = default;

	int GetId() const override;
	std::string GetType() const override;
	void draw() const override;

private:
	static int nextId;
	int id;
	double radius;
};