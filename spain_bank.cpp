#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

const int MAX_DATA_ENTRIES = 100;
const int final_year = 2022;

struct Data
{ // define the structure for each read row from file
    int year;
    double interestRate;
    double inflationRate;
};

class SpainBank
{
private:
    Data data[MAX_DATA_ENTRIES]; // Array to hold spain data
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

    double recievedValue(double investment, int investmentYear)
    {
        double value = investment;

        for (const Data &currentDataEntry : data)
        {
            double realInterest = currentDataEntry.interestRate - currentDataEntry.inflationRate;

            if (currentDataEntry.year >= investmentYear && currentDataEntry.year > 2001 && currentDataEntry.year <= final_year) // 2002-2022
            {
                value *= 1.0 + realInterest / 100.0;
            }
            else if (currentDataEntry.year >= investmentYear && currentDataEntry.year < 2002) // 1960-2001
            {

                value *= 1.0 + realInterest / 100.0;

                if (currentDataEntry.year == 2001)
                {
                    value = value / 166;
                }
            }
        }
        return value;
    }

    double investedValue(double received, int investmentYear)
    {
        double value = received;

        for (int year = 2022; year >= investmentYear; year--)
        {

            Data dataEntry;

            for (int i = 0; i < numDataEntries; i++)
            {
                if (data[i].year == year)
                {
                    dataEntry = data[i];
                    break;
                }
            }

            double realInterest = dataEntry.interestRate - dataEntry.inflationRate;

            if (year == 2001)
            {
                value = value * 166.0;
            }

            value /= 1.0 + realInterest / 100.0;
        }

        value = round(value * 100.0) / 100.0;
        return value;
    }

    void growthRate()
    {
        double dictorialInterest = 0;
        double monarchicalInterest = 0;

        for (Data curr : data)
        {
            if (curr.year <= 1977)
            {
                dictorialInterest += curr.interestRate - curr.inflationRate;
            }
            else if (curr.year > 1977 && curr.year <= final_year)
            {
                monarchicalInterest += curr.interestRate - curr.inflationRate;
            }
        }

        dictorialInterest = dictorialInterest / 18;
        monarchicalInterest = monarchicalInterest / 45;

        if (dictorialInterest > monarchicalInterest)
        {
            cout << "Dictorial Growth Rate which is " << round(dictorialInterest * 100.0) / 100.0 << " % grew faster than Monarchical Growth Rate which is " << round(monarchicalInterest * 100.0) / 100.0 << endl;
        }
        else
        {
            cout << "Dictorial Growth Rate which is " << round(dictorialInterest * 100.0) / 100.0 << " % grew slower than Monarchical Growth Rate which is " << round(monarchicalInterest * 100.0) / 100.0 << endl;
        }
    }
};

int main()
{
    SpainBank bank;
    bank.extractData("spain_data.csv");

    // bank.printData();

    double investment;
    int investmentYear;

    cout << "Enter investment amount: ";
    cin >> investment;

    if (investment < 0)
    {
        cout << "Investment amount cannot be negative." << endl;
        return 1;
    }

    cout << "Enter investment year: ";
    cin >> investmentYear;

    if (investmentYear < 1960 || investmentYear > 2022)
    {
        cout << "Investment year should be between 1960 and 2022." << endl;
        return 1;
    }

    double returnValue = bank.recievedValue(investment, investmentYear);
    double investedValue = bank.investedValue(returnValue, investmentYear);
    returnValue=(returnValue * 100.0) / 100.0;
    
    cout << "Return value in 2022: ";
    cout << returnValue << " Euro" << endl;

    cout << "Actual Invested value in " << investmentYear << " : ";

    if (investmentYear >= 2002)
    {
        cout << investedValue << " Euro" << endl;
    }
    else
    {
        cout << investedValue << " Peseta" << endl;
    }

    bank.growthRate();

    return 0;
}
