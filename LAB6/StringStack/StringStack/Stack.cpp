#include "stdafx.h"
#include "Stack.h"


CStringStack::CStringStack()
{
	last_data = nullptr;
}

void CStringStack::push(const std::string & value)
{
	if (last_data == NULL)
	{
		last_data = std::unique_ptr<StackElement>(new StackElement());
		last_data->string = value;
		last_data->ptr = NULL;
	}
	else
	{
		std::unique_ptr<StackElement> p(new StackElement());
		p->ptr = std::move(last_data);
		p->string = value;
		last_data = std::move(p);
	}	
}

void CStringStack::pop()
{
	if (!isEmpty())
	{
		auto p = std::make_unique<StackElement>;
		last_data = std::move(last_data->ptr);
	}
	else
	{
		throw std::exception("Stack is empty");
	}
	
}

std::string CStringStack::get() const
{
	if (!isEmpty())
	{
		return last_data->string;
	}
	else
	{
		throw std::exception("Stack is empty");
	}
	
}

bool CStringStack::isEmpty() const
{
	if (last_data == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}


CStringStack::~CStringStack()
{
}
