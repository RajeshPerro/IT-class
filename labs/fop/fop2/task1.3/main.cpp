#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main(int argc, char const* argv[])
{
    list<int> numbers;
    string answer;
    string filename;
    int num;

    while(true){
        cout << "Add new number? [y/n]\n>";
        cin >> answer;
        if(answer[0] == 'y'){
            cout << "Give an integer number\n>";
            cin >> num;
            numbers.push_back(num);
        }
        else
            break;
    }

    if(numbers.size() == 0){
        cout << "The list of nubers is empty" << endl;
        return 0;
    }

    numbers.sort();
    numbers.reverse();

    cout << "Give the name of the file to create\n>";
    cin >> filename;

    ofstream tempfile;
    tempfile.open(filename.c_str());

    for(list<int>::iterator i = numbers.begin(); i != numbers.end(); ++i){
        if(1000 > *i && *i > 99){
            if(((*i % 1000) /100 + (*i % 100)/10 + (*i % 10)) % 2 == 1)

            tempfile << *i << ' ';
        }
    }

    tempfile.close();

    ifstream myfile(filename.c_str());
    string line;
    if (myfile.is_open()) {
        while ( myfile.good() ) {
          getline (myfile,line);
          cout << line << endl;
        }
        myfile.close();
     }

     else cout << "Unable to open file"; 
    return 0;
}
