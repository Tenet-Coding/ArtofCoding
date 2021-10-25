/**
Problem Statement 🗼

Human civilization now has its base on another planet called Geekland, all credit goes to Geeklog Gusk.
 There are N communication towers numbered from 0 to N-1 on the whole planet which are connected by M wires,
 each wire connects two different towers,
 more formally ith wire connects connections[i][0] and connections[i] [1] tower. All towers run on 9G technology.

Geeklog Gusk has decided to upgrade the technology of some towers to 10G, the newest and fastest technology ever made.
If tower a is upgraded to 10G, then all towers which are connected to tower a should also be upgraded.
More formally two towers should have the same technology if they are connected.
Geeklog only has enough budget to upgrade atmost X towers. Find a maximum number of towers which can be upgraded.



**/



#include <bits/stdc++.h>
using namespace std;

// find size of connected components using dfs
int countOfTowers(vector<vector<int>> &towers ,int currentTowerNumber , vector<bool> &visitedTowers){
    visitedTowers[currentTowerNumber] = true;
    int towerCount = 1; // add current tower to tower count
    for(int i=0;i<towers[currentTowerNumber].size();++i){
        if(visitedTowers[towers[currentTowerNumber][i]] == 0){
            towerCount += countOfTowers(towers , towers[currentTowerNumber][i] , visitedTowers);
        }
    }
    return towerCount;
}

// Knapsack for choosing connected components such that we did not cross max limit
int maxPossibleConversions(vector<int> &sizes , int allowedConversions){
    vector<vector<int>> dp(sizes.size()+1,vector<int>(allowedConversions+1,0));

    for(int i=1;i<=sizes.size();++i){
        for(int j=1;j<=allowedConversions;++j){
            if(sizes[i-1]<=j){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-sizes[i-1]]+sizes[i-1]);
            }
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[sizes.size()][allowedConversions];
}

int main(){
    int towerCount , wireCount , allowedConversions;
    cin>>towerCount>>wireCount>>allowedConversions;

    // creating adjacency list for connected towers
    // we are visualizing interconnections as a undirected graph
    vector<vector<int>> towers(towerCount);
    for(int i=0;i<wireCount;++i){
        int tower1 , tower2 ;
        cin>>tower1>>tower2;
        towers[tower1].push_back(tower2);
        towers[tower2].push_back(tower1);
    }

    vector<bool> visitedTowers(towerCount,false);

    // find size of each connected component
    vector<int> sizes;
    for(int i=0;i<towerCount;++i){
        if(visitedTowers[i]==0){
            sizes.push_back(countOfTowers(towers , i , visitedTowers));
        }
    }

    //print max conversions that we can do with given limit (9G to 10G conversions)
    cout<<maxPossibleConversions(sizes , allowedConversions)<<endl;

    return 0;
}


/*
Time complexity : O(n+m) + O(n*x)
for dfs is O(n+m) , where n is number of nodes in the graph (number of towers)
and m is total number of edges in the graph (number of wires)

for dynamic programming , complexity is O(n*x) , where x is max conversions allowed

total time complexity : O(n+m) + O(n*x)
---------------------------------------------------------------------------------------------------
Space complexity : O(n+m) + O(nx)
for making adjacency list it is O(n+m)
for making dp table it is O(nx)
overall is O(n+m) + O(nx)
---------------------------------------------------------------------------------------------------

Example 1:
Input:
N = 4, M = 2, X = 3
connections[ ][ ] = {{1, 2},
{0, 3}}

Output:
2

Explanation:
Either tower 1 and 2 or tower 3 and 4
can be upgraded.

Example
Input:
N = 4, M = 3, X = 3
connections[ ][ ] = {{0, 1},
{1, 2},
{2, 3}}

Output:
0

Example
Input:
N = 12, M = 8, X = 4
connections[ ][ ] = {{0, 1},
{1, 2},
{2, 3},
{3, 4},
{5, 6},
{7, 8},
{9, 10},
{10, 11}}

Output:
4
*/
