vector<int> dist(n+1,(int)-1e17);

dist[1]=0;

for(int i = 1 ; i < n ; i++ ){
	for(auto& e : g ){
		int a,b,w;
		tie(a,b,w)=e;
		dist[b]=max(dist[b],dist[a]+w);
	}
}

for(auto& e : g ){
	int a,b,w;
	tie(a,b,w)=e;
	if( dist[b] < dist[a] + w ){
		cycle[b]=true;
	}
}