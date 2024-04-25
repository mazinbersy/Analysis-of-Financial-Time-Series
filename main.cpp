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
        return a.date < b.date;
    }

    // Overload > operator
    friend bool operator>(const exchangeInfo& a, const exchangeInfo& b) {
        return a.date > b.date;
    }
};

vector<exchangeInfo> readInfo(string x)
{
    vector<exchangeInfo> dataVector;
    ifstream file(x);

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
    }

    file.close();
    return dataVector;
}

void findMaxValues(int n, BinaryHeap<exchangeInfo>& heap)
{
    cout << "MAX VALUES:" << endl;

    for (int i = 0; i < n; i++)
    {
        exchangeInfo temp = heap.deleteMaxNode();
        cout<<"Date: "<<temp.date << "     " << "Value: "<<temp.value << endl;
    }
}

void findMinValues(int n, BinaryHeap<exchangeInfo>& heap)
{
    cout << "MIN VALUES:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Date: " << << "     " << "Value: " << temp.value << endl;
    }
}

int main()
{
    vector<exchangeInfo> dataVector = readInfo("exchangeInfo.txt");
	BinaryHeap<exchangeInfo> heap(dataVector.size()+1);
    heap.BuildMaxHeap(dataVector);
    heap.BuildMinHeap(dataVector);


    findMaxValues(10, heap);
    findMinValues(10, heap);


    
   

    return 0;




}
