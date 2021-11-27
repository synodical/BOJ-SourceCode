#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
int n, m, k;
int arr[101][101] = {0, };
bool visit[101][101] = {false, };
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int cnt = 0;
int area = 0;
vector<int> v;

int dfs(int x, int y) {
    visit[x][y]= true;
    area++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
            continue;
        }
        if (!visit[nx][ny] && arr[nx][ny] == 0) {
            dfs(nx, ny);
        }
    }
    return area;
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> m >> n >> k;
    for (int t = 0; t < k; t++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = y1; i < y2; i++) {
            for (int j = x1; j < x2; j++) {
                arr[m-i-1][j] = 1;
            }
        }
    }
    /*
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
     */
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visit[i][j] && arr[i][j] == 0) {
                cnt++;
                int a = dfs(i, j);
                v.push_back(a);
                area = 0;
            }
        }
    }
    sort(v.begin(), v.end());
    cout << cnt << '\n';
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}


