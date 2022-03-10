#pragma once

#include "BDD.h"

class security
{

	Q_OBJECT
		BDD *db;

	public:

		/* Constructeur */
		security();

		/* Destructeur */
		~security();

	private slots:
		
		/* Setup security class */
		void setSecurity();

		/* Setup security class by ID */
		void setSecurityById(int idSecurity);

		/* Return the ID in database */
		void getIdSecurity();

		/* Return the room in database */
		void getRoom();

		/* Return the bit in database */
		void getBit();

		/* Return the statut in database */
		void getStatut();

		/* Return a historic table of sensor/activator in database */
		void histoSecurity();

		/* Send the statut on the client */
		virtual bool selectStatut() = 0;

		/* Update the statut in database */
		virtual void updateStatut() = 0;

	protected:

		int idSecurity;

		int room;

		int bit;

		bool statut;

};

class continuity : public security
{

public:

	continuity(int room)
	{
		this->room = room;
	}

	virtual bool selectStatut();

	virtual void updateStatut();

private:

	int room;

};

class sensor : public security
{

};

class tamper : public security
{

};

class presence : public security
{

};