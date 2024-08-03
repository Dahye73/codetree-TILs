#include <iostream>
using namespace std;

int main() {

    // 상, 우, 하, 좌
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    int n, m;
    int arr[202][202];

    cin >> n>>m;

    for(int i = 1; i <= n; i++){
        for(int j = 1;j<=m;j++){
            cin >> arr[i][j];
        }
    }


    int max_num = 0;

    for(int i = 1; i<=n;i++){
        for(int j =1; j<=m;j++){
            
            int sum = arr[i][j];
            //가로줄 탐색

            if(j + 1 <=m && j + 2 <=m){
                for(int k = 1;k<3;k++){
                    sum += arr[i][j+k];
                }
            }

            max_num = max(sum, max_num);

            sum = arr[i][j];
            //세로줄 탐색

            if(i + 1 <=n && i + 2 <=n){
                for(int k = 1; k<3;k++){
                    sum += arr[i+k][j];
                }
            }
            max_num = max(sum, max_num);
        
            // 나머지 탐색
            for(int k = 0;k<4;k++){
                sum = arr[i][j];
                
                int nx = i + dx[k];
                int ny = j + dy[k];

                int nx2 = i + dx[k+1];
                int ny2 = j + dy[k+1];

                if(1 <= nx && nx <= n && 1 <= ny && ny <= m && 1 <= nx2 && nx2 <= n && 1 <= ny2 && ny2 <= m ){
                    sum = sum + arr[nx][ny] + arr[nx2][ny2];
                    max_num = max(sum, max_num);                
                }
            }
        }
    }

    cout<<max_num;    
    return 0;
}