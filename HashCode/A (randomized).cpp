//#define _CRT_SECURE_NO_DEPRECATE
//#include <cstdio>
//#include <cstdlib>
//#include <iostream>
//#include <set>
//#include <vector>
//#include <map>
//#include <algorithm>
//#include <iomanip>
//#include <cmath>
//#include <string>
//#include <bitset>
//#include <queue>
//#include <functional>
//#include <stack>
//#include <time.h>
//
//using namespace std;
//
//typedef pair<int, int> ii;
//typedef long long ll;
//
//const ll MOD = 1e9+7;
//const double eps = 1e-7;
//const ll linf = LLONG_MAX;
//const int inf = INT_MAX;
//const double PI = 3.14159265359;
//
//int R, C, F, N, B, T;
//
//string DATAFILE = "a_example";
//
//struct ride{
//	int start_row;
//	int start_col;
//	int finish_row;
//	int finish_col;
//	int pickup; //some time t
//	int dropoff; //some time t
//} rides[10000];
//
//int length(ride r){
//	return abs(r.finish_col - r.start_col) + abs(r.finish_row - r.start_row);
//}
//
//int r(int max){
//	return rand() % max;
//}
//
//
//
//vector<int> assignments[1000];
//
//int main(){
//
//	freopen((DATAFILE + ".in").c_str(), "r", stdin);
//	freopen((DATAFILE + ".out").c_str(), "w", stdout);
//
//	srand(time(NULL));
//
//	cin >> R >> C >> F >> N >> B >> T;
//
//	for(int i = 0; i < N; i++){
//		cin >> rides[i].start_row >> rides[i].start_col >> rides[i].finish_row >> rides[i].finish_col >> rides[i].pickup >> rides[i].dropoff;
//	}
//
//	for(int i = 0; i < N; i++){
//		assignments[r(F)].push_back(i);
//	}
//
//	for(int i = 0; i < F; i++){
//		random_shuffle(assignments[i].begin(), assignments[i].end());
//	}
//
//	for(int i = 0; i < F; i++){
//		cout << assignments[i].size() << " ";
//		for(int r : assignments[i])
//			cout << r << " ";
//		cout << endl;
//	}
//
//	return 0;
//}