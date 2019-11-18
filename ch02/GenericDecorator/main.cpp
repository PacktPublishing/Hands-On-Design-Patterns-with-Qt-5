#include <QCoreApplication>
#include <QDebug>

void GenericDecoratorUsage();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // Set the Identity of the application (just good form)
    a.setOrganizationName("Packt");
    a.setApplicationName("GenericDecorator");

    // Set how qDebug() displays
//    QString logFormatVerbose  ("%{time yyyy-MM-dd hh:mm:ss.zzz} | [%{if-debug}D%{endif}%{if-info}I%{endif}%{if-warning}W%{endif}%{if-critical}C%{endif}%{if-fatal}F%{endif}] | %{function} [%{file}(%{line})] | %{message}");
//    QString logFormatTimeStamp("%{time yyyy-MM-dd hh:mm:ss.zzz} | [%{if-debug}D%{endif}%{if-info}I%{endif}%{if-warning}W%{endif}%{if-critical}C%{endif}%{if-fatal}F%{endif}] | %{message}");
//    qSetMessagePattern(logFormatTimeStamp);

    // Generic Decorator Execution
    GenericDecoratorUsage();
}
