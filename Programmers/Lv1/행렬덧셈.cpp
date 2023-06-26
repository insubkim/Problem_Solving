#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    size_t arr_row = arr2.size();
    size_t arr_col = arr2`[0].size();
    
    for (int i = 0; i < arr_row; i++){
        for(int j = 0; j < arr_col; j++){
            arr1[i][j] += arr2[i][j];
        }
    }
    return arr1;
}