#ifndef CONNECTIONTHREAD_H
#define CONNECTIONTHREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
class connectionThread : public QThread
{
		Q_OBJECT
	public:
		explicit connectionThread(qintptr socketDescriptor, QObject *parent = 0);
	protected:
		void run();
	signals:
		void error(QTcpSocket::SocketError socketError);
	public slots:
		void disconnected ();
		void readyRead ();

	private:
		qintptr socketDescriptor;
		QTcpSocket* socket;
};

#endif // CONNECTIONTHREAD_H
