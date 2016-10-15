#include <bits/stdc++.h>
using namespace std;
#define INF 1000000
struct edge
{
	int u;
	int cost; //weighted graph 
};
vector <edge> v[10001];
bool operator <(edge a , edge b)
{
	return a.cost < b.cost;
 
}
int dist[10001]; // to store the distances
int dijk( int s )
{
	priority_queue <edge> q;//since weighted graph rest simple bfs implementation
	q.push((edge){s,0});
	dist[s] = 0;
	while( !q.empty() )
	 {
	 	edge val = q.top();
	 	q.pop();
	 	int u = val.u;
	 	for(int i=0;i<v[u].size();i++)
	 	 {
	 	 	int value = v[u][i].u;
	 	 	int price = v[u][i].cost;
	 	 	if( dist[value] > dist[u] + price )
	 	 	 {
	 	 	 	dist[value] = dist[u] + price ;
	 	 	 	q.push(v[u][i]);
	 	 	 }
	 	 }
	 }
}
int main() 
{
 
	// your code here
	int t;
	scanf("%d",&t);
	while( t-- )
	 {
	 	int i,vert,k;
	 	scanf("%d%d",&vert,&k);
	 	for(i=0;i<=vert;i++)
	 	 v[i].clear();
	 	while( k-- )
	 	 {
	 	 	int x,y,c;
	 	 	scanf("%d%d%d",&x,&y,&c);
	 	 	v[x].push_back((edge){y,c});
	 	 }
	 	for(i=0;i<=vert;i++)
	 	 dist[i]=INF;
	 	int source , dest;
	 	scanf("%d%d",&source,&dest);
	 	dijk( source );
	 	if(dist[dest]!=INF)
	 	 printf("%d\n",dist[dest]);
	 	else 
	 	 printf("NO\n");
	 }
	return 0;
}