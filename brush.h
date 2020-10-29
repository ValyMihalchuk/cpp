#pragma once
#include "abstract_brush.h"

class brush : public abstract_brush {
public:
	brush() {  }
	void SetColor(int c) override { color = c; }
	void SetSize(int c) override { size = c; };
};

