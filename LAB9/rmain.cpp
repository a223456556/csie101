#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class ReplaceMyString
{
    public:
    ReplaceMyString()
    {
        ifstream inputFile(__FILE__);
        ofstream outputFile("rmain.cpp");
    }
    void replaceString(string a,string b)
    {
        ifstream inputFile(__FILE__);
        ofstream outputFile("rmain.cpp");
        
        if(inputFile.is_open() && outputFile.is_open())
        {
            string line;
            while (getline(inputFile, line)) 
            {
                size_t P = line.find(a);
                while (P != string::npos) 
                {
                    line.replace(P, a.length(), b);
                    P = line.find(a, P + b.length());
                }
                outputFile << line << endl;
            }
            inputFile.close();
            outputFile.close();
        }
        else
        {
            cout<<"fail"<<endl;
        }
        
    }
    
};
int main()
{
    ReplaceMyString my;
    my.replaceString("IU is best","IU is best is best");
    
    return 0;
}
