// Meysam Aghighi

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define INF 20000000

struct edge{
	int to, weight;
	edge(){}
	edge(int _to, int _weight){
		to = _to;
		weight = _weight;
	}
	bool operator < (edge e) const {
		return weight > e.weight;
	}
};

int n,m,qq,s,u,v,w;

int main(){
	while (scanf("%d%d%d%d",&n,&m,&qq,&s) && n){
		vector <pair<edge,int> > edgelist;
		for (int i=0;i<m;i++) scanf("%d%d%d",&u,&v,&w), edgelist.push_back(make_pair(edge(u,v),w));
		// Bellman-Ford's Algorithm
		vector <int> dist = vector<int>(n+1,INF);
		dist[s] = 0;
		for (int i=0;i<n-1;i++)
			for (int j=0;j<m;j++){
				u = edgelist[j].first.to;
				v = edgelist[j].first.weight;
				w = edgelist[j].second;
				if (dist[u] != INF && dist[u] + w < dist[v]) dist[v] = dist[u] + w;
			}
		// Detect negative cycles
		for (int i=0;i<n;i++) // Avalesh in for nabud wrong shodam! faghat ye bar yal ha ro check mikardam, vali ba in accept shod! :)
			for (int j=0;j<m;j++){
				u = edgelist[j].first.to;
				v = edgelist[j].first.weight;
				w = edgelist[j].second;
				if (dist[u] != INF && dist[u] + w < dist[v]) dist[v] = -INF;
			}

		for (int i=0;i<qq;i++){
			scanf("%d",&u);
			if (dist[u] == INF) printf("Impossible\n");
			else if (dist[u] == -INF) printf("-Infinity\n");
			else printf("%d\n",dist[u]);
		}
		printf("\n");
	}
	return 0;
}

