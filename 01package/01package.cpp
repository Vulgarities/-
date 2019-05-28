#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
class package01{
private:
	int number;		//物品数量
	int capacity;	//背包容量
	int *v;
	int *w;
	int **m;
public:
	void FindMax() {
		int i, j;
		for (i = 1; i <= number; i++) {
			for (j = 1; j <= capacity; j++) 
			{
				if (j < w[i]) {//装不下
					m[i][j] = m[i - 1][j];
				}
				else {//装得下
					if (m[i - 1][j] > m[i - 1][j - w[i]] + v[i])//不装价值大
						m[i][j] = m[i - 1][j];
					else//装价值更大
						m[i][j] = m[i - 1][j - w[i]] + v[i];
				}
			}
		}
		cout << "best:"<<m[number][capacity]<<endl;
	}
	package01(){
		cout << "input number,capacity:";
		cin >> number>>capacity;
		v = new int[number+1];
		w = new int[number+1];	
		m = new int*[number + 1];
		for (int i = 0; i < number + 1; i++)
			m[i] = new int[capacity + 1];
		for (int i = 0; i < number + 1; i++)
			m[i][0] = 0;
		for (int j = 0; j < capacity + 1; j++)
			m[0][j] = 0;
		for (int i = 1; i < number + 1; i++) {
			cout << "w,v of item" << i <<":";
			cin >> w[i] >> v[i];
		}
	}
};
int main() {
	package01 Y;
	Y.FindMax();
	return 0;
}
