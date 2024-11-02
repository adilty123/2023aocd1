#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class MyClass{

    public:
    int GetValue(string myLine){
        string arr = myLine;
        int i = 1;
        int k = myLine.length()-1;
        char iChar = arr[i];
        char kChar = arr[k];
        
        while(!isdigit(iChar) || !isdigit(kChar)){
            if(!isdigit(iChar) || iChar == '\0'){
                i++;
            }

            if(!isdigit(kChar) || kChar == '\0'){
                k--;
            }

            iChar = myLine[i];
            kChar = myLine[k];
        }
        string result;
        result += iChar;
        result += kChar;
        cout << result << endl;
        
        int value = stoi(result);
        return value;
    }
};

int main(){
    ifstream myFile ("day1input.txt");
    string myLine;
    MyClass helper;
    int calValue = 0;


    while(myFile){
        getline(myFile, myLine);            
            
        calValue += helper.GetValue(myLine);
    }
    
    cout << calValue << endl;
    return 0;
}

