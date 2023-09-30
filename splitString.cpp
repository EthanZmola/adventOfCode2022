/*CSCI 1300 Fall 2022
Author: Ethan Zmola
Recitaion: 307 - Zachary Atkins
Homework 5 - Problem 4 */

#include <iostream>
#include <string>
#include <cassert>
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
    string testcase = "RST,UVW,XYZ";
    char separator = ',';
    int arr_size = 3;
    string arr[arr_size];
    // num_splits is the value returned by split
    assert(split(testcase, separator, arr, arr_size)==3);

    string testcase1 = "RST,UVW,XYZ,sdfghjk";
    char separator1 = ',';
    int arr_size1 = 3;
    string arr1[arr_size1];
    // num_splits is the value returned by split
    assert(split(testcase1, separator1, arr1, arr_size1)==-1);

    string testcase2 = "A B C D E F G";
    char separator2 = ' ';
    int arr_size2 = 10;
    string arr2[arr_size2];
    // num_splits is the value returned by split
    assert(split(testcase2, separator2, arr2, arr_size2)==7);

    string testcase3 = "";
    char separator3 = ' ';
    int arr_size3 = 10;
    string arr3[arr_size3];
    // num_splits is the value returned by split
    assert(split(testcase3, separator3, arr3, arr_size3)==0);
    return 0;
}

