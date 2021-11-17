#pragma once

class Stack
{
private:
	class Node
	{
	public:
		Node(int val, Node* next)
			:
			value(val),
			next(next)
		{}
		Node(const Node& source)
			:
			value(source.value)
		{
			if (source.next != nullptr)
			{
				next = new Node(*source.next);
			}
		}
		~Node()
		{
			delete next;
			next = nullptr;
		}
		int GetVal()
		{
			return value;
		}
		Node* Disconnect()
		{
			
			auto temp = next;
			next = nullptr;
			return temp;
			
		}
		int GetCount()
		{
			if (next != nullptr)
			{
				return next->GetCount() + 1;

			}
			else
				return 1;
		}
	private:
		int value;
		Node* next = nullptr;
	};
public:
	Stack() = default;
	Stack(const Stack& source);
	~Stack();
	Stack& operator=(const Stack& source);
	void Push( int val );
	int Pop();
	int Size() const;
	bool Empty() const;
private:
	Node* top = nullptr;
};