/**
 * Author: xiaoran
 * Time: 2018-10-29
 * 
 * hash.h in SimulateMR
 * Copyright (c) 2018, xiaoran. All rights reserved.
 **/ 

#ifndef _mapper_h
#define _mapper_h

#include <iostream>
#include <vector>
#include <string>

class Mapper {
public:
    Mapper(std::vector<std::string> _inputPaths, std::string _outputDir, int _mapperNum, int _reducerNum, 
           void (*_mapFunction)(const std::string, const std::string)=NULL):
                inputPaths(_inputPaths), 
                outputDir(_outputDir), 
                mapperNum(_mapperNum), 
                reducerNum(_reducerNum) {
                    mapfunction = _mapFunction;
                }
    
    ~Mapper() {
        inputPaths.clear();
        outputDir.clear();
    }
    // virtual void mapFunction(const std::string&& inputfile, const std::string&& outputPathDir) = 0;
    
    void partation();

private:
    int mapperNum;
    int reducerNum;
    std::vector<std::string> inputPaths;
    std::string outputDir;
    // void (*mapfunction);
    void (*mapfunction)(const std::string, const std::string); 
};

void Mapper::partation() {
    for(int i = 0; i < inputPaths.size(); i ++) {
        std::cout<<inputPaths[i]<<std::endl;
        std::string outputfile = "../temp/reducer" + std::to_string(i);
        mapfunction(inputPaths[i], outputfile);
    }
}

#endif /* _mapper_h */