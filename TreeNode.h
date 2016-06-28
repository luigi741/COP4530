#ifndef TREENODE_H_INCLUDED
#define TREENODE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <cassert>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include "LinkList.h"

using namespace std;

template<class T> class LinkList;

template<class Type> class TreeNode
{
private:
    int key;
    Type data;

    TreeNode<Type> *parentNode; //points to parent node
    TreeNode<Type> *next; //Points to the next sibling in the LinkList of its parent.
    LinkList<TreeNode*> *children; //LinkList holds list of children

    int siblings;
    int Size = 0; //Number of elements in the tree
    int Height;
    TreeNode<Type> *root;

    template <class T> friend class LinkList;

public:
    TreeNode() : key(0), parentNode(NULL), next(NULL), children(NULL)
    {
        //
    }
    TreeNode(const int &key, const Type &data) : parentNode(NULL), next(NULL), children(NULL)
    {
        this->data = data;
        this->key = key;
    }

    ~TreeNode()
    {}

    void insert(const Type & data, const int &key, TreeNode<Type> *parent,int node_pos)
    {
        cout << "Inserting " << data <<" in position "<<node_pos<<  ", parent is " << (parent==NULL ? "NULL, this is the root.":parent->data) << endl;
        TreeNode<Type> *n = new TreeNode<Type>(key, data);
        if (parent==NULL)
        {
            root = n;
            Size++;
        }
        else
        {
            if (parent->children->getHead() == NULL)
            {
                n->parentNode = parent;
                parent->children->head = n;
                Size++;
            }
            else
            {
                TreeNode<Type> *ptr = parent->children->getHead();
                while(ptr->getNext() != NULL) 
                {
                    ptr = ptr->getNext();
                }
                    
                n->parentNode = parent;
                ptr->next = n;
                Size++;
            }
        }
    }

    TreeNode<Type> * findParent(string str)
    {
        int level = 0;
        for (int i=str.size()-1;i>=0;i--)
        {
            if (str[i]=='.') level++;
        }
        if (level < 1) return root;
        else
        {
            int last_dot = str.find_last_of('.');
            int cur_level = 0;
            str = str.substr(last_dot+1); // 0.#.#.par_pos
            string::size_type sz;
            int par_pos = atoi(str.c_str());
            TreeNode<Type> * ptr = root;
            while (ptr !=nullptr && cur_level!=level)
            {
                ptr= ptr->children->getHead();
                cur_level++;
            }
            for(int i=0;i<par_pos;i++)
            {
                ptr = ptr->getNext();
            }
            return ptr;
        }
    }

    void buildTree(const string path)
    {
        string line;
        ifstream myfile (path);
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {
                int pos = line.find('.');
                string data = line.substr(0,pos);

                int pos2 = line.find(' ');
                string key0 = line.substr(pos2, pos);
                int key1 = atoi(key0.c_str()); 

                string str = line.substr(pos2+1);
                pos = str.find_last_of('.');
                string str2 = str.substr(pos+1);
                string::size_type sz;

                int node_pos = atoi(str2.c_str());
                str = str.substr(0,pos);
                TreeNode<Type> *ptr = findParent(str);
                // cout << "parent for " << data << " is "<< (ptr==nullptr?"nullptr":ptr->data)<<endl;
                insert(data, key1, ptr, node_pos);
            }
            myfile.close();
        }
        else cout << "Unable to open file";

    }

    void Clear()
    {
        //Remove all elements of the tree.
        root->children->delAll();
        delete root;
        root = NULL;
    }

    void del(Type &data)
    {
        //deletes "data" from tree.
    }

    //===========================================================================
    //Accessors
    //===========================================================================
    
    TreeNode<Type>* getRoot()
    {
        return root;
    }

    int getSize()
    {
        //Return size, which is the number of elements in the tree
        return Size;
    }
    //?? DONE
    int getHeight()
    {
        //returns height of tree.
        int h = 0;
        TreeNode<Type> *ptr = root;
        TreeNode<Type> *childs = this->children->childArray;
        if(ptr->children != NULL)
        {
            while(childs != NULL)
            {
                int h = h + height(childs);
                childs++;
            }
        }
        //
        //
        ptr = NULL;

        Height = h;
        return h;
    }
    //NOT DONE
    int getHeight(TreeNode<Type> *_ptr)
    {
        //Return height of _ptr
        int h = 0;


        _ptr = NULL;

        return h;
    }
    //NOT DONE
    int getDepth(TreeNode<Type> *_ptr)
    {
        //Return depth of _ptr.
        return 0;
    }

    bool isEmpty() const
    {
        return root==NULL;
    }
    //NOT DONE
    int leaves()
    {
        //Returns the number of leaves.
        int numLeaves = 0;

        if (root == NULL) {
            return numLeaves = 0;
        }
        else if (children == NULL) {
            return numLeaves = 1;
        }

        return numLeaves;
    }
    //NOT DONE
    int returnSiblings(TreeNode<Type> *_ptr)
    {
        //Return the number of siblings that the _ptr has.
        return 0;
    }

    //NOT DONE
    TreeNode<Type>* findCommonAncestor(TreeNode<Type> *_ptr1, TreeNode<Type> *_ptr2)
    {
        TreeNode<Type> *cAncestor;

        return cAncestor;
    }

    //NOT DONE
    TreeNode<Type>* findNode(Type &data)
    {
        //Return pointer to a node that holds data
    }

    //NOT DONE
    void preorder()
    {
        //PREORDER TRAVERSAL
    }

    //NOT DONE
    void postorder()
    {
        //post order traversal
    }

    //NOT DONE
    void levelorder()
    {

    }

    TreeNode<Type>* getNext() const
    {
        return next;
    }

    Type showData() const
    {
        if(this == NULL)
        {
            return "NULL";
        }
        return data;
    }

    int showKey() const
    {
        if(this == NULL)
        {
            return "NULL";
        }
        return key;
    }

    void disTree() const
    {
        TreeNode<Type> *ptr = root;


        while(ptr != NULL)
        {
            //
        }
    }
};
#endif // TREENODE_H_INCLUDED
