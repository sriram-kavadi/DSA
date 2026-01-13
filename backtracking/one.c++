#include<iostream>
#include<vector>
using namespace std;

bool knightTour(vector<vector<int>>& vec, int row, int col, int count) {
    int n = vec.size();

    // boundary check
    if (row < 0 || col < 0 || row >= n || col >= n)
        return false;

    // already visited
    if (vec[row][col] != -1)
        return false;

    // place knight
    vec[row][col] = count;

    // SUCCESS condition
    if (count == n * n - 1) {
        return true;
    }

    // all 8 knight moves
    if (knightTour(vec, row + 2, col + 1, count + 1)) return true;
    if (knightTour(vec, row + 1, col + 2, count + 1)) return true;
    if (knightTour(vec, row - 1, col + 2, count + 1)) return true;
    if (knightTour(vec, row - 2, col + 1, count + 1)) return true;
    if (knightTour(vec, row - 2, col - 1, count + 1)) return true;
    if (knightTour(vec, row - 1, col - 2, count + 1)) return true;
    if (knightTour(vec, row + 1, col - 2, count + 1)) return true;
    if (knightTour(vec, row + 2, col - 1, count + 1)) return true;

    // backtrack
    vec[row][col] = -1;
    return false;
}


int main(){
    vector<vector<int>>vec;
    int n=8;
    for(int i=0;i<n;i++){
        vector<int>row;
        for(int j=0;j<n;j++){
            row.push_back(-1);
        }
        vec.push_back(row);
    }
    cout<<"------------"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"-----------"<<endl;
    knightTour(vec,0,0,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"-----------"<<endl;
    return 0;
}