// you can use includes, for example:
// #include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <iostream>

using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution1(vector<int> &A) {
    cout << "Problema: dado un vector de enteros, devolver el número mínimo de pasos necesarios para igualar todos los números de este a través de una suma o resta a un elemento cada vez" << endl;
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
        
        //cout << value << " " << count << ",,";
        //cout << *it << endl;
    }
    par[value] = count;
    
    for(map<int,int>::iterator it = par.begin(); it != par.end(); it++){
    	//cout << it->first << " " << it->second << endl;
    }

    int min = -1;

    for(int i = *ord.begin(); i < *ord.end()+1; i++){
        count = 0;
        //cout << "a";
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

int solution2(vector<int> &A){
    
    cout << "Problema: dado un vector de enteros, devolver el número mínimo de pasos necesarios para igualar todos los números de este a través de una suma o resta a un elemento cada vez" << endl;
    // Implement your solution here
    multiset<int> ord(A.begin(), A.end());
    map<int,int> par;
    int count = 0;
    int value = *ord.begin();

    for(multiset<int>::iterator it = ord.begin(); it != ord.end(); it++){
	if (value == *it){
	    count ++;
	} else {
	    par[value] = count;
	    value = *it;
	    count = 1;
	}
    }
    par[value] = count;

    map<int,int>::iterator min = par.begin();
    map<int,int>::reverse_iterator max = par.rbegin();
    map<int,int>::iterator minadd;
    map<int,int>::reverse_iterator maxadd;
    
    int aux = 0;
    int pasos = 0;
    
    while( min->first != max->first ){
    	if( min->second <= max->second ){
    		minadd = min;
    		minadd++;
    		aux = ( minadd->first - min->first );
    		pasos += min->second * aux;
    		minadd->second += min->second;
    		min++;
    	} else {
    		maxadd = max;
    		maxadd++;
    		aux = ( max->first - maxadd->first );
    		pasos += max->second * aux;
    		maxadd->second += max->second;
    		max++;
    	}
    }
    return pasos;
}

int main(){
	
	vector<int> lista = {1, 2, 2, 3, 3, 4, 5, 1, 3, 3};
	
	int sol = solution1(lista);
	int sol2 = solution2(lista);
	
	cout << sol << " " << sol2 << endl;
	
 	return 0;
}
