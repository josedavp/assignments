
/* 
 * airport.h
 * Project1
 * Jose Pague
 *
 * This file is used as a header for the functions in airport.c ,and also contains 
 * the struct Airport for latitude and longitude.
 */

#ifndef AIRPORT_H
#define AIRPORT_H

typedef struct Airport
{
    char name[ 50 ];
    char code [ 4 ];
    double latitude;
    double longitude;
} Airport;

void printAirports( Airport airports [ MAX ], int length );
void printAirport( Airport airport);
Airport findAirport (Airport airports [ MAX ], int length, char code [ 4 ]);
double calculateDistance ( Airport airport1, Airport airport2 );
void findInRange ( Airport airports [ MAX ], int length, Airport origin, int range, Airport output [ MAX ], int *resultsLength);


#endif






