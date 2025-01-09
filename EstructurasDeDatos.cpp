#include <iostream>
#include <set>

using namespace std;

int main(){
	
	int lista[] = {20, 40, 30, 10, 50};
	
	set<int> orden (lista, lista+5);
	
	for (set<int>::iterator i = orden.begin(); i != orden.end() ; i++)
		cout << *i << endl;
	
 	return 0;
}
