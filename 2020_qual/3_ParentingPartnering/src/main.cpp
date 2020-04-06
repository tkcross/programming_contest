//  Program : ParentingPartnering
//  Author  : Kojima Takuya
//  Date    : 2020/04/04
using namespace std;
#include <cstdint>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

typedef struct{
    int index;
    int Smin;
    int Emin;
    string  Name;
}Time;

int main(
){
    int     T = 0;
    int     t = 0;
    std::cin >> T;
    int     n = 0;
    int     N[T] = {0};
    string  ans[T];
    string  buf1 = "C";
    string  buf2 = "J";
    int     Ctime = 0;
    int     Jtime = 0;
    int     tmp = 0;
    for(t = 0; t < T; t++){
        Jtime = 0;
        Ctime = 0;
        tmp = 0;
        std::cin >> N[t];
        vector<Time> thistime;
        thistime.resize(N[t]);
        for(n = 0; n < N[t]; n++){
            std::cin >> thistime[n].Smin >> thistime[n].Emin;
            thistime[n].index = n;
        }
        std::stable_sort(&thistime[0], &thistime[N[t]],
            [](Time x, Time y){ return x.Smin < y.Smin;});
        //0はCameron
        thistime[0].Name = buf1;
        Ctime = thistime[0].Emin;
        for(n = 1; n < N[t]; n++){
            if(thistime[n].Smin - Ctime >= 0 && thistime[n].Smin - Jtime >= 0){
                if(thistime[n].Smin - Ctime < thistime[n].Smin - Jtime){
                    thistime[n].Name = buf1;
                    Ctime = thistime[n].Emin;
                }else{
                    thistime[n].Name = buf2;
                    Jtime = thistime[n].Emin;
                }
            }else if(thistime[n].Smin - Ctime < 0 && thistime[n].Smin - Jtime >= 0){
                thistime[n].Name = buf2;
                Jtime = thistime[n].Emin;
            }else if(thistime[n].Smin - Ctime >= 0 && thistime[n].Smin - Jtime < 0){
                thistime[n].Name = buf1;
                Ctime = thistime[n].Emin;
            }else{
                thistime[n].Name = "IMPOSSIBLE";
                tmp = thistime[n].index;
                break;
            }
        }
        std::stable_sort(&thistime[0], &thistime[N[t]],
            [](Time x, Time y){ return x.index < y.index;});
        if(strcmp(thistime[tmp].Name.c_str(), "IMPOSSIBLE") == 0){
            ans[t] = "IMPOSSIBLE";
        }else{
            for(n = 0; n < N[t]; n++){
                ans[t] += thistime[n].Name;
            }
        }
    }
    for(t = 0; t < T; t++){
        std::cout << "Case #" << t+1 << ": " << ans[t] << std::endl;
    }
    return 0;  
}



