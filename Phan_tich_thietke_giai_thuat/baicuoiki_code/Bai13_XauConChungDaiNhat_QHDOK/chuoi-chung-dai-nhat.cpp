#include <bits/stdc++.h>
using namespace std;
const int maxx = 10000;
string str1;
string str2;
string res ="";
int Basic = 0;
/*2 mang dx,dy dung de truy nguoc lai*/
int dx[3] = {1,1,0};/*ko dung*/
int dy[3] = {1,0,1};/*ko dung*/
int des1 = 0;
int minn = 0;/*Bien luu chieu dai xau con chung dai nhat*/
int C[maxx][maxx]; /*bang luu giá tri do dai xau chung dai nhat voi moi giá tri cua mang VD C[i][j] là do dai xâu chung dài nhat vs i phan tu str1 và j phan tu trong str2*/
int b[maxx][maxx]; /* Mang truy vet*/
int main(){
    freopen("Crash.IN","r",stdin);
    getline(cin,str1);
    getline(cin,str2);
    for(int i = 0; i <= maxx; i ++) {C[i][0] = 0;C[0][i] = 0;}
    clock_t start = clock();
    for(int i = 1; i <= str1.length(); i ++)
    for(int j = 1; j <= str2.length(); j ++){
            Basic++;
        if(str1[i - 1] == str2[j - 1]) {
                C[i][j] = C[i - 1][j - 1] + 1;
                if(C[i][j] > minn){
                    minn = C[i][j];
                    des1 = i - 1;/*Bien luu diem ket thúc xâu con chung dài nhat trong xâu str1*/
                }
        }
        if(str1[i - 1] != str2[j - 1]){
            C[i][j] = 0;
        }
    }
    clock_t finish = clock();
    int temp = des1 - minn;/*do vòng for i di tu 1 ==> phai tru them 1*/
    while(des1 > temp){
        res = res + str1[des1];
        des1--;
    }

    for(int i = res.length() - 1; i >= 0; i --){
        cout<<res[i];
    }
    cout << "\nmaxLen = " <<minn<<endl;
    double duration = (double)(finish - start) / (CLOCKS_PER_SEC/1000);
    cout<<"RunTime: "<<duration<<endl;
    cout<<str1.length()<<"  "<<str2.length();
    cout<<endl<<"Basic Operation: "<<Basic<<endl;
    /*for(int i = 0; i <= str1.length(); i++){
        for(int j = 0; j <= str2.length(); j++){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }*/
}
