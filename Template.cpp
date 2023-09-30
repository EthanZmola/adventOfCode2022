#include <iostream>
#include <fstream>
#include <vector>

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

    }


    
    cout << most << endl;
    return 0;
}