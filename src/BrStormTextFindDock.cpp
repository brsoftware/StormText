/**
 * @brief BrStormTextFindDock.hpp: A file of the StormText project.
 * @author Bright Software Foundation.
 * @date 27 May 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextFindDock.hpp"
#include "BrStormTextTab.hpp"

#include <QVBoxLayout>
#include <QGridLayout>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QGroupBox>
#include <QMessageBox>
#include <QDebug>


BrStormTextFindDock::BrStormTextFindDock(BrStormTextTab *tab, QWidget *parent)
    : QDockWidget(tr("Find and Replace Panel"), parent)
{
    setVisible(false);
    setFocus();

    m_tab = tab;

    QWidget *lw;
    lw = new QWidget();

    QVBoxLayout *l;
    l = new QVBoxLayout();

    l->setSpacing(0);

    QFormLayout *fl;
    fl = new QFormLayout();

    fl->setHorizontalSpacing(0);
    fl->setVerticalSpacing(0);

    QLabel *flb;
    flb = new QLabel(tr("Find &What: "));
    m_lef = new QLineEdit();
    m_lef->setDragEnabled(true);
    m_lef->setAcceptDrops(true);
    m_lef->setMinimumWidth(200);
    flb->setBuddy(m_lef);
    fl->addRow(flb, m_lef);

    QLabel *flr;
    flr = new QLabel(tr("&Replace With: "));
    m_ler = new QLineEdit();
    m_ler->setDragEnabled(true);
    m_ler->setAcceptDrops(true);
    m_ler->setMinimumWidth(200);
    flr->setBuddy(m_ler);
    fl->addRow(flr, m_ler);

    l->addLayout(fl);

    QGroupBox *gbOption;
    gbOption = new QGroupBox(tr("Options"));
    gbOption->setMinimumHeight(0);

    QVBoxLayout *gbL;
    gbL = new QVBoxLayout();

    gbL->setSpacing(0);
    gbL->setContentsMargins(0, 0, 0, 0);

    m_checkRegex = new QCheckBox(tr("&1. Enable ReGeX"));
    gbL->addWidget(m_checkRegex);

    m_checkCaseSensitive = new QCheckBox(tr("&2. Case Sensitive"));
    gbL->addWidget(m_checkCaseSensitive);

    m_checkWholeWord = new QCheckBox(tr("&3. Whole Word Only"));
    gbL->addWidget(m_checkWholeWord);

    gbOption->setLayout(gbL);

    l->addWidget(gbOption);

    QDialogButtonBox *box;
    box = new QDialogButtonBox();
    QPushButton *bfn;
    bfn = new QPushButton(tr("Find &Next"));
    connect(bfn, SIGNAL(clicked(bool)), this, SLOT(findNext(bool)));
    connect(m_lef, &QLineEdit::returnPressed, this, [=](){findNext(true);});
    box->addButton(bfn, QDialogButtonBox::AcceptRole);
    QPushButton *bfp;
    bfp = new QPushButton(tr("Find &Previous"));
    connect(bfp, SIGNAL(clicked(bool)), this, SLOT(findPrevious(bool)));
    box->addButton(bfp, QDialogButtonBox::ActionRole);
    QPushButton *brn;

    l->addWidget(box);

    QDialogButtonBox *box2;
    box2 = new QDialogButtonBox();
    box2->setCenterButtons(true);
    brn = new QPushButton(tr("R&eplace Next"));
    connect(brn, SIGNAL(clicked(bool)), this, SLOT(replaceNext(bool)));
    box2->addButton(brn, QDialogButtonBox::ActionRole);
    QPushButton *brp;
    brp = new QPushButton(tr("Rep&lace Previous"));
    connect(brp, SIGNAL(clicked(bool)), this, SLOT(replacePrevious(bool)));
    box2->addButton(brp, QDialogButtonBox::ActionRole);
    QPushButton *bra;

    l->addWidget(box2);

    QDialogButtonBox *box3;
    box3 = new QDialogButtonBox();
    box3->setCenterButtons(true);
    bra = new QPushButton(tr("Replace &All"));
    connect(bra, SIGNAL(clicked(bool)), this, SLOT(replaceAll(bool)));
    box3->addButton(bra, QDialogButtonBox::ActionRole);

    l->addWidget(box3);

    lw->setLayout(l);

    setWidget(lw);
}

void BrStormTextFindDock::findNext(bool isChecked)
{
    Q_UNUSED(isChecked)

    if (m_tab->currentTab())
    {
        if (m_lef->text() != "")
        {
            m_tab->currentTab()->findFirst(m_lef->text(),
                                           m_checkRegex->isChecked(),
                                           m_checkCaseSensitive->isChecked(),
                                           m_checkWholeWord->isChecked(),
                                           true);
        }

        else
        {
            QMessageBox *msg;
            msg = new QMessageBox();
            msg->setIcon(QMessageBox::Critical);
            msg->setWindowTitle(tr("ValueError"));
            msg->setText(tr("You cannot have a null-text. You must enter something to find that."));
            msg->setInformativeText(tr("Maybe you've not opened the find panel yet and type something "
                                       "into it? Open it up, try again, or else contact your technician. \n"
                                       "BR_STORMTEXT_0x00565630"));
            msg->setStandardButtons(QMessageBox::Ok);
            msg->exec();
        }
    }
}

void BrStormTextFindDock::findPrevious(bool isChecked)
{
    Q_UNUSED(isChecked)

    if (m_tab->currentTab())
    {
        if (m_lef->text() != "")
        {
            m_tab->currentTab()->findFirst(m_lef->text(),
                                           m_checkRegex->isChecked(),
                                           m_checkCaseSensitive->isChecked(),
                                           m_checkWholeWord->isChecked(),
                                           true,
                                           false);
        }

        else
        {
            QMessageBox *msg;
            msg = new QMessageBox();
            msg->setIcon(QMessageBox::Critical);
            msg->setWindowTitle(tr("ValueError"));
            msg->setText(tr("You cannot have a null-text. You must enter something to find that."));
            msg->setInformativeText(tr("Maybe you've not opened the find panel yet and type something "
                                       "into it? Open it up, try again, or else contact your technician. \n"
                                       "BR_STORMTEXT_0x00565630"));
            msg->setStandardButtons(QMessageBox::Ok);
            msg->exec();
        }
    }
}

void BrStormTextFindDock::replacePrevious(bool isChecked)
{
    Q_UNUSED(isChecked)

    if (m_tab->currentTab())
    {
        if (m_lef->text() != "" && m_ler->text() != "")
        {
            m_tab->currentTab()->beginUndoAction();
            m_tab->currentTab()->findFirst(m_lef->text(),
                                           m_checkRegex->isChecked(),
                                           m_checkCaseSensitive->isChecked(),
                                           m_checkWholeWord->isChecked(),
                                           true,
                                           false);
            m_tab->currentTab()->replace(m_ler->text());
            m_tab->currentTab()->endUndoAction();
        }

        else
        {
            QMessageBox *msg;
            msg = new QMessageBox();
            msg->setIcon(QMessageBox::Critical);
            msg->setWindowTitle(tr("ValueError"));
            msg->setText(tr("You cannot have a null-text. You must enter something to replace that."));
            msg->setInformativeText(tr("Maybe you've not opened the find panel yet and type something "
                                       "into it? Open it up, try again, or else contact your technician. \n"
                                       "BR_STORMTEXT_0x00565631"));
            msg->setStandardButtons(QMessageBox::Ok);
            msg->exec();
        }
    }
}

void BrStormTextFindDock::replaceNext(bool isChecked)
{
    Q_UNUSED(isChecked)

    if (m_tab->currentTab())
    {
        if (m_lef->text() != "" && m_ler->text() != "")
        {
            m_tab->currentTab()->beginUndoAction();
            m_tab->currentTab()->findFirst(m_lef->text(),
                                           m_checkRegex->isChecked(),
                                           m_checkCaseSensitive->isChecked(),
                                           m_checkWholeWord->isChecked(),
                                           true);
            m_tab->currentTab()->replace(m_ler->text());
            m_tab->currentTab()->endUndoAction();
        }

        else
        {
            QMessageBox *msg;
            msg = new QMessageBox();
            msg->setIcon(QMessageBox::Critical);
            msg->setWindowTitle(tr("ValueError"));
            msg->setText(tr("You cannot have a null-text. You must enter something to replace that."));
            msg->setInformativeText(tr("Maybe you've not opened the find panel yet and type something "
                                       "into it? Open it up, try again, or else contact your technician. \n"
                                       "BR_STORMTEXT_0x00565631"));
            msg->setStandardButtons(QMessageBox::Ok);
            msg->exec();
        }
    }
}

void BrStormTextFindDock::replaceAll(bool isChecked)
{
    Q_UNUSED(isChecked)

    if (m_tab->currentTab())
    {
        if (m_lef->text() != "" && m_ler->text() != "")
        {
            m_tab->currentTab()->beginUndoAction();

            while (m_tab->currentTab()->findFirst(m_lef->text(),
                                                  m_checkRegex->isChecked(),
                                                  m_checkCaseSensitive->isChecked(),
                                                  m_checkWholeWord->isChecked(),
                                                  true))
            {
                m_tab->currentTab()->replace(m_ler->text());
            }

            m_tab->currentTab()->endUndoAction();
        }

        else
        {
            QMessageBox *msg;
            msg = new QMessageBox();
            msg->setIcon(QMessageBox::Critical);
            msg->setWindowTitle(tr("ValueError"));
            msg->setText(tr("You cannot have a null-text. You must enter something to replace that."));
            msg->setInformativeText(tr("Maybe you've not opened the find panel yet and type something "
                                       "into it? Open it up, try again, or else contact your technician. \n"
                                       "BR_STORMTEXT_0x00565631"));
            msg->setStandardButtons(QMessageBox::Ok);
            msg->exec();
        }
    }
}
