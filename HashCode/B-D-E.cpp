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
//#include <deque>
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
////string DATAFILE = "a_example";
////string DATAFILE = "b_should_be_easy";
////string DATAFILE = "c_no_hurry";
//string DATAFILE = "d_metropolis";
////string DATAFILE = "e_high_bonus";
//
//struct ride{
//	int idx;
//	int start_row;
//	int start_col;
//	int finish_row;
//	int finish_col;
//	int pickup; //some time t
//	int dropoff; //some time t
//
//	int length(){
//		return abs(finish_col - start_col) + abs(finish_row - start_row);
//	}
//
//	int cart(){
//		return sqrt((finish_col - start_col)*(finish_col - start_col) + (finish_row - start_row)*(finish_row - start_row));
//	}
//
//	int dist_to(ride r){
//		return abs(finish_col - r.start_col) + abs(finish_row - r.start_row);
//	}
//
//} rides[10000];
//
//ride r0;
//
//bool taken[10000];
//int diffs[10000][10000];
//int diff0[10000];
//vector<int> assignments[400];
//int times[400];
//
//int r(int max){
//	return rand() % max;
//}
//
//int get_min(int idx){
//	int min = -1;
//	if(idx == -1){
//		for(int i = 0; i < N; i++){
//			if(!taken[i] && (min == -1 || diff0[min] > diff0[i]))
//				min = i;
//		}
//	}else{
//		for(int i = 0; i < N; i++){
//			if(!taken[i] && (min == -1 || diffs[idx][min] > diffs[idx][i]))
//				min = i;
//		}
//	}
//	taken[min] = true;
//	return min;
//}
//
//int get_last_dropoff_time(int car){
//	if(assignments[car].size() == 0)
//		return 0;
//	else
//		return rides[assignments[car].back()].dropoff;
//}
//
//int calc_new_time(ride r, int car){
//	return max(r.pickup, times[car] + (assignments[car].size() == 0 ? r0.dist_to(r) : rides[assignments[car].back()].dist_to(r))) + r.length();
//}
//
//bool in_time(ride r, int car){
//	return calc_new_time(r, car) <= r.dropoff;
//}
//
//int main(){
//	r0.start_col = 0;
//	r0.start_row = 0;
//	r0.finish_col = 0;
//	r0.finish_row = 0;
//	memset(taken, sizeof(taken), false);
//	memset(times, sizeof(times), 0);
//
//	freopen((DATAFILE + ".in").c_str(), "r", stdin);
//	freopen((DATAFILE + ".out").c_str(), "w", stdout);
//
//	srand(time(NULL));
//
//	cin >> R >> C >> F >> N >> B >> T;
//
//	int totlen = 0;
//
//	for(int i = 0; i < N; i++){
//		cin >> rides[i].start_row >> rides[i].start_col >> rides[i].finish_row >> rides[i].finish_col >> rides[i].pickup >> rides[i].dropoff;
//		rides[i].idx = i;
//		totlen += rides[i].length();
//	}
//
//	sort(rides, rides+N, [](ride lhs, ride rhs)->bool {return lhs.pickup < rhs.pickup || (lhs.pickup == rhs.pickup && lhs.dropoff < rhs.dropoff);});
//
//	deque<ride> rq;
//	for(int i = 0; i < N; i++)
//		rq.push_back(rides[i]);
//	
//	int cnt = 0;
//	while(!rq.empty()){
//		ride r = rq.front();
//		rq.pop_front();
//		int bestcar = -1;
//		for(int i = 0; i < F; i++){
//			if(in_time(r, i) && (times[i] < times[bestcar] || bestcar == -1 ) && calc_new_time(r, i) < T){
//				bestcar = i;
//			}
//		}
//		if(bestcar == -1){
//			cnt++;
//			continue;
//		}
//		assignments[bestcar].push_back(cnt++);
//		times[bestcar] = calc_new_time(r, bestcar);
//	}
//
//	for(int i = 0; i < F; i++){
//		cout << assignments[i].size() << " ";
//		for(int r : assignments[i])
//			cout << rides[r].idx << " ";
//		cout << endl;
//	}
//
//	return 0;
//}