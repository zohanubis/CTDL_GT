void prim(int u){
	vector<canh> MST; // cay khung
	int d = 0; // chieu dai cay khung
	used[u] = true; // dua dinh u vao tap V(MST)
	while(MST.size() < n - 1){
		//e = (x, y) : Cạnh ngắn nhất có x thuộc V và y thuộc V(MST)
		int min_w = INT_MAX;
		int X, Y; // luu 2 dinh cua canh e
		for(int i = 1; i <= n; i++){
			//neu dinh i thuoc tap V(MST)
			if(used[i]){
				//duyet danh sach ke cua dinh i
				for(pair<int,int> it : adj[i]){
					int j = it.first, trongso = it.second;
					if(!used[j] && trongso < min_w){
						min_w = trongso;
						X = j; Y = i;
					}
				}
			}
		}
		MST.push_back({X, Y, min_w});
		d += min_w;
		used[X] = true; // cho dinh X vao V(MST), loai X khoi tap V
	}
	cout << d << endl;
	for(canh e : MST){
		cout << e.x <<  " " << e.y << " " << e.w << endl;
	}
}