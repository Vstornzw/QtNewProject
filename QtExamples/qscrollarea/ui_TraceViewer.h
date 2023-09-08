/********************************************************************************
** Form generated from reading UI file 'TraceViewer.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRACEVIEWER_H
#define UI_TRACEVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TraceViewer
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QFrame *line;
    QToolButton *exportButton;
    QToolButton *resetZoomButton;
    QToolButton *preButton;
    QToolButton *nextButton;
    QToolButton *toolButton_5;
    QSpacerItem *horizontalSpacer;
    QLabel *readColorLabel;
    QLabel *textureIdNumber;
    QLabel *writeColorShowLabel;
    QLabel *writeColorLabel;
    QLabel *textureIdLabel;
    QLabel *readColorShowLabel;
    QLabel *clearColorShowLabel;
    QLabel *clearColorLabel;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_9;
    QLabel *label_8;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *timelineLayout;

    void setupUi(QWidget *TraceViewer)
    {
        if (TraceViewer->objectName().isEmpty())
            TraceViewer->setObjectName(QString::fromUtf8("TraceViewer"));
        TraceViewer->resize(814, 200);
        verticalLayout = new QVBoxLayout(TraceViewer);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_7 = new QLabel(TraceViewer);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout->addWidget(label_7);

        line = new QFrame(TraceViewer);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        exportButton = new QToolButton(TraceViewer);
        exportButton->setObjectName(QString::fromUtf8("exportButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/save.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        exportButton->setIcon(icon);

        horizontalLayout->addWidget(exportButton);

        resetZoomButton = new QToolButton(TraceViewer);
        resetZoomButton->setObjectName(QString::fromUtf8("resetZoomButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("images/clean.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        resetZoomButton->setIcon(icon1);

        horizontalLayout->addWidget(resetZoomButton);

        preButton = new QToolButton(TraceViewer);
        preButton->setObjectName(QString::fromUtf8("preButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("images/remove.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        preButton->setIcon(icon2);

        horizontalLayout->addWidget(preButton);

        nextButton = new QToolButton(TraceViewer);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("images/append.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        nextButton->setIcon(icon3);

        horizontalLayout->addWidget(nextButton);

        toolButton_5 = new QToolButton(TraceViewer);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("images/delete.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon4);

        horizontalLayout->addWidget(toolButton_5);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        readColorLabel = new QLabel(TraceViewer);
        readColorLabel->setObjectName(QString::fromUtf8("readColorLabel"));

        horizontalLayout->addWidget(readColorLabel);

        textureIdNumber = new QLabel(TraceViewer);
        textureIdNumber->setObjectName(QString::fromUtf8("textureIdNumber"));

        horizontalLayout->addWidget(textureIdNumber);

        writeColorShowLabel = new QLabel(TraceViewer);
        writeColorShowLabel->setObjectName(QString::fromUtf8("writeColorShowLabel"));

        horizontalLayout->addWidget(writeColorShowLabel);

        writeColorLabel = new QLabel(TraceViewer);
        writeColorLabel->setObjectName(QString::fromUtf8("writeColorLabel"));

        horizontalLayout->addWidget(writeColorLabel);

        textureIdLabel = new QLabel(TraceViewer);
        textureIdLabel->setObjectName(QString::fromUtf8("textureIdLabel"));

        horizontalLayout->addWidget(textureIdLabel);

        readColorShowLabel = new QLabel(TraceViewer);
        readColorShowLabel->setObjectName(QString::fromUtf8("readColorShowLabel"));

        horizontalLayout->addWidget(readColorShowLabel);

        clearColorShowLabel = new QLabel(TraceViewer);
        clearColorShowLabel->setObjectName(QString::fromUtf8("clearColorShowLabel"));

        horizontalLayout->addWidget(clearColorShowLabel);

        clearColorLabel = new QLabel(TraceViewer);
        clearColorLabel->setObjectName(QString::fromUtf8("clearColorLabel"));

        horizontalLayout->addWidget(clearColorLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 9, -1, -1);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        widget = new QWidget(TraceViewer);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setWordWrap(false);

        verticalLayout_3->addWidget(label_4);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_3->addWidget(label_5);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_3->addWidget(label_6);

        label_9 = new QLabel(widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_3->addWidget(label_9);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_3->addWidget(label_8);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFrameShape(QFrame::Box);

        verticalLayout_3->addWidget(label_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        verticalLayout_5->addWidget(widget);

        verticalLayout_5->setStretch(0, 6);

        horizontalLayout_2->addLayout(verticalLayout_5);

        timelineLayout = new QVBoxLayout();
        timelineLayout->setObjectName(QString::fromUtf8("timelineLayout"));

        horizontalLayout_2->addLayout(timelineLayout);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 10);

        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 5);

        retranslateUi(TraceViewer);

        QMetaObject::connectSlotsByName(TraceViewer);
    } // setupUi

    void retranslateUi(QWidget *TraceViewer)
    {
        TraceViewer->setWindowTitle(QApplication::translate("TraceViewer", "TraceViewer", nullptr));
        label_7->setText(QApplication::translate("TraceViewer", "Controls", nullptr));
        exportButton->setText(QApplication::translate("TraceViewer", "...", nullptr));
        resetZoomButton->setText(QApplication::translate("TraceViewer", "...", nullptr));
        preButton->setText(QApplication::translate("TraceViewer", "...", nullptr));
        nextButton->setText(QApplication::translate("TraceViewer", "...", nullptr));
        toolButton_5->setText(QApplication::translate("TraceViewer", "...", nullptr));
        readColorLabel->setText(QApplication::translate("TraceViewer", "TextLabel", nullptr));
        textureIdNumber->setText(QApplication::translate("TraceViewer", "TextLabel", nullptr));
        writeColorShowLabel->setText(QApplication::translate("TraceViewer", "TextLabel", nullptr));
        writeColorLabel->setText(QApplication::translate("TraceViewer", "TextLabel", nullptr));
        textureIdLabel->setText(QApplication::translate("TraceViewer", "TextLabel", nullptr));
        readColorShowLabel->setText(QApplication::translate("TraceViewer", "TextLabel", nullptr));
        clearColorShowLabel->setText(QApplication::translate("TraceViewer", "TextLabel", nullptr));
        clearColorLabel->setText(QApplication::translate("TraceViewer", "clearColor", nullptr));
        label_4->setText(QApplication::translate("TraceViewer", "EID:", nullptr));
        label_5->setText(QApplication::translate("TraceViewer", "Draw", nullptr));
        label_6->setText(QApplication::translate("TraceViewer", "Texture", nullptr));
        label_9->setText(QApplication::translate("TraceViewer", "RenderPass", nullptr));
        label_8->setText(QApplication::translate("TraceViewer", "Viewport", nullptr));
        label_2->setText(QApplication::translate("TraceViewer", "Program", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TraceViewer: public Ui_TraceViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRACEVIEWER_H
