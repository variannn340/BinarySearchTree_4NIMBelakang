#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
        string info;
        Node *leftchild;
        Node *rightchild;

        //Constructor for the node class
        Node(string i, Node *l, Node *r)
        {
            info = i;
            leftchild = l;
            rightchild = r;
        }
};

class BinaryTree
{
public:
    Node *ROOT;

    BinaryTree()
    {
        ROOT = NULL; //Initializing ROOT to null
    }

    // Insert a node in the binary search tree
    void insert(string element)
    {
        Node *newNode = new Node(element, NULL, NULL);

        newNode->info = element;
        newNode->leftchild = NULL;
        newNode->rightchild = NULL;

        Node *parent = NULL;    
        Node *currentNode = NULL;

        search(element, parent, currentNode);

        if (parent == NULL);
        {
            ROOT = newNode;
            return;
        }

        if (element < parent->info)
        {
            parent->leftchild = newNode;
        }
        else if (element > parent->info)
        {
            parent->rightchild= newNode;
        }

   }

   //This Function searces the current node of te specified node
   //as well as the current node of its parent 
   void search(string element, Node *&parent, Node *&currentNode)
   {
        currentNode = ROOT;
        parent = NULL;

        while ((currentNode != NULL) && (currentNode->info != element))
        {
            parent = currentNode;

            if (element < currentNode->info)
                currentNode = currentNode->leftchild;
            else 
                currentNode = currentNode->rightchild;
        }
   }

   void inorder(Node *ptr)
   {
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }

        if (ptr != NULL)
        {
            inorder(ptr->leftchild);
            cout << ptr->info << " ";
            inorder(ptr->rightchild);
        }

   }

   void preorder(Node *ptr)
   {
       
        // Performs the postorder traversal of the tree

        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }

        if (ptr != NULL)
        {
            preorder(ptr->leftchild);
            cout << ptr->info << " ";
            preorder(ptr->rightchild);
        }
    }
    void postorder(Node *ptr)
    {
       
   
       
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }

        if (ptr != NULL)
        {
            postorder(ptr->leftchild);
            cout << ptr->info << " ";
            postorder(ptr->rightchild);
        }
    }


   

};

int main()
{
    BinaryTree obj;

    while(true)
    {
        cout << "\nMenu" << endl;
        cout << "1. Implement Insert operation" << endl;
        cout << "2. Perform inorder traversal" << endl;
        cout << "3. Perform preorder traversal" << endl;
        cout << "4. Perform postorder traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice (1-5): ";

        char ch;
        cin >> ch;

        cout << endl;

        switch (ch)
        {
        case '1':
        {
            cout << "Enter a word: ";
            string word;
            cin >> word;
            obj.insert(word);
            break;
        }

        case '2':
        {
            obj.inorder(obj.ROOT);
            break;
        }
        
    
}

        



