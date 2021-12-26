#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 21;
int N, M, x, y, K, ans = 0;
int arr[MAX][MAX];
int dice[6];

int main(void) {
    cin >> N >> M >> x >> y >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    dice[0] = arr[x][y];
    for (int i = 0; i < 6; i++) {
        dice[i] = 0;
    }
    while (K--) {
        int new_dice[6];
        copy(dice, dice + 6, new_dice);
        int a;
        cin >> a;
        if (a == 1) {
            if (y+1 >= M) {
                continue;
            }
            new_dice[0] = dice[2];
            new_dice[2] = dice[5];
            new_dice[5] = dice[3];
            new_dice[3] = dice[0];
            ++y;
        }
        else if (a == 2) {
            if (y-1 < 0) {
                continue;
            }
            new_dice[0] = dice[3];
            new_dice[2] = dice[0];
            new_dice[5] = dice[2];
            new_dice[3] = dice[5];
            --y;
        }
        else if (a == 3) {
            if (x-1 < 0) {
                continue;
            }
            new_dice[0] = dice[1];
            new_dice[4] = dice[0];
            new_dice[5] = dice[4];
            new_dice[1] = dice[5];
            --x;
        }
        else if (a == 4) {
            if (x+1 >= N) {
                continue;
            }
            new_dice[0] = dice[4];
            new_dice[5] = dice[1];
            new_dice[1] = dice[0];
            new_dice[4] = dice[5];
            ++x;
        }
        cout << new_dice[5] << '\n';
        if (arr[x][y] != 0) {
            new_dice[0] = arr[x][y];
            arr[x][y] = 0;
        }
        else {
            arr[x][y] = new_dice[0];
        }
        copy(new_dice, new_dice + 6, dice);
    }
    return 0;
}



