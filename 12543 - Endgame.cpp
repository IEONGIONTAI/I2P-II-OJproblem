#include <iostream>
#include <queue>

using namespace std;
//global variable
char map[1000][1000];
int N, M;
int tobeDestory = 0;

int bfs(int start_x, int start_y) {
    int r[4] = {1, -1, 0 , 0};
    int c[4] = {0 , 0, 1, -1};
    int dest_r, dest_c;
    queue< pair<int ,int> > q;
    q.push(make_pair(start_x, start_y));
    q.push(make_pair(0, 0));
    map[start_x][start_y] = 'C';


    while(!q.empty()) {
        int now_r = q.front().first;
        int now_c = q.front().second;
        q.pop();
        int dist = q.front().first;
        q.pop();
        //cout << '(' << now_r << ',' << now_c << ") " << endl;

        for(int i=0 ;i<4; i++) {
            dest_r = now_r + r[i];
            dest_c = now_c + c[i];
            //cout << '(' << dest_r << ',' << dest_c << ") " << dist;
            if(dest_r < 0 || dest_r >= N || dest_c < 0 || dest_c >= M) continue; // fixed
            if(map[dest_r][dest_c] == 'C' ) continue;
            if(map[dest_r][dest_c] == 'T' ) {
                tobeDestory--;
                //cout << tobeDestory << endl;
                //cout << "-> T" << endl;
                if(tobeDestory == 0) return dist+1;
            }
            //cout << endl;
            map[dest_r][dest_c] = 'C';
            q.push(make_pair(dest_r, dest_c));
            q.push(make_pair(dist + 1, 0));
        }
    }
    return -1;
}

int main() {
    int x, y;
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> map[i][j];
            if(map[i][j] == 'I') {
                x = i;
                y = j;
            }
            else if(map[i][j] == 'T')
                tobeDestory++;
        }
    }
    int ans = bfs(x ,y);
    cout << ans << endl;
    return 0;
}
