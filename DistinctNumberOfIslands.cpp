#include <bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>>&grid,int i ,int j ){
	if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0 )
	return ;
	grid[i][j] = 0;
	dfs(grid,i+1,j);
	dfs(grid,i-1,j);
	dfs(grid,i,j+1);
	dfs(grid,i,j-1);

}

void dfsnew(vector<vector<int>>&grid,int i ,int j ,int x0,int y0,vector<pair<int,int>>&v){
	if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
		return ;
	grid[i][j] = 0; 
	v.push_back({i-x0,j-y0});
	dfsnew(grid,i+1,j,x0,y0,v);
	dfsnew(grid,i-1,j,x0,y0,v);
	dfsnew(grid,i,j+1,x0,y0,v);
	dfsnew(grid,i,j-1,x0,y0,v);
}
int distinctIslands(vector<vector<int>>&grid){
	
	int count =0 ; 									//for finding the number of islands
	set<vector<pair<int,int>>> coords ;  
	for(int i =0 ; i < grid.size() ; ++i){
		for(int j =0 ; j < grid[0].size() ; ++j){
			if(grid[i][j] == 0)
				continue;
			count++; 								//for finding the total number of islands
			vector<pair<int,int>> v;
			dfsnew(grid,i,j,i,j,v);
			//dfs(grid,i,j); 							//total number of islands
			coords.insert(v);
		}
	}
	return coords.size();
	//return count; 					// total number of islands with total number of islands being enabled i.e. dfs function
}

int main()
{
	vector<vector<int> > grid = { { 1, 1, 0, 1, 1 },
								{ 1, 0, 0, 0, 1},
								{ 0, 0, 0, 0, 1 },
								{ 1, 1, 0, 1, 1 }, 
								{ 1, 1, 1, 1, 0 }
							};
		cout<<"Islands<<"<<distinctIslands(grid);

	return 0;
}
