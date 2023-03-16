#pragma once
#include <exception>
using namespace std;

class Bad_range: public exception
{
public:
	Bad_range() = default;
	virtual const char* what() const throw() override;

};

