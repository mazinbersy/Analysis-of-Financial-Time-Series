#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "BinaryHeap.h"
using namespace std;

struct exchangeInfo
{
	string date;
	double value;

    // Overload < operator
    friend bool operator<(const exchangeInfo& a, const exchangeInfo& b) {
        return a.value < b.value;
    }

    // Overload > operator
    friend bool operator>(const exchangeInfo& a, const exchangeInfo& b) {
        return a.value > b.value;
    }
};

vector<exchangeInfo> readInfo_and_findAverage(string x, double & avg)
{
    vector<exchangeInfo> dataVector;
    ifstream file(x);
    double sum = 0; int count = 0;
    if (!file.is_open()) {
        cout << "Failed to open file: " << x << endl;
        return dataVector;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        exchangeInfo newData;

        // Parse date and value from each line
        if (!(iss >> newData.date >> newData.value)) {
            cout << "Failed to parse line: " << line << endl;
            continue;
        }

        // Add parsed data to vector
        dataVector.push_back(newData);
        count++;
        sum = sum + newData.value;
    }
    avg = sum / count;
    file.close();
    return dataVector;
}

//Find and Display N Maximum exchange rate values
void findMaxValues(int n, BinaryHeap<exchangeInfo>& heap, double avg)
{
    cout << "MAX VALUES:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "Date: " << heap.returnHeap()[i].date << "     " << "Value: " << heap.returnHeap()[i].value << "    " << "Change from Mean: " << (heap.returnHeap()[i].value - avg) <<endl;
    }
}

//Find and Display N Minumum exchange rate values
void findMinValues(int n, BinaryHeap<exchangeInfo>& heap, double avg)
{
    cout << "MIN VALUES:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "Date: " << heap.returnHeap()[i].date << "     " << "Value: " << heap.returnHeap()[i].value << "    " << "Change from Mean: " << (heap.returnHeap()[i].value - avg )<< endl;
    }
}

//Find Start and End Indices for of the contiguous period over which the sum of rate changes is maximum
void maxSubsequence(int &start, int &end, vector<exchangeInfo> data, double avg)
{
    start = 0;
    end = 0;
    int temp = 0;
    double currentSum = 0; double maxSum = 0;
    for (int i=0; i<data.size() ; i++)
    {
        currentSum += data[i].value - avg;
        if (currentSum > maxSum)
        {
            maxSum = currentSum;
            start = temp;
            end = i;
        }
        if (currentSum < 0)
        {
            currentSum = 0;
            temp = i + 1;
        }
    }

}

int main()
{
    double avg; string file;

    cout << "Enter 0 for default Exchange Rate Information or Enter File Path to New Information: ";
    cin >> file;

    file = (file == "0") ? "exchangeInfo.txt" : file;
    vector<exchangeInfo> dataVector = readInfo_and_findAverage(file, avg);
    cout << endl << endl;
    cout <<"Mean Exchange Rate: "<< avg<<endl;     cout << endl << endl;

	BinaryHeap<exchangeInfo> Maxheap(dataVector.size()+1);
    BinaryHeap<exchangeInfo> Minheap(dataVector.size() + 1);
    
    int n;
    cout << "Enter Number of Max and Min values requested: ";
    cin >> n;
    
    Maxheap.BuildMaxHeap(dataVector);
    findMaxValues(n, Maxheap, avg);
    cout << endl << endl;

    Minheap.BuildMinHeap(dataVector);
    findMinValues(n, Minheap, avg);
    cout << endl << endl;
    int start, end;
    maxSubsequence(start, end, dataVector, avg);
    
    cout << "Maximum Subsequence Sum--> Start Date: " << dataVector[start].date << "        End Date: " << dataVector[end].date << endl;;
    
    
   

    return 0;




}
