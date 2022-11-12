#include <iostream>
using namespace std;
struct node
{
    int data ;
    node*left ;
    node*right;

};
void BinaryTOLink(node*root,node**head)
{
    if(root==NULL)
    {
        return;
    }
    static node*prev=NULL;
    BinaryTOLink(root->left,head);
    if(prev==NULL)
    {
        *head=root;

    }
     else {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    BinaryTOLink(root->right,head);


}
node*newNode(int data)
{
    node* new_node = new node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return (new_node);
}
 
void print(node*node)

{
 while(node!=NULL)
 {
    cout<<node->data<<" ";
    node=node->right;
 }
}
int main()
{
    node* root=newNode(5);
    root->left=newNode(3);
    root->right=newNode(1);
    root->left->left=newNode(4);
    root->left->right=newNode(10);
    root->right->left=newNode(20);
    root->right->right=newNode(8);
    
    node*head=NULL;
    BinaryTOLink(root,&head);
    print(head);
    return 0;

}
