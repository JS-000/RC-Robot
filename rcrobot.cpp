#include<bits/stdc++.h>

using namespace std;

void moveRobot(pair<int, int>& grid, pair<int, int>& rPos, char& rDir, string instructions)
{
    int d;
    switch(rDir)
    {
        case 'N': 
            d = 0;
            break;
        case 'E':
            d = 1;
            break;
        case 'S':
            d = 2;
            break;
        case 'W':
            d = 3;
            break;
    }
    for(int i = 0; i < instructions.length(); i++)
    {
        if(instructions[i] == 'M')
        {
            if(d == 0) rPos.second++;
            else if(d == 1) rPos.first++;
            else if(d == 1) rPos.second--;
            else rPos.first--;
        }
        else if(instructions[i] == 'L')
            d = (d + 3) % 4;
        else
            d = (d + 1) % 4;
    }
    switch(d)
    {
        case 0: 
            rDir = 'N';
            break;
        case 1:
            rDir = 'E';
            break;
        case 2:
            rDir = 'S';
            break;
        case 3:
            rDir = 'W';
            break;
    }
}

int main() 
{
    pair<int, int> grid;
    cin>>grid.first>>grid.second;
    pair<int, int> rPos;   //Program runs for 1 robot at a time, input does not mention no. of robots.
    cin>>rPos.first>>rPos.second;
    char rDir;
    cin>>rDir;
    string instructions;
    cin>>instructions;
    moveRobot(grid, rPos, rDir, instructions);
    cout<<rPos.first<<" "<<rPos.second<<" "<<rDir;
    return 0;
}