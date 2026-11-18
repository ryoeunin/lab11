#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "student.h"

namespace inryoeun2693255
{
    void readwriteStudentDataFile(std::istream& fin, std::ofstream& fout)
    {
        std::vector<student> v;
        while(!fin.eof())
        {
            student s; 
            std::streambuf* origBuf{ std::cout.rdbuf() };
            std::cout.rdbuf(nullptr);
            fin >> s; 
            std::cout.rdbuf(origBuf);

            v.push_back(s);
        }

        for(const auto& vi : v)
            fout << vi;
    }
}


int main()
{
    using namespace inryoeun2693255;

    std::ifstream fin{ "studentData.txt" };
    if (fin.fail())
    {
        std::cout << "Input file opening failed\n";
        std::exit(1);
    }
    std::ofstream fout{ "out.txt" };
    //std::string fileName;
    //std::cout << "Enter file name: ";
    //std::cin >> fileName; fileName = fileName + ".txt";
    //fout.open(fileName);
    if(fout.fail())
    {
        std::cout << "Output file opening failed\n";
        std::exit(1);
    }

    readwriteStudentDataFile(fin, fout);
    
    fin.close();
    fout.close();
    //student s; 
    //std::streambuf* origBuf{ std::cout.rdbuf() };
    //std::cout.rdbuf(nullptr);
    //fin >> s; 
    //std::cout.rdbuf(origBuf);
    //std::cout << s;
    return 0;
}
