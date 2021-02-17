#pragma once

#include <string>

#include "Utilities.h"
#include "InvalidCast.h"

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
	void getValue(int& result) const;
	void getValue(float& result) const;
	void getValue(bool& result) const;
	void getValue(std::string& result) const;
	ValueType getType() const;
	std::string toString() const;
	void castTo(const ValueType& type);

	static ValueType getDataType(const std::string& data);
	static bool isValue(const std::string& data);

private:
	ValueType _type;

	int _intVal;
	std::string _stringVal;
	float _floatVal;
	bool _booleanVal;
};

