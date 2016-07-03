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
        	T ptr = head;
	        if (ptr == NULL)
	        {
	        	//cout << "ptr" << ptr->getNext() << endl;
	            head = _node;
	            sz++;
	        }
	        else
	        {
	            while(ptr->getNext() != NULL)
	            {
	                ptr = ptr->getNext();
	            }
	            ptr->setNext(_node);
	            sz++;
	        }
        	//LinkList::printList();
		}

//Accessors
        bool isEmpty()
        {
        	if(head==0) cout << "Empty" << endl;
            return head==0;
        }

		T getHead()
		{
			return head;
		}

		void setHead(T TreeNode)
		{
			addNode(TreeNode);
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
	            cout << "Node[" << ptr->showKey() <<"]="; // << ptr->data << "-->";
	            ptr = ptr->getNext();
	        }
	        cout << "end" << endl;
    	}
};



#endif // TREENODE_H_INCLUDED
