#pragma once

#include <memory>

#include "IValue.h"
#include "Boolean.h"
#include "Integer.h"
#include "String.h"
#include "Float.h"
#include "None.h"

class ValueHandler
{
public:
	static std::shared_ptr<IValue> getValue(const std::string& data);
	static std::shared_ptr<IValue> createValue(const float data);
	static std::shared_ptr<IValue> createValue(const int data);
	static std::shared_ptr<IValue> createValue(const std::string& data);
	static std::shared_ptr<IValue> createValue(const bool data);
	static ValueType getType(const std::string& data);
	static bool isValue(const std::string& data);
	static std::shared_ptr<IValue> castTo(const std::shared_ptr<IValue>& value, const ValueType type);
};
