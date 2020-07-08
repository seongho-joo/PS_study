//
//  12791.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/07/02.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/12791 Starman

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Album {
    int year;
    string name;
    Album() : year(0), name("") {}
    Album(int y, string n) : year(y), name(n) {}
};

Album a[26];

void init() {
    a[0] = Album(1967, "DavidBowie");
    a[1] = Album(1969, "SpaceOddity");
    a[2] = Album(1970, "TheManWhoSoldTheWorld");
    a[3] = Album(1971, "HunkyDory");
    a[4] = Album(1972, "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars");
    a[5] = Album(1973, "AladdinSane");
    a[6] = Album(1973, "PinUps");
    a[7] = Album(1974, "DiamondDogs");
    a[8] = Album(1975, "YoungAmericans");
    a[9] = Album(1976, "StationToStation");
    a[10] = Album(1977, "Low");
    a[11] = Album(1977, "Heroes");
    a[12] = Album(1979, "Lodger");
    a[13] = Album(1980, "ScaryMonstersAndSuperCreeps");
    a[14] = Album(1983, "LetsDance");
    a[15] = Album(1984, "Tonight");
    a[16] = Album(1987, "NeverLetMeDown");
    a[17] = Album(1993, "BlackTieWhiteNoise");
    a[18] = Album(1995, "1.Outside");
    a[19] = Album(1997, "Earthling");
    a[20] = Album(1999, "Hours");
    a[21] = Album(2002, "Heathen");
    a[22] = Album(2003, "Reality");
    a[23] = Album(2013, "TheNextDay");
    a[24] = Album(2016, "BlackStar");
    a[25] = Album(9999, "");
}

int main() {
    init();
    int Q;
    cin >> Q;
    
    while(Q--) {
        int s, e;
        cin >> s >> e;
        int j = -1, k = -1, cnt = 0;
        if (s < 1967) s = 1967;
        for(int i = 0; i < 26; i++) {
            if(a[i].year >= s && a[i].year <= e) cnt += 1;
            if(a[i].year >= s && j == -1) j = i;
            if(a[i].year > e) {
                k = i - 1;
                break;
            }
        }
        if(j == -1 && k == -1) cout << "0\n";
        else {
            cout << cnt << "\n";
            for(int i = j; i <= k; i++)
                cout << a[i].year << " " << a[i].name << "\n";
        }
    }
    
    return 0;
}
