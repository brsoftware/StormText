/**
 * @brief BrStormTextGotoDialog.cpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Aug 3 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextGotoDialog.hpp"
#include "../BrStormTextTab.hpp"

#include <QLabel>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>


BrStormTextGotoDialog::BrStormTextGotoDialog(BrStormTextTab *tab, QWidget *parent)
    : QDialog(parent)
{
    setWindowModality(Qt::WindowModal);

#ifdef Q_OS_WINDOWS
    setWindowFlag(Qt::WindowContextHelpButtonHint, false);
#endif
    m_tab = tab;

    QVBoxLayout *l;
    l = new QVBoxLayout();

    QFormLayout *fl;
    fl = new QFormLayout();

    QLabel *gl;
    gl = new QLabel(tr("&Go to Line"));
    m_leg = new QSpinBox();
    m_leg->setAcceptDrops(false);
    m_leg->setMinimum(1);
    m_leg->setMaximum(2147483647);
    m_leg->setMinimumWidth(100);
    gl->setBuddy(m_leg);
    fl->addRow(gl, m_leg);

    l->addLayout(fl);

    QDialogButtonBox *box;
    box = new QDialogButtonBox();
    QPushButton *goto_;
    goto_ = new QPushButton(tr("Go &to"));
    connect(goto_, SIGNAL(clicked(bool)), this, SLOT(goto_(bool)));
    box->addButton(goto_, QDialogButtonBox::AcceptRole);
    l->addWidget(box);

    setLayout(l);
}

void BrStormTextGotoDialog::goto_(bool isChecked)
{
    Q_UNUSED(isChecked)

    if (m_leg->value() > m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_GETLINECOUNT) + 1)
    {
        QMessageBox *msg;
        msg = new QMessageBox();
        msg->setIcon(QMessageBox::Critical);
        msg->setWindowTitle(tr("OverflowError"));
        msg->setText(tr("Your desired line number is larger than the line number of the current editor."));
        msg->setInformativeText(tr("Try enter a smaller number, please. \n"
                                   "BR_STORMTEXT_0x31506192"));
        msg->setStandardButtons(QMessageBox::Ok);
        msg->exec();
        close();
        return;
    }

    m_tab->currentTab()->setCursorPosition(m_leg->value() - 1, 0);

    close();
}
