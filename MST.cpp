/* 
Name : Mohit Khare 
B.Tech 2nd Year
Computer Science and Engineering
MNNIT Allahabad
*/    
#include <bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i > (int)(b); i--)
#define ll long long int
#define ull unsigned long long int
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000007
# define INF 0x3f3f3f3f
ll ans = 0;
 
typedef pair<int, int> iPair;
 
class Graph
{
    int V;    // No. of vertices
 
    list< pair<int, int> > *adj;
 
public:
    Graph(int V);  // Constructor
 
    void addEdge(int u, int v, int w);
 
    void primMST();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair> [V];
}
 
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
 
void Graph::primMST()
{
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
 
    int src = 0; // Taking vertex 0 as source
 
    vector<int> key(V, INF);
 
    vector<int> parent(V, -1);
 
    vector<bool> inMST(V, false);
 
    pq.push(make_pair(0, src));
    key[src] = 0;
 
    while (!pq.empty())
    {
        
        int u = pq.top().second;
        pq.pop();
 
        inMST[u] = true;  // Include vertex in MST
 
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
 
            if (inMST[v] == false && key[v] > weight)
            {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
 
    for (int j = 1; j < V; ++j)
    {
        ans+=key[j];
    }
}
 
int main()
{
    int node,edge;
    scanf("%d %d",&node,&edge);
    Graph g(node);
    while(edge--)
    {
        int i,j,k;
        scanf("%d %d %d",&i,&j,&k);
        i--;
        j--;
        g.addEdge(i,j,k);
    }
    g.primMST();
    printf("%lld\n",ans);
 
    return 0;
}
