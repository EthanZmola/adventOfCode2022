#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    ifstream boxes;
    boxes.open("day5BoxTest.txt");

    ifstream movesFile;
    movesFile.open("day5MoveTest.txt");

    string tempBox;
    string trash;

    int moves[3];
    char box_arr[3];

    vector<char> boxVector[3]; 

    vector<char> tempBoxVect;



    if (boxes.is_open())
    {
        cout << "Bueno" << endl;
    }

    while (getline(boxes, tempBox))
    {
        
        for (int i = 0; i < 3; i++)
        {
            char temp_char;
            temp_char = tempBox[1+i*4];
            box_arr[i] = temp_char;
            
            if (box_arr[i] != 0 && box_arr[i] != ' ')
            {
                boxVector[i].push_back(box_arr[i]);
            }
        }

    }

    for (int i = 0; i <3; i++)
    {
        cout << i << endl;
        boxVector[i].erase(boxVector[i].begin()-1);
    }


    while (movesFile >> trash >> moves[0] >>  trash >> moves[1] >> trash >> moves[2])
    {
        for (int i = 0; i < moves[0]; i++)
        {
            char temp_char;
            cout << "hfghjk" << endl;
            temp_char = boxVector[moves[1]][0];
            cout << "herre " << endl;
            boxVector[moves[1]].erase(boxVector[moves[1]].begin());
            boxVector[moves[2]].insert(boxVector[moves[2]].begin(), temp_char);

        }
    }


    return 0;
}