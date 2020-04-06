//  Program : Vestigium
//  Author  : Kojima Takuya
//  Date    : 2020/04/04
using namespace std;

#include <cstdint>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

typedef struct{
    int K;
    int numR;
    int numC;
}Answer;

int main(
){
    int   t = 0;
    int   T = 0;
    int   n = 0;
    int   N = 0;
    int   r = 0;
    int   c = 0;
    std::cin >> T;
    Answer answer[T] = {0};
    for(t = 0; t < T; t++){
        std::cin >> N;
        vector<int> Matrix;
        Matrix.resize(N*N);
        for(n = 0; n< N*N; n++){
            std::cin >> Matrix[n];
        }
        vector<int> Test;
        Test.resize(N);

        //Kを求める
        for(c = 0; c < N; c++){
            answer[t].K += Matrix[c*N + c];
        }

        //numRを求める
        for(c = 0; c < N; c++){
            std::memcpy(&(Test[0]), &(Matrix[c*N]), N*sizeof(int));
            std::stable_sort(&Test[0], &Test[N]);
            for(r = 0; r < N; r++){
                if(r+1 != Test[r]){
                    answer[t].numR ++;
                    break;
                }
            }
            Test.clear();
        }

        //numCを求める
        for(r = 0; r < N; r++){
            for(c = 0; c < N; c++){
                Test[c] = Matrix[c*N+r];
            }
            std::stable_sort(&Test[0], &Test[N]);
            for(c = 0; c < N; c++){
                if(c+1 != Test[c]){
                    answer[t].numC ++;
                    break;
                }
            }
            Test.clear();
        }
    }

    for(t = 0; t < T; t++){
        std::cout << "Case #" << t+1 << ": " << answer[t].K << " " << answer[t].numR << " " << answer[t].numC << std::endl;
    }
   return 0;
    
}



