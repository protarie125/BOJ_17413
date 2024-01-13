#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

string s;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	getline(cin, s);
	auto st = stack<char>{};
	auto stack_open = bool{ true };

	for (auto i = 0; i < s.length(); ++i) {
		if ('<' == s[i]) {
			while (!st.empty()) {
				cout << st.top();
				st.pop();
			}

			stack_open = false;
			cout << s[i];
			continue;
		}
		else if ('>' == s[i]) {
			stack_open = true;
			cout << s[i];
			continue;
		}
		else if (stack_open && ' ' == s[i]) {
			while (!st.empty()) {
				cout << st.top();
				st.pop();
			}
			cout << s[i];
			continue;
		}

		if (stack_open) {
			st.push(s[i]);
		}
		else {
			cout << s[i];
		}
	}

	if (stack_open) {
		while (!st.empty()) {
			cout << st.top();
			st.pop();
		}
	}

	return 0;
}