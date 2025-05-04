/********************************************************************************
** Form generated from reading UI file 'editingsalarydialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITINGSALARYDIALOG_H
#define UI_EDITINGSALARYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_editingsalarydialog
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *editingsalarydialog)
    {
        if (editingsalarydialog->objectName().isEmpty())
            editingsalarydialog->setObjectName("editingsalarydialog");
        editingsalarydialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(editingsalarydialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        retranslateUi(editingsalarydialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, editingsalarydialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, editingsalarydialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(editingsalarydialog);
    } // setupUi

    void retranslateUi(QDialog *editingsalarydialog)
    {
        editingsalarydialog->setWindowTitle(QCoreApplication::translate("editingsalarydialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class editingsalarydialog: public Ui_editingsalarydialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITINGSALARYDIALOG_H
