#include "ancsnotification.h"

ANCSNotification::ANCSNotification()
{
}

void ANCSNotification::UpdateData(const QByteArray & d)
{
    QByteArray data(d);
    Uid = data.mid(1, 4);
    data.remove(0, 5);

    while (!data.isEmpty())
    {
        uint8_t attrID = data[0];
        data.remove(0,1);
        uint16_t attrLength = data[0] | (data[1] << 8);
        data.remove(0,2);
        QByteArray attr = data.left(attrLength);
        data.remove(0, attrLength);

        switch (attrID)
        {
            case ANCSNotification::NotificationAttributeID::AppIdentifier:
                AppIdentifier = attr.toStdString().c_str();
                break;

            case ANCSNotification::NotificationAttributeID::Title:
                Title = attr.toStdString().c_str();
                break;

            case ANCSNotification::NotificationAttributeID::Subtitle:
                Subtitle = attr.toStdString().c_str();
                break;

            case ANCSNotification::NotificationAttributeID::Message:
                Message = attr.toStdString().c_str();
                break;

            case ANCSNotification::NotificationAttributeID::MessageSize:
                // Don't care
                break;

            case ANCSNotification::NotificationAttributeID::Date:
                Date = QDateTime::fromString(attr.toStdString().c_str(), "yyyyMMddTHHmmSS");
                break;

            case ANCSNotification::NotificationAttributeID::PositiveActionLabel:
                PostiveActionLabel = attr.toStdString().c_str();
                break;

            case ANCSNotification::NotificationAttributeID::NegativeActionLabel:
                NegativeActionLabel = attr.toStdString().c_str();
                break;
        }

    }
}

QByteArray ANCSNotification::getUid() const
{
    return Uid;
}

uint8_t ANCSNotification::getCategoryID() const
{
    return CategoryID;
}

QString ANCSNotification::getAppIdentifier() const
{
    return AppIdentifier;
}

QString ANCSNotification::getTitle() const
{
    return Title;
}

QString ANCSNotification::getSubtitle() const
{
    return Subtitle;
}

QString ANCSNotification::getMessage() const
{
    return Message;
}

QDateTime ANCSNotification::getDate() const
{
    return Date;
}

QString ANCSNotification::getPostiveActionLabel() const
{
    return PostiveActionLabel;
}

QString ANCSNotification::getNegativeActionLabel() const
{
    return NegativeActionLabel;
}
