#include<iostream>
#include<sstream>
using namespace std;

int getInteger(const string& prompt) {
while (true) {
cout << prompt;
string line;
if (!getline(cin, line)) // when does this fail?
throw domain_error("NOOOO~!");
istringstream iss(line);
int result; char trash;
if (iss >> result && !(iss >> trash))
return result;
}
}

int main()
{
    getInteger("hello");
}
