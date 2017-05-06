#include "server.h"
#include <QDebug>


server::server(QObject *parent) : QTcpServer(parent)
{

}

void server::start()
{
	int port = 2345;
	if(this->listen (QHostAddress::Any, port)){
		qDebug() << "Listen..." << endl;
	}
	else
		qDebug() << "Fail.." << endl;
}

void server::incomingConnection(qintptr socketDescriptor)
{
	qDebug() << "Connecting..." << socketDescriptor;
	connectionThread* thrd = new connectionThread(socketDescriptor, this);
	connect (thrd, SIGNAL(finished()), thrd, SLOT(deleteLater()));

	thrd->start ();
}
