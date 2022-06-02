#pragma once

#include "security.h"

class continuity : public security
{

	bool actualState[3];
	bool lastState[3];

public:

	/* Construct continuity class */
	continuity(PCI_7248_Card * card, database * db)
		: security(card)
	{
		this->db = db;
	}

	/* Send the statut continuity on the client */
	virtual void selectStatut();

	/* Update the statut continuity in database */
	virtual void updateStatut(bool status, int room);

private:

	int room;
};