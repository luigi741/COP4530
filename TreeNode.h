#ifndef TREENODE_H_INCLUDED
#define TREENODE_H_INCLUDED

#include <iostream>
#include <cassert>
#include "tinyxml.h"
#include "LinkList.h"


/*
*/
using namespace std;

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

    template <class T> friend class LinkedList;
public:
    TreeNode():key(0), parentNode(NULL), next(NULL), children(NULL)
    {
        //
    }
    TreeNode(const int &key, const Type &data):parentNode(NULL), next(NULL), children(NULL)
    {
        this->data = data;
        this->key = key;
    }

    ~TreeNode()
    {}

//Mutators
    void buildTree(const string &Tree_xml)
    {
        //Reads text file and builds tree from xml file
        TiXmlDocument doc(Tree_xml);

        if (!doc.LoadFile())
        {
            cout << "Could not load file " << Tree_xml << endl;
            cout << "Error= " << doc.ErrorDesc() << endl;
        }

        TiXmlNode* tree_file_node = doc.FirstChild("Tree");
        assert(tree_file_node != 0);

        //Set the root node---> venue_file_node->FirstChild() == "<RootNode>"
        TiXmlNode* root_node = tree_file_node->FirstChild();
        assert(root_node != 0);

        //set the key variable
        TiXmlNode* member_node = root_node->FirstChild(); //points to childID Node
        assert(member_node != 0);
        this->key = (int)member_node->Value();

        //set the data variable
        member_node = member_node->NextSibling();
        assert(member_node != 0);
        this->data = member_node->Value();

        //set children integer.
        member_node = member_node->NextSibling();
        assert(member_node != 0);
        this->childID = (int)member_node->Value();


        //Set the root node---> venue_file_node->FirstChild() == "<RootNode>"
        cout << *root_node;

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

    void insertNode(int &_key, Type &_data)
    {
        TreeNode<Type> *newNode = new TreeNode<Type>(_key, _data);
        Size++;
        if(Size == 1)
        {
            root = newNode;
        }
    }

    //*******************************************************
    //Accessors
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

        return numLeaves;
    }
    //NOT DONE
    int siblings(TreeNode<Type> *_ptr)
    {
        //Return the number of siblings that the _ptr has.

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

    TreeNode<Type> *showParent() const
    {
        if(this->parentNode==NULL)
        {
            return NULL;
        }
        else
        {
            return this->parentNode;
        }
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
