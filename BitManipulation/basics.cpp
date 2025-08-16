#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
class BasicBitManipulation{
public:
    static string Decimal2Binary(int n){
        string res = "";
        while(n!=1){
            if(n%2 == 1) res+='1';
            else res+='0';
            n = n/2;
        }
        res+='1';
        reverse(res.begin(), res.end());
        return res;
    }
    static int Binary2Decimal(string binary){
        int num = 0, p2 = 1;
        for(int i = binary.length() - 1; i>=0; i--){
            if(binary[i] == '1') num+=p2;
            p2*=2;
        }
        return num;
    }
    static void basicBitOperations(){
        int a, b;
        cout << "Enter a : ";
        cin >> a;
        cout << "Enter b : ";
        cin >> b;
        int andOp = a&b, orOp = a|b, xorOp = a^b;
        cout << "a&b : "  << andOp << endl;
        cout << "a|b : "  << orOp << endl;
        cout << "a^b : "  << xorOp << endl;
    }
};
int main(){
    int ch = 1;
    while(ch){
        cout << "Enter 1 to convert given integer to decimal\nEnter 2 to convert given binary number to integer\nEnter 0 to stop : ";
        cin >> ch;
        switch(ch){
            case 0 : break;
            case 1 : {int n;
                cout << "Enter integer : ";
                cin >> n;
                string ans = BasicBitManipulation :: Decimal2Binary(n);
                cout << "Binary Equivalent of " << n << " is " << ans << endl;
                break;}
            case 2 : {string ip;
                cout << "Enter Binary no. : ";
                cin >> ip;
                int ansDec = BasicBitManipulation :: Binary2Decimal(ip);
                cout << "Decimal equivalent of " << ip << " is " << ansDec << endl;
                break;}
        }
    }
}