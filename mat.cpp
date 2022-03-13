#include <iostream>
#include <string>
#include "mat.hpp"
#include <vector>
#include <stdexcept>


using namespace std;
namespace ariel{
    string mat(int cols, int rows, char first, char second){
        const int max = 126;
        const int min = 33;
        unsigned char u_first= first; 
        unsigned char u_second = second; 
        //check if the input is right
        if (cols%2 == 0 || rows%2 == 0 || cols <= 0 || rows <= 0){ 
            throw runtime_error ("please enter positive and odd number");
        }
        if (first < min || first > max || second < min || second > max){
            throw runtime_error ("please enter legal number");
        }
        int flag = 1; // current symbole, 1=first, 0=second
        string s_carp; //the carpet
        if(cols == 1){  //if have only 1 colmun
            for(int i=0; i<rows; i++){
                s_carp += first;
                s_carp += "\n";
            }
            return s_carp;
        }
        vector<vector<int>> carp(rows, vector<int>(cols));
        for(int i= 0; i<(rows/2); i++){ 
            for(int j=i; j<(cols-i); j++){ //fill 2 rows- 1 from the start and 1 from the end
                if(flag == 1){
                    carp[i][j] = u_first; // row number i from the start
                    carp[rows-i-1][j] = u_first; // row number i from the last
                }
                else{
                    carp[i][j] = u_second;
                    carp[rows-i-1][j] = u_second;
                }
            }
            for(int j=i; j<(rows-i); j++){ //fill 2 colmuns- 1 from the start and 1 from the end
                if(flag == 1){
                    carp[j][i] = u_first; //colmun i from the start
                    carp[j][cols-i-1] = u_first; // colmun i from the end
                }
                else{
                    carp[j][i] = u_second; 
                    carp[j][cols-i-1] = u_second;
                }
            }
            flag = (flag+1)%2; //change the symbole
        }
        for(int j=0; j<cols; j++){ //fill the middle row.
            if(carp[rows/2][j] != first && carp[rows/2][j] != second){
                if (flag == 1){
                    carp[rows/2][j] = u_first;
                }
                else{
                    carp[rows/2][j] = u_second;
                }
            }
        }
        // transform the vector to string.
        for(int i= 0; i<rows; i++){
            for(int j=0; j<cols; j++){
                char c= carp[i][j];
                s_carp += c;
            }
            s_carp += "\n";
        }
        return s_carp; //return the carpet
    }
}