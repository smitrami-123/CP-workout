
#include<bits/stdc++.h>
using namespace std;

queue<int> q;
vector<int> graph[1000001];
vector<bool> visited(1000001,0);
vector<int> dist(1000001,0);

void addEdge(int u,int v)
{
	graph[u].push_back(v);
	graph[v].push_back(u);
}

void bfs(int x)
{
	visited[x]=true;
	cout << "Visited Node : " << x << "\n";
	dist[x]=0;
	q.push(x);
	while(!q.empty())
	{
		int s = q.front();
		q.pop();
		for(auto u : graph[s])
		{
			if(visited[u])continue;
			visited[u]=true;
			cout << "Visited Node : " << u << "\n";
			dist[u]=dist[s]+1;
			q.push(u);
		}
	}
}

int main()
{
	int n;cin >> n;//no of edges
	for(int i=0;i<n;i++)
	{
		int u,v;cin >> u >> v;
		addEdge(u,v); //add edge between u and v for directed graph
	}
	bfs(1);
	return 0;
}