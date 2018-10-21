#include "checkbox_file_status.h"

#include <QString>

CheckBoxFileStatus::CheckBoxFileStatus(QWidget* parent) :
	QCheckBox (parent),
	m_relativeFileName("null")
{
}

CheckBoxFileStatus::CheckBoxFileStatus(QString relativeFilePath, QWidget* parent) :
	QCheckBox (parent),
	m_relativeFileName(relativeFilePath)
{
}

CheckBoxFileStatus::CheckBoxFileStatus(QString relativeFilePath, QString text, QWidget* parent) :
	QCheckBox (text, parent),
	m_relativeFileName(relativeFilePath)
{
}

QString CheckBoxFileStatus::filePath()
{
	return m_relativeFileName;
}
