/** @file functions.cpp*/

#define debug(x)  std::cerr << "(" << __LINE__ << ") " << #x << " == " << (x) << std::endl


#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <algorithm>

#include "functions.h"



// definitions of functions

std::string trim(const std::string &s) {
     size_t first = s.find_first_not_of(' ');
     if (std::string::npos == first)
     {
          return s;
     }
     size_t last = s.find_last_not_of(' ');
     return s.substr(first, (last - first + 1));
}

void addEdge(edge *&mainHead, int x1, int x2, double weight) {
     edge *tempHead = mainHead;
     edge *tempEdge = new edge(x1, x2, weight);
     tempEdge->Next = nullptr;
     if (tempHead == nullptr) {
          tempHead = tempEdge;
     } else {
          while (tempHead->Next) {
               tempHead = tempHead->Next;

          }
          tempHead->Next = tempEdge;
     }
}

edge *lightestEdge(edge *mainHead) {
     edge *tempHead = mainHead;
     edge *tempEdge = tempHead;
     while (tempHead) {
          if (tempHead->weight <= tempEdge->weight) {
               tempEdge = tempHead;
          }
          tempHead = tempHead->Next;
     }
     return tempEdge;
}

bool removeEdge(edge *&mainHead, edge * sngEdge) {
     edge *tempHead = mainHead;
     edge *lastEdge = nullptr;
     while (tempHead) {
          if (tempHead->x1 == sngEdge->x1 && tempHead->x2 == sngEdge->x2 && tempHead->weight == sngEdge->weight) {
               if (lastEdge == nullptr) {
                         if (!mainHead->Next) {
                              delete mainHead;
                              sngEdge = nullptr;
                              return false;
                         } else
                    mainHead = mainHead->Next;
                    sngEdge = nullptr;
                    return true;
               }
               if (tempHead->Next == nullptr) {
                    sngEdge = nullptr;
                    lastEdge->Next = sngEdge;
                    return true;
               }
               lastEdge->Next = sngEdge->Next;
               sngEdge = nullptr;
               return true;
          }
          lastEdge = tempHead;
          tempHead = tempHead->Next;
     }
     return false;
}

int getTree( verticle *&mainHead, int x ){
     verticle * tempHead = mainHead;
     while (tempHead) {
          if (tempHead->x == x) {
               return tempHead->tree;
          }
          tempHead = tempHead->next;
     }
     return -1;
}

void bound( verticle *&mainHead, int x, int y ){
     verticle * tempHead = mainHead;
     int tree_x = getTree( mainHead, x );
     int tree_y = getTree( mainHead, y );
     while (tempHead) {
          if (tempHead->tree == tree_x) {
               tempHead->tree = tree_y;
          }
          tempHead = tempHead->next;
     }
}


void addVerticle(verticle *&verticleHead, int x) {
     verticle *tempHead = verticleHead;
     verticle *tempVerticle = new verticle{x, x};
     tempVerticle->next = nullptr;
     if (verticleHead == nullptr) {
          verticleHead = tempVerticle;
     }
     else {
          while (tempHead->next) {
               if (tempHead->x == x) {
                    break;
               }
                       tempHead = tempHead->next;
          }
          if (tempHead->x != x) {
               tempHead->next = tempVerticle;
          }

     }
}

void deleteEdges (edge *&edgesHead) {
    while (edgesHead->Next) {
        edge *tempEdge = edgesHead->Next;
        delete edgesHead;
        edgesHead = tempEdge;
    }
    delete edgesHead;
}


void deleteVerticles (verticle*&verticlesHead) {
    while(verticlesHead->next) {
        verticle *tempVerticle = verticlesHead->next;
        delete verticlesHead;
        verticlesHead = tempVerticle;
    }
    delete verticlesHead;
}


void eraseCharsfromMiddle(std::string &str, char charsToRemove)
{
    for (unsigned int i = 0; i < 1; ++i)
    {
        str.erase(remove(str.begin(), str.end(), charsToRemove), str.end());
    }
}

edge::edge (int _x1, int _x2, double _weight){ // to make first verticle smaller
        if (_x1 > _x2) {
            x1 = _x2;
            x2 = _x1;
        } else {
            x1 = _x1;
            x2 = _x2;
        }
        weight = _weight;
    }