#include "BluetoothA2DPSink.h"

BluetoothA2DPSink a2dp_sink;

// Pin 2 is the onboard blue LED on most ESP32 boards
const int LED_PIN = 2; 

// Callback function triggered when Bluetooth state changes
void connection_state_changed(esp_a2d_connection_state_t state, void *ptr) {
  if (state == ESP_A2D_CONNECTION_STATE_CONNECTED) {
    digitalWrite(LED_PIN, HIGH); // Turn blue LED ON when connected
  } else if (state == ESP_A2D_CONNECTION_STATE_DISCONNECTED) {
    digitalWrite(LED_PIN, LOW);  // Turn blue LED OFF when disconnected
  }
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  
  // Register the connection callback
  a2dp_sink.set_on_connection_state_changed(connection_state_changed);
  
  // Start the Bluetooth audio receiver
  a2dp_sink.start("ESP32_BT_Stereo");
}

void loop() {
  // Streaming runs in the background
}
