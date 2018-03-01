#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <string>
#include <bitset>
#include <queue>
#include <functional>
#include <stack>
#include <time.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

const ll MOD = 1e9+7;
const double eps = 1e-7;
const ll linf = LLONG_MAX;
const int inf = INT_MAX;
const double PI = 3.14159265359;

int R, C, F, N, B, T;

//string DATAFILE = "a_example";
//string DATAFILE = "b_should_be_easy";
string DATAFILE = "c_no_hurry";
//ring DATAFILE = "d_metropolis";
//string DATAFILE = "e_high_bonus";

struct ride{
	int start_row;
	int start_col;
	int finish_row;
	int finish_col;
	int pickup; //some time t
	int dropoff; //some time t

	int length(){
		return abs(finish_col - start_col) + abs(finish_row - start_row);
	}

	int dist_to(ride r){
		return abs(finish_col - r.start_col) + abs(finish_row - r.start_row);
	}

} rides[10000];

ride r0;

bool taken[10000];
int diffs[10000][10000];
int diff0[10000];
vector<int> assignments[1000];

int r(int max){
	return rand() % max;
}

int get_min(int idx){
	int min = -1;
	if(idx == -1){
		for(int i = 0; i < N; i++){
			if(!taken[i] && (min == -1 || diff0[min] > diff0[i]))
				min = i;
		}
	}else{
		for(int i = 0; i < N; i++){
			if(!taken[i] && (min == -1 || diffs[idx][min] > diffs[idx][i]))
				min = i;
		}
	}
	taken[min] = true;
	return min;
}



int main(){
	r0.start_col = 0;
	r0.start_row = 0;
	memset(taken, sizeof(taken), false);

	freopen((DATAFILE + ".in").c_str(), "r", stdin);
	freopen((DATAFILE + ".out").c_str(), "w", stdout);

	srand(time(NULL));

	cin >> R >> C >> F >> N >> B >> T;

	for(int i = 0; i < N; i++){
		cin >> rides[i].start_row >> rides[i].start_col >> rides[i].finish_row >> rides[i].finish_col >> rides[i].pickup >> rides[i].dropoff;
	}

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			diffs[i][j] = rides[i].dist_to(rides[j]);
		}
		diff0[i] = rides[i].dist_to(r0);
	}

	for(int i = 0; i < F; i++){
		int sum = 0;
		int prev = -1;
		while(sum < T){
			prev = get_min(prev);
			if(prev == -1)
				break;
			sum += rides[prev].length();
			if(sum > T){
				taken[prev] = false;
			}else{
				assignments[i].push_back(prev);
			}
		}
	}

	for(int i = 0; i < F; i++){
		cout << assignments[i].size() << " ";
		for(int r : assignments[i])
			cout << r << " ";
		cout << endl;
	}

	return 0;
}