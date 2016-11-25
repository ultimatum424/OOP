#include "stdafx.h"
#include "Stack.h"


CStringStack::CStringStack()
{
	m_top = nullptr;
}

void CStringStack::Push(const std::string& value)
{
		auto newNode = std::make_unique<SNode>(value, std::move(m_top));
		m_top = move(newNode);
}

void CStringStack::Pop()
{
	if (!IsEmpty())
	{
		m_top = std::move(m_top->prev);
	}
	else
	{
		throw std::exception("Stack is empty");
	}
	
}

std::string CStringStack::Get() const
{
	if (!IsEmpty())
	{
		return m_top->data;
	}
	else
	{
		throw std::exception("Stack is empty");
	}
	
}

bool CStringStack::IsEmpty() const
{
	return (m_top == nullptr);

}

void CStringStack::Clear()
{
	while (m_top)
	{
		Pop();
	}
}

CStringStack::~CStringStack()
{
	Clear();
}
