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
    vector<string> lines;

    while (getline(file, temp))
    {
        lines.push_back(temp);
    }


    cout << lines.size();

    for (int i =0; i <=lines.size(); i+=3)
    {
        found = false;

        for (int z = 0; z < lines[i].length() && found == false; z++)
        {
            for (int j = 0; j < lines[i+1].length() && found == false; j++)
            {
                if (lines[i][z] == lines[i+1][j])
                {
                    for (int k =0; k < lines[i+2].length() && found == false; k++)
                    {
                        if (lines[i][z] == lines[i+2][k])
                        {
                            repeats.push_back(lines[i][z]);
                            found = true;
                        }
                    }
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