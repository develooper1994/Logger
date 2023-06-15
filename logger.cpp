

#include "logger.h"

// ANSI kaçış dizileri ile renkli yazı yazma
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Kırmızı */
#define GREEN   "\033[32m"      /* Yeşil */
#define YELLOW  "\033[33m"      /* Sarı */
#define BLUE    "\033[34m"      /* Mavi */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* Beyaz */

namespace Utilities{

QString Logger::filename = QDir::currentPath() + QDir::separator() + "log.txt";
QIODevice::OpenModeFlag openModeFlag = QIODevice::OpenModeFlag::Append;
bool Logger::logging = false;
static const QtMessageHandler QT_DEFAULT_MESSAGE_HANDLER = qInstallMessageHandler(nullptr);

Logger::Logger(QObject *parent) : QObject(parent)
{}

void Logger::attach(){
    Logger::logging = true;
    qInstallMessageHandler(Logger::handler);
}

void Logger::handler(QtMsgType type, const QMessageLogContext &context, const QString &msg){
    QString color, txt;
    color.resize(sizeof(RESET));
    if(Logger::logging) {
        switch (type) {
        case QtInfoMsg:
            color = GREEN;
            txt = QString("Info: %1").arg(msg);
            break;
        case QtDebugMsg:
            color = BLUE;
            txt = QString("Debug: %1").arg(msg);
            break;
        case QtWarningMsg:
            color = YELLOW;
            txt = QString("Warning: %1").arg(msg);
            break;
        case QtCriticalMsg:
            color = RED;
            txt = QString("Critical: %1").arg(msg);
            break;
        case QtFatalMsg:
            color = MAGENTA;
            txt = QString("Fatal: %1").arg(msg);
            break;
        }
        QFile file(Logger::filename);
        if(file.open(openModeFlag)) {
            QTextStream ts(&file);

            ts << QDateTime::currentDateTime().toString() << " - " << txt << context.file << " line: " << context.line << '\r' << '\n';
            ts.flush();
            file.close();
        }
    }

    QString&& konsolOutput = QString("%1%2").arg(color,txt);
    (*QT_DEFAULT_MESSAGE_HANDLER)(type, context, konsolOutput);

}

void Logger::printColoredMessage(QStringView message, QStringView color, QLoggingCategory &lcat){
    qDebug(lcat).noquote() << color << message << RESET;
}

void PrintCategoryEnabled(QLoggingCategory &lcat){
    qDebug(lcat) << "Debug";
    qInfo(lcat) << "Info";
    qWarning(lcat) << "Warning";
    qCritical(lcat) << "Critical";
}

}
