#include "TreeNode.h"
#include "LinkList.h"


using namespace std;

int main()
{
    /*
	cout << "This is GeneralTree Function... " << endl;
	cout << "First, lets create a GeneralTree" << endl;
	cout << "Start with a root Node. Enter a " << endl
        << "key(int) and a value(string) to" << endl
        << "create your first node." << endl;

    cout << "->Key(int): ";
    int Key;
    cin >> Key;
    cout << "->Value(string): ";
	string Value;
	cin >> Value;


    TreeNode<string>* Tree = new TreeNode<string>(Key, Value);



    cout << "\'X\' to exit" << endl;
    cout << "Does does this node have children? Y|N : " << endl;
    char YN;
    cin >> YN;
    while (YN != 'X')
    {
        if(YN == 'Y')
        {
            while(Key != 969)
            {
                cout << "Enter \'969\' to quite" << endl;
                cout << "->Key(int): ";
                int Key;
                cin >> Key;
                cout << "->Value(string): ";
                string Value;
                cin >> Value;
                Tree->insertNode(Key,Value);
            }
        }
    }
    */
    TreeNode<string>* Tree = new TreeNode<string>;

    int opCode;
    cout << "GeneralTree Functions: " << endl;
    cout << "1. BuildTree()" << endl;
    cout << "2. AddNode()" << endl;
    cout << "3. del()" << endl;
    cin >> opCode;

    switch(opCode)
    {
    case 1:

        Tree->buildTree("Tree.xml");
    }


    cout << "This is a test from Luis's Tower at 8:00P" << endl;

	return 0;
}
