#include <iostream>
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

        score += response;

        if (play == response)
        {
            score += 3;
        }
        else if ((play == 1 && response == 2) || (play == 2 && response == 3) || (play == 3 && response == 1))
        {
            score += 6;
        }


    }

    cout << score << endl;
    

    return 0;
}
