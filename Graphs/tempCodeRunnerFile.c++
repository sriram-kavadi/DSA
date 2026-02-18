
    graph.insert(5,6);

    graph.print();

    graph.bfs(6);
    
    vector<bool>vis(7,false);

    graph.dfs(0,vis);