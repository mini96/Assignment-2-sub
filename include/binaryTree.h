//Header File Binary Search Tree
#ifndef H_binaryTree
#define H_binaryTree
#include <cassert>
//*************************************************************
// Author: D.S. Malik
//
// class binaryTreeType
// This class specifies the basic operations to implement a
// binary tree.
//*************************************************************

#include <iostream>

using namespace std;

//Definition of the node
template <class elemType>
struct binaryTreeNode
{
    elemType info;
    binaryTreeNode<elemType> *llink;
    binaryTreeNode<elemType> *rlink;
};

//Definition of the class
template <class elemType>
class binaryTreeType
{
public:
    const binaryTreeType<elemType>& operator=
    (const binaryTreeType<elemType>&);
    //Overload the assignment operator.
    bool isEmpty() const;
    //Returns true if the binary tree is empty;
    //otherwise, returns false.
    void insert(const elemType& insertItem);
    void returnBuy(int buyn);
    void inorderTraversal() const;
    //Function to do an inorder traversal of the binary tree.
    void preorderTraversal() ;
    //Function to do a preorder traversal of the binary tree.
    void postorderTraversal() const;
    //Function to do a postorder traversal of the binary tree.

    int treeHeight() const;
    //Returns the height of the binary tree.
    int treeNodeCount();
    //Returns the number of nodes in the binary tree.
    int treeLeavesCount() ;
    //Returns the number of leaves in the binary tree.
    void destroyTree();
    //Deallocates the memory space occupied by the binary tree.
    //Postcondition: root = NULL;

    binaryTreeType(const binaryTreeType<elemType>& otherTree);
    //copy constructor

    binaryTreeType();
    //default constructor

    ~binaryTreeType();
    //destructor

protected:
    binaryTreeNode<elemType>  *root;

private:
    void copyTree(binaryTreeNode<elemType>* &copiedTreeRoot,
                  binaryTreeNode<elemType>* otherTreeRoot);
    //Makes a copy of the binary tree to which
    //otherTreeRoot points. The pointer copiedTreeRoot
    //points to the root of the copied binary tree.

    void destroy(binaryTreeNode<elemType>* &p);
    //Function to destroy the binary tree to which p points.
    //Postcondition: p = NULL

    void inorder(binaryTreeNode<elemType> *p) const;
    //Function to do an inorder traversal of the binary
    //tree to which p points.
    void preorder(binaryTreeNode<elemType> *p) ;
    //Function to do a preorder traversal of the binary
    //tree to which p points.
    void postorder(binaryTreeNode<elemType> *p) const;
    //Function to do a postorder traversal of the binary
    //tree to which p points.
    void buy(int);
    int height(binaryTreeNode<elemType> *p) const;
    //Function to return the height of the binary tree
    //to which p points.
    int max(int x, int y) const;
    //Returns the larger of x and y.
    int nodeCount(binaryTreeNode<elemType> *p);
    //Function to return the number of nodes in the binary
    //tree to which p points
    int leavesCount(binaryTreeNode<elemType> *p);
    //Function to return the number of leaves in the binary
    //tree to which p points
    int leaves=0;
};

//Definition of member functions
template <class elemType>
void binaryTreeType<elemType>::insert(const elemType& insertItem)
{
    binaryTreeNode<elemType> *current;  //pointer to traverse the tree
    binaryTreeNode<elemType> *trailCurrent; //pointer behind current
    binaryTreeNode<elemType> *newNode;  //pointer to create the node

    newNode = new binaryTreeNode<elemType>;
    assert(newNode != NULL);
    newNode->info = insertItem;
    newNode->llink = NULL;
    newNode->rlink = NULL;

    if (binaryTreeType<elemType>::root == NULL)
        binaryTreeType<elemType>::root = newNode;
    else
    {
        current = binaryTreeType<elemType>::root;
        while (current != NULL)
        {
            trailCurrent = current;

            /*if (current->info == insertItem)
            {
                cerr << "The insert item is already in the list-";
                cerr << "duplicates are not allowed."
                     << insertItem << endl;
                return;
            }
            else
            */
            current = current->rlink;
        }//end while
        trailCurrent->rlink = newNode;
    }
}//end insert

template <class elemType>
binaryTreeType<elemType>::binaryTreeType()
{
    root = NULL;//add a new node here
}

template <class elemType>
bool binaryTreeType<elemType>::isEmpty() const
{
    return (root == NULL);
}

template <class elemType>
void binaryTreeType<elemType>::inorderTraversal() const
{
    inorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::returnBuy(int buyn)
{
    buy(buyn);
}

template <class elemType>
void binaryTreeType<elemType>::preorderTraversal()
{
    preorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::postorderTraversal() const
{
    postorder(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeHeight() const
{
    return height(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeNodeCount()
{
    return nodeCount(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeLeavesCount()
{
    return leavesCount(root);
}

template <class elemType>
void  binaryTreeType<elemType>::copyTree
(binaryTreeNode<elemType>* &copiedTreeRoot,
 binaryTreeNode<elemType>* otherTreeRoot)
{
    if (otherTreeRoot == NULL)
        copiedTreeRoot = NULL;
    else
    {
        copiedTreeRoot = new binaryTreeNode<elemType>;
        copiedTreeRoot->info = otherTreeRoot->info;
        copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
        copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
    }
} //end copyTree

template <class elemType>
void binaryTreeType<elemType>::buy(int buyN)
{
    if (root==NULL){
        cout << "There is nothing to buy unfortunatly bye "<<endl;
        return;
    }
    stack <binaryTreeNode<elemType>* > stre;
     binaryTreeNode<elemType> *temp1=root;
    binaryTreeNode<elemType> *temp2;
    //temp2=root;
    if (buyN==1)
    {
        root=temp1->rlink;
        free(temp1);
        return;
    }
    for (int i = 0 ; i < buyN-2; i++){
        temp1=temp1->rlink;
    }
    temp2=temp1->rlink;
    temp1->rlink=temp2->rlink;
    free(temp2);
    /*
    int counter=0;
    system("CLS");
    while ((p != NULL) || (!stre.empty()))
    {
        if (p!=NULL)
        {
            stre.push(p);
            p=p->llink;
        }
        else
        {
            p=stre.top();
            stre.pop();
            cout << ++counter<<". " << p->info << endl;
            p=p->rlink;
        }
    }*/
}
template <class elemType>
void binaryTreeType<elemType>::inorder(binaryTreeNode<elemType> *p) const
{
    stack <binaryTreeNode<elemType>* > stre;
    int counter=0;
    system("CLS");
    while ((p != NULL) || (!stre.empty()))
    {
        if (p!=NULL)
        {
            stre.push(p);
            p=p->llink;
        }
        else
        {
            p=stre.top();
            stre.pop();
            cout << ++counter <<" . " << p->info << endl;
            p=p->rlink;
        }
    }
}

template <class elemType>
void binaryTreeType<elemType>::preorder(binaryTreeNode<elemType> *p)
{
    if (p != NULL)
    {
        cout<<p->info<<" ";
        preorder(p->llink);
        preorder(p->rlink);
    }
}

template <class elemType>
void binaryTreeType<elemType>::postorder(binaryTreeNode<elemType> *p) const
{
    if (p != NULL)
    {
        postorder(p->llink);
        postorder(p->rlink);
        cout << p->info << " ";
    }
}

//Overload the assignment operator
template <class elemType>
const binaryTreeType<elemType>& binaryTreeType<elemType>::
operator=(const binaryTreeType<elemType>& otherTree)
{
    if (this != &otherTree) //avoid self-copy
    {
        if (root != NULL)  //if the binary tree is not empty,
            //destroy the binary tree
            destroy(root);

        if (otherTree.root == NULL) //otherTree is empty
            root = NULL;
        else
            copyTree(root, otherTree.root);
    }//end else

    return *this;
}

template <class elemType>
void  binaryTreeType<elemType>::destroy(binaryTreeNode<elemType>* &p)
{
    if (p != NULL)
    {
        destroy(p->llink);
        destroy(p->rlink);
        delete p;
        p = NULL;
    }
}

template <class elemType>
void  binaryTreeType<elemType>::destroyTree()
{
    destroy(root);
}

//copy constructor
template <class elemType>
binaryTreeType<elemType>::binaryTreeType
(const binaryTreeType<elemType>& otherTree)
{
    if (otherTree.root == NULL) //otherTree is empty
        root = NULL;
    else
        copyTree(root, otherTree.root);
}

template <class elemType>
binaryTreeType<elemType>::~binaryTreeType()
{
    destroy(root);
}

template <class elemType>
int binaryTreeType<elemType>::height(binaryTreeNode<elemType> *p) const
{
    if (p == NULL)
        return 0;
    else
        return 1 + max(height(p->llink), height(p->rlink));
}

template <class elemType>
int binaryTreeType<elemType>::max(int x, int y) const
{
    if (x >= y)
        return x;
    else
        return y;
}

template <class elemType>
int binaryTreeType<elemType>::nodeCount(binaryTreeNode<elemType> *p)
{

    // cout << "Write the definition of the function nodeCount for programming exercise 9.3"
    //    << endl;
    if (p!=NULL)
    {
        nodeCount(p->llink);
        nodeCount(p->rlink);
    }

    return 0;
}

template <class elemType>
int binaryTreeType<elemType>::leavesCount(binaryTreeNode<elemType> *p)
{
    //  cout << "Write the definition of the function leavesCount"
    //     << endl;
    if (p==NULL)
        leaves++;
    if (p!=NULL)
    {
        leavesCount(p->llink);
    }
    if(p!=NULL)
    {
        leavesCount(p->rlink);
    }

    return leaves;
}

#endif
