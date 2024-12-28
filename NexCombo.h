#ifndef __NEXCOMBO_H__
#define __NEXCOMBO_H__

#include "NexTouch.h"

/**
 * @brief NexCombo component for Nextion ComboBox.
 */
class NexCombo : public NexTouch {
public:
    /**
     * @brief Constructor for NexCombo.
     * 
     * @param pid Page ID.
     * @param cid Component ID.
     * @param name Name of the component in Nextion Editor.
     */
    NexCombo(uint8_t pid, uint8_t cid, const char *name);

    /**
     * @brief Add an option to the ComboBox.
     * 
     * @param option The option text to add.
     * @return true if success, false otherwise.
     */
    bool addOption(const char *option);

    /**
     * @brief Clear all options from the ComboBox.
     * 
     * @return true if success, false otherwise.
     */
    bool clearOptions();

    /**
     * @brief Get the currently selected option text from the ComboBox.
     * 
     * @param buffer Buffer to store the selected text.
     * @param len Length of the buffer.
     * @return The length of the returned text, or 0 if failed.
     */
    uint16_t getSelectedText(char *buffer, uint16_t len);

    /**
     * @brief Get the currently selected option index from the ComboBox.
     * 
     * @param number Pointer to store the selected index.
     * @return true if success, false otherwise.
     */
    bool getSelectedIndex(uint32_t *number);
};

#endif /* __NEXCOMBO_H__ */
