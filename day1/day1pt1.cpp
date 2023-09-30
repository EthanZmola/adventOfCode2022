#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream file;
    file.open("day1pt1.txt");

    string temp;
    int individual = 0;
    int most = 0;

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
            if (individual > most)
            {
                most = individual;
                cout << most << endl;
            }
            individual = 0;
        }
        temp = "";
    }
    cout << most << endl;
    return 0;
}