#ifndef OPENMW_QUESTAPI_HPP
#define OPENMW_QUESTAPI_HPP

#include <Script/Platform.hpp>

#define QUESTAPI \
    {"ClearJournalChanges",               QuestFunctions::ClearJournalChanges},\
    {"ClearKillChanges",                  QuestFunctions::ClearKillChanges},\
    \
    {"GetJournalChangesSize",             QuestFunctions::GetJournalChangesSize},\
    {"GetKillChangesSize",                QuestFunctions::GetKillChangesSize},\
    \
    {"AddJournalEntry",                   QuestFunctions::AddJournalEntry},\
    {"AddJournalEntryWithTimestamp",      QuestFunctions::AddJournalEntryWithTimestamp},\
    {"AddJournalIndex",                   QuestFunctions::AddJournalIndex},\
    {"AddKill",                           QuestFunctions::AddKill},\
    \
    {"SetReputation",                     QuestFunctions::SetReputation},\
    \
    {"GetJournalItemQuest",               QuestFunctions::GetJournalItemQuest},\
    {"GetJournalItemIndex",               QuestFunctions::GetJournalItemIndex},\
    {"GetJournalItemType",                QuestFunctions::GetJournalItemType},\
    {"GetJournalItemActorRefId",          QuestFunctions::GetJournalItemActorRefId},\
    {"GetKillRefId",                      QuestFunctions::GetKillRefId},\
    {"GetKillNumber",                     QuestFunctions::GetKillNumber},\
    \
    {"GetReputation",                     QuestFunctions::GetReputation},\
    \
    {"SendJournalChanges",                QuestFunctions::SendJournalChanges},\
    {"SendKillChanges",                   QuestFunctions::SendKillChanges},\
    {"SendReputation",                    QuestFunctions::SendReputation},\
    \
    {"InitializeJournalChanges",          QuestFunctions::InitializeJournalChanges},\
    {"InitializeKillChanges",             QuestFunctions::InitializeKillChanges}

namespace QuestFunctions
{
    /**
    * \brief Clear the last recorded journal changes for a player.
    *
    * This is used to initialize the sending of new PlayerJournal packets.
    *
    * \param pid The player ID whose journal changes should be used.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL ClearJournalChanges(unsigned short pid) noexcept;

    /**
    * \brief Clear the last recorded kill count changes for a player.
    *
    * This is used to initialize the sending of new WorldKillCount packets.
    *
    * \param pid The player ID whose kill count changes should be used.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL ClearKillChanges(unsigned short pid) noexcept;

    /**
    * \brief Get the number of indexes in a player's latest journal changes.
    *
    * \param pid The player ID whose journal changes should be used.
    * \return The number of indexes.
    */
    EXPORT_APIFUNCTION unsigned CDECL int GetJournalChangesSize(unsigned short pid) noexcept;

    /**
    * \brief Get the number of indexes in a player's latest kill count changes.
    *
    * \param pid The player ID whose kill count changes should be used.
    * \return The number of indexes.
    */
    EXPORT_APIFUNCTION unsigned CDECL int GetKillChangesSize(unsigned short pid) noexcept;

    /**
    * \brief Add a new journal item of type ENTRY to the journal changes for a player,
    *  with a specific timestamp.
    *
    * \param pid The player ID whose journal changes should be used.
    * \param quest The quest of the journal item.
    * \param index The quest index of the journal item.
    * \param actorRefId The actor refId of the journal item.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL AddJournalEntry(unsigned short pid, const char* quest, unsigned int index, const char* actorRefId) noexcept;

    /**
    * \brief Add a new journal item of type ENTRY to the journal changes for a player,
    *  with a specific timestamp.
    *
    * \param pid The player ID whose journal changes should be used.
    * \param quest The quest of the journal item.
    * \param index The quest index of the journal item.
    * \param actorRefId The actor refId of the journal item.
    * \param The daysPassed for the journal item.
    * \param The month for the journal item.
    * \param The day of the month for the journal item.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL AddJournalEntryWithTimestamp(unsigned short pid, const char* quest, unsigned int index, const char* actorRefId,
        unsigned int daysPassed, unsigned int month, unsigned int day) noexcept;

    /**
    * \brief Add a new journal item of type INDEX to the journal changes for a player.
    *
    * \param pid The player ID whose journal changes should be used.
    * \param quest The quest of the journal item.
    * \param index The quest index of the journal item.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL AddJournalIndex(unsigned short pid, const char* quest, unsigned int index) noexcept;

    /**
    * \brief Add a new kill count to the kill count changes for a player.
    *
    * \param pid The player ID whose kill count changes should be used.
    * \param refId The refId of the kill count.
    * \param number The number of kills in the kill count.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL AddKill(unsigned short pid, const char* refId, int number) noexcept;

    /**
    * \brief Set the reputation of a certain player.
    *
    * \param pid The player ID.
    * \param value The reputation.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetReputation(unsigned short pid, int value) noexcept;

    /**
    * \brief Get the quest at a certain index in a player's latest journal changes.
    *
    * \param pid The player ID whose journal changes should be used.
    * \param index The index of the journalItem.
    * \return The quest.
    */
    EXPORT_APIFUNCTION const CDECL char *GetJournalItemQuest(unsigned short pid, unsigned int index) noexcept;

    /**
    * \brief Get the quest index at a certain index in a player's latest journal changes.
    *
    * \param pid The player ID whose journal changes should be used.
    * \param index The index of the journalItem.
    * \return The quest index.
    */
    EXPORT_APIFUNCTION int CDECL GetJournalItemIndex(unsigned short pid, unsigned int index) noexcept;

    /**
    * \brief Get the journal item type at a certain index in a player's latest journal changes.
    *
    * \param pid The player ID whose journal changes should be used.
    * \param index The index of the journalItem.
    * \return The type (0 for ENTRY, 1 for INDEX).
    */
    EXPORT_APIFUNCTION int CDECL GetJournalItemType(unsigned short pid, unsigned int index) noexcept;

    /**
    * \brief Get the actor refId at a certain index in a player's latest journal changes.
    *
    * Every journal change has an associated actor, which is usually the quest giver.
    *
    * \param pid The player ID whose journal changes should be used.
    * \param index The index of the journalItem.
    * \return The actor refId.
    */
    EXPORT_APIFUNCTION const CDECL char *GetJournalItemActorRefId(unsigned short pid, unsigned int index) noexcept;

    /**
    * \brief Get the refId at a certain index in a player's latest kill count changes.
    *
    * \param pid The player ID whose kill count changes should be used.
    * \param index The index of the kill count.
    * \return The refId.
    */
    EXPORT_APIFUNCTION const CDECL char *GetKillRefId(unsigned short pid, unsigned int index) noexcept;

    /**
    * \brief Get the number of kills at a certain index in a player's latest kill count changes.
    *
    * \param pid The player ID whose kill count changes should be used.
    * \param index The index of the kill count.
    * \return The number of kills.
    */
    EXPORT_APIFUNCTION int CDECL GetKillNumber(unsigned short pid, unsigned int index) noexcept;

    /**
    * \brief Get the a certain player's reputation.
    *
    * \param pid The player ID.
    * \return The reputation.
    */
    EXPORT_APIFUNCTION int CDECL GetReputation(unsigned short pid) noexcept;

    /**
    * \brief Send a PlayerJournal packet with a player's recorded journal changes.
    *
    * \param pid The player ID whose journal changes should be used.
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param skipAttachedPlayer Whether the packet should skip being sent to the player attached
    *                           to the packet (false by default).
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SendJournalChanges(unsigned short pid, bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept;

    /**
    * \brief Send a WorldKillCount packet with a player's recorded kill count changes.
    *
    * \param pid The player ID whose kill count changes should be used.
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param skipAttachedPlayer Whether the packet should skip being sent to the player attached
    *                           to the packet (false by default).
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SendKillChanges(unsigned short pid, bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept;

    /**
    * \brief Send a PlayerReputation packet with a player's recorded reputation.
    *
    * \param pid The player ID whose reputation should be used.
    * \param sendToOtherPlayers Whether this packet should be sent to players other than the
    *                           player attached to the packet (false by default).
    * \param skipAttachedPlayer Whether the packet should skip being sent to the player attached
    *                           to the packet (false by default).
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SendReputation(unsigned short pid, bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept;

    // All methods below are deprecated versions of methods from above

    EXPORT_APIFUNCTION void CDECL InitializeJournalChanges(unsigned short pid) noexcept;
    EXPORT_APIFUNCTION void CDECL InitializeKillChanges(unsigned short pid) noexcept;
}

#endif //OPENMW_QUESTAPI_HPP
