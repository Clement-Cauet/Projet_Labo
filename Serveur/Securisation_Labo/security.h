#pragma once

#include "database.h"
#include "PCI_7248_Card.h"

#include "lib/text_color-lib/text_color.h"

class security
{
public:
	security(PCI_7248_Card * card)
	{
		this->card = card;
	}
	

	void loop();

	/* Send the statut on the client */
	virtual void selectStatut() = 0;

	/* Update the statut in database */
	virtual void updateStatut(bool status, int room) = 0;

protected:

	int idSecurity;
	int room;
	int bit;
	bool statut;

	database *db;

	PCI_7248_Card *card;

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	enum Coord
	{
		continuityCoordX	= 15,
		sensorCoordX		= 15,
		tamperCoordX		= 15,
		presenceCoordX		= 15,

		continuityCoordY	= 7,
		sensorCoordY		= 9,
		tamperCoordY		= 11,
		presenceCoordY		= 13,

		largeur				= 8,
		hauteur				= 0,

	};

};







