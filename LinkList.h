#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

#include <iostream>
#include "TreeNode.h"

using namespace std;

template<class K> class TreeNode;

template<class T> class LinkList
{
	private:
		int sz; //number of entries in linked list.
		int childID = 1;
		T head;
		T tail;
		T childArray; //An pointer to Node pointers that
							//point to the children of a node.

		template<class Type> friend class TreeNode;
	public:
		LinkList():head(NULL), tail(NULL)
		{
		    //Time Analysis: O(1)
			childArray = NULL;
			sz = 0;
		}

		~LinkList()
		{}
//Mutators
        void delAll()
        {
            while (head != NULL)
            {
                T const tmp = head;
                head = head->next;
                delete tmp;
            }
            tail = NULL;
        }
// /*
		void addNode(T _node)
		{
			//Adds node to the back of the linkList.
			T tmp_node = _node;
        	T ptr = head;
	        if (ptr == NULL)
	        {
	            head = tmp_node;
	            sz++;
	            childID = 1;
	        }
	        else
	        {
	            while(ptr->getNext() != NULL)
	            {
	                ptr = ptr->getNext();
	                childID++;
	            }
	            ptr->setNext(tmp_node);
	            sz++;
	        }
        	LinkList::printList();
		}

//Accessors
        bool isEmpty()
        {
            return head==0;
        }

		T getHead()
		{
			return head;
		}

		T getTail()
		{
		    return tail;
		}

		void printList() const
		{
	        T ptr = head;
	        while(ptr !=NULL)
	        {
	            cout << "Node[" << ptr->getID() <<"]="; // << ptr->data << "-->";
	            ptr = ptr->getNext();
	        }
	        cout << "end" << endl;
    	}
};



#endif // TREENODE_H_INCLUDED
