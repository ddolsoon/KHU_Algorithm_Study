// 힙(2930번 문제).cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	priority_queue<int> q;
	vector<int> ans;
	
	int t;
	int num = 1;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {

			int oper;
			int x;
			cin >> oper;

			if (oper == 1) {
				cin >> x;
				q.push(x);
			}
			else {
				if (q.empty()) {
					ans.push_back(-1);
				}
				else {
					ans.push_back(q.top());
					q.pop();
				}
			}
		}

		cout << '#' << num++ << ' ';
		for (int value : ans) {
			cout << value << ' ';
		}
		cout << '\n';

		while (!q.empty()) {
			q.pop();
		}
		ans.clear();
	}

    return 0;
}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//void swap(int &n1, int &n2) {
//	int temp = n1;
//	n1 = n2;
//	n2 = temp;
//}
//
//
//class Heap {
//private:
//	int arr[500];
//	int size;
//	int cur;
//public:
//	Heap(int size) {
//		this->size = size;
//		this->cur = 0;
//	}
//
//	int length() {
//		return cur;
//	}
//
//	bool empty() {
//		if (cur == 0) {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//
//	void push(int x) {
//
//		arr[++cur] = x;
//		int i = cur;
//
//		while (i > 1) {
//			if (arr[i] > arr[i / 2]) {
//				swap(arr[i], arr[i / 2]);
//				i = i / 2;
//			}
//			else {
//				break;
//			}
//		}
//	}
//
//	void pop() {
//
//		if (empty()) {
//			return;
//		}
//
//		arr[1] = arr[cur];
//		cur--;
//
//		int i = 1;
//		while (i < cur) {
//
//			int leftChild = i * 2;
//			int rightChild = i * 2 + 1;
//			if (cur < leftChild) { //자식이 없는 경우,
//				break;
//			}
//			else if (cur < rightChild) { // 왼쪽 자식만 있는 경우,
//				if (arr[i] < arr[i * 2]) {
//					swap(arr[i], arr[i * 2]);
//					i = 2 * i;
//				}
//				else
//					break;
//			}
//			else { //자식이 모두 있는 경우,
//
//				if (arr[i] < arr[i * 2] && arr[i] < arr[i * 2 + 1]) {
//					if (arr[i * 2 + 1] > arr[i * 2]) {
//						swap(arr[i], arr[i * 2 + 1]);
//						i = 2 * i + 1;
//					}
//					else {
//						swap(arr[i], arr[i * 2]);
//						i = 2 * i;
//					}
//				}
//				else if (arr[i] < arr[i * 2]) {
//					swap(arr[i], arr[i * 2]);
//					i = 2 * i;
//				}
//				else if (arr[i] < arr[i * 2 + 1]) {
//					swap(arr[i], arr[i * 2 + 1]);
//					i = 2 * i + 1;
//				}
//				else {
//					break;
//				}
//			}
//		}
//	}
//
//	int top() {
//		return arr[1];
//	}
//};
//
//int main(void) {
//
//		Heap q(500);
//		vector<int> ans;
//
//		//for (int i = 0; i < 100; i++) {
//		//	int x = rand() % 100;
//		//	q.push(x);
//		//}
//
//		//for (int i = 0; i < 100; i++) {
//		//	cout << q.top() << endl;
//		//	q.pop();
//
//		//}
//		
//		int t;
//		int num = 1;
//		cin >> t;
//		while (t--) {
//			int n;
//			cin >> n;
//			for (int i = 0; i < n; i++) {
//	
//				int oper;
//				int x;
//				cin >> oper;
//	
//				if (oper == 1) {
//					cin >> x;
//					q.push(x);
//				}
//				else {
//					if (q.empty()) {
//						ans.push_back(-1);
//					}
//					else {
//						ans.push_back(q.top());
//						q.pop();
//					}
//				}
//			}
//	
//			cout << '#' << num++ << ' ';
//			for (int value : ans) {
//				cout << value << ' ';
//			}
//			cout << '\n';
//	
//			while (!q.empty()) {
//				q.pop();
//			}
//			ans.clear();
//		}
//	
//
//	return 0;
//}
