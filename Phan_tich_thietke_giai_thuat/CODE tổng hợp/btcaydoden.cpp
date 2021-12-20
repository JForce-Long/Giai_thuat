#include<stdio.h>
#include<stdlib.h>


// khai bao hang so
const char Red = 1;
const char Black = 0;

typedef struct NodeRB
{
	int key;
	char color;
	NodeRB *Left, *Right, *Parent;
	
};
// khoi tao node
NodeRB * CreateNodeRB(int key)
{
	NodeRB *p = new NodeRB;
	if(p == NULL) return p;
	p->key = key;
	p->color = Red;
	p->Left = p->Right = NULL;
	return p; 
}
//ham quay trai
void rotateLeft(NodeRB *x,*root)
{
	NodeRB *y=x->Right;
	x->Right = y->Left;
	if(y->Left != NULL)
	{
		y->Left->Parent = x;
		y->Left = x;
	}
	if(x->Parent != NULL){//x k phai root
		y->Parent = x->Parent;
		if(x->Parent->Left == x)//x la node con
		{
		x->Parent->Left = y;
		}
		else{
			x->Parent->Right = y;
		}
	}
	else {//x la root
		y->Parent == NULL;
		root = y;
	}
	//cha cua x
	x->Parent = y;
	x=y;
}
//ham quay phai
void rotateRight(NodeRB *x,*root)
{
	NodeRB *y=x->Left;
	x->Left = y->Right;
	if(y->Right != NULL)
	{
		y->Right->Parent = x;
		y->Right = x;
	}
	if(x->Parent != NULL){//x k phai root
		y->Parent = x->Parent;
		if(x->Parent->Left == x)//x la node con
		{
		x->Parent->Left = y;
		}
		else{
			x->Parent->Right = y;
		}
	}
	else {//x la root
		y->Parent == NULL;
		root = y;
	}
	//cha cua x
	x->Parent = y;
	x=y;
}
// tim kiem khoa tren cay do den
void SearchNode(NodeRB *root, int x)
{
	if(root == NULL) return 0;
	if(root->key == x) return 1;
	if(root->key > x) return SearchNode(root->Left,x);
	else return SearchNode(root->Right, x);
}
//them node vao cay
void InsertNode(NodeRB *root, NodeRB *x)
{
	if(root==NULL) root=x;
	return x;
	else if(x->key == root->key) return;
	else if(x->key < root->key)
	{
		if(root->Left == NULL)
		{
			root->Left = x;
			root->Left->Parent = root;
		}else{
		if(root->Right == NULL)
		{
			root->Right  = x;
			root->Right->Parent = root;
		}
	}
	}
}
int KTChau(NodeRB *x)
{
	NodeRB *P, *G;
	p = x->Parent;
	G = P->Parent;
	if((G->Left == P && P->Left == x) || (G->Right == P && P->Right == x))
	return 0;//x la chau ngoai
	else return 1;//x la chau noi
}
//chinh sua khi them mot node
void InsertFixup(NodeRB *root, NodeRB *x)
{
	//x la goc nen doi mau x
	if(x  == root)
	{
	    x->color = Black;
	    return ;
    }
    // x k la goc
    else
    {
    	NodeRB *P = x->Parent;
    	//th1: cha cua x mau den 
    	if(P->color == Black) return;
    	else//th2: cha cua x mau do
    	{
    		// u la chu
    		NodeRB *U,*G;
    		if(P->Parent !=NULL)
    		{
    			G = P->Parent;
    			if(G->Left == P && G->Right != NULL)//p la con trai
    			{
    				U = G->Right;
    				U->Parent = G;
    				
    				//u do thi doi mau u,p,g
    				if(U->color == Red) 
    				{
    					U->color = P->color = Black;
    					if(G!=root)
    					{
    						G->color = Red;
						}
						return;
					}
					else //u den
					{
						//th P do, G den, x la chau ngoai thi doi mau P,G quay phai tai G, doi mau
						if(KTChau(x) == 0)
						{
							P->color = Black;
							G->color = Red;
							rorateRight(G,root);
						}
						
					}
				}
				
			}
		}
	}
	
} 
