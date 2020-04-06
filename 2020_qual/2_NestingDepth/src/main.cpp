//  Program : NestingDepth
//  Author  : Kojima Takuya
//  Date    : 2020/04/04
using namespace std;

#include <iostream>
#include <string>


int main(
){
    int     t = 0;
    int     l = 0;
    int     L = 0;
    int     T = 0;
    int     k = 0;
    int     K = 0;
    int     Kakko = 0;
    std::cin >> T;

    string  str[T];
    string  ans[T];

    string  buf1 = "(";
    string  buf2 = ")";

    for(t = 0; t < T; t++){
        std::cin >> str[t];
        L = str[t].length();

        //0の場合
        K = str[t][0] - '0';
        for(k=0; k<K; k++){
            ans[t] += buf1; 
        }
        //1～L-1の場合
        for(l = 0; l < L-1; l++){
            ans[t] += str[t][l];
            Kakko = (int)(str[t][l+1]) - (int)(str[t][l]);
            if (Kakko > 0){
                for(k = 0; k < Kakko; k++){
                    ans[t] += buf1;
                }
            }else{
                for(k = 0; k < (-Kakko); k++){
                    ans[t] += buf2;
                }
            }
        }
        //Lの場合
        ans[t] += str[t][L-1];
        K = str[t][L-1] - '0';
        for(k=0; k<K; k++){
            ans[t] += buf2; 
        }
    }

    for(t = 0; t < T; t++){
        std::cout << "Case #" << t+1 << ": " << ans[t] << std::endl;
    }
    
    return 0;
    
}



