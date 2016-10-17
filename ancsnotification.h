#ifndef ANCSNOTIFICATION_H
#define ANCSNOTIFICATION_H

#include <QByteArray>
#include <QDateTime>
#include <QString>


class ANCSNotification
{
public:
    struct CategoryID {
        const static uint8_t Other              = 0;
        const static uint8_t IncomingCall       = 1;
        const static uint8_t MissedCall         = 2;
        const static uint8_t Voicemail          = 3;
        const static uint8_t Social             = 4;
        const static uint8_t Schedule           = 5;
        const static uint8_t Email              = 6;
        const static uint8_t News               = 7;
        const static uint8_t HealthAndFitness   = 8;
        const static uint8_t BusinessAndFinance = 9;
        const static uint8_t Location           = 10;
        const static uint8_t Entertainment      = 11;
    };

    struct EventID {
        const static uint8_t NotificationAdded    = 0;
        const static uint8_t NotificationModified = 1;
        const static uint8_t NotificationRemoved  = 2;
    };

    struct EventFlags {
        const static uint8_t Silent         = ( 1 << 0 );
        const static uint8_t Important      = ( 1 << 1 );
        const static uint8_t PreExisting    = ( 1 << 2 );
        const static uint8_t PositiveAction = ( 1 << 3 );
        const static uint8_t NegativeAction = ( 1 << 4 );
    };

    struct CommandID {
        const static uint8_t GetNotificationAttributes = 0;
        const static uint8_t GetAppAttributes          = 1;
        const static uint8_t PerformNotificationAction = 2;
    };

    struct NotificationAttributeID {
        const static uint8_t AppIdentifier       = 0;
        const static uint8_t Title               = 1;
        const static uint8_t Subtitle            = 2;
        const static uint8_t Message             = 3;
        const static uint8_t MessageSize         = 4;
        const static uint8_t Date                = 5;
        const static uint8_t PositiveActionLabel = 6;
        const static uint8_t NegativeActionLabel = 7;
    };

    struct ActionID {
        const static uint8_t Positive = 0;
        const static uint8_t Negative = 1;
    };

    struct AppAttributeID {
        const static uint8_t DisplayName = 0;
    };

    ANCSNotification();

    void UpdateData(const QByteArray&);

    QByteArray getUid() const;
    uint8_t getCategoryID() const;
    QString getAppIdentifier() const;
    QString getTitle() const;
    QString getSubtitle() const;
    QString getMessage() const;
    QDateTime getDate() const;
    QString getPostiveActionLabel() const;
    QString getNegativeActionLabel() const;

private:
    QByteArray Uid;
    uint8_t    CategoryID;
    QString    AppIdentifier;
    QString    Title;
    QString    Subtitle;
    QString    Message;
    QDateTime  Date;
    QString    PostiveActionLabel;
    QString    NegativeActionLabel;
};

#endif // ANCSNOTIFICATION_H
