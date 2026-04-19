#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e6 + 10;
int a[MAXN];
vector<int> b;

struct student {
	int grade;
	string fn;
};
bool cmp(student& i, student& j)
{
	// if (i.grade == j.grade) return i.fn < j.f\n;
	// return i.grade > j.grade;

	return (i.grade == j.grade ? i.fn < j.fn : i.grade > j.grade);

}
vector <student> st;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
	for(int i = 0; i < n; i++)
	{
		student tmp;
		cin >> tmp.grade >> tmp.fn;
		st.push_back(tmp);
	}

	sort(st.begin(), st.end(), cmp);
	for(int i = 0; i < n; i++)
	{
		cout << st[i].fn << " : " << st[i].grade << endl;
	}
}