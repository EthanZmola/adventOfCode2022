#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int split(string input_string, char separator, string array[], int arr_size)
{
    int length = input_string.length();
    int found = 0;
    bool error = 0;
    int index[arr_size] = {0};
    //Makes sure input string is not nothing
    if (input_string.length() < 1)
    {
        return 0;
    }
    //Loops though all of string to find separators and saves the positions.
    for (int x =0; x < length && found < arr_size; x++)
    {
        if (input_string[x] == separator)
        {
            index[found] = x;
            found++;
        }
    }
    //For when there are more separators then the array size
    if (found == arr_size)
    {
        //erases excess part of string
        input_string.erase(index[found-1]);
        //Sets error to true
        error =1;
        //Adjusts found to new number of separators
        found--;
    }
    //loops from back to front of the stored separator values.
    for (int i = found-1; i >= 0; i--)
    {
        //Takes substring from separator to end of function and puts into array
        array[i+1] = input_string.substr(index[i]+1);
        //Erases the part of teh string after the separator
        input_string.erase(index[i]);
    }
    //Sets remainder to first entry in array.
    array[0] = input_string;
    //When error is true from earlier this happens
    if (error)
    {
        //Adjusts found to be correct at end.
        found =-2;
    }
    //Adjusts found to be correct from earlier, since counted separators not the strings.
    found++;
    return found;
}


int main()
{
    ifstream file;
    file.open("day4.txt");

    string temp;
    int individual = 0;
    int most = 0;

    if (file.is_open())
    {
        cout << "Bueno" << endl;
    }

    string split1[2];

    string split2[2];

    int endpoints[4];

    while (getline(file, temp))
    {
        split(temp, ',', split1, 2);

//split first half
        split(split1[0], '-', split2, 2);

        endpoints[0] = stoi(split2[0]);
        endpoints[1] = stoi(split2[1]);

//Split second half
        split(split1[1], '-', split2, 2);

        endpoints[2] = stoi(split2[0]);
        endpoints[3] = stoi(split2[1]);

    // for (int i =0; i <4; i++)
    // {
    //     cout << endpoints[i] << endl;
    // }

        if ((endpoints[0] <= endpoints[2] && endpoints[1] >= endpoints[3]) || (endpoints[0] >= endpoints[2] && endpoints[1] <= endpoints[3]))
        {
            most++;
        }
    }


    
    cout << most << endl;
    return 0;
}