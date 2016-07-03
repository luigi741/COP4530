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
    
    TreeNode<Type> *root;
    TreeNode<Type> *parentNode; //points to parent node
    TreeNode<Type> *next; //Points to the next sibling in the LinkList of its parent.
    LinkList<TreeNode*> *children; //LinkList holds list of children

    int siblings;
    int Size = 0; //Number of elements in the tree
    int Height;

    template <class T> friend class LinkList;

public:
    TreeNode() : key(0), parentNode(NULL), root(NULL), next(NULL), children(NULL)
    {
        //
    }
    TreeNode(const int &key, const Type &data) : parentNode(NULL), root(NULL), next(NULL), children(NULL)
    {
        this->data = data;
        this->key = key;
    }

    ~TreeNode()
    {}

    void insert(const Type & data, const int &key, TreeNode<Type> *parent,int node_pos)
    {
        cout << "Inserting " << data <<" in Childposition "<< node_pos <<  ", parent is " << (parent==NULL ? "NULL, this is the root.":parent->data) << endl;
        
        TreeNode<Type> *n = new TreeNode<Type>(key, data);

        if (parent==NULL)
        {
            root = n;
            Size++;
        }
        else
        {
            if(parent->children == NULL)
            {
                parent->children = new LinkList<TreeNode*>;
            }

            parent->children->addNode(n);
            
            Size++;

        }
    }

    TreeNode<Type> * findParent(string str)
    {
        int level = 0;
        //Counts the number of periods (represent levels in tree)
        for (int i = str.size()-1; i >=0 ; i--)
        {
            if (str[i]=='.') level++;
            //cout << "HERE" << endl;
        }

        cout << "level: " << level << endl;
        if (level == 0)
        {
            //If there were no periods it was the root node, NULL parent.
            //cout << "return NULL" << endl;
            return NULL;
        }  
        else
        {
            return root;
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
                cout << "**********************" << endl;
                cout << "**Data = " << data << endl;


                string str = line.substr(pos+1);
                int pos2 = str.find('.');
                string key0 = line.substr(pos+1, pos2);
                int key1 = atoi(key0.c_str());
                cout <<"**Key1 = " << key1 << endl;
                

                pos = str.find_last_of('.');
                string str2 = str.substr(pos+1);
                //cout << "**str2 = " << str2 << endl;
                //DELETE::string::size_type sz;
                int node_pos = atoi(str2.c_str());
                cout << "**pos : " << node_pos << endl;
                
                str = str.substr(pos2+1);
                cout << "**str: " << str << endl;

                //Find the parentNode to the TreeNode.
                TreeNode<Type> *pPtr = findParent(str);
                
                cout << "**parent: " << pPtr->showData() << endl;

                insert(data, key1, pPtr, node_pos);
                Size++; //Increment size.

                pPtr = NULL;
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

    void visit(TreeNode<Type> *node)
    {
        if(node != NULL)
        {
            cout << "VISIT: " << node->data << endl;
        }
        else
        {
            cout << "VISIT: NULL" << endl;
        }
    }

    //NOT DONE
    void preorder(TreeNode<Type>* node)
    {
        //PREORDER TRAVERSAL
        visit(node);
        if(node->children != NULL)
        {
            if(node->children->getHead() != NULL)
            {
                preorder(node->children->getHead());
            }
        }
        if(node->next != NULL)
        {
            preorder(node->next);
        }
    }

    //NOT DONE
    void postorder(TreeNode<Type> *node)
    {
        //post order traversal
        if(node->children->getHead() == NULL)
        {
            postorder(node->children->getHead());
        }
        this->visit(node);
        if(node->getNext() == NULL)
        {
            postorder(node->getNext());
        }
    }

    //NOT DONE
    void levelorder()
    {

    }

    void setNext(TreeNode<Type>* node)
    {
        this->next = node;
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

    void isChildren()
    {
        if(children == NULL)
        {
            cout << "CHILDREN::NULL" << endl;
            return;
        }
        cout << "HIDE YO KIDS" << endl;
    }

};
#endif // TREENODE_H_INCLUDED
