#define debug(x) std::cerr << "(" << __LINE__ << ") " << #x << " == " << (x) << std::endl
#define USAGE_FMT "%s [-i input file] [-o output file]"

/**
 * @file main.cpp
 */

#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string.h>
#include <cstring>
#include <math.h>

/** all the structures are declared in structures.h
 */
#include "functions.h"

using namespace std;


int main(int count, char *params[]) {
    parameters Arguments;
    {
        string argH, argC; //argH - arg header, argC - arg content
        for (int i = 1; i < count; i += 2) {
            argH = string(params[i]);
            argC = string(params[i+1]);
            Arguments.iPath = (argH == "-i") ? trim(argC) : Arguments.iPath; //download input path to Arguments.iPath
            Arguments.oPath = (argH == "-o") ? trim(argC) : Arguments.oPath; //download output path to Arguments.oPath
        }
        if (Arguments.iPath != "" && Arguments.oPath != "") {
            Arguments.iFile.open(Arguments.iPath, ios::in);
            Arguments.oFile.open(Arguments.oPath, ios::out);
            if (!Arguments.iFile.is_open() || !Arguments.oFile.is_open()) {
                cout << "Can not reach files, check if paths are correct!\n"; //Files are not open
                return 0;
            }
        } else {
            cout << "Invalid parameters, check if those are correct with this templte:\nprogram [-i input file] [-o output file]\n"; //Params are not correct
            return 0;
        }
    }

    string tempLine, tempString;
    int tempInt1, tempInt2;
    double tempDouble1;

    edge *edgesHead =nullptr;
    verticle *verticleHead=nullptr;

    while (getline(Arguments.iFile, tempLine)) {
        eraseCharsfromMiddle(tempLine, ',');
        eraseCharsfromMiddle(tempLine, '(');
        eraseCharsfromMiddle(tempLine, ')');
        std::cout<<tempLine<<std::endl;
        stringstream ss(tempLine);
        while (ss) {
            ss >> tempInt1 >> tempInt2 >> tempDouble1;
            if (edgesHead == nullptr) {
                edgesHead = new edge(tempInt1, tempInt2, tempDouble1);
                edgesHead->Next = nullptr;

                if (verticleHead == nullptr){
                    addVerticle(verticleHead, tempInt1);
                    addVerticle(verticleHead, tempInt2);
                }
            } else {
                addEdge(edgesHead, tempInt1, tempInt2, tempDouble1);

                addVerticle(verticleHead, tempInt1);
                addVerticle(verticleHead, tempInt2);
            }
        }
    }



    edge *MST =nullptr;

    edge *tempHead = edgesHead; 

    while (tempHead != NULL) { // loop until edgesHead is empty
        edge *lightest = lightestEdge(edgesHead); // searching for lightest edge

       
        if( getTree( verticleHead, lightest->x1 ) != getTree( verticleHead, lightest->x2 )  )
        { // adding edge to MST
            if (MST == nullptr) {
                MST = new edge(lightest->x1, lightest->x2, lightest->weight);
                MST->Next = nullptr;
            } else
                addEdge(MST, lightest->x1, lightest->x2, lightest->weight);
            bound( verticleHead, lightest->x1, lightest->x2 );
        }

            if (!removeEdge(edgesHead, lightest))
            { // remove edge from main head
                break;
        }
        delete lightest;
    }
        {
            edge *tempHead = MST;
            while (tempHead)
            {
                Arguments.oFile << "(" << tempHead->x1 << ", " << tempHead->x2 << ", " << tempHead->weight << ")";
                if(tempHead->Next) {
                    Arguments.oFile << ", ";
                }
                tempHead = tempHead->Next;
            }
        }


    //end
    Arguments.iFile.close();
    Arguments.oFile.close();
    deleteEdges(edgesHead);
    deleteEdges(MST);
    deleteVerticles(verticleHead);
    return 0;
}


