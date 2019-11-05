#include <QCoreApplication>
#include "Signaler.h"

int main(int argc, char *argv[])
{
    // process the command line args and set up the application
    QCoreApplication a(argc, argv);

    // Set the Identity of the application (just good form)
    a.setOrganizationName("Packt");
    a.setApplicationName("SignalsAndSlots-1");

    // Set how qDebug() displays
    QString logFormatVerbose  ("%{time yyyy-MM-dd hh:mm:ss.zzz} | [%{if-debug}D%{endif}%{if-info}I%{endif}%{if-warning}W%{endif}%{if-critical}C%{endif}%{if-fatal}F%{endif}] | %{function} [%{file}(%{line})] | %{message}");
    QString logFormatTimeStamp("%{time yyyy-MM-dd hh:mm:ss.zzz} | [%{if-debug}D%{endif}%{if-info}I%{endif}%{if-warning}W%{endif}%{if-critical}C%{endif}%{if-fatal}F%{endif}] | %{message}");
    qSetMessagePattern(logFormatTimeStamp);

    // Create the Signaler and start it
    Signaler    mySignaler;
    mySignaler.DoSendSignals();

    // start the Qt event loop
    return a.exec();
}
