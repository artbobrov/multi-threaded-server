#include <QCoreApplication>
#include "server.h"
int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	server* srv = new server;
	srv->start ();
	return a.exec();
}
