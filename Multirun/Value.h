#pragma once

#include <string>

#include "Utilities.h"

enum class ValueType
{
	NONE,
	INTEGER,
	STRING,
	FLOAT,
	BOOLEAN
};

class Value
{
public:
	Value();
	Value(const std::string& data);

	void setValue(const std::string& data);
	void getValue(void* result) const;
	ValueType getType() const;
	std::string toString() const;

	static ValueType getDataType(const std::string& data);

private:
	ValueType _type;

	int _intVal;
	std::string _stringVal;
	float _floatVal;
	bool _booleanVal;
};

