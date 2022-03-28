#include <iostream>
#include <string>
#include <cmath>
//include libares.

using namespace std;
// take a erase distance.
string eraseSpaces(string text)
{
    // chack suitable for entrance.
    string value;
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] != ' ')
        
        {
            value += text[i];
        }
    }
    return value;
}

int main()
{
    string text, time[3]{};
    int index{0}, timeInt[3]{};
    bool askAgain{true};
    while (askAgain)
    {
        // show user for input the format.
        index = 0;
        cout << "Enter time (HH:MM:SS): ";
        getline(cin, text);
        // chack suitable for entrance.
        text = eraseSpaces(text);
        askAgain = (text.length()) ? false : true;
        for (int i = 0; i < text.length(); i++)
        {
            if (index > 2)
            {
                askAgain = true;
                break;
            }
            //if is digit mean munber .
            if (isdigit(text[i]))
            {
                time[index] += text[i];
                //Add the box to the text.
            }
            else if (text[i] == ':')
            {
                index += 1;
            }
            else
            {
                askAgain = true;
                break;
            }
        }
        if (askAgain)
        {
            continue;
        }
        for (int i = 0; i < 3; i++)
        {
            //stoi function Convert the text to an integer.
            timeInt[i] = stoi(time[i]);
        }
        
       // Divide the number of hours, minutes and seconds.
        if ((timeInt[0] > 23 || timeInt[0] < 0) || (timeInt[1] > 60 || timeInt[1] < 0) || (timeInt[2] > 60 || timeInt[2] < 0))
        {
            askAgain = true;
        }
    }
    //Calculate the number of seconds by multiplying hours and minutes by 60.
    int sum{timeInt[0] * 60 * 60 + timeInt[1] * 60 + timeInt[2]};
    cout << sum;
}