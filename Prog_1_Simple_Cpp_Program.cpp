/* Simple C++ Program */

/* Program for converting 12 hrs format into 24 hrs format
   Input	: Time in HH:MM AM/PM
   Output	: Equivalent time in 24 hrs format
*/

#include <iostream>
#include <string>
using namespace std;

string ConvertTime_12To24Hrs(const string &iStrTimeNow)
{
    string strHour_12 = iStrTimeNow.substr(0, 2);

    // Check is AM?
    string strHour_24 = "";
    if ("AM" == iStrTimeNow.substr(6, 2))
    {
        strHour_24 = ("12" == strHour_12) ? "00" : strHour_12;
    }
    else // it is PM
    {
        if ("12" == strHour_12)
            strHour_24 = strHour_12;
        else
        {
            int Hour_24 = ::stoi(strHour_12) + 12;
            strHour_24 = ::to_string(Hour_24);
        }
    }

    return (strHour_24 + iStrTimeNow.substr(2, 3));
}

int main()
{
    string strTimeNow1 = "12:00 AM";
    string strTimeNow2 = "12:00 PM";
    string strTimeNow3 = "01:00 AM";
    string strTimeNow4 = "01:00 PM";

    cout << "Time (in 24 hrs) is:    " << ConvertTime_12To24Hrs(strTimeNow1) << endl;
    cout << "Time (in 24 hrs) is:    " << ConvertTime_12To24Hrs(strTimeNow2) << endl;
    cout << "Time (in 24 hrs) is:    " << ConvertTime_12To24Hrs(strTimeNow3) << endl;
    cout << "Time (in 24 hrs) is:    " << ConvertTime_12To24Hrs(strTimeNow4) << endl;

    // Validate results
    if (("00:00" == ConvertTime_12To24Hrs(strTimeNow1)) &&
        ("12:00" == ConvertTime_12To24Hrs(strTimeNow2)) &&
        ("01:00" == ConvertTime_12To24Hrs(strTimeNow3)) &&
        ("13:00" == ConvertTime_12To24Hrs(strTimeNow4)))
        cout << "Test results PASSED";
    else
        cout << "Test results FAILED";

    return 0;
}