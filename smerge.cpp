#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <omp.h>

int main(int argc, char *argv[]){
#pragma omp parallel for num_threads(2)
    for (int i=1; i<argc; i++ ){
        std::string line = "";
        std::string filename = argv[i];
        std::cerr << "Streaming " << filename << "\n";
        std::ifstream infile(filename);
        while (std::getline(infile, line)){
#pragma omp critical
            {
            std::cout << line << "\n" ;
            }       
        }
    }
}