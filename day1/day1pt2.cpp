#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream file;
    file.open("day1pt1.txt");

    string temp;
    int individual = 0;
    int most[3] = {0,0,0};

    if (file.is_open())
    {
        cout << "Bueno" << endl;
    }

    while (getline(file, temp))
    {
        if (temp.substr(0,2) != "\r")
        {
            individual += stoi(temp);
        }
        else if (temp.substr(0,2) == "\r")
        {
            bool greater = false;
            int temp_int = individual;


            for (int i =0; i < 3 && !greater; i++)
            {
                if (individual > most[i])
                {
                    greater = true;
                    if (i == 2)
                    {
                        
                    }
                    else if (i == 1)
                    {
                        most[2] = most[1];
                    }
                    else if (i == 0)
                    {
                        most[2] = most[1];
                        most[1] = most[0];
                    }

                    most[i] = individual;
                }
            }
            greater = false;
            individual = 0;
        }
        
        temp = "";
    }
    for (int i = 0; i <3; i++)
    {
        cout << most[i] << endl;
    }
    int sum = most[0] + most[1] + most[2];
    cout << sum << endl;
    return 0;
}