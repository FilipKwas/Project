/** @file functions.h */

// header file

// prevention of multiple includes
#ifndef FUNCTIONS_H  // if FUNCTIONS_H is not defined ...
#define FUNCTIONS_H  // ... then define  FUNCTIONS_H
                     // otherwise jump to #endif

#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>

#include "structures.h"

// include definitions of structures

/** Trimming string
 * @brief Triming string line
 * @return string without spaces
 * @param str String stream to trim */
std::string trim(const std::string &s);


/**
*Deletes whole list of edges
*@param edgesHead Begining of the list
*/
void deleteEdges (edge *&edgesHead);
/**
*Deletes whole list of verticles
*@param verticlesHead Begining of the list
*/
void deleteVerticles (verticle*&verticlesHead);
/**
*Erases specified characters from the string
*@param str string with characters to remove
*@param charsToRemove character to remove from the string
*/
void eraseCharsfromMiddle(std::string &str, char charsToRemove);

/** Retrieving tree
* @brief Retrieves tree identifier of a verticle
* @param head Begining of the list
* @param x Index of verticle
* @return int Identifier of the tree
*/
int getTree( verticle *&head, int x );
/** Bounding trees
*@brief Merges two trees by changing tree identifiers of verticles
*@param mainHead Begining of the list
*@param x index of first verticle
*@param y index of the second verticle
*/
void bound( verticle *&mainHead, int x, int y );
/** Adding edges
 * @brief Adds edge to verticles main structure Head
 * 
 * @param mainHead verticle main head
 * @param x1 first verticle of edge
 * @param x2 seccond verticle of edge
 * @param weight weight of edge
 */
void addEdge (edge *&mainHead, int x1, int x2, double weight);

/** The lightest of edges
 * @brief Search for the lightest of all edges
 * 
 * @param mainHead begining of the list
 * @return edge* pointer to lightest edge
 */
edge * lightestEdge (edge * mainHead);

/** Removing single edge from head
 * @brief Removes pointed edge from the list
 * @param mainHead Begining of the list
 * @param sngEdge Edge to remove
 */
bool removeEdge (edge * &mainHead, edge* sngEdge);

/** Adding verticle
	@brief Adds verticle to the list
	@param verticleHead begining of the list
	@param x Verticle to add
*/
void addVerticle (verticle *&verticleHead, int x);

#endif