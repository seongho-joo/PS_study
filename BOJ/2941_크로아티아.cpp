#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solution(string alpabet){
    int count = 0;
    for(int i=0;i<alpabet.size();i++){
        switch(alpabet[i]){
        case 'c':
            if (alpabet[i + 1] == '=' || alpabet[i + 1] == '-')  {count++; i++;}
            else count++;
            break;
        case 'd': 
            if(alpabet[i+1] == 'z' && alpabet[i+2]== '=') {count++; i+=2;}
            else if(alpabet[i+1] == '-') {count++; i++;}
            else count++; 
            break;
        case 'l': 
            if(alpabet[i+1] == 'j') {count++; i++;}
            else count++;
            break;
        case 'n':
            if(alpabet[i+1] == 'j') {count++; i++;}
            else count++;
            break;
        case 's':
            if(alpabet[i+1] == '=') {count++; i++;}
            else count++;
            break;
        case 'z':
            if(alpabet[i+1] == '=') {count++; i++;}
            else count++;
            break;
        default: 
            count++;
        }
        if (i == alpabet.size() - 1) break;
    }
    cout << count;
}

int main(){
    string alpabet;
    cin >> alpabet;

    solution(alpabet);
    
    return 0;
}