#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

string tournamentWinner(vector<vector<string> > competitions, vector<int> results) {
  // Write your code here.
	unordered_map<string, int> umap;
	
	for (int i = 0; i < results.size(); i++){
		if (results[i] == 0){
			if (umap.find(competitions[i][1]) != umap.end()){
				umap.at(competitions[i][1]) += 3;
			}
			else {
				umap.insert(make_pair(competitions[i][1], 3));
			}
		}
		else {
			if (umap.find(competitions[i][0]) != umap.end()){
				umap.at(competitions[i][0]) += 3;
			}
			else {
				umap.insert(make_pair(competitions[i][0], 3));
			}
		}
	}
	int max = INT_MIN;
	string winner;
	for (auto x: umap){
		if (x.second > max){
			max = x.second;
			winner = x.first;
		}
	}
  return winner;
}

int main(){
	vector<vector<string> > competitions;
	vector<int> results;

	for (int i = 0; i < 3; i++){
		vector<string> vec;
		for (int j = 0; j < 2; j++){
			string a;
			cin >> a;
			vec.push_back(a);
		}
		competitions.push_back(vec);
	}

	for (int i = 0; i < 3; i++){
		int n;
		cin >> n;
		results.push_back(n);
	}

	cout << tournamentWinner(competitions, results) << endl;

	return 0;
}