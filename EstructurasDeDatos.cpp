// you can use includes, for example:
// #include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <iostream>

using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here
    multiset<int> ord(A.begin(), A.end());
    map<int,int> par;
    int count = 0;
    int value = 0;

    for(multiset<int>::iterator it = ord.begin(); it != ord.end(); it++){
        if (value == *it){
            count ++;
        } else {
            par[value] = count;
            value = *it;
            count = 1;
        }
        
        cout << value << " " << count << ",,";
        cout << *it << endl;
    }
    par[value] = count;
    
    for(map<int,int>::iterator it = par.begin(); it != par.end(); it++){
    	cout << it->first << " " << it->second << endl;
    }

    int min = -1;

    for(int i = *ord.begin(); i < *ord.end()+1; i++){
        count = 0;
        cout << "a";
        for(map<int,int>::iterator it = par.begin(); it != par.end(); it++){
            value = (it->first - i);
            if(value < 0)
                value = (-1)*value;
            count += value * it->second;
        }
        if(min == -1 || min > count)
            min = count;
    }

    return min;
}

int main(){
	
	vector<int> lista = {3, 3, 3};
	
	int sol = solution(lista);
	
	cout << sol << endl;
	
 	return 0;
}
