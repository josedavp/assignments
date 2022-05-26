/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   itinerary.h
 * Author: vib296
 *
 * Created on November 25, 2019, 1:30 PM
 */

#ifndef ITINERARY_H
#define ITINERARY_H

typedef struct Destination
{
    char airCode[4];              /* the value of this node */
    struct Destination *next; 
    
} Destination;

#define TRUE 1
#define FALSE 0

Destination *create(char *code );
Destination *insertAfter( Destination *head, Destination *node, char *key );
Destination *find(Destination *head, char *key );
Destination *removeNode(Destination *head, char *key );
void print( Destination *head );
void printItinerary( Destination *head);
Destination *destruct( Destination *head);
void printMenu();

#endif /* ITINERARY_H */

