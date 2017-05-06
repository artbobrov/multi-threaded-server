#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QThread>
#include "connectionthread.h"
class server : public QTcpServer
{
		Q_OBJECT
	public:
		explicit server(QObject *parent = 0);
		void start();

	protected:
		void incomingConnection (qintptr socketDescriptor);

	signals:

	public slots:
};

#endif // SERVER_H
