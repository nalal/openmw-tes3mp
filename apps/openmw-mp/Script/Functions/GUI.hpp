#ifndef OPENMW_GUIAPI_HPP
#define OPENMW_GUIAPI_HPP

#include <Script/Platform.hpp>

#define GUIAPI \
    {"MessageBox",                 GUIFunctions::_MessageBox},\
    {"CustomMessageBox",           GUIFunctions::CustomMessageBox},\
    {"InputDialog",                GUIFunctions::InputDialog},\
    {"PasswordDialog",             GUIFunctions::PasswordDialog},\
    {"ListBox",                    GUIFunctions::ListBox},\
    \
    {"ClearQuickKeyChanges",       GUIFunctions::ClearQuickKeyChanges},\
    \
    {"GetQuickKeyChangesSize",     GUIFunctions::GetQuickKeyChangesSize},\
    \
    {"GetQuickKeySlot",            GUIFunctions::GetQuickKeySlot},\
    {"GetQuickKeyType",            GUIFunctions::GetQuickKeyType},\
    {"GetQuickKeyItemId",          GUIFunctions::GetQuickKeyItemId},\
    \
    {"AddQuickKey",                GUIFunctions::AddQuickKey},\
    \
    {"SendQuickKeyChanges",        GUIFunctions::SendQuickKeyChanges},\
    \
    {"SetMapVisibility",           GUIFunctions::SetMapVisibility},\
    {"SetMapVisibilityAll",        GUIFunctions::SetMapVisibilityAll},\
    \
    {"InitializeQuickKeyChanges",  GUIFunctions::InitializeQuickKeyChanges}

namespace GUIFunctions
{
    /**
    * \brief Display a simple messagebox at the bottom of the screen that vanishes
    *        after a few seconds.
    *
    * Note for C++ programmers: do not rename into MessageBox so as to not conflict
    * with WINAPI's MessageBox.
    *
    * \param pid The player ID for whom the messagebox should appear.
    * \param id The numerical ID of the messagebox.
    * \param label The text in the messagebox.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL _MessageBox(unsigned short pid, int id, const char *label) noexcept;

    /**
    * \brief Display an interactive messagebox at the center of the screen that
    *        vanishes only when one of its buttons is clicked.
    *
    * \param pid The player ID for whom the messagebox should appear.
    * \param id The numerical ID of the messagebox.
    * \param label The text in the messagebox.
    * \parm buttons The captions of the buttons, separated by semicolons (e.g. "Yes;No;Maybe").
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL CustomMessageBox(unsigned short pid, int id, const char *label, const char *buttons) noexcept;

    /**
    * \brief Display an input dialog at the center of the screen.
    *
    * \param pid The player ID for whom the input dialog should appear.
    * \param id The numerical ID of the input dialog.
    * \param label The text at the top of the input dialog.
    * \parm note The text at the bottom of the input dialog.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL InputDialog(unsigned short pid, int id, const char *label, const char *note) noexcept;

    /**
    * \brief Display a password dialog at the center of the screen.
    *
    * Although similar to an input dialog, the password dialog replaces all
    * input characters with asterisks.
    *
    * \param pid The player ID for whom the password dialog should appear.
    * \param id The numerical ID of the password dialog.
    * \param label The text at the top of the password dialog.
    * \parm note The text at the bottom of the password dialog.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL PasswordDialog(unsigned short pid, int id, const char *label, const char *note) noexcept;

    /**
    * \brief Display a listbox at the center of the screen where each item takes up
    *        a row and is selectable, with the listbox only vanishing once the Ok button
    *        is pressed.
    *
    * \param pid The player ID for whom the listbox should appear.
    * \param id The numerical ID of the listbox.
    * \param label The text at the top of the listbox.
    * \parm items The items in the listbox, separated by newlines (e.g. "Item 1\nItem 2").
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL ListBox(unsigned short pid, int id, const char *label, const char *items);

    /**
    * \brief Clear the last recorded quick key changes for a player.
    *
    * This is used to initialize the sending of new PlayerQuickKeys packets.
    *
    * \param pid The player ID whose quick key changes should be used.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL ClearQuickKeyChanges(unsigned short pid) noexcept;

    /**
    * \brief Get the number of indexes in a player's latest quick key changes.
    *
    * \param pid The player ID whose quick key changes should be used.
    * \return The number of indexes.
    */
    EXPORT_APIFUNCTION unsigned CDECL int GetQuickKeyChangesSize(unsigned short pid) noexcept;

    /**
    * \brief Add a new quick key to the quick key changes for a player.
    *
    * \param pid The player ID whose quick key changes should be used.
    * \param slot The slot to be used.
    * \param slot The type of the quick key (0 for ITEM, 1 for ITEM_MAGIC, 2 for MAGIC, 3 for UNASSIGNED).
    * \param itemId The itemId of the item.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL AddQuickKey(unsigned short pid, unsigned short slot, int type, const char* itemId = "") noexcept;

    /**
    * \brief Get the slot of the quick key at a certain index in a player's latest quick key changes.
    *
    * \param pid The player ID whose quick key changes should be used.
    * \param index The index of the quick key in the quick key changes vector.
    * \return The slot.
    */
    EXPORT_APIFUNCTION int CDECL GetQuickKeySlot(unsigned short pid, unsigned int index) noexcept;

    /**
    * \brief Get the type of the quick key at a certain index in a player's latest quick key changes.
    *
    * \param pid The player ID whose quick key changes should be used.
    * \param index The index of the quick key in the quick key changes vector.
    * \return The quick key type.
    */
    EXPORT_APIFUNCTION int CDECL GetQuickKeyType(unsigned short pid, unsigned int index) noexcept;

    /**
    * \brief Get the itemId at a certain index in a player's latest quick key changes.
    *
    * \param pid The player ID whose quick key changes should be used.
    * \param index The index of the quick key in the quick key changes vector.
    * \return The itemId.
    */
    EXPORT_APIFUNCTION const CDECL char *GetQuickKeyItemId(unsigned short pid, unsigned int index) noexcept;

    /**
    * \brief Send a PlayerQuickKeys packet with a player's recorded quick key changes.
    *
    * \param pid The player ID whose quick key changes should be used.
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SendQuickKeyChanges(unsigned short pid) noexcept;

    //state 0 - disallow, 1 - allow

    /**
    * \brief Determine whether a player can see the map marker of another player.
    *
    * Note: This currently has no effect, and is just an unimplemented stub.
    *
    * \param targetPid The player ID whose map marker should be hidden or revealed.
    * \param affectedPid The player ID for whom the map marker will be hidden or revealed.
    * \param state The state of the map marker (false to hide, true to reveal).
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetMapVisibility(unsigned short targetPid, unsigned short affectedPid, unsigned short state) noexcept;

    /**
    * \brief Determine whether a player's map marker can be seen by all other players.
    *
    * Note: This currently has no effect, and is just an unimplemented stub.
    *
    * \param targetPid The player ID whose map marker should be hidden or revealed.
    * \param state The state of the map marker (false to hide, true to reveal).
    * \return void
    */
    EXPORT_APIFUNCTION void CDECL SetMapVisibilityAll(unsigned short targetPid, unsigned short state) noexcept;

    // All methods below are deprecated versions of methods from above

    EXPORT_APIFUNCTION void CDECL InitializeQuickKeyChanges(unsigned short pid) noexcept;
}

#endif //OPENMW_GUIAPI_HPP
