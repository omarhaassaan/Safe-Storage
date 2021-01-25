/*
 * Protocol.h
 *
 *  Created on: Jan 9, 2021
 *      Author: omarh
 */

#ifndef PROTOCOL_H_
#define PROTOCOL_H_

#define PASSWORD_CHANGING 44		// INFORM THAT PASSWORD IS CHANGING
#define OPEN_THE_DOOR 55			// Message to open the door
#define ACK 33						// Acknowledge bit
#define NACK 34						// Negative-acknowledge means that no ack bit received
#define CONFIRMED_PASSWORD 2		// successfully password set
#define NOT_CONFIRMED_PASSWORD 12	//error number 12 description: incorrent confirmation password


#endif /* PROTOCOL_H_ */
