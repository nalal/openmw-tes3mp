
#include "tablesubview.hpp"

#include <QVBoxLayout>

#include "../../model/doc/document.hpp"

#include "table.hpp"

CSVWorld::TableSubView::TableSubView (const CSMWorld::UniversalId& id, CSMDoc::Document& document,
    bool createAndDelete)
: SubView (id)
{
    QVBoxLayout *layout = new QVBoxLayout;

    layout->setContentsMargins (QMargins (0, 0, 0, 0));

    layout->addWidget (
        mTable = new Table (id, document.getData(), document.getUndoStack(), createAndDelete), 2);

    QWidget *widget = new QWidget;

    widget->setLayout (layout);

    setWidget (widget);

    connect (mTable, SIGNAL (editRequest (int)), this, SLOT (editRequest (int)));
}

void CSVWorld::TableSubView::setEditLock (bool locked)
{
    mTable->setEditLock (locked);
}

void CSVWorld::TableSubView::editRequest (int row)
{
    focusId (mTable->getUniversalId (row));
}

void CSVWorld::TableSubView::updateEditorSetting(const QString &settingName, const QString &settingValue)
{
    mTable->updateEditorSetting(settingName, settingValue);
}
