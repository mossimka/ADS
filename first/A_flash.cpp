#include <iostream>
#include <vector>

using namespace std;

int main(){
    int decks;
    cin >> decks;
    for (int deck=0; deck<decks; ++deck){
        int len;
        cin >> len;
        vector<int> pos ;
        for(int i=1; i<=len; ++i){
            pos.push_back(i);
        }
        int moves = len-1;
        for(int i=len-1; i>0; --i){
            int temp = moves;
            while(temp > 0){
                int el = pos.back();
                pos.pop_back();
                pos.insert(pos.begin() + i -1, el);
                temp--;
            }
            moves--;
        }
        for (int el:pos){
            cout << el << ' ';
        }
        cout << endl;
    }
    return 0;
}