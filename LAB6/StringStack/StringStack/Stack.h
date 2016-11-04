#pragma once

struct StackElement {
	std::string string;
	std::unique_ptr<StackElement> ptr;
};

class CStringStack
{
public:
	CStringStack();
	~CStringStack();

	void push(const std::string& value);
	void pop();
	std::string get() const;
	bool isEmpty() const;
private:
	
	std::unique_ptr<StackElement> last_data;
};




