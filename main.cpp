#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Game.h"
#include "ComputerPlayer.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    engine.globalObject().setProperty("gamePlay", engine.newQObject(new Game));
    engine.globalObject().setProperty("computer", engine.newQObject(new ComputerPlayer));
    return app.exec();
}
