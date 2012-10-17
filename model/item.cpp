#include "model/item.h"

namespace model {

Item::Item(const QUuid& id)
    : m_uuid(id)
{
    if (m_uuid.isNull()) {
        m_uuid = QUuid::createUuid();
    }
}

Item::~Item()
{

}

QUuid Item::uuid() const
{
    return m_uuid;
}

QString Item::text() const
{
    return m_text;
}

void Item::setText(const QString& i)
{
    m_text = i;
}

} // namespace

