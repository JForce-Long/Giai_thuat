#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
//Khai bao hang so
const char Red = 1;
const char Black = 0;

//Khai bao struct
typedef struct tagNodeRB
{
int key;
char color;
tagNodeRB* left, *right, *parent;
} NodeRB;

//==========ham tao node==================
NodeRB* createNodeRB(int key)
{
NodeRB *p= new NodeRB;
if(p==NULL) return NULL;
p->key=key;
p->color=Red;
p->left=p->right=NULL;
return p;
}

//=============ham quay trai=========
void rotateLeft(NodeRB *&x,NodeRB *root)
{
NodeRB *y=x->right;
//xac lap x->right=y->left
x->right=y->left;
if(y->left!=NULL)
y->left->parent=x;
//xac lap y->left=x
y->left=x;
if(x->parent!=NULL) //x khong phai root
{
y->parent=x->parent;
if(x->parent->left==x)//x la node con
x->parent->left=y;
else
x->parent->right=y;
}
else //x la root
{
y->parent=NULL;
root=y;
}
//xac lap cha cho x
x->parent=y;
//tra lai con tro
x=y;
}

//==========ham quay phai=========
void rotateRight(NodeRB *&x,NodeRB *root)
{
NodeRB *y=x->left;
//xac lap x->left=y->right
x->left=y->right;
if(y->right!=NULL)
y->right->parent=x;
//xac lap y->right=x
y->right=x;
if(x->parent!=NULL) //x khong phai root
{
y->parent=x->parent;
if(x->parent->left==x)//x la node con
x->parent->left=y;
else
x->parent->right=y;
}
else //x la root
{
y->parent=NULL;
y=root;
}
//xac lap cha cho x
x->parent=y;
//tra lai con tro
x=y;
}

//====them node vao cay nhung chua can bang===
void BSTree_Insert(NodeRB *&root,NodeRB *x)
{
if(root==NULL)
{
root=x;
return;
}
else if(x->key==root->key) return;
else if(x->key<root->key)
{
if(root->left==NULL)
{
root->left=x;
root->left->parent=root;
}
BSTree_Insert(root->left,x);
}
else
{
if(root->right==NULL)
{
root->right=x;
root->right->parent=root;
}
BSTree_Insert(root->right,x);
}
}

//==============================================
int KTChau(NodeRB *x)
{
NodeRB *P,*G;
P=x->parent;
G=P->parent;
if((G->left==P && P->left==x) || (G->right==P && P->right==x))
return 0;//x la chau ngoai
else return 1;//x la chau noi
}

//===========ham kiem tra va can bang sau khi them node==========
void insertFixup(NodeRB *root, NodeRB *x)
{
//x la goc nen doi mau
if(x==root)
{
x->color=Black;
return;
}
else //x khong la goc
{
NodeRB *P=x->parent;

//TH1 : cha cua x (node p) mau den
if(P->color==Black) return;
else//cha cua x (node p) mau do
{
//TH2 : U do thi doi mau P,U,G
NodeRB *G,*U;
if(P->parent!=NULL)
{
G=P->parent;
if(G->left==P && G->right!=NULL)//P la con trai
{
U=G->right;
U->parent=G;
//TH2 : U do thi doi mau P,U,G
if(U->color==Red)
{
U->color=P->color=Black;
if(G!=root)
{
G->color=Red;
}
return;
}
else //U den
{
//TH3 : x la chau ngoai (P do, G den)
//doi mau P ,G, quay tai G
if(KTChau(x)==0)
{
P->color=Black;
G->color=Red;
rotateRight(G,root);
}
else //x la chau noi
{
rotateLeft(P,root); //quay tai P cho x thanh chau ngoai
//doi mau P ,G, quay tai G
P->color=Black;
G->color=Red;
rotateRight(G,root);
}
}
}
else if(G->right==P && G->left!=NULL)//P la con phai
{
U=G->left;
U->parent=G;
//TH2 : U do thi doi mau P,U,G
if(U->color=Red)
{
U->color=P->color=Black;
if(G->parent!=root)
{
G->color=Red;
}
}
else //U den
{
//TH3 : x la chau ngoai (P do, G den)
//doi mau P ,G, quay tai G
if(KTChau(x)==0)
{
P->color=Black;
G->color=Red;
rotateLeft(G,root);
}
else //x la chau noi
{
rotateRight(P,root); //quay tai P cho x thanh chau ngoai
//doi mau P ,G, quay tai G
P->color=Black;
G->color=Red;
rotateLeft(G,root);
}
}
}
}
}
}
}

//================them node vao cay============
void RBTree_Insertion(NodeRB *&root, int key)
{
NodeRB *x = createNodeRB(key);

BSTree_Insert(root, x);
insertFixup(root, x);
}

//=============================================
void LNR(NodeRB* root)
{
if(root!=NULL)
{
LNR(root->left);
cout<<root->key<<" ";
LNR(root->right);
}
}

//===============================================
void createTextFile(int n) //tao file dulieu.txt chua day n so nguyen
{
int a[500];//Mang chua 500 so nguyen
srand(time(NULL));//Lam ham rand() co gia tri ngau nhien moi lan chay
for(int i=0; i<n; i++)
a[i]=rand()%500;
ostream out("dulieu.txt");
out<<n<<endl;
for(i=0; i<n; i++)
out<<a[i]<<endl;
out.close();
}

//=============================================
void createTreeFromTextFile(NodeRB* &root) //xay dung cay do den tu du lieu file dulieu.txt
{
ifstream in("dulieu.txt");
int n;//Chua so phan tu cua cay
in>>n;
for(int i=1; i<=n; i++)
{
int x;//Chua key
in>>x;
RBTree_Insertion(root,x);
}
}

//============tim kiem khoa tren cay do den===========
int searchNode(NodeRB *root,int x) //Tra ve 0: khong tim thay; 1: tim thay
{
if(root==NULL) return 0;
if(root->key==x) return 1;
if(root->key>x) return searchNode(root->left,x);
else return searchNode(root->right,x);
}
