#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 10;

struct Singer {
    int beg;
    int ti;
};

Singer singers[MAXN];

int studio[MAXN], n;
priority_queue <pair <int, int> > used_studios;
priority_queue <int> free_studios;

// функция за сравнение, която ще се използва от std::sort. Тук искаме да сортираме певците по нарастващ момент на пристигане и ако
// двама човека са дошли по едно и също време, да обслужим първо този, чийто запис ще трае повече време
bool cmp(Singer a, Singer b) {
    if (a.beg != b.beg) return a.beg < b.beg;
    return a.ti > b.ti;
}

int find_studio(int t) {
    while (!used_studios.empty() && -used_studios.top().first <= t) {
    	free_studios.push(used_studios.top().second);
    	used_studios.pop();
    }
    
    if (free_studios.empty()) {
    	free_studios.push(used_studios.top().second);
    	used_studios.pop();
    }
    
    int idx = -free_studios.top();
    free_studios.pop();
    return idx;
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> singers[i].beg >> singers[i].ti;
    }

    sort(singers, singers + m, cmp);
    for (int i = 1; i <= n; i++) {
        studio[i] = 0;
        free_studios.push(-i); // добавяме отрицателни елементи, защото така .top() ще ни даде най-малкия елемент
    }

    int ansTime, ansIdx = 0;
    ansTime = 0;
    for (int i = 0; i < m; i++) {
        int idx = find_studio(singers[i].beg);
        studio[idx] = max(singers[i].beg, studio[idx]) + singers[i].ti;
        used_studios.push({-studio[idx], -idx}); // добавяме отрицателни елементи, защото така .top() ще ни даде най-малкия елемент(а именно:
        // най-малката наредена двойка)
        
        if (studio[idx] > ansTime || (studio[idx] == ansTime && idx > ansIdx)) {
            ansTime = studio[idx];
            ansIdx = idx;
        }
    }
    cout << ansTime << ' ' << ansIdx << endl;
    return 0;
}
/*

*/
