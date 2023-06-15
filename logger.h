/*
Example Usage:

    qInfo() << "File:" << Logger::filename;
    Logger::attach();

    qInfo() << "test";

    Logger::logging = false;
    qInfo() << "This will not get logged";
    Logger::logging = true;

    qWarning() << "Warning!";

    qInfo() << "Finished";

*/

#ifndef LOGGER_H
#define LOGGER_H

#include <QLoggingCategory>
#include <QObject>
#include <QDebug>
#include <QDateTime>
#include <QFile>
#include <QDir>
#include <QTextStream>

namespace Utilities{

/*
Tutorial:

QLoggingCategory network("network");
QLoggingCategory memory("memory");
QLoggingCategory Commander("Commander");
QLoggingCategory CommanderManager("CommanderManager");
...
network.setEnabled(QtMsgType::QtDebugMsg,false);
memory.setEnabled(QtMsgType::QtInfoMsg,true);
...
QLoggingCategory::setFilterRules(QStringLiteral("UdpReceiverCategory.debug=false"));

...
if(!network().isDebugEnabled()){
    QLoggingCategory::setFilterRules(QStringLiteral("network.debug=true"));
    qDebug(network) << "We turned it back on!";
}

*/

inline static QLoggingCategory LoggerCategory("Logger");

void PrintCategoryEnabled(QLoggingCategory& lcat);

class Logger : public QObject
{
    Q_OBJECT
public:
    explicit Logger(QObject *parent = nullptr);
    static bool logging;
    static QString filename;
    static void attach();
    static void handler(QtMsgType type, const QMessageLogContext &context, const QString & msg);
    static void printColoredMessage(QStringView message, QStringView color, QLoggingCategory &lcat=LoggerCategory);

signals:

};

}

#endif // LOGGER_H
