#include "main_window.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QLibraryInfo>

#ifdef Q_OS_UNIX
int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	// set translator
	QString locale = QLocale::system().name().section('_', 0, 0);
	QTranslator translator;
	translator.load(QString("qt_" + locale), QLibraryInfo::location(QLibraryInfo::TranslationsPath));
	app.installTranslator(&translator);

	MainWindow w;
	w.show();

	return app.exec();
}
#endif
