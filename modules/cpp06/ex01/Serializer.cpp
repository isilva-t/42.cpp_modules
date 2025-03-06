#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::Serializer(const Serializer& other)
{	*this = other;	}

Serializer& Serializer::operator=(const Serializer& other)
{	(void)other;
	return *this;	}

Serializer::~Serializer() {}

/////////////////////////////////////////////////////////////

uintptr_t	Serializer::serialize(Data* ptr)
{
	uintptr_t converted_raw;

	converted_raw = reinterpret_cast<uintptr_t>(ptr);

	return converted_raw;
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	Data* converted_ptr;

	converted_ptr = reinterpret_cast<Data*>(raw);

	return converted_ptr;
}
