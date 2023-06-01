#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>
using namespace std;

class myString
{
    private:
        string m_str;
    public:
    myString (string s)
    {
        m_str = s;
    }
};
class ReadClass
{
public:
    void showClass()
    {
        ifstream file("main.cpp");
        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                smatch match;
                if (regex_search(line, match, classNameRegex))
                {
                    string className = match[1].str();
                    classNames.push_back(className);
                }
            }
            file.close();
        }

        // 輸出類別數目
        cout << classNames.size() << " Class in main.cpp"<< endl;

        // 輸出每個類別的名字
        for (const string& className : classNames)
        {
            cout << "class "<<className << endl;
        }
    }

private:
    regex classNameRegex{"class\\s+(\\w+)"};
    vector<string> classNames;
};

int main()
{
    ReadClass rfile;
    rfile.showClass();

    return 0;
}
