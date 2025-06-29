//51. N-Queens
//https://leetcode.com/problems/n-queens/description/

class Solution {
public:
    void printans(vector<vector<string>>& ans, int n ,vector<vector<string>> &board){
        vector<string> temp;
        for(int i = 0 ; i < n ; i++){
            string row = "";
            for(int j = 0 ; j < n; j++){
                 row += board[i][j];
            }
            temp.push_back(row);
        }
        ans.push_back(temp);
    }

    bool issafe(int row, int col , int n , vector<vector<string>> &board){

        //first check for row 
        int x= row ;
        int y = col; 

        while(y>=0){
            if(board[x][y]=="Q"){
                return false;
            }
            y--;
        }

        //why to check columns when i am placing correctly in recursion

        //diagonal upper check
        //x is going backward in this soo -> x>=0
        x= row ;
        y = col; 
        while(x>=0 && y>=0){
            if(board[x][y]=="Q"){
                return false;
            }
            x--;
            y--;
        }

        //lower diagonal check
        //x is going afterward in this soo -> x<n
        x= row ;
        y = col; 
        while(x<n && y>=0){
            if(board[x][y]=="Q"){
                return false;
            }
            x++;
            y--;
        }
        return true;
    }
    void solve ( int col , int n , vector<vector<string>> &board ,vector<vector<string>>& ans ){

        //base case when col equal to last col
        if(col == n){
            printans(ans , n ,board);
            return;
        }

        //solve 1 case and rest recusrion
        //pehli column ki saari columns mein jana hai baaki columns recursion sambhal lega

        for(int row = 0 ; row <n ; row++){
            if(issafe(row , col , n , board)){
                board[row][col] = "Q";
                solve(col+1, n , board, ans);
                board[row][col]= ".";//backtrack
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> board(n , vector<string>(n,"."));
        vector<vector<string>> ans;

        solve( 0, n , board , ans );
        return ans;
    }
};