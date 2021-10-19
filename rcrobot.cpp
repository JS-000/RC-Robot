#include<bits/stdc++.h>

using namespace std;

string compass = "NESW";

bool moveRobot(pair<int, int>& grid, pair<int, int>& rPos, char& rDir, string instructions)
{
    int d = compass.find(rDir);                        //Change direction from character to integer
    
    for(int i = 0; i < instructions.length(); i++)
    {
        if(instructions[i] == 'M')      //Move
        {
            if(d == 0) rPos.second++;
            else if(d == 1) rPos.first++;
            else if(d == 2) rPos.second--;
            else rPos.first--;
            
            if(rPos.first > grid.first || rPos.first < 0 || rPos.second > grid.second || rPos.second < 0)   //Check if instrctions result in moving out of grid
                return false;
        }
        else if(instructions[i] == 'L') //Rotate Left
            d = (d + 3) % 4;
        else                            //Rotate Right
            d = (d + 1) % 4;
    }
    rDir = compass[d];  //Changing direction from integer to character
    return true;
}

int main() 
{
    pair<int, int> grid;
    cin>>grid.first>>grid.second;
    pair<int, int> rPos;        //Program runs for 1 robot at a time, input does not mention no. of robots.
    cin>>rPos.first>>rPos.second;
    char rDir;
    cin>>rDir;
    string instructions;
    cin>>instructions;
    if(moveRobot(grid, rPos, rDir, instructions))   //if input sequence is valid
        cout<<rPos.first<<" "<<rPos.second<<" "<<rDir;
    else
        cout<<"Invalid Instruction Sequemce";
    return 0;
}
