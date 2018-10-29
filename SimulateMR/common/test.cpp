#include "mapper.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

void mapFunction(const string inputfile, const string outputfile) {
    cout<<inputfile<<endl;
    cout<<outputfile<<endl;
}

int main()
{
    vector<string> inputfiles = {"a.txt", "b.txt"};
    string outputfile = "/xiaoran";
    Mapper mapper(inputfiles, outputfile, 1, 1, mapFunction);

    mapper.partation();

    return 0;
}