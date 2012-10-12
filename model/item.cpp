#include "model/item.h"

namespace model {

QString Item::text() const
{
    return m_text;
}

void Item::setText(const QString& i)
{
    m_text = i;
}

} // namespace

