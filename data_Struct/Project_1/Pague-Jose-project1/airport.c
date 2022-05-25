/*
 * airport.c
 * Project 1
 * Jose Pague
 * 
 * This is the driver for the airport.h program. It contains all the equations 
 * needed within the main menu along with storing the airports in the system. 
 * airport-program.c will call this program and use the information acquired to 
 * display the airports, distance, and range of the airport. 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "airport-program.h"
#include "airport.h"

#define PI 3.1415926

/***************************************************************************/
/* Prints out the intended airports*/
void printAirports ( Airport airports [], int length ) 
{
    int i;
    for (i = 0; i < length; i++)
    {
        printAirport ( airports[i] ); 
        printf("\n");
    }
}

/***************************************************************************/

/* Print out a single airport */
void printAirport ( Airport airport) 
{
    printf("%-3s %-52s %-14.8lf %-14.8lf", airport.code, airport.name, airport.latitude, airport.longitude); 
}
/***************************************************************************/

/* Locates the airport wanted using the listed code */
Airport findAirport (Airport airports[] , int length, char code[] )
{
    Airport foundAirport;
    
    foundAirport.code[ 0 ] = '\0';
    
    int i;
    
    for(i = 0; i < length; i++)
    {
        if ( strcmp(code, airports[i].code) == 0)
        {
            foundAirport = airports[i];
        }
    }
    
    if ( foundAirport.code[ 0 ] == '\0' )  // check if its NULL
    {
        foundAirport.latitude = -999999;
        foundAirport.longitude = -999999;
    }  
    
     return foundAirport;           
}
/***************************************************************************/

/*Calculates the distance between two airports. */
double calculateDistance ( Airport airport1, Airport airport2 )
{
    // Calculate the distance along with radians.
    double distance;
    double a;
    double c;
    double radius = 3959.0; //miles
    
    
    double distlongitude = (PI/180) * ((airport2.longitude) - (airport1.longitude)); 
    double distlatitude = (PI/180) * ((airport2.latitude) - (airport1.latitude));
    
    double radlat2 = (PI/180) * airport2.latitude;
    double radlat1 = (PI/180) * airport1.latitude;
    
    double radlong2 = (PI/180) * airport2.longitude;
    double radlong1 = (PI/180) * airport1.longitude; 
    
    a = pow(sin(distlatitude/2), 2 ) + cos(radlat1) * cos(radlat2) * pow(sin(distlongitude/2), 2);
    c = 2 * atan2(sqrt(a), sqrt(1-a));
    distance = radius * c;
    
    return distance;
     
}
/***************************************************************************/

/* Finds the distance of an airport to all airports within a certain mile range */
void findInRange ( Airport airports [], int length, Airport origin, int range, Airport output [], int *resultsLength)
{
    int counter = 0;
    int i;
    for ( i = 0; i < length; i++) 
    {
       if ( range >= calculateDistance( origin, airports[i])) 
       {
           output[counter] = airports[i];
           counter++;
       }
    }
    *resultsLength = counter;
}
/***************************************************************************/

/***************************************************************************/

/* To store every airport within the program */
int fillAirports( Airport airports [])
{
    int length = 0;
                airports[0].latitude = 29.533958;
                airports[0].longitude = -98.469056;
                strcpy(airports[0].name, "San Antonio Int1" );
                strcpy(airports[0].code, "SAT");
                length++;
                
                airports[1].latitude = 13.681108;
                airports[1].longitude = 100.747283;
                strcpy( airports[1].name, "Bangkok Suvarnabhumi" );
                strcpy(airports[1].code, "BKK");
                length++;
                
                airports[2].latitude = 49.009722;
                airports[2].longitude = 2.547780;
                strcpy( airports[2].name, "Paris Charles De Gaulle" );
                strcpy(airports[2].code, "CDG");
                length++;
                
                airports[3].latitude = -22.809999;
                airports[3].longitude = -43.250555;
                strcpy( airports[3].name, "Rio De Janeiro Galeão");
                strcpy(airports[3].code, "GIG");
                length++;
    
                airports[4].latitude = 22.308889;
                airports[4].longitude = 113.914722;
                strcpy( airports[4].name, "Hong Kong Int1" );
                strcpy(airports[4].code, "HKG");
                length++;
                
                airports[5].latitude = 40.639926;
                airports[5].longitude = -73.778694;
                strcpy( airports[5].name, "New York-JFK" );
                strcpy(airports[5].code, "JFK");
                length++;
                
                airports[6].latitude = -26.133693;
                airports[6].longitude = 28.242317;
                strcpy( airports[6].name, "O.R. Tambo Johannesburg" );
                strcpy(airports[6].code, "JNB");
                length++;
                
                airports[7].latitude = 33.942496;
                airports[7].longitude = -118.408048;
                strcpy( airports[7].name, "Los Angeles Int1" );
                strcpy(airports[7].code, "LAX");
                length++;
                
                airports[8].latitude = 51.477500;
                airports[8].longitude = -0.461388;
                strcpy( airports[8].name, "London Heathrow" );
                strcpy(airports[8].code, "LHR");
                length++;
                
                airports[9].latitude = 19.436303;
                airports[9].longitude = -99.072096;
                strcpy( airports[9].name, "Mexico City Benito Juarez" );
                strcpy(airports[9].code, "MEX");
                length++;

                airports[10].latitude = 1.359211;
                airports[10].longitude = 103.989333;
                strcpy( airports[10].name, "Singapore Changi" );
                strcpy(airports[10].code, "SIN");
                length++;
                
                airports[11].latitude = 35.765556;
                airports[11].longitude = 140.385556;
                strcpy( airports[11].name, "Tokyo Narita" );
                strcpy(airports[11].code, "NRT");
                length++;
                
                return length;
}







