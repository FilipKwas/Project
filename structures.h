/**@file structures.h
*/

#include <string>
#include <fstream>
/**
    structure containing program parameters
*/
struct parameters {
    std::string iPath;//<Path to the input file
    std::ifstream iFile;//<Input file handle
    std::string oPath;//<Path to the output file
    std::ofstream oFile;//<Output file handle
};

/**
    structure containing verticle data and pointer to next element in list
*/
struct verticle {
    int x;//<index of the verticle
    int tree;//<tree identifier

    verticle *next;//<pointer to next element of list
};

/**
    structure containing edge data and pointer to next element in a list
*/
struct edge {
    int x1;//<first verticle
    int x2;//<second verticle
    double weight;//<weight of an edge
    edge* Next;//<pointer to the next element in a list

    edge (int _x1, int _x2, double _weight);
};