#include "NexCombo.h"
#include "NexHardware.h" // Tambahkan ini untuk akses fungsi seperti sendCommand

NexCombo::NexCombo(uint8_t pid, uint8_t cid, const char *name)
    : NexTouch(pid, cid, name) {}

bool NexCombo::addOption(const char *option) {
    // Mengecek apakah ada lebih dari satu opsi dengan karakter newline
    String cmd = String(getObjName()) + ".path=\"" + option + "\"";
    
    // Menambahkan opsi-opsi jika ada lebih dari satu baris
    sendCommand(cmd.c_str());
    
    // Mengirim perintah dan menunggu konfirmasi bahwa perintah selesai
    return recvRetCommandFinished();
}

bool NexCombo::clearOptions() {
    String cmd = String(getObjName()) + ".clr()";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint16_t NexCombo::getSelectedText(char *buffer, uint16_t len) {
    String cmd = "get " + String(getObjName()) + ".txt";
    sendCommand(cmd.c_str());
    return recvRetString(buffer, len);
}

bool NexCombo::getSelectedIndex(uint32_t *number) {
    String cmd = "get " + String(getObjName()) + ".val";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}
