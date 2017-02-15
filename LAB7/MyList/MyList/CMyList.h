#pragma once
#include <string>
#include <memory>
template<typename T>
class CMyList
{
public:
	struct SNode
	{
		SNode(const T & data, SNode * prev, std::unique_ptr<SNode> && next) : 
			data(data), prev(prev), next(std::move(next)) {}

		T data;
		SNode *prev;
		std::unique_ptr<SNode> next;
	};

	class CMyListIterator : std::iterator< std::bidirectional_iterator_tag, T>
	{
		friend class CMyList;
	public:
		CMyListIterator(SNode* data, bool isReverse)
			: m_node(data), m_isReverse(isReverse) {}

		T & operator*() const
		{
			return m_node->data;
		}

		bool operator!=(CMyListIterator const& node) const
		{
			return m_node != node.m_node;
		}
		bool operator==(CMyListIterator const& node) const
		{
			return m_node == node.m_node;
		}

		CMyListIterator operator++()
		{
			if (!m_isReverse)
			{
				m_node = m_node->next.get();
			}
			else
			{
				m_node = m_node->prev;
			}
			return *this;
		}
		CMyListIterator operator--()
		{
			if (!m_isReverse)
			{
				m_node = m_node->prev;
			}
			else
			{
				m_node = m_node->next.get();
			}
			return *this;
		}

	private:
		T* operator->()const
		{
			return &m_node->data;
		}
		SNode* m_node = nullptr;
		bool m_isReverse = false;
	};
	class CMyConstListInterator : std::iterator< std::bidirectional_iterator_tag, T>
	{
		friend class CMyList;
	public:
		CMyConstListInterator(SNode* data, bool isReverse)
			:m_node(data), m_isReverse(isReverse){}
		const T & operator* () const
		{
			return m_node->data;
		}
		bool operator!=(CMyConstListInterator const& node) const
		{
			return m_node != node.m_node;
		}
		bool operator==(CMyConstListInterator const& node) const
		{
			return m_node == node.m_node;
		}
		CMyConstListInterator operator++()
		{
			if (!m_isReverse)
			{
				m_node = m_node->next.get();
			}
			else
			{
				m_node = m_node->prev;
			}
			return *this;
		}
		CMyConstListInterator operator--()
		{
			if (!m_isReverse)
			{
				m_node = m_node->prev;
			}
			else
			{
				m_node = m_node->next.get();
			}
			return *this;
		}
			

	private:
		const T * operator->()const
		{
			return &m_node->data;
		}
		SNode * m_node = nullptr;
		bool m_isReverse = false;
	};

	CMyList() = default;
	CMyList(CMyList & list) : m_firstNode(list.m_firstNode.get())
	{
		m_lastNode = list.m_lastNode;
		m_size = list.m_size;
	}

	~CMyList()
	{
		Clear();
	}

	size_t GetSize() const
	{
		return m_size;
	}

	void Clear()
	{
		while (m_lastNode)
		{
			m_lastNode->next = nullptr;
			m_lastNode = m_lastNode->prev;
		}
		m_firstNode = nullptr;
		m_size = 0;
	}

	bool IsEmpty() const
	{
		return m_firstNode == nullptr;
	}

	void PushBack(const T & data)
	{
		auto newNode = std::make_unique<SNode>(data, m_lastNode, nullptr);
		if (!IsEmpty())
		{
			m_lastNode->next = std::move(newNode);
			m_lastNode = m_lastNode->next.get();
		}
		else
		{
			m_firstNode = std::move(newNode);
			m_lastNode = m_firstNode.get();
		}
		m_size++;
	}
	void PushFront(const T & data)
	{
		auto newNode = std::make_unique<SNode>(data, nullptr, std::move(m_firstNode));
		if (newNode->next)
		{
			newNode->next->prev = newNode.get();
		}
		else
		{
			m_lastNode = newNode.get();
		}
		m_firstNode = std::move(newNode);
		m_firstNode->prev = nullptr;
		m_size++;
	}

	const T & GetLastElement() const
	{
		if (m_lastNode == nullptr)
		{
			throw std::logic_error("List is empty");
		}
		return m_lastNode->data;	
	}
	const T & GetFirstElement() const
	{
		if (m_firstNode == nullptr)
		{
			throw std::logic_error("List is empty");
		}
		return m_firstNode->data;
	}

	CMyListIterator begin()
	{
		return CMyListIterator(m_firstNode.get(), false);
	}
	CMyListIterator end()
	{
		return CMyListIterator(m_lastNode->next.get(), false);
	}
	CMyListIterator rbegin()
	{
		return CMyListIterator(m_firstNode.get(), true);
	}
	CMyListIterator rend()
	{
		return CMyListIterator(m_lastNode->next.get(), true);
	}

	const CMyConstListInterator cbegin() const
	{
		return CMyConstListInterator(m_firstNode.get(), false);
	}
	const CMyConstListInterator cend() const
	{
		return CMyConstListInterator(m_lastNode->next.get(), false);
	}
	const CMyConstListInterator crbegin() const
	{
		return CMyConstListInterator(m_lastNode, true);
	}
	const CMyConstListInterator crend() const
	{
		return CMyConstListInterator(m_firstNode->prev, true);
	}

	CMyListIterator Insert(const CMyListIterator & it, T & data)
	{
		if ((IsEmpty()) || it == begin())
		{
			PushFront(data);
			return begin();
		}
		else
		{
			SNode *prevNode = it.m_node->prev;
			auto newNode = std::make_unique<SNode>(data, it.m_node->prev, std::move(it.m_node->prev->next));
			prevNode->next = std::move(newNode);
			m_size++;
			return CMyListIterator(it.m_node->prev->next.get());
		}
		/*
		if (it == begin())
		{	
			PushFront(data);
		}
		else if (it == end())
		{
			PushBack(data);
		}
		else
		{
			auto newNode = std::make_unique<SNode>(data, it->prev, std::move(it->prev->next));
			it->prev = std::move(newNode.get());
			newNode->prev->next = std::move(newNode);
		}
		*/
	}
	void Erase(const CMyListIterator & it)
	{
		if (m_size == 1)
		{
			Clear();
			return;
		}

		if (it == begin())
		{
			it->next->prev = nullptr;
			m_firstNode = move(it->next);
		}
		else if (it->data == GetLastElement())
		{
			it->prev->next = nullptr;
			m_lastNode = std::move(it->prev);
		}
		else
		{
			it->next->prev = std::move(it->prev);
			it->prev->next = std::move(it->next);
		}

		if (m_size > 0)
		{
			m_size--;
		}
	}
private:
	size_t m_size = 0;
	std::unique_ptr<SNode> m_firstNode = nullptr;
	SNode * m_lastNode = nullptr;
};