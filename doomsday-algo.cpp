#include <iostream>
using namespace std;

int doomsDay[] = {31, 28, 14, 4, 9, 6, 11, 8, 5, 10, 7, 12};
int year[] = {1900, 2000, 2100, 2200};
string day[] = {"wedensday", "tuesday", "sunday", "friday"};
string weekDays[] = {"saturday", "sunday", "monday", "tuesday", "wedensday", "thursday", "friday"};
int getDay();
int getMonth();
int getYear();
void adjustYear(int &x, int &calcu);
int whichDay(int &x, int calc);
void play(int dday, int mmonth, int diff);
int main()
{
    struct
    {
        int dday = getDay();     // to get the day from the user
        int mmonth = getMonth(); // to get the month from the user
        int yyear = getYear();   // to get the year from the user
        int yearIdx;             // to save the index of the year which in the genral year array
        int flag;                // to match the index of the doomsday of the genral year with the genral year
        int diff;                // the diffence between the doomsday and the given day
        int calc;                // to calculte the dooms day of the year
    } game;
    adjustYear(game.yyear, game.calc);
    game.diff = whichDay(game.yyear, game.calc);
    play(game.dday, game.mmonth, game.diff);
}

int getDay()
{
    int dday;
    cout << "input the day : ";
    cin >> dday;
    return dday;
}

int getMonth()
{
    int mmonth;
    cout << "input the month : ";
    cin >> mmonth;
    return mmonth;
}

int getYear()
{
    int yyear;
    cout << "input the year : ";
    cin >> yyear;
    return yyear;
}

void adjustYear(int &x, int &calcu)
{
    int firstTwoNums = x % 100; // to get first two numbers to do calculations
    x = x - firstTwoNums;
    for (;;)
    {
        if (x < year[0])
        {
            x += 400;
        }
        else if (x > year[3])
        {
            x -= 400;
        }
        else
        {
            break;
        }
    }
    calcu = firstTwoNums / 4;
    calcu = calcu + firstTwoNums;
    int u = calcu / 7;
    calcu = calcu - (u * 7);
}

int whichDay(int &x, int calc)
{
    int flag;
    int y;
    int diff;
    for (int i = 0; i < 4; i++)
    {
        if (x == year[i])
        {
            y = i;
        }
    }
    string doomsdaySelcted = day[y];
    for (int i = 0; i < 7; i++)
    {
        if (doomsdaySelcted[0] == weekDays[i][0] && doomsdaySelcted[1] == weekDays[i][1])
            flag = i;
    }
    if ((flag + calc) > 6)
    {
        diff = (flag + calc) - 7;
    }
    else
    {
        diff = flag + calc;
    }
    return diff;
}

void play(int dday, int mmonth, int diff)
{
    for (int i = 0; i < 12; i++)
    {
        if (dday == doomsDay[i])
        {
            if (mmonth == (i + 1))
            {
                cout << weekDays[diff] << "\n";
            }
        }
        else if (mmonth == i + 1)
        {
            if (dday > doomsDay[i] && dday < 31)
            {
                int h = dday - doomsDay[i];
                int t = h / 7;
                t = t * 7;
                t = h - t;
                if ((diff + t) > 6)
                {
                    t = (diff + t) - 7;
                    cout << weekDays[t] << "\n";
                }
                else
                {
                    t = t + diff;
                    cout << weekDays[t] << "\n";
                }
            }
            else if (dday < doomsDay[i] && dday > 0)
            {
                int h = doomsDay[i] - dday;
                int t = h / 7;
                t = t * 7;
                t = h - t;
                if ((diff - t) < 0)
                {
                    t = (diff - t) + 7;
                    cout << weekDays[t] << "\n";
                }
                else if ((diff - t) > 0)
                {
                    t = diff - t;
                    cout << weekDays[t] << "\n";
                }
            }
        }
    }
}
