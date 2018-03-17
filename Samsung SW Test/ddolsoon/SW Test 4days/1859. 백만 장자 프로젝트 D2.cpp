#include <iostream>

using namespace std;

int arr[1000001];
int n;

int max_Index(int startIndex,int * arr2) {
	
	int max_value = arr[startIndex];
	int max_Index = startIndex;
	for (int i = startIndex + 1; i <= n; i++) {
		if (max_value < arr2[i]) {
			max_value = arr2[i];
			max_Index = i;
		}
	}

	return max_Index;
}

int main()
{
	ios_base::sync_with_stdio(false);

	int t;
	int num = 1;
	cin >> t;

	while (t--) {
		
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}

		long long ans = 0;
		int startIndex = 1;
		int currentIndex = 1;
		bool isRunning = true;
		while (isRunning) {

			int nextIndex = max_Index(startIndex,arr);
			
			if (currentIndex == n && nextIndex == n) {
				isRunning = false;
				continue;
			}
			if (currentIndex == nextIndex) {
				//.cout << "일치" << endl;
				startIndex++;
				currentIndex++;
				continue;
			}

			

			for (int i = startIndex; i <= nextIndex - 1; i++) {
				ans -= arr[i];
			}
			//cout << "ans : " << ans << endl;
			ans += arr[nextIndex] * (nextIndex - startIndex);
			//cout << "ans : " << ans << endl;
			if (nextIndex == n) {
				break;
			}

			startIndex = nextIndex + 1;
			currentIndex = nextIndex + 1;
			
		}

		cout << '#' << num++ << ' ' << ans << '\n';


	}

    return 0;
}