#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include "functions.h"

using namespace std;

const int MAX_DATA_ENTRIES = 100;
const int final_year = 2022;

struct Data
{ // define the structure for each read row from file
    int year;
    double interestRate;
    double inflationRate;
};

class IndianBank
{
private:
    Data data[MAX_DATA_ENTRIES]; // Array to hold data
    int numDataEntries = 0;      // Counter for the number of data entries

public:
    void extractData(const string &filename)
    {
        ifstream file(filename);
        if (!file.is_open())
        {
            cerr << "Failed to open file: " << filename << endl;
            return;
        }

        string line;
        // Skip the header line
        int sno;
        getline(file, line);

        while (getline(file, line) && numDataEntries < MAX_DATA_ENTRIES)
        {
            istringstream row(line);
            char comma;
            row >> sno >> comma >> data[numDataEntries].year >> comma >> data[numDataEntries].interestRate >> comma >> data[numDataEntries].inflationRate;
            numDataEntries++;
        }

        file.close();
    }

    void printData()
    {
        for (int i = 0; i < numDataEntries; i++)
        {
            cout << "Year: " << data[i].year << ", Interest Rate: " << data[i].interestRate
                 << ", Inflation Rate: " << data[i].inflationRate << endl;
        }
    }



    double recievedValue(double investment, int investmentYear)
    {
        double value;
        double realInterest = 1;
        double interest;

        for (const Data &dp : data)
        {

            if (dp.year >= investmentYear && dp.year <= final_year)
            {
                interest = dp.interestRate - dp.inflationRate;
                realInterest = realInterest * (1.0 + interest / 100.0);
            }
        }


        value = compound(investment, realInterest); // find the interest compoundly

        return value;
    }



    double investedValue(double received, int investmentYear)
    {
        double value;
        double realInterest = 1;
        double interest;

        for (const Data &dp : data)
        {

            if (dp.year >= investmentYear && dp.year <= final_year)
            {
                interest = dp.interestRate - dp.inflationRate;
                realInterest = realInterest * (1.0 + interest / 100.0);
            }
        }
        value = compoundReverse(received, realInterest);
        return value;
    }
};

int main()
{
    IndianBank bank;
    bank.extractData("india_data.csv");

    // bank.printData();

    double investment;
    int investmentYear;

    cout << "Enter investment amount: ";
    cin >> investment;


    if (investment < 0) {
        cout << "Investment amount cannot be negative." << endl;
        return 1; 
    }

    cout << "Enter investment year: ";
    cin >> investmentYear;

    if (investmentYear < 1960 || investmentYear > 2022) {
        cout << "Investment year should be between 1960 and 2022." << endl;
        return 1; 
    }


    double returnValue = bank.recievedValue(investment, investmentYear);
    double investedValue = bank.investedValue(returnValue, investmentYear); 
    returnValue=round(returnValue * 100.0) / 100.0; 
    
    cout << "Return value in 2022: ";
    cout <<  returnValue <<" Rs" << endl;

    cout << "Actual Invested value in " << investmentYear << " : " << investedValue << " Rs" << endl;

    return 0;
}
