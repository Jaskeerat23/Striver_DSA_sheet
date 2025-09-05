#include<iostream>
#include<vector>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    static int totalFruits(vector<int>& fruits){
        int i = 0, j = 0, ans = INT_MIN;
        unordered_map<int, int> fruitsInBasket;

        while(j < fruits.size()){
            //Add the new fruit into the basket
            fruitsInBasket[fruits[j]]+=1;

            //If new fruit is encountered
            //We will remove a fruit with less cnt
            if(fruitsInBasket.size() > 2){

                cout << "Fruit basket exceeded with fruit " << fruits[j] << endl;
                
                while(i < j){
                    int f = fruits[i];
                    if(fruitsInBasket[f] - 1 == 0) {
                        fruitsInBasket.erase(f);
                        cout << "After erasing " << f << " new size is " << fruitsInBasket.size() << endl;
                        i++;
                        break;
                    }
                    fruitsInBasket[f]-=1;
                    i++;
                }

            }

            ans = max(ans, (j - i + 1));
            j++;
        }
        return ans;
    }
};
int main() {
    int range;
    vector<int> fruits;
    cout << "Enter range : ";
    cin >> range;
    for(int i = 0; i<range; i++){
        int num;
        cin >> num;
        fruits.push_back(num);
    }
    int f = Solution :: totalFruits(fruits);
    cout << f << endl;
}