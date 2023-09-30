#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream file;
    file.open("day3.txt");

    string temp;
    int individual = 0;
    int score = 0;
    bool found = false;

    if (file.is_open())
    {
        cout << "Bueno" << endl;
    }

    vector<char> repeats;

    while (getline(file, temp))
    {
        found = false;
        int length = temp.length();

        for (int i = 0; i < length / 2 && found == false; i++)
        {
            for (int j = 0; j < length / 2 && found == false; j++)
            {
                if (temp[i] == temp [j + length/2])
                {
                    repeats.push_back(temp[i]);
                    found = true;
                }
            }
        }
    }

    for (int i =0; i < repeats.size(); i ++)
    {
        int type = repeats[i];
        if (type < 91)
        {
            score += 27 + type%65;
        }
        else if (type > 96)
        {
            score += 1 + type%97;
        }
    }

    cout << repeats.size() << endl;
    cout << score << endl;

    return 0;
}