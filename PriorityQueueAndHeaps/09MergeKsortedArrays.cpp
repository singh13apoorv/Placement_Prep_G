#include <bits/stdc++.h>
using namespace std;

class triplet{
    public:
    int value;
    int idx;
    int jdx;
};

vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
	triplet t;
    auto compare = [](triplet &a, triplet &b){
        return a.value > b.value;
    };
    priority_queue<triplet, vector<triplet>, decltype(compare)> pq(compare);
    
    for (int i = 0; i < input.size(); i++){
        t.value = input[i] -> at(0);
        t.idx = i;
        t.jdx = 0;
        
        pq.push(t);
    }
    
    vector<int> ans;
    while (!pq.empty()){
        triplet temp = pq.top();
        ans.push_back(temp.value);
        pq.pop();
        
        if ((temp.jdx + 1) < input[temp.idx] -> size()){
            t.value = input[temp.idx] -> at(temp.jdx + 1);
            t.idx = temp.idx;
            t.jdx = temp.jdx + 1;
            
            pq.push(t);
        }
    }
    
    return ans;
}

int main() {
    int k;
    cin >> k;

    vector<vector<int> *> input;

    for (int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;

        for (int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current->push_back(a);
        }

        input.push_back(current);
    }

    vector<int> output = mergeKSortedArrays(input);

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    return 0;
}