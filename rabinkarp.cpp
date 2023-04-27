#include<bits/stdc++.h>
using namespace std;

#define d 256

void rabinkarp(char txt[], char pat[], int q){
    int n = strlen(txt);
    int m = strlen(pat);
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;
    
    int i,j;

    // this one is important "i < m-1"
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < m; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for(i=0; i<=n-m; i++){
        if(p==t){
            for(j=0; j<m; j++){
                if(txt[i+j]!=pat[j])
                    break;
            }
            if(j==m){
                cout << "Pattern found at index " << i << endl;
            }

        }
        if (i < n-m) {
            t = (d * (t- txt[i] * h ) + txt[i+m]) % q;
            if(t<0)
                t = (t + q);
        }
    }

}


int main(){

    char text[100], pat[100];
    cout<< "Enter the Text : " ;
    cin >> text;
    cout<< "Enter the Pattern : " ;
    cin >> pat;

    int q = 31; 
    rabinkarp(text,pat, q);


    return 0;
}

// string S = "cxyzghxyzvjkxyz"; 
// string P = "xyz";
