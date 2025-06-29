//Rat in a Maze Problem - I
//https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1?page=1&category=Backtracking&sortBy=submissions

class Solution {
  public:
  
    bool issafe( int newx , int newy , vector<vector<int>>& maze , int n , vector<vector<bool>> &visited){
        if((newx >= 0 && newx<n) && (newy>= 0 && newy<n) && visited[newx][newy] == 0 && maze[newx][newy] ==1){
            return true;
        }
        else{
            return false;
        }
    }
    void solve(int x , int y , vector<vector<int>>& maze , int n , vector<string> &ans, vector<vector<bool>> &visited, string path){
        
        //base case
        if(x== n-1 && y== n-1){
            ans.push_back(path);
            return;
        }
        
        //4 movements 
        //DLRU ->lexicographically arranged (soretd)
        
        //Down (x+1,y)
        if(issafe(x+1,y , maze, n , visited)){
            visited[x][y]=1;
            solve(x+1, y , maze , n, ans, visited , path + 'D');
            visited[x][y] = 0;  //for backtracking
        }
        
        //Left (x,y-1)
        if(issafe(x,y-1 , maze, n , visited)){
            visited[x][y]=1;
            solve(x, y-1, maze , n, ans, visited , path + 'L');
            visited[x][y] = 0;  //for backtracking
        }
        
        //Right (x,y+1)
        if(issafe(x,y+1 , maze, n , visited)){
            visited[x][y]=1;
            solve(x, y+1 , maze , n, ans, visited , path + 'R');
            visited[x][y] = 0;  //for backtracking
        }
        
        //Up (x-1,y)
        if(issafe(x-1,y , maze, n , visited)){
            visited[x][y]=1;
            solve(x-1, y , maze , n, ans, visited , path + 'U');
            visited[x][y] = 0;  //for backtracking
        }
        
        
    }
  
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n = maze.size();
        vector<string> ans;
        vector<vector<bool>> visited(n , vector<bool>(n,0));
        string path = "";
        
        if(maze[0][0]==0){
            return ans;
        }
        
        solve(0,0,maze,n , ans , visited, path);
        return ans;
    }
};