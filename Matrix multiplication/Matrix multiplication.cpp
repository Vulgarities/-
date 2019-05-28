#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

class Mult {
private:
	int n;				//number of matrix
	vector<int> p;		//dimension of matrix
	vector<vector<int>> m;	//m[i][j]: times of catulating A[i:j]
	vector<vector<int>> s;	//s[i][j]: record the position of disconnection A[i:j]
public:
	Mult();
	void MatrixChain();
	void Traceback(int i,int j);
	void print();
};

Mult::Mult() {
	int temp;
	cout << "input n and p[0]...p[n]:"<<endl;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		cin >> temp;
		p.push_back(temp);
	}
	
	m.resize(n + 1);
	s.resize(n + 1);
	for (int i = 0; i <= n; i++) {
		m[i].resize(n + 1);
		s[i].resize(n + 1);
		m[i][i] = 0;
	}
}
void Mult::MatrixChain() {
	for (int r = 2; r <= n; r++) {	//r: i,j之间的矩阵个数，如A[1:2] r=2
		for (int i = 1; i <= n - (r - 1); i++) {//求A[i:j]的最小相乘次序
			int j = i + (r - 1);				
			
			int k = i;
			m[i][j] = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];			//A[1:1]*A[2:j]
			s[i][j] = k;																
			for (k = i + 1; k <= j-1; k++) {									//求出A[1:k]*A[k+1:j]的最小值
				int temp = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (temp < m[i][j]) {
					m[i][j] = temp;
					s[i][j] = k;
				}
			}
		}
	}
}
void Mult::Traceback(int i,int j) {//通过s记录的位置输出[i:j]的最优解
	if (i == j)
		return;
	Traceback(i, s[i][j]);
	Traceback(s[i][j] + 1, j);
	cout << "Multiply A" << i << ',' << s[i][j];
	cout << "and A" << s[i][j] + 1 << ',' << j << endl;
}
void Mult::print() {
	cout <<endl<< "least times:" << m[1][n]<<endl<<endl;
	Traceback(1, n);
}
int main() {
	Mult A;
	A.MatrixChain();
	A.print();
}
