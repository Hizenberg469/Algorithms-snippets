priority_queue<pii> q;
q.push({0,1});
dist[1]=0;
while(!q.empty()){
	pii n=q.top();q.pop();
	int weight=n.F,node=n.S;
	
	if( vis[node] )continue;
	vis[node]=true;
	for(pii& nbr : g[node]){
		int n_nbr=nbr.F,n_w=nbr.S;
		if( dist[node]+n_w<dist[n_nbr] ){
			dist[n_nbr]=dist[node]+n_w;
			q.push({-dist[n_nbr],n_nbr});
		}
	}
}