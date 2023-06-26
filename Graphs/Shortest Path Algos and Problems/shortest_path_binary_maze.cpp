if(grid[0][0]==1)return -1;
        //defining starting and ending nodes
        int srow=0;
        int scol=0;
        int trow=grid.size()-1;
        int tcol=grid[0].size()-1;
        
        int m=grid.size();
        int n=grid[0].size();
        //defining the initial configuration
        vector<vector<int>>dist(m,vector<int>(n,1e9));//distance matrix
        dist[srow][scol]=1;
        queue<pair<int,pair<int,int>>>q;//queue: dist,row,col
        q.push({1,{0,0}});
        
        //defining the movements
        int drow[]={-1,-1,0,1,1,1,0,-1};
        int dcol[]={0,1,1,1,0,-1,-1,-1};

        //djkistra implementation
        while(!q.empty())
        {
            int d=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            for(int i=0;i<8;i++)
            {
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==0 && dist[nrow][ncol]>d+1)
                {
                    dist[nrow][ncol]=d+1;
                    q.push({d+1,{nrow,ncol}});
                }
            }
            
        }
        if(dist[trow][tcol]==1e9)//path not possible
            return -1;
        return dist[trow][tcol];
        
