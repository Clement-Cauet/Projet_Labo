#include <QtCore/QCoreApplication>

#include "ReaderCard.h"
#include "webServer.h"
#include "database.h"
#include "securitySysteme.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

	security::superviseTable(); // Affiche un tableau pour les �tats des capteurs

	//database * db = new database();

	webServer::getInstance(2569); // Instancie le serveur websocket
	
	ReaderCard::getInstance();	// Instancie le lecteur RFID

	securitySysteme::getInstance();	// Affiche les �tats des capteurs

    return a.exec();
}