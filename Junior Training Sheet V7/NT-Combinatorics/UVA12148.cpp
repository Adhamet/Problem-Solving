#include <bits/stdc++.h>
#define adhamet ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

inline bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void solve(int records)
{
    int prevD=0,prevM=0,prevY=0,prevC=0,cons=0;
    unsigned long long tConsumption = 0;
    
    for(int i = 0; i < records; i++)
    {
        int d,m,y,c;
        cin >> d >> m >> y >> c;
        if(prevD == 31 && prevM == 12 && d == 1 && m == 1 && y - prevY == 1)
        {
            ++cons;
            tConsumption += c - prevC;
        }
        else if(prevY == y)
        {
            if(prevM == m)
            {
                if(d - prevD == 1)
                {
                    ++cons;
                    tConsumption += c - prevC;
                }
            }
            else if(m - prevM == 1 && d == 1)
            {
                bool isNext = (prevM == 1 && prevD == 31);
                isNext = isNext or (not isLeapYear(prevY) and prevM == 2 and prevD == 28);
		        isNext = isNext or (isLeapYear(prevY) and prevM == 2 and prevD == 29);
		        isNext = isNext or (prevM == 3 and prevD == 31);
			    isNext = isNext or (prevM == 4 and prevD == 30);
		        isNext = isNext or (prevM == 5 and prevD == 31);
			    isNext = isNext or (prevM == 6 and prevD == 30);
		        isNext = isNext or (prevM == 7 and prevD == 31);
		        isNext = isNext or (prevM == 8 and prevD == 31);
		        isNext = isNext or (prevM == 9 and prevD == 30);
			    isNext = isNext or (prevM == 10 and prevD == 31);
			    isNext = isNext or (prevM == 11 and prevD == 30);

				        if (isNext)
				        {
					          cons++;
					          tConsumption+=c - prevC;
				        }
            }
        }
        prevD = d;
        prevM = m;
        prevY = y;
        prevC = c;
    }
    cout << cons << " " << tConsumption << '\n';
}

int main()
{
    adhamet;
    
    int T;
    while(cin >> T && T)
    {
        solve(T);
    }
    
    return 0;
}
