/**
 * @brief BrStormTextLexerAboutDialog.cpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jul 5 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextAboutDialog.hpp"

#include <QPixmap>
#include <QLabel>
#include <QVBoxLayout>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QDebug>


BrStormTextAboutDialog::BrStormTextAboutDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowModality(Qt::WindowModal);
    setWindowTitle(tr("About"));
    setWindowFlag(Qt::WindowCloseButtonHint);

#ifdef Q_OS_WINDOWS
    setWindowFlag(Qt::WindowContextHelpButtonHint, false);
#endif

    resize(200, 200);

    QPixmap img(":/rsc/stormtext-icon.png");
    img = img.scaled(32, 32);

    QLabel *lbIcon = new QLabel();
    lbIcon->setPixmap(img);

    QVBoxLayout *l = new QVBoxLayout();
    l->addWidget(lbIcon, 0, Qt::AlignHCenter);

    QLabel *lbTitle = new QLabel();
    lbTitle->setText("<p style=\"font-weight:900;\">StormText</p>");
    lbTitle->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);
    l->addWidget(lbTitle, 0, Qt::AlignHCenter);

    QLabel *lbVersion = new QLabel();
    lbVersion->setText("Version 1.0.0");
    lbVersion->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);
    l->addWidget(lbVersion, 0, Qt::AlignHCenter);

    QLabel *lbCopy = new QLabel();
    lbCopy->setText("Copyright \u00a9 Bright Software Foundation 2023. Under BSL 1.0.");
    lbCopy->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);
    l->addWidget(lbCopy, 0, Qt::AlignHCenter);

    QDialogButtonBox *box;
    box = new QDialogButtonBox();
    QPushButton *ok;
    ok = new QPushButton(tr("&OK"));
    box->addButton(ok, QDialogButtonBox::AcceptRole);
    connect(ok, &QPushButton::clicked, this, [=](bool c){Q_UNUSED(c);close();});
    l->addWidget(box);

    setLayout(l);
}
