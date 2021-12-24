#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
using ll = long long;

int n, m, cnt1 = 0, cnt2 = 0;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
char arr[102][102];
bool visited[102][102];
string s;

void bfs(int i, int j) {
    queue<pair<int, int> > q;
    q.push({i, j});
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        // visited[x][y] = true;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 | ny >= m) {
                continue;
            }
            if (!visited[nx][ny] && arr[x][y] == arr[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return;
}

void bfs2(int i, int j) { // 적록색맹의 경우
    queue<pair<int, int> > q;
    q.push({i, j});
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        //visited[x][y] = true;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 | ny >= m || visited[nx][ny]) {
                continue;
            }
            if (arr[x][y] == arr[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
            else if (arr[x][y] == 'R' && arr[nx][ny] == 'G') {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
            else if (arr[x][y] == 'G' && arr[nx][ny] == 'R') {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return;
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            arr[i][j] = s[j];
            visited[i][j] = false;
        }
    }
    m = s.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                bfs(i, j);
                cnt1++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = false;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                bfs2(i, j);
                cnt2++;
            }
        }
    }
    cout << cnt1 << " " << cnt2;
    return 0;
}


