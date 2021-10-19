#include<bits/stdc++.h>

using namespace std;

bool moveRobot(pair<int, int>& grid, pair<int, int>& rPos, char& rDir, string instructions)
{
    int d;
    switch(rDir)                        //Change direction character to integer
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
        if(instructions[i] == 'M')      //Move
        {
            if(d == 0) rPos.second++;
            else if(d == 1) rPos.first++;
            else if(d == 2) rPos.second--;
            else rPos.first--;
            
            if(rPos.first > grid.first || rPos.first < 0 || rPos.second > grid.second || rPos.second < 0)
                return false;
        }
        else if(instructions[i] == 'L') //Rotate Left
            d = (d + 3) % 4;
        else                            //Rotate Right
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
    return true;
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
    if(moveRobot(grid, rPos, rDir, instructions))
        cout<<rPos.first<<" "<<rPos.second<<" "<<rDir;
    else
        cout<<"Invalid Instruction Sequemce";
    return 0;
}
