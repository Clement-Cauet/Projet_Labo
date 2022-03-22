#include <QtCore/QCoreApplication>

#include "database.h"
#include "user.h"
#include "security.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

	database *db		= new database();
	user * User			= new user();

	continuity * cont	= new continuity(db);
	sensor * sens		= new sensor(db);
	tamper * tamp		= new tamper(db);
	presence * pres		= new presence(db);

	User->setUserByIdCard("1");

	cont->selectStatut();
	qDebug() << "--------------------------";
	sens->selectStatut();
	qDebug() << "--------------------------";
	tamp->selectStatut();
	qDebug() << "--------------------------";
	pres->selectStatut();

    return a.exec();
}