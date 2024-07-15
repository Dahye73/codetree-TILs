#include <iostream>
using namespace std;

int n, m;

// 해당 행이 행복한 수열인지 판단하는 함수
bool check_arr(int *arr){


    for(int i = 0; i<=n - m;i++){

        int cnt = 1;
        for(int j = 1; j< m;j++){
            if(arr[i] == arr[i + j]) cnt++;
        }

        if(cnt == m){
            return true;
        }
    }
    return false;
}

int main() {

    int arr[100][100];
    int cnt = 0;
    cin >> n >> m;

    for(int i = 0; i<n;i++){
        for(int j = 0; j<n;j++){
            cin >> arr[i][j];
        }
    }

    // 가로행 탐색
    for(int i = 0; i<n;i++){
        if(check_arr(arr[i]))cnt++;
    }
    
    // 세로행 탐색
    for(int j = 0; j<n;j++){
        
        // 임시배열
        int tmp_arr[100];
        for(int i = 0; i<n;i++){
            tmp_arr[i] = arr[i][j];
        }

        if(check_arr(tmp_arr)) cnt++;
    }

    cout<<cnt<<endl;
    return 0;
}