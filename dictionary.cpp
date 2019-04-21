#include <iostream>
using namespace std;

namespace andre{
class Dictionary
{

private:
	struct Node
	{
		char* key;
		int value;
		Node * prev;
		Node * next;
	};

	Node first;
	Node last;

public:

	Dictionary(): first(NULL), last(NULL)
	{}

	~Dictionary()
	{
		while(first)
		{
			Node * n = first;
			first = n->next;
			delete n;
		}
	}

	addEntry(char* addKey, int value)
	{
		Dictionary * new_p = new Dictionary();

		if(first)
		{
			new_p->next = NULL;
			new_p->prev = NULL;
			first = p;
			last = p;

		} else {

			p = last;
			new_p->next = NULL;
			new_p->prev = p;
			p->next = new_p;
			last = new_p;
		}

	}

	void Clear()
	{
		while(first)
		{
			Node * n = first;
			first = n->next;
			delete n;
		}
	}

	int searchNumberkey(char* findStr)
	{
		while(first)
		{
			if(!strcmp(first->value , findStr))
				return (first->key);

			first = first->next;
		}

		return -1;
	}

	size_t size() const
	{
		size_t size = 0;

		if(!first)
			return;
		Dictionary p  = first;

		while(p)
		{
			++size;
			p = p->next;
		}

		return size;
	}

	void dump()
	{
		cout << endl;

		if(!first)
			cout << "Dictionary is empty..." << endl;

		Dictionary p = first;

		cout << "Dictionary:" << endl;

		while(p)
		{
			cout << p->key << " " << p->value << endl;
			p = p->next;
		}
	}


};

}

int main()
{
	
	return 0;
}