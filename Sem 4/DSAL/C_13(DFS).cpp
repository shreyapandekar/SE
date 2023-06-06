// DFS
#include<iostream>
using namespace std;

class stack
{
   public:
      int top;
      int arr[10];
      stack()
      {
         top=-1;
      }
      void push(int data)
      {
            arr[++top]=data;
      }
      int pop()
      {
         int data=arr[top];
         top--;
         return data;
      }
      int isEmpty()
      {
         if(top==-1)
            return 1;
         else 
            return 0;
      }
};

int main()
{
      int v,ch,u,n;
      int visited[10];
      int mat[10][10];
      stack s;
      cout<<"\nHow many vertices do you want : ";
      cin>>n;
      int i,j;
      for(int i=0;i<n;i++)
      {
         for(int j=0;j<n;j++)
         {
            mat[i][j]=0;
         }
      }
      do
      {
         cout<<"\nEnter edge in pair : ";
         cin>>u>>v;
         mat[u][v]=1;
         // mat[v][u]=1;
         cout<<"\nDo you want to enter next pair (enter 1): ";
         cin>>ch;
      }while(ch==1);
    
      cout<<"\n\nMatrix is : \n";
      for(int i=0;i<n;i++)
      {
         for(int j=0;j<n;j++)
         {
            cout<<"\t"<<mat[i][j];
            
         }
        cout<<"\n";
      }
    
      for(int i=0;i<n;i++)
      {
         visited[i]=0;
      }
      
      cout<<"\nEnter the starting vertex : ";
      cin>>u;
      cout<<"\n\nDFS TRAVERSAL :\n";
      s.push(u);
      
         while(!s.isEmpty())
         {
            v=s.pop();
            if(visited[v]==0)
            {
               visited[v]=1;
               cout<<"\t"<<v;
            }
            for(int j=n-1;j>=0;j--)
            {
               if(mat[v][j]==1 && visited[j]==0)
               {
                  s.push(j); 
               }
            }
         }
      
      cout<<"\n";
   return 0;
}   
