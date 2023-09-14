/**
 * @brief BrStormTextLexerAboutApplicationDialog.cpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jul 5 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextAboutApplicationDialog.hpp"

#include <QApplication>
#include <QLabel>
#include <QGroupBox>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QDebug>


BrStormTextAboutApplicationDialog::BrStormTextAboutApplicationDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowModality(Qt::WindowModal);
    setWindowTitle(tr("About This Application"));
    setWindowFlag(Qt::WindowCloseButtonHint);

#ifdef Q_OS_WINDOWS
    setWindowFlag(Qt::WindowContextHelpButtonHint, false);
#endif

    QVBoxLayout *lo;
    lo = new QVBoxLayout();

    // Core
    QString app_applicationDirPath = QApplication::applicationDirPath();
    QString app_applicationFilePath = QApplication::applicationFilePath();
    QString app_applicationName = QApplication::applicationName();
    QString app_applicationPid = QString::number(QApplication::applicationPid());
    QString app_applicationVersion = QApplication::applicationVersion();
    QString app_organizationDomain = QApplication::organizationDomain();
    QString app_organizationName = QApplication::organizationName();

    // Gui
    QString app_applicationDisplayName = QApplication::applicationDisplayName();
    QString app_platformName = QApplication::platformName();

    QGroupBox *gpCore;
    gpCore = new QGroupBox();

    QFormLayout *lCore;
    lCore = new QFormLayout();

    QLabel *nAppDirPath = new QLabel(tr("Application Directory Path: "));
    QLabel *lAppDirPath = new QLabel(app_applicationDirPath);
    lAppDirPath->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);
    lCore->addRow(nAppDirPath, lAppDirPath);

    QLabel *nAppFnPath = new QLabel(tr("Application File Path: "));
    QLabel *lAppFnPath = new QLabel(app_applicationFilePath);
    lAppFnPath->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);
    lCore->addRow(nAppFnPath, lAppFnPath);

    QLabel *nAppNm = new QLabel(tr("Application Name: "));
    QLabel *lAppNm = new QLabel(app_applicationName);
    lAppNm->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);
    lCore->addRow(nAppNm, lAppNm);

    QLabel *nAppPid = new QLabel(tr("Application Process ID: "));
    QLabel *lAppPid = new QLabel(app_applicationPid);
    lAppPid->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);
    lCore->addRow(nAppPid, lAppPid);

    QLabel *nAppVer = new QLabel(tr("Application Version: "));
    QLabel *lAppVer = new QLabel(app_applicationVersion);
    lAppVer->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);
    lCore->addRow(nAppVer, lAppVer);

    QLabel *nOrgDmn = new QLabel(tr("Organization Domain: "));
    QLabel *lOrgDmn = new QLabel(app_organizationDomain);
    lOrgDmn->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);
    lCore->addRow(nOrgDmn, lOrgDmn);

    QLabel *nOrgNm = new QLabel(tr("Organization Name: "));
    QLabel *lOrgNm = new QLabel(app_organizationName);
    lOrgNm->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);
    lCore->addRow(nOrgNm, lOrgNm);

    gpCore->setLayout(lCore);

    lo->addWidget(gpCore);

    QGroupBox *gpGui;
    gpGui = new QGroupBox();

    QFormLayout *lGui;
    lGui = new QFormLayout();

    QLabel *nAppDisNm = new QLabel(tr("Application Display Name: "));
    QLabel *lAppDisNm = new QLabel(app_applicationDisplayName);
    lAppDisNm->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);
    lGui->addRow(nAppDisNm, lAppDisNm);

    QLabel *nPlatNm = new QLabel(tr("Platform Name: "));
    QLabel *lPlatNm = new QLabel(app_platformName);
    lPlatNm->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);
    lGui->addRow(nPlatNm, lPlatNm);

    gpGui->setLayout(lGui);

    lo->addWidget(gpGui);

    QDialogButtonBox *box;
    box = new QDialogButtonBox();
    QPushButton *ok;
    ok = new QPushButton(tr("&OK"));
    box->addButton(ok, QDialogButtonBox::AcceptRole);
    connect(ok, &QPushButton::clicked, this, [=](bool c){Q_UNUSED(c);close();});
    lo->addWidget(box);

    setLayout(lo);
}
