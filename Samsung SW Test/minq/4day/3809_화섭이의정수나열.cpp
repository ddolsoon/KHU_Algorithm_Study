#include <iostream>
#include <string>
using namespace std;

int main() {
	int test_Case;
	cin >> test_Case;
	for (int T = 1; T <= test_Case; T++)
	{
		string org;
		int n;
		cin >> n;
		while (n--) {
			int temp; cin >> temp;
			org += to_string(temp);
		}
		for (int i = 0; i < org.length(); i++) {
			if (org[i] == ' ') {
				org.erase(i, 1);
			}
		}
		cout << org << endl;
		for (int i = 0; i <= 1000; i++) {
			if (org.find(to_string(i)) == string::npos) {
				cout << "#" << T << " " << i << endl;
				break;
			}
		}
	}
}