#include "connectionthread.h"

connectionThread::connectionThread(qintptr socketDescriptor, QObject *parent) : QThread(parent)
{
	this->socketDescriptor = socketDescriptor;

}

void connectionThread::run()
{
	socket = new QTcpSocket();
	if(!socket->setSocketDescriptor(socketDescriptor)){
		emit error(socket->error ());
		return;
	}
	connect (socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
	connect (socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::ConnectionType::DirectConnection);

	qDebug() << "Client Connected";
	exec ();
}

void connectionThread::disconnected()
{
	qDebug() << "Disconnected.." << endl;
	socket->deleteLater ();
	exit (0);
}

void connectionThread::readyRead()
{
	QByteArray data = socket->readAll();
	qDebug() << socketDescriptor << " Data in: " << data;
	socket->write(data);
}
