#ifndef QTSERVICE_SERVICE_P_H
#define QTSERVICE_SERVICE_P_H

#include <QtCore/QPointer>

#include "service.h"
#include "servicebackend.h"

namespace QtService {

class ServiceControl;
class ServicePrivate
{
public:
	ServicePrivate(int &argc, char **argv, int flags);

	static QStringList listBackends();
	static ServiceControl *createControl(const QString &provider, QString &&serviceId, QObject *parent);
	static QDir runtimeDir(const QString &serviceName);

	static QPointer<Service> instance;

	int &argc;
	char **argv;
	int flags;

	QString backendProvider;
	ServiceBackend *backend = nullptr;
	QHash<QByteArray, std::function<QVariant(QVariantList)>> callbacks;

	bool isRunning = false;
	bool wasPaused = false;
	bool terminalActive = false;
};

}

#endif // QTSERVICE_SERVICE_P_H