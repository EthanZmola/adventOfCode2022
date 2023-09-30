#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream file;
    file.open("day2pt1.txt");

    string temp;
    int play = 0;
    int response = 0;
    int score = 0;


    if (file.is_open())
    {
        cout << "Bueno" << endl;
    }

    while (getline(file, temp))
    {
        play = temp[0];
        response = temp[2];

        play =1+ play % 65;
        response =1+ response % 88;
    
        // cout << play << endl;
        // cout << response << endl;

        //score += response;

        if (response == 2)
        {
            score += 3;
            score += play;
        }
        else if (response == 3)
        {
            score += 6;

            score += play%3 +1;
        }
        else
        {
            if (play == 1)
            {
                score += 3;
            }
            else if (play ==2)
            {
                score += 1;
            }
            else
            {
                score +=2;
            }
        }


    }

    cout << score << endl;
    temp = "A";
    play = temp[0];
    cout << (1 +play%65) % 3 << endl;
    return 0;
}
