#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
/*
vector<vector<bool>> propose(int X, int K, int M){
	vector<vector<bool>> A(M, vector<bool>(X));
	rep(i,M){
		rep(j,X){
			if(i==j)A[i][j]=1;
			else A[i][j]=0;
		}
	}
	return A;
}

vector<int> detect(int X, int K, int M, const vector<vector<bool>> &A, const vector<bool> &R){
	vector<int> ans;
	rep(i,M)if(R[i]) ans.push_back(i);
	return vector<int>{ans};
}
*/
vector<vector<bool>> propose(int X, int K, int M){
	vector<vector<bool>> A(M, vector<bool>(X));
	int x=1;
	rep(i,M){
		if(i!=0)x*=2;
		if(x>X)break;
		rep(j,X){
			A[i][j]=(j/x+1)%2;
			cout<<A[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
	x=1;
	rep(i,M){
		if(i!=0)x*=2;
		if(x>X)break;
		rep(j,X){
			A[i][j]=(j/x)%2;
			cout<<A[i][j];
		}
		cout<<endl;
	}
	return A;
}

vector<int> detect(int X, int K, int M, const vector<vector<bool>> &A, const vector<bool> &R){
	
	return vector<int>{0};
}



int X, K, M, T, seed;

void wrong(string str){cout << str << endl; exit(1);}
void propose_check(vector<vector<bool>> &A){
	bool right = A.size() == M; for(auto &t : A) right &= t.size() == X;
	if(!right) wrong("Invalid Proposal");
}
void repeating_number_check(vector<int> &R, int id){
	if(R.size() != set < int >(R.begin(), R.end()).size())
		wrong("Detection " + to_string(id) + " Repeating Numbers");
}
void out_of_bound_check(vector<int> &R, int id){
	bool right = 1; for(auto &t : R) right &= t >= 0 && t <= X - 1;
	if(!right) wrong("Detection " + to_string(id) + " Out of Bound");
}
void same_check(vector<int> &R, vector<int> &P, int id){
	bool right = 1; if(R.size() != P.size()) right = 0;
	set < int > positive(P.begin(), P.end());
	for(auto &t : R) right &= positive.find(t) != positive.end();
	if(!right){
		stringstream output;
		output << "Failed Detection " << id << endl;
		output << "Your Answer:";
		for(auto t : R) output << " " << t;
		output << endl;
		output << "Correct Answer:";
		for(auto t : P) output << " " << t;
		output << endl;
		wrong(output.str());
	}
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	cin >> X >> K >> M >> T >> seed; mt19937 rnd(seed);
	vector<vector<bool>> A = propose(X, K, M);
	propose_check(A);
	
	for(int i = 1 ; i <= T ; ++i){
		int C = rnd() % K + 1; vector < int > positive;
		if(K <= 4){
			set < int > P; while(P.size() < C) P.insert(rnd() % X);
			positive = vector<int>(P.begin(), P.end());
		}else{
			vector < int > P;
			for(int i = 0 ; i < X ; ++i) P.push_back(i);
			shuffle(P.begin(), P.end(), rnd);
			positive = vector<int>(P.begin(), P.begin() + C);
		}
		vector<bool>R(M, 0);
		for(int i = 0 ; i < M ; ++i) for(auto t: positive) R[i] = R[i] | A[i][t];
		vector < int > result = detect(X, K, M, A, R);
		repeating_number_check(result, i);
		out_of_bound_check(result, i);
		same_check(result, positive, i);
	}
	cout << "Accepted." << endl;
	return 0;
}