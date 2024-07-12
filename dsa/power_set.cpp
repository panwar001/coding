#include <bits/stdc++.h>
using namespace std;

vector<string> AllPossibleStrings(string s){

    		vector<string> allCombinations;
    
		    int length = s.size();
    
		    // calculate total number of combinations
		    int totalCount = pow(2,length);
    
		    // loop over all numbers and checking bit set
		    // logic here is to check the set bits of numbers till 2n
		    for (int count = 1; count < totalCount; count++) {
		        string sub = "";
		        for (int j = 0; j < length; j++) {
		            if ( (count & (1<<j)) != 0) {
		                sub = sub + s[j] ;
		            }
		        }
		        allCombinations.push_back(sub);
		    }
		    
		    // Sort vector <string> lexigraphically
		    sort(allCombinations.begin(), allCombinations.end());
		    return allCombinations;
		}

int main() {
    cout << "Power Set!" << std::endl;

    string s = "abc";

    vector<string> allCombinations = AllPossibleStrings(s);

    cout << "For " << s << endl;
    for (size_t i = 0; i < allCombinations.size(); ++i) {
        cout << allCombinations[i] << " ";
    }
    cout << endl;
    
    return 0;
}
