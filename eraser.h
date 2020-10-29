#pragma once
#include "abstract_brush.h"

class eraser : public abstract_brush {
public:
	eraser() { color = 0; size = 1; }
	void SetColor(int c) override {};
	void SetSize(int c) override {};
};

