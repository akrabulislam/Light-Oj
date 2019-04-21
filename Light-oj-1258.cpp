#include <bits/stdc++.h>
using namespace std;

void compute_lps(string pattern,int m,int lps[]){
    int len=0;
    lps[0]=0;

    int i=1;
    while(i<m){
        if(pattern[i]==pattern[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}

int kmp(string str,string pattern){
    int n=str.size();
    int m=pattern.size();

    bool ok=false;

    int lps[m];
    compute_lps(pattern,m,lps);

    int i=0,j=0;
    while(i<n){
        if(pattern[j]==str[i]){
            i++;
            j++;
        }
        if(j==m){
            ok=true;
           // j=lps[j-1];
           break;
        }
        else if(i<n&&pattern[j]!=str[i]){
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    return j;
}


int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        string s;
        cin>>s;
        string tem=s;
        reverse(tem.begin(),tem.end());
        int tak=kmp(s,tem);
       // cout<<tak<<endl;
        printf("Case %d: %d\n",cs++,(2*s.size()-tak));
    }
    return 0;
}
