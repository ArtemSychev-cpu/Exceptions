#pragma once
using namespace std;
#include <exception>

class Bad_length: public exception
{
public:
	Bad_length() = default;
	virtual const char* what() const throw() override;

};

