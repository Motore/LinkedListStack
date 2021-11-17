#include "Stack.h"

Stack::Stack(const Stack& source)
{
	*this = source;
}

Stack::~Stack()
{
	delete top;
	top = nullptr;
}

Stack& Stack::operator=(const Stack& source)
{
	if (!Empty())
	{
		delete top;
		top = nullptr;
	}
	if (!source.Empty())
	{
		top = new Node(*source.top);
	}
	return *this;
}

void Stack::Push(int val)
{
	top = new Node(val, top);
}

int Stack::Pop()
{
	if (Empty())
	{
		return -1;
	}
	else
	{
		const int tempVal = top->GetVal();
		auto oldTop = top;
		top = top->Disconnect();
		delete oldTop;
		return tempVal;
	}
}

int Stack::Size() const
{
	if (Empty())
	{
		return 0;
	}
	else
	{	
		return top->GetCount();
	}
}

bool Stack::Empty() const
{
	return top==nullptr;
}

