#include<iostream>
using namespace std;

#define infinity 9999
#define ROW 10
#define COL 10

class Prims
{       
    int graph[ROW][COL], nodes;
        public:
        void createGraph();    
        void primsAlgo();  
};

void Prims::createGraph()    
{     
            int i, j;    
            cout << "Enter total number of cities(nodes): ";   
            cin >> nodes;
            cout << endl;   
            cout << "Enter the cost of connecting each pair of cities............" << endl;       
            for (i = 0; i < nodes; i++)    
            {            
                for (j = i; j < nodes; j++)
                {                
                    cout << "Enter the cost of connecting city " << i + 1 << " and city " << j + 1 << ": ";   
                    cin >> graph[i][j];
                    graph[j][i] = graph[i][j];     
                    cout << endl;         
                }        
            }
            for (i = 0; i < nodes; i++)  
            {           
                for (j = 0; j < nodes; j++)
                {              
                    if (graph[i][j] == 0)   
                    {                   
                         graph[i][j] = infinity;
                    }
                }
            }
}

 void Prims::primsAlgo()  
{        
            int visited[ROW], min = 0, i, j, x, y, ne = 0;      
            int cost = 0;     
            for (i = 0; i < nodes; i++)    
            {            
                visited[i] = 0;     
            }
            visited[0] = 1;   
            while(ne < nodes-1)
            {   
                min = infinity;      
                for(i=0;i<nodes;i++)
                {                
                    if(visited[i]==1)
                    {                    
                        for(j=0;j<nodes;j++)
                        {                        
                            if(visited[j]==0)
                            {
                               if(min > graph[i][j])
                               {                               
                                 min = graph[i][j];                                
                                 x = i;                               
                                 y = j;
                               }
                            }
                        }
                    }
                }
                visited[y] =1 ;            
                cout<<"Edge "<<x+1<<"->"<<y+1<<" is visited with cost "<<min<<endl;            
                cost+=graph[x][y];            
                ne++;       
            }        
            cout << "The minimum cost of connecting all the cities is: " << cost <<" units"<< endl;  
}

int main()
{    
    Prims obj;    
    obj.createGraph();    
    obj.primsAlgo();    
    return 0;
}
