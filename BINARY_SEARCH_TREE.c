#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct bst
{
int data;
struct bst*lf;
struct bst*rt;
};


struct bst* addele(struct bst*q,int data)
{
	if(q==NULL)
	 {
	 	 q=(struct bst*)malloc(sizeof(struct bst));
	 	 q->data=data;
		 q->lf=q->rt=NULL;
	 	return q;
	 }
	 
	else
	   {
	     if(q->data>data)
		 q->lf=addele(q->lf,data);
		 else
		 q->rt=addele(q->rt,data);	
	   } 
}




void preorder(struct bst*q)
{
	if(q==NULL)
	   return;
	
	printf(" %d",q->data);
	
	preorder(q->lf);
	
	preorder(q->rt); 
}


void inorder(struct bst*q)
{
	if(q==NULL)
	   return;
	
	inorder(q->lf);
	
	printf(" %d",q->data);
	
	inorder(q->rt); 
}



void postorder(struct bst*q)
{
	if(q==NULL)
	   return;
	
	
	postorder(q->lf);
	
	postorder(q->rt);
	 
	printf(" %d",q->data);
}



int search(struct bst*q,int data)
{
  if(q==NULL)
    return 0;	
  if(q->data==data)
     return 1;
  else
    {
    	if(q->data>data)
    	 return search(q->lf,data);
    	else
		 return search(q->rt,data); 
	}	 	
}

int searchwithoutrec(struct bst*q,int data)
{
	if(q==NULL)
	 return 0;
	 while(q!=NULL)
	    {
	   	 if(q->data==data)
	   	    return 1;
	   	 else
			 {
			 if(q->data>data)
			   q=q->lf;
			 else
			   q=q->rt;  	
			 }   
		} 
	 if(!q)
	    return 0;	
}




int minele(struct bst*q)
{

if(q->lf==NULL)
  return q->data;
  	
minele(q->lf);	

}




int minelewithoutrec(struct bst*q)
{

if(q==NULL)
  return 0;

while(q->lf!=NULL)
 {
 	q=q->lf;
 }
   	
return q->data;  	
}



int maxele(struct bst*q)
{
	
if(q->rt==NULL)	
 return q->data;
 
 maxele(q->rt);
}






int maxelewithoutrec(struct bst*q)
{

if(q==NULL)
  return 0;

while(q->rt!=NULL)
 {
 	q=q->rt;
 }
   	
return q->data;  	
}




struct bst* del(struct bst*q,int data)
{
	struct bst*temp;
	if(q==NULL)
	 return NULL;
	
	if(q->data!=data)
	 {
	if(q->data>data)
	  {
	  	q->lf=del(q->lf,data);
	  }
	else
	  {
	    q->rt=del(q->rt,data);
	  }
      }
     else
	    {
	   	 if(!q->lf)
	   	      {
	   	       temp=q;
			   q=q->rt;
			   free(temp);
			   return q;	   	
			  }
		 else if(!q->rt)
		      {
		       temp=q;
			   q=q->lf;
			   free(temp);
			   return q;	
			  }	  
		  else
		      {
		       temp=maxele(q->lf);
			   del(q,temp);  	
			   q->data=temp;
			  }	  
		} 
		return q;
}








struct bst*lca(struct bst*q,int n,int m)
{
if(q==NULL)
return NULL;

if(q->data>=n&&m>=q->data||q->data>=m&&n>=q->data)
  return q;
if(q->data>n)
return lca(q->lf,n,m);    	
	
else
return lca(q->rt,n,m);    	
}




int height(struct bst*q,int m)
{
	
	int i=0;
if(q==NULL)
 return 0;

   while(q->data!=m)
      {
       	++i;
		if(q->data>m)
		  q=q->lf;
		else
		  q=q->rt;        	
	  }
 	
	return i;
}






int isbst(struct bst*q)
{
if(q==NULL)
  return 0;
  
if(q->lf&&q->lf->data>q->data)
   return 0;
if(q->rt&&q->rt->data<q->data)
   return 0;
if(!isbst(q->lf)||!isbst(q->rt))
   return 0;
 return 1;          	
	
}




int main() 
{
struct bst*q=NULL;

q=addele(q,10);
q=addele(q,6);
q=addele(q,16);
q=addele(q,4);
q=addele(q,9);
q=addele(q,13);
q=addele(q,7);
q=addele(q,1);
q=addele(q,5);
q=addele(q,11);
q=addele(q,15);
q=addele(q,28);
/*
printf("THIS IS CALLED INORDER TRAVERSAL:- ");
inorder(q);

printf("\n\nTHIS IS CALLED PREORDER TRAVERSAL:- ");
preorder(q);

printf("\n\nTHIS IS CALLED POSTORDER TRAVERSAL:- ");
postorder(q);

int i=search(q,16);
if(i)
 printf("\n ITEM FOUND");
else
 printf("\n ITEM NOT FOUND"); 
 
 
 
 int i=searchwithoutrec(q,19);
if(i)
 printf("\n ITEM FOUND");
else
 printf("\n ITEM NOT FOUND"); 
 
 
printf(" %d",minele(q));
 
printf(" %d",maxele(q));

printf(" %d",minelewithoutrec(q));


printf(" %d",maxelewithoutrec(q));



q=del(q,10);

printf("\n\nTHIS IS CALLED PREORDER TRAVERSAL:- ");
preorder(q);



if(lca(q,10,1)==NULL)
printf("COMMING NULL");
else
printf("the lowest common ancestor %d\n",lca(q,10,1)->data);

int m=height(q,lca(q,10,1)->data);


printf("DISTANCE BETWEEN 10 and 1 is %d",height(q,10)+height(q,1)-2*m);

*/

isbst(q)?printf("YES"):printf("NO");


return 0;
}
