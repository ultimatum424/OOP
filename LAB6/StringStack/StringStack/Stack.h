#pragma once

class CStringStack
{
public:
	CStringStack();
	~CStringStack();

	void Push(const std::string& value);
	void Pop();
	std::string Get() const;
	bool IsEmpty() const;
	void Clear();
private:
	struct SNode
	{
		SNode(const std::string data, std::unique_ptr<SNode> && prev)
			: data(data), prev(std::move(prev))
		{
		}
		std::string data;
		std::unique_ptr<SNode> prev;
	};
	std::unique_ptr<SNode> m_top;
};




