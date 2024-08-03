#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[22][22]; 

    // 배열 초기화
    for (int i = 0; i < 22; i++) {
        for (int j = 0; j < 22; j++) {
            arr[i][j] = 0;
        }
    }

    // 입력 받기
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    int max_count = 0;

    // k의 최댓값
    int maxK = (n + 1) / 2;

    // 모든 가능한 k 값에 대해 탐색
    for (int k = 1; k <= maxK; k++) {
        int cost = k * k + (k - 1) * (k - 1);

        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                int count = 0;

                for (int i = -(k+1) + 1; i < k; i++) {

                    int width = k - abs(i);
                    for (int j = -width + 1; j < width; j++) {
                        int nx = x + i;
                        int ny = y + j;
                        
                        if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && arr[nx][ny]) {
                            count++;
                        }
                    }
                }

                // 비용 대비 수익 계산
                if (cost <= count * m && max_count < count) {
                    max_count = count;
                }
            }
        }
    }

    cout << max_count << endl;
    return 0;
}