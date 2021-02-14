
#include<bits/stdc++.h>
using namespace std;


vector<int> graph[1000001];
vector<bool> visited(1000001,0);

void addEdge(int u,int v)
{
	graph[u].push_back(v);
	graph[v].push_back(u);
}

void dfs(int node)
{
	if(visited[node])
		return;
	visited[node] = true;
	cout << "Visited Node : " << node << "\n";
	for(auto a : graph[node])
		dfs(a);
}

int main()
{
	int n;cin >> n;//no of edges
	for(int i=0;i<n;i++)
	{
		int u,v;cin >> u >> v;
		addEdge(u,v); //add edge between u and v for directed graph
	}
	dfs(1);
	return 0;
}