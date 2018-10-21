#ifndef CHECKBOX_FILE_STATUS_H
#define CHECKBOX_FILE_STATUS_H

#include <QCheckBox>
#include <QString>

class CheckBoxFileStatus : public QCheckBox
{
public:
	CheckBoxFileStatus(QWidget* parent = nullptr);
	CheckBoxFileStatus(QString relativeFilePath, QWidget* = nullptr);
	CheckBoxFileStatus(QString relativeFilePath, QString text, QWidget* parent = nullptr);

	QString filePath();
private:
	QString m_relativeFileName;
};

#endif // CHECKBOX_FILE_STATUS_H
