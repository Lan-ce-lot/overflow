#include<bits/stdc++.h>
using namespace std;
#define MAX_N 10000
struct node{
	int val;
	node *lch,*rch;
}; 
node *insert(node *p,int x)
{
	if(p == NULL)
	{
		node *p = new node;
		p->val;
		p->lch = p->rch = NULL;
		return p;
	}
	else
	{
		if(x < p->val)
		p->lch = insert (p->lch,x);
		else
		p->rch = insert(p->rch,x);
		return p;
	}
}

bool find(node *p,int x)
{
	if(p == NULL)
	return false;
	else if(x == p->val)
	return true;
	else if(x < p->val)
	return find(p->lch,x);
	else return find(p->rch,x);
}

node *remove(node *p,int x)
{
	if(p == NULL)return NULL;
	else if(x<p->val)
	p->lch = remove(p->lch,x);
	else if(x>p->val)
	p->rch = remove(p->rch,x);
	else if(p->lch==NULL)
	{
		node *q = p->rch;
		delete p;
		return q;
		
	 } 
	 else if(p->lch->rch == NULL)
	 {
	 	node *q = p->lch;
	 	q->rch = p->rch;
	 	delete p;
		return q; 
	 }
	 else 
	 {
	 	node *q;
	 	for(q = p->lch;q->rch != NULL;q = q->rch);
	 	node *r = q->rch;
	 	q->rch = r->lch;
	 	r->lch = p->lch;
	 	r->rch = p->rch;
	 	delete p;
	 	return r;
	 }
	 return p;
}


int main()
{
	node *root = NULL;
	root = insert(root,1);
	cout<<find(root,1);
//	system("pause");
	return 0;
}
