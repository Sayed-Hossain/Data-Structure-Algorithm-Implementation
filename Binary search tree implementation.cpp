/*This code implements the Binary search tree Insertion, Search, Find height, traverse by level, Inorder traversal,
Checking if it is a binary search tree and deletion operation.
 */
 
#include<bits/stdc++.h>
using namespace std;

struct BstNode
{
    int data;
    BstNode* left;
    BstNode* right;
};

void traverse_level(BstNode *root);

void inorder(BstNode *root);

BstNode* Insert(BstNode* root,int data);

int find_height(BstNode *root);

bool Search(BstNode* root,int data);

bool IsBST(BstNode* root,int min_value,int max_value);

bool is_binarysearch_tree(BstNode* root);

BstNode* Delete(BstNode * root ,int data);

BstNode* find_min(BstNode* root);

int main()
{
    BstNode* root = NULL;

    cout<<"Binary Search tree"<<endl;
    cout<<"1.Insert"<<endl;
    cout<<"2.Search"<<endl;
    cout<<"3.Find height"<<endl;
    cout<<"4.traverse by level"<<endl;
    cout<<"5.Inorder traversal"<<endl;
    cout<<"6.Is binary search tree"<<endl;
    cout<<"7.delete"<<endl;
    cout<<"8.exit"<<endl;

    while(1)
    {

        cout<<"Enter the choice: ";
        int item;
        cin>>item;

        switch(item)
        {
        case 1:
           {
            int data;
            cout<<"insert data: ";
            cin>>data;
            root = Insert(root,data);
            break;
           }
        case 2:
            {
            int number;
            cout<<"Enter number be searched\n";
            cin>>number;

            if(Search(root,number) == true)
                cout<<"Found\n";
            else
                cout<<"Not Found\n";

            break;
            }
        case 3:
            {
                int height = find_height(root);
                cout<<height<<endl;
                break;
            }
        case 4:
            {
                traverse_level(root);
                cout<<endl;
                break;

            }
        case 5:
            {
                inorder(root);
                cout<<endl;
                break;
            }
        case 6:
            {
               if(is_binarysearch_tree(root)==true)
                cout<<"YES"<<endl;
               else
                cout<<"NO"<<endl;
                break;
            }

        case 7:
            {
                int value;
                cout<<"Enter the node to be deleted: ";
                cin>>value;
            Delete(root,value);
            }
        case 8:
            {
                exit(1);
            }
        }

    }
}

BstNode* Insert(BstNode* root,int data)
{
    if(root == NULL)
    {
        BstNode* newNode = new BstNode();
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        root = newNode;
    }

    else if(data <= root->data)
    {
        root->left = Insert(root->left,data);
    }

    else
    {
        root->right = Insert(root->right,data);
    }
    return root;
}

bool Search(BstNode* root,int data)
{
    if(root == NULL)
    {
        return false;
    }
    else if(root->data == data)
    {
        return true;
    }
    else if(data <= root->data)
    {
        return Search(root->left,data);
    }
    else
    {
        return Search(root->right,data);
    }
}

int find_height(BstNode *root)
{
    if(root == NULL)
    {
        return -1;
    }
    int left_height = find_height(root->left);

    int right_height = find_height(root->right);


    return max(left_height,right_height)+1;

}

void traverse_level(BstNode *root)
{
    if(root == NULL) return;

    queue<BstNode*>Q;

    Q.push(root);

    while(!Q.empty())
    {
        BstNode * current = Q.front();

           Q.pop();

        cout<< current->data<<" ";
        if(current->left!=NULL) Q.push(current->left);
        if(current->right!=NULL) Q.push(current->right);


    }

}

void inorder(BstNode *root)
{
    if(root == NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

bool IsBST(BstNode* root,int min_value,int max_value)
{

    if(root==NULL) return true;

    if(root->data > min_value && root->data < max_value && IsBST(root->right,root->data,max_value) && IsBST(root->left,min_value,root->data) )

        return true;

    else
        return false;
}


bool is_binarysearch_tree(BstNode* root)
{

    return IsBST(root ,INT_MIN,INT_MAX);
}


BstNode* Delete(BstNode * root ,int value)
{

    if(root == NULL) return root;

    else if(root->data > value) root->right = Delete(root->right,value);
    else if(root->data < value) root->left = Delete(root->left,value);
    else
    {
        if(root->right == NULL && root->left == NULL)
        {
            delete root;
            root = NULL;
        }
        else if( root->right == NULL )
        {
            BstNode * temp = root;

            root = root->left;

            temp->data = root->data;

            delete temp;

        }

        else if( root->left == NULL )
        {
            BstNode * temp = root;

            root = root->right;

            temp->data = root->data;

            delete temp;

        }
        else
        {
            BstNode* temp = find_min(root->right);

            root->data = temp->data;

            root->right = Delete(root->right,temp->data);
        }

        return root;

    }
}

BstNode* find_min(BstNode* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}
