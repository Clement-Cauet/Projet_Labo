#include "user.h"

user::user(database * db)
{
	_db = db;
}

user::~user()
{}

// - Set user variables with user infos
void user::setUser(QString idCard, QString mail, QString password, QString isAdmin)
{
	this->_idCard = idCard.toInt();
	this->_mail = mail;
	this->_password = password;
	this->_isAdmin = isAdmin.toInt();
}

// - get user infos by idCard
void user::setUserByIdCard(QString idCard)
{
	qDebug() << "//----- Verification Carte -----//\n" << endl;
	qDebug() << "Passage de le carte " + idCard << endl;
	int countUser = _db->countdb(_db->user_table, " WHERE idCard = " + idCard);
	if (countUser > 0)
	{
		QString * User[4];
	
		//*User = database::selectdb(database::user_table, " WHERE idCard = " + idCard);
		//
		//_idCard = User[1]->toInt();
		//_mail = User[2]->toStdString;
		//_password = User[3]->toStdString;
		//_isAdmin = User[4]->toInt();

		_isAdmin = 1;
	
		if (_isAdmin == 1) {
			qDebug() << "L'utilisateur est administrateur" << endl;
			qDebug() << "Acces accorde, ouverture de la gache" << endl;
			//Ouverture de la g�che
		}
		else {
			qDebug() << "Verification de la plage horaire..." << endl;
			// V�rification de la plage horaire
			qDebug() << "Acces en plage horaire, acces accorde" << endl;
			qDebug() << "ouverture de la gache" << endl;
			// Si plage horaire respect�e alors ouverture de la g�che
		}
	}
	else { 
		qDebug() << "Carte non renseignee en base de donnee\n" << endl; 
	}
}

void user::getIdCard(QString user)
{}

void user::getMail(QString user)
{}

void user::getAdmin(QString user)
{}

void user::connexion()
{}

void user::deconnexion()
{}

void user::selectUser(QString user)
{}

void user::insertUser(QString user)
{}

void user::updateUser(QString user)
{}

void user::deleteUser(QString user)
{}

void user::histoPassage()
{}

void user::histoPassageByUser()
{}


/* R�cup�ration heure

// date / heure actuelle bas�e sur le syst�me actuel
			time_t tmm = time(0);

			// convertir en forme de cha�ne
			char* dt = ctime(&tmm);
			qDebug() << "La date et l'heure locales sont: " << dt << endl;

*/
