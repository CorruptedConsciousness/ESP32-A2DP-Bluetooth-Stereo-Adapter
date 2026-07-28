#include "BluetoothA2DPSink.h"

BluetoothA2DPSink a2dp_sink;

const int LED_PIN = 2;

void connection_state_changed(esp_a2d_connection_state_t state, void *ptr) {
    if (state == ESP_A2D_CONNECTION_STATE_CONNECTED) {
        digitalWrite(LED_PIN, HIGH);
    } else if (state == ESP_A2D_CONNECTION_STATE_DISCONNECTED) {
        digitalWrite(LED_PIN, LOW);
    }
}

void setup() {
    pinMode(LED_PIN, OUTPUT);

    // Define custom I2S pin configuration for the PCM5102A
    i2s_pin_config_t my_pin_config = {
        .mck_io_num = I2S_PIN_NO_CHANGE,
        .bck_io_num = 26,                 // Orange Wire -> BCK
        .ws_io_num = 25,                  // Yellow Wire -> LCK / WS
        .data_out_num = 22,               // Blue Wire   -> DIN
        .data_in_num = I2S_PIN_NO_CHANGE
    };

    // Apply pin configuration to the A2DP sink
    a2dp_sink.set_pin_config(my_pin_config);

    // Register callback
    a2dp_sink.set_on_connection_state_changed(connection_state_changed);

    // Start Bluetooth
    a2dp_sink.start("ESP32_BT_Stereo");
}

void loop() {
    // Streaming runs in background
}
