#ifndef OPENMW_SHAPESHIFTAPI_HPP
#define OPENMW_SHAPESHIFTAPI_HPP

#include "../Types.hpp"

#include <Script/Platform.hpp>

#define SHAPESHIFTAPI \
    {"GetScale",                    ShapeshiftFunctions::GetScale},\
    {"IsWerewolf",                  ShapeshiftFunctions::IsWerewolf},\
    {"GetCreatureRefId",            ShapeshiftFunctions::GetCreatureRefId},\
    {"GetCreatureNameDisplayState", ShapeshiftFunctions::GetCreatureNameDisplayState},\
    \
    {"SetScale",                    ShapeshiftFunctions::SetScale},\
    {"SetWerewolfState",            ShapeshiftFunctions::SetWerewolfState},\
    {"SetCreatureRefId",            ShapeshiftFunctions::SetCreatureRefId},\
    {"SetCreatureNameDisplayState", ShapeshiftFunctions::SetCreatureNameDisplayState},\
    \
    {"SendShapeshift",              ShapeshiftFunctions::SendShapeshift}

namespace ShapeshiftFunctions
{
    /**
    * \brief Get the scale of a player.
    *
    * \param pid The player ID.
    * \return The scale.
    */
    EXPORT_APIFUNCTION double CDECL GetScale(unsigned short pid) noexcept;

    /**
    * \brief Check whether a player is a werewolf.
    *
    * This is based on the last PlayerShapeshift packet received or sent for that player.
    *
    * \param pid The player ID.
    * \return The werewolf state.
    */
    EXPORT_APIFUNCTION bool CDECL IsWerewolf(unsigned short pid) noexcept;

    /**
    * \brief Get the refId of the creature the player is disguised as.
    *
    * \param pid The player ID.
    * \return The creature refId.
    */
    EXPORT_APIFUNCTION const CDECL char *GetCreatureRefId(unsigned short pid) noexcept;

    /**
    * \brief Check whether a player's name is replaced by that of the creature they are
    *        disguised as when other players hover over them.
    *
    * This is based on the last PlayerShapeshift packet received or sent for that player.
    *
    * \param pid The player ID.
    * \return The creature name display state.
    */
    EXPORT_APIFUNCTION bool CDECL GetCreatureNameDisplayState(unsigned short pid) noexcept;

    /**
    * \brief Set the scale of a player.
    *
    * This changes the scale recorded for that player in the server memory, but
    * does not by itself send a packet.
    *
    * \param pid The player ID.
    * \param scale The new scale.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetScale(unsigned short pid, double scale) noexcept;

    /**
    * \brief Set the werewolf state of a player.
    *
    * This changes the werewolf state recorded for that player in the server memory, but
    * does not by itself send a packet.
    *
    * \param pid The player ID.
    * \param isWerewolf The new werewolf state.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetWerewolfState(unsigned short pid, bool isWerewolf) noexcept;

    /**
    * \brief Set the refId of the creature a player is disguised as.
    *
    * This changes the creature refId recorded for that player in the server memory, but
    * does not by itself send a packet.
    *
    * \param pid The player ID.
    * \param refId The creature refId.
    * \param displaysCreatureName Whether the player's name appears as that of the creature
    *                             when hovered over by others.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetCreatureRefId(unsigned short pid, const char *refId) noexcept;

    /**
    * \brief Set whether a player's name is replaced by that of the creature they are
    *        disguised as when other players hover over them.
    *
    * \param pid The player ID.
    * \param displayState The creature name display state.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetCreatureNameDisplayState(unsigned short pid, bool displayState) noexcept;

    /**
    * \brief Send a PlayerShapeshift packet about a player.
    *
    * This sends the packet to all players connected to the server. It is currently used
    * only to communicate werewolf states.
    *
    * \param pid The player ID.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SendShapeshift(unsigned short pid);
}

#endif //OPENMW_SHAPESHIFTAPI_HPP
