#include <iostream>
#include <string>
using namespace std;

/* 문자를 숫자로 변환하는 함수 */
int conversion(char ch){
    if (ch < 'D') return 2;
    else if (ch < 'G') return 3;
    else if(ch < 'J') return 4;
    else if(ch < 'M') return 5;
    else if(ch < 'P') return 6;
    else if(ch < 'T') return 7;
    else if(ch < 'W') return 8;
    else if(ch <= 'Z') return 9;
    else return 1;
}

/* 다이얼을 구하는 함수 */
int solution(string dial) {
    int sum = 0;

    for(int i=0;i<dial.size();i++){
        switch(dial[i] - 48){
            case 1: sum += 2; break;
            case 2: sum += 3; break;
            case 3: sum += 4; break;
            case 4: sum += 5; break;
            case 5: sum += 6; break;
            case 6: sum += 7; break;
            case 7: sum += 8; break;
            case 8: sum += 9; break;
            case 9: sum += 10; break;
            default: sum+= 11;
        }
    }

    return sum;
}

int main()
{
    string dial;
    cin >> dial;

    for(int i = 0;i<dial.size();i++)
        dial[i] = conversion(dial[i]) + 48;

    cout << solution(dial) ;
    return 0;
}