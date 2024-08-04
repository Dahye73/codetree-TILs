#include <iostream>
#include <algorithm>
#include <cstdlib>

#define MAX_NUM 20

using namespace std;

int n, m;
int grid[MAX_NUM][MAX_NUM];

// 주어진 k에 대하여 마름모의 넓이를 반환한다.
int GetArea(int k){
    return k * k + (k+1) * (k+1);
}

// 주어진 k에 대하여 채굴 가능한 금의 개수를 반환한다.
int GetNumOfGold(int row, int col, int k){

    int count = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

            if(abs(row - i) + abs(col - j) <= k)
                count += grid[i][j];
        }
    }

    return count;
}


int main() {
    
    int max_gold = 0;

    cin >> n >> m;
    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            cin >> grid[row][col];
        }
    }

    // 격자의 각 위치가 마름모의 중앙일 때 채굴 가능한 금의 개수를 구한다.
    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            for(int k = 0; k <= 2 * (n - 1); k++){
                int num_of_gold = GetNumOfGold(row, col, k);

                if(num_of_gold * m >= GetArea(k)){
                    max_gold = max(max_gold, num_of_gold);
                }
            }
        }
    }

    cout<<max_gold;
    return 0;

}