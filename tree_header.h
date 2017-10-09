#ifndef _TREE_HEADER_H_
#define _TREE_HEADER_H_

#define ElementType int

struct treenode;
typedef treenode* ptot;
ptot createtreenode(int X);
void treeadd(ptot* T,int X);


struct TreeNode
{
  ElementType element;
  TreeNode* left;
  TreeNode* right;
};
typedef struct TreeNode* Position;
typedef struct TreeNode* SearchTree;

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X,SearchTree T);
SearchTree Delect(ElementType X, SearchTree T);
ElementType Retrive(Position P);
int ShowTree(SearchTree T,int D);
SearchTree CreateTree(ElementType X);

#endif

