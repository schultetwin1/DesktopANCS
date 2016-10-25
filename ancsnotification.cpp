#include <QDataStream>

#include "ancsnotification.h"

ANCSNotification::ANCSNotification()
{
}

void ANCSNotification::UpdateData(const QByteArray & data)
{
    QDataStream stream(data);
    stream.setByteOrder(QDataStream::LittleEndian);
    uint8_t command;
    stream >> command;
    stream >> Uid;

    while (!stream.atEnd())
    {
        uint8_t attrID;
        uint16_t attrLength;
        stream >> attrID;
        stream >> attrLength;

        char* attr = new char[attrLength + 1];
        attr[attrLength] = '\0';
        stream.readRawData(attr, attrLength);

        switch (attrID)
        {
            case ANCSNotification::NotificationAttributeID::AppIdentifier:
                AppIdentifier = attr;
                break;

            case ANCSNotification::NotificationAttributeID::Title:
                Title = attr;
                break;

            case ANCSNotification::NotificationAttributeID::Subtitle:
                Subtitle = attr;
                break;

            case ANCSNotification::NotificationAttributeID::Message:
                Message = attr;
                break;

            case ANCSNotification::NotificationAttributeID::MessageSize:
                // Don't care
                break;

            case ANCSNotification::NotificationAttributeID::Date:
                Date = QDateTime::fromString(attr, "yyyyMMddTHHmmSS");
                break;

            case ANCSNotification::NotificationAttributeID::PositiveActionLabel:
                PostiveActionLabel = attr;
                break;

            case ANCSNotification::NotificationAttributeID::NegativeActionLabel:
                NegativeActionLabel = attr;
                break;
        }
        delete attr;

    }
}

uint32_t ANCSNotification::getUid() const
{
    return Uid;
}

uint8_t ANCSNotification::getCategoryID() const
{
    return CategoryID;
}

std::string ANCSNotification::getAppIdentifier() const
{
    return AppIdentifier;
}

std::string ANCSNotification::getTitle() const
{
    return Title;
}

std::string ANCSNotification::getSubtitle() const
{
    return Subtitle;
}

std::string ANCSNotification::getMessage() const
{
    return Message;
}

QDateTime ANCSNotification::getDate() const
{
    return Date;
}

std::string ANCSNotification::getPostiveActionLabel() const
{
    return PostiveActionLabel;
}

std::string ANCSNotification::getNegativeActionLabel() const
{
    return NegativeActionLabel;
}
