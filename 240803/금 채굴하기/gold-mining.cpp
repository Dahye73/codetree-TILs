#include <iostream>
using namespace std;

int main() {
    
    //상, 하, 좌, 우
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int n, m;
    int arr[22][22];
    int max_count = 0;
    cin >> n >> m;

    for(int i = 1; i<=n;i++){
        for(int j = 1; j<=n;j++){
            cin >> arr[i][j];
        }
    }

    // k의 최댓값
    int k = (n + 1)/2;
    
    for(int kk = 1; kk <= k; kk++){

        // k에 따른 마름모의 중앙 정사각형 크기
        int k_l = (kk - 1) * 2 + 1;

        // k에 따른 비용
        int cost = kk * kk + (kk+1) * (kk+1);

        for(int i = 1; i<=n;i++){
            for(int j = 1; j<=n;j++){

                // 중앙 사각형 탐색 

                // 시작 위치
                int x = i - (kk-1);
                int y = j - (kk-1);

                //금 탐색
                int count = 0;

                
                for(int l_x = 0; l_x < k_l;l_x++){
                    for(int l_y = 0; l_y < k_l; l_y++){
                        int nx = x + l_x;
                        int ny = y + l_y;

                        if(1 <= nx && nx <=n && 1 <= ny && ny <=n && arr[nx][ny]){
                            count++;
                        }
                    }
                }

                // 4방향 테두리 탐색
                for(int d = 0; d < 4; d++){
                    int nx = i + dx[d] * kk;
                    int ny = j + dy[d] * kk;

                    if(1 <= nx && nx <= n && 1 <= ny && ny <= n && arr[nx][ny]){
                        count++;
                    }
                }
                
                if(cost <= count * m && max_count < count){
                    max_count = count;
                }
            }
        }
    }

    cout<< max_count <<endl;
    return 0;
}