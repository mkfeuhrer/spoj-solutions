/* Name: Mohit Khare
B.Tech 2nd Year
Computer Science and Engineering
MNNIT Allahabad
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb push_back
#define VI vector<int>
#define VS vector<string>
typedef pair<int,int> pii;
#define ALL(x) x.begin(), x.end()
int ans = 0;
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists  // A function used by DFS
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // function to add an edge to graph
    void DFS(int v);
    int DFSUtil(int v, bool visited[]);    // DFS traversal of the vertices reachable from v
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
int Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    int m,m1=-1,m2=-1;
    visited[v] = true;
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            {
                m=DFSUtil(*i, visited);
                if(m>=m1)
                {
                 m2= m1;
                 m1 = m;
                }
                else if(m>m2)
                 m2=m;
            }
    ans = max(ans , m1+m2+2);
    return (m1 + 1);        
}
 
// DFS traversal of the vertices reachable from v. It uses recursive DFSUtil()
/*void Graph::DFS(int v)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function to print DFS traversal
    DFSUtil(v, visited);
}*/
 
int main()
{
    // Create a graph given in the above diagram
    int n;
    scanf("%d",&n);
    Graph g(n);
    int m = n-1;
    while(m--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        a--; b--;
        g.addEdge(a, b);
    }
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    g.DFSUtil(0, visited);
    cout<<ans<<endl;
    return 0;
}