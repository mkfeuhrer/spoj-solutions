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
int rank[1000001];

// Class to represent a Digraph, with vertices labeled
// from 0 to V-1, where V is the number of vertices
class Graph
{
private:
    int V;
    vector <int>* adjList;
    bool* explored;
    list <int> topologicalOrder;
    int r = 1;
    void dfsUtil(int u)
    {
        explored[u] = true;
        for (vector <int>::iterator v = adjList[u].end()-1; v != adjList[u].begin()-1; v--)
            if (!explored[*v])
            {
                rank[*v]=r;
                r++;
                dfsUtil(*v);
                r--;
            }
        r++;
        topologicalOrder.push_front(u);
    }

    void dfs()
    {
        for (int u = 0; u < V; u++)
            if (!explored[u])
            {
                rank[u]=r;
                r++;
                dfsUtil(u);
            }
    }

public:

    // create an empty Digraph having V vertices
    Graph(int V)
    {
        this->V = V;
        adjList = new vector <int>[V];
        explored = new bool[V];
        memset(explored, false, V * sizeof(bool));
    }

    ~Graph()
    {
        delete [] adjList;
        delete [] explored;
    }

    // add a directed edge u -> v to the digraph
    // returns false if either u or v is less than 0 or greater than equal to V
    // returns true if the edge was added to the digraph
    bool addEdge(int u, int v)
    {
        if (u < 0 || u >= V) return false;
        if (v < 0 || v >= V) return false;
        adjList[u].push_back(v);
        return true;
    }

    list <int> getTopologicalOrder()
    {
        if (topologicalOrder.empty())
            dfs();

        return topologicalOrder;
    }

    void printTopologicalOrder()
    {
        int i = 0;
        if (topologicalOrder.empty())
            dfs();
        for (list<int>::iterator it = topologicalOrder.begin(); it != topologicalOrder.end(); it++)
            {
                printf("%d %d\n",rank[*it],*it);
                i++;
            }
        printf("\n");
    }

};

int main()
{
    int t;
    int k=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,r;
        scanf("%d %d",&n,&r);
        memset(rank,0,sizeof(rank));
        Graph G(n);
        while(r--)
        {
          int a,b;
          scanf("%d %d",&a,&b);
          G.addEdge(a, b);
        }

        printf("Scenario #%d",k);
        k++;
        G.printTopologicalOrder();
    }
    return 0;
}
