#pragma once

#include <string>

enum class Type
{
	NONE,
	INTEGER,
	STRING,
	FLOAT,
	BOOLEAN
};

class Variable
{
public:
	Variable(const std::string& data);
	Variable();

	void getValue(void* result) const;
	void setValue(const std::string& data);
	std::string toString() const;

	static Type getDataType(const std::string& data);
private:
	Type _type;

	int _intVal;
	std::string _stringVal;
	float _floatVal;
	bool _booleanVal;
};

