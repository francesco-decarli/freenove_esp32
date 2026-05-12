#include "BluetoothSerial.h"
#include "driver/i2s.h"
#include "nvs.h"
#include "nvs_flash.h"
#include "esp_bt.h"
#include "bt_app_core.h"
#include "bt_app_av.h"
#include "esp_bt_main.h"
#include "esp_bt_device.h"
#include "esp_gap_bt_api.h"
#include "esp_a2dp_api.h"
#include "esp_avrc_api.h"

// This is for configuration (enabling code in #ifndef scope)
#define CONFIG_CLASSIC_BT_ENABLED
#define CONFIG_BT_ENABLED 
#define CONFIG_BLUEDROID_ENABLED

BluetoothSerial SerialBT;

// Initialize Bluetooth connection
static void bt_av_hdl_stack_evt(uint16_t event, void *p_param){
  if(event==0) {
    // Initialize A2DP
    esp_a2d_register_callback(&bt_app_a2d_cb);
    esp_a2d_sink_register_data_callback(bt_app_a2d_data_cb);
    esp_a2d_sink_init();
    // Initialize AVRCP controller
    esp_avrc_ct_init();
    esp_avrc_ct_register_callback(bt_app_rc_ct_cb);
    // Set discoverable and connectable mode
    esp_bt_gap_set_scan_mode(ESP_BT_CONNECTABLE, ESP_BT_GENERAL_DISCOVERABLE);
  }
}

void setup() {
  Serial.begin(115'200);
  SerialBT.begin("ESP32-Wroover-E");

  esp_err_t err = nvs_flash_init();
  if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
    ESP_ERROR_CHECK(nvs_flash_erase());
    err = nvs_flash_init();
  }
  i2s_config_t i2s_config;
  i2s_config.mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX | I2S_MODE_PDM);
  i2s_config.bits_per_sample = I2S_BITS_PER_SAMPLE_24BIT;
  i2s_config.sample_rate = 44'100;  // sampling frequency of audio stream
  i2s_config.channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT;  
  i2s_config.communication_format = I2S_COMM_FORMAT_STAND_I2S;
  i2s_config.intr_alloc_flags = 0;      // interrupt priority
  i2s_config.dma_buf_count = 6;         // DMA partitions
  i2s_config.dma_buf_len = 60;          // DMA capacity for each partition
  i2s_config.tx_desc_auto_clear = true; // DMA data auto clearing
  i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL);
  i2s_set_dac_mode(I2S_DAC_CHANNEL_BOTH_EN);
  i2s_set_pin(I2S_NUM_0, NULL);

  // BT HW initialization
  esp_bluedroid_init();
  esp_bluedroid_enable();
  bt_app_task_start_up();
  bt_app_work_dispatch(bt_av_hdl_stack_evt, 0, NULL, 0, NULL);
  Serial.println("Init ok!");
  Serial.println("Waiting to pair...");
}

void loop(){
  ;  
}