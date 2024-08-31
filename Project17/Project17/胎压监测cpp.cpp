#include<iostream>
using namespace std;
struct car {
	int a;
	int making;
};
int main1() {
	int i, min2, min1, max=0,total=0,t=0;
	car car[4] = {0};
	for (i = 0; i < 4; i++) {
		car[i].making = 0;
	}
	for (i = 0; i < 4; i++) {
		cin >> car[i].a;
		if (i == 0) {
			max = car[i].a;
		}
		if (max < car[i].a) {
			max = car[i].a;
		}
	}
	cin >> min1 >> min2;
	for (i = 0; i < 4; i++) {
		if (car[i].a < min1) {
			total++;
			t = t + 1;
			car[i].making = 1;
		}
	}
	for (i = 0; i < 4; i++) {
		if (car[i].making == 0) {
			if (max - car[i].a > min2) {
				total++;
				t = i + 1;
			}
		}
	}
	if (total == 0) {
		cout << "Normal" << endl;
	}
	else if (total == 1) {
		cout << "Warning: please check #" << t << "!";
	}
	else cout << "Warning: please check all the tires!";
	return 0;
}