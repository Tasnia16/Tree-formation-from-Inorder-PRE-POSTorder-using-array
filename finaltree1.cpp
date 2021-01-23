#include<bits/stdc++.h>
using namespace std;
string Preorder[100];
string Inorder[100];
string Postorder[100];
string Tree[100]={};int k=1,p;

void create_node_preorder(int position,int start,int end){
    if(start>end)
        return;
    int i=start;
    k++;
    while(Inorder[i]!=Preorder[k])
        i++;
    Tree[position]=Inorder[i];
    create_node_preorder(position*2,start,i-1);
    create_node_preorder(position*2+1,i+1,end);

}

void create_node_postorder(int pos,int start,int End)
{
    if(start>End)
        return;
    int i=start;
    p--;
    if(p>0)
    {
        while(Inorder[i]!=Postorder[p]&&i<=End)
            i++;

        if(Inorder[i]==Postorder[p])
        {
            Tree[pos]=Inorder[i];}
            create_node_postorder(pos*2+1,i+1,End);
            create_node_postorder(pos*2,start,i-1);

    }

}
int main(void)
{
    int j,length,choice;
    int i=1,position=1,end_Of_Tree=100;
    cout<<"Enter the length of Inorder and preorder/postorder:";
    cin>>length;
        cout<<"Enter Inorder:";
        for(j=1;j<=length;j++)
        cin>>Inorder[j];

        cout<<"Enter choice ( 1: Preorder, 2: Postorder):";
        cin>>choice;

        if(choice==1)
      {
          cout<<"Enter preorder:";
        for(j=1;j<=length;j++)
          cin>>Preorder[j];
          Tree[position]=Preorder[1];
      while(Inorder[i]!=Preorder[position])
        i++;
      create_node_preorder(position*2,1,i-1);
      create_node_preorder(position*2+1,i+1,length);

   }

   else
   {
       cout<<"Enter postorder:";
        for(j=1;j<=length;j++)
          cin>>Postorder[j];

          Tree[position]=Postorder[length];
    while(Inorder[i]!=Postorder[length])
        i++;
    p=length;
    create_node_postorder(position*2+1,i+1,length);
    create_node_postorder(position*2,1,i-1);
   }
   while(Tree[end_Of_Tree].empty())
        end_Of_Tree--;

     cout<<"Tree is : ";

      for(i=1;i<=end_Of_Tree;i++)
        {
            if(Tree[i].empty())
                cout<<"-"<<" ";
            else
                cout<<Tree[i]<<" ";
        }
}

