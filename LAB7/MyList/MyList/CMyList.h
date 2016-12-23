#pragma once
#include <string>
#include <memory>
#include <cassert>
template<typename T>
class CMyList
{

	struct SNode
	{
		SNode(const T & data, SNode * prev, std::unique_ptr<SNode> && next) : 
			data(data), prev(prev), next(std::move(next)) {}

		T data;
		SNode *prev;
		std::unique_ptr<SNode> next;
	};

	template<typename U>
	class CMyListIterator : std::iterator<std::random_access_iterator_tag, U>
	{
	public:
		CMyListIterator(SNode* data, bool isReverse)
			: m_node(data), m_isReverse(isReverse) {}

		friend class CMyList<T>;

		U & operator*() const
		{
			return m_node->data;
		}

		bool operator!=(CMyListIterator const& node)
		{
			return m_node != node.m_node;
		}
		bool operator==(CMyListIterator const& node) const
		{
			return m_node == node.m_node;
		}

		CMyListIterator operator++()
		{
			if (m_isReverse)
			{
				m_node = m_node->prev;
				return *this;
			}
			m_node = m_node->next.get();
			return *this;
		}
		CMyListIterator operator--()
		{
			if (m_isReverse)
			{
				m_node = m_node->next;
				return *this;
			}
			m_node = m_node->prev.get();
			return *this;
		}

	private:
		SNode* operator->()const
		{
			return m_node;
		}
		SNode* m_node = nullptr;
		bool m_isReverse = false;
	};
	typedef CMyListIterator<T> MyListIterator;
public:
	CMyList() = default;
	CMyList(CMyList & list)
	{
		if (list.GetSize() == 0)
		{
			size_t m_size = 0;
			std::unique_ptr<SNode> m_firstNode = nullptr;
			SNode * m_lastNode = nullptr;
		}
		else
		{
			CMyList tmp;
			for (auto elem : list)
			{
				tmp.PushBack(elem);
			}
			std::swap(m_firstNode, tmp.m_firstNode);
			std::swap(m_lastNode, tmp.m_lastNode);
			m_size = tmp.m_size;
		}
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
		return m_size == 0;
	}

	void PushBack(const T & data)
	{
		auto newNode = std::make_unique<SNode>(data, m_lastNode, nullptr);
		SNode *newLastNode = newNode.get();
		if (m_lastNode)
		{
			m_lastNode->next = std::move(newNode);
		}
		else
		{
			m_firstNode = std::move(newNode);
		}
		m_lastNode = newLastNode;
		m_lastNode->next = nullptr;
		++m_size;
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

	MyListIterator begin()
	{
		return MyListIterator(m_firstNode.get(), false);
	}
	MyListIterator end()
	{
		return MyListIterator(m_lastNode->next.get(), false);
	}
	MyListIterator rbegin()
	{
		return MyListIterator(m_firstNode.get(), true);
	}
	MyListIterator rend()
	{
		return MyListIterator(m_lastNode->next.get(), true);
	}

	void Insert(const MyListIterator & it, T data)
	{
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
	}
	void Erase(const MyListIterator & it)
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