/********************************************************************************
** Form generated from reading UI file 'dialog13_1.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG13_1_H
#define UI_DIALOG13_1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnStartThread;
    QPushButton *btnDiceBegin;
    QPushButton *btnDiceEnd;
    QPushButton *btnStopThread;
    QPushButton *btnClear;
    QHBoxLayout *horizontalLayout_3;
    QPlainTextEdit *plainTextEdit;
    QLabel *LabPic;
    QLabel *LabA;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(489, 410);
        verticalLayout_2 = new QVBoxLayout(Dialog);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(3, 3, 3, 3);
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnStartThread = new QPushButton(groupBox);
        btnStartThread->setObjectName(QString::fromUtf8("btnStartThread"));

        horizontalLayout->addWidget(btnStartThread);

        btnDiceBegin = new QPushButton(groupBox);
        btnDiceBegin->setObjectName(QString::fromUtf8("btnDiceBegin"));
        btnDiceBegin->setEnabled(false);

        horizontalLayout->addWidget(btnDiceBegin);

        btnDiceEnd = new QPushButton(groupBox);
        btnDiceEnd->setObjectName(QString::fromUtf8("btnDiceEnd"));
        btnDiceEnd->setEnabled(false);

        horizontalLayout->addWidget(btnDiceEnd);

        btnStopThread = new QPushButton(groupBox);
        btnStopThread->setObjectName(QString::fromUtf8("btnStopThread"));
        btnStopThread->setEnabled(false);

        horizontalLayout->addWidget(btnStopThread);

        btnClear = new QPushButton(groupBox);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));

        horizontalLayout->addWidget(btnClear);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        plainTextEdit = new QPlainTextEdit(groupBox);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        horizontalLayout_3->addWidget(plainTextEdit);

        LabPic = new QLabel(groupBox);
        LabPic->setObjectName(QString::fromUtf8("LabPic"));
        LabPic->setMinimumSize(QSize(150, 0));
        LabPic->setPixmap(QPixmap(QString::fromUtf8(":/dice/images/d0.jpg")));

        horizontalLayout_3->addWidget(LabPic);


        verticalLayout->addLayout(horizontalLayout_3);

        LabA = new QLabel(groupBox);
        LabA->setObjectName(QString::fromUtf8("LabA"));

        verticalLayout->addWidget(LabA);


        verticalLayout_2->addWidget(groupBox);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\345\244\232\347\272\277\347\250\213\357\274\214\344\275\277\347\224\250\344\277\241\345\217\267\344\270\216\344\270\273\347\272\277\347\250\213\351\200\232\350\256\257", nullptr));
        groupBox->setTitle(QApplication::translate("Dialog", "\347\272\277\347\250\213", nullptr));
        btnStartThread->setText(QApplication::translate("Dialog", "\345\220\257\345\212\250\347\272\277\347\250\213", nullptr));
        btnDiceBegin->setText(QApplication::translate("Dialog", "\345\274\200\345\247\213", nullptr));
        btnDiceEnd->setText(QApplication::translate("Dialog", "\346\232\202\345\201\234", nullptr));
        btnStopThread->setText(QApplication::translate("Dialog", "\347\273\223\346\235\237\347\272\277\347\250\213", nullptr));
        btnClear->setText(QApplication::translate("Dialog", "\346\270\205\347\251\272\346\226\207\346\234\254", nullptr));
        LabPic->setText(QString());
        LabA->setText(QApplication::translate("Dialog", "Thread\347\212\266\346\200\201\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG13_1_H
